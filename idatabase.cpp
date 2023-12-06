#include "idatabase.h"

void iDataBase::initDatabase()
{
    database=QSqlDatabase::addDatabase("QSQLITE"); //添加sql lite数据库驱动
    QString aFile="libqtlab4a.db";
    database.setDatabaseName(aFile);//设置数据库路径，不存在则创建

    if(database.open()){
        qDebug()<<"open database is ok!";
    }
    else{
        qDebug()<<"failed to open database";
    }

}

bool iDataBase::initPatientModel()
{
    patientTabModel = new QSqlTableModel(this,database);
    patientTabModel->setTable("patient");
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);                       //数据保存方式,OnManualSubmit, OnRowChange
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder);       //排序
    if(!(patientTabModel->select()))    //查询数据
        return false;

    patientSelection = new QItemSelectionModel(patientTabModel);
    return true;

}

int iDataBase::addNewPatient()
{
    //QModelIndex是用来表示model位置的类
    patientTabModel->insertRow(patientTabModel->rowCount(),QModelIndex());  //在末尾添加一个纪律
    QModelIndex curIndex = patientTabModel->index(patientTabModel->rowCount()-1,1);//创建最后一行的modelIndex

    int curRecNo=curIndex.row();
    QSqlRecord curRec=patientTabModel->record(curRecNo);        //获取当前记录
    curRec.setValue("CREATEDTIME",QDateTime::currentDateTime().toString("yyyy-MM-dd"));

    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));

    patientTabModel->setRecord(curRecNo,curRec);

    return curIndex.row();
}

bool iDataBase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

bool iDataBase::deleteCurrentPatient()
{
    QModelIndex curIndex = patientSelection->currentIndex();    //获取当前选择单元格的索引
    patientTabModel->removeRow(curIndex.row());                //从模型删除
    patientTabModel->submitAll();
    patientTabModel->select();
}

bool iDataBase::submitPatientEdit()
{
    return patientTabModel->submitAll();
}

void iDataBase::revertPatientEdit()
{
  patientTabModel->revertAll();

}

QString iDataBase::userLogin(QString userName, QString password)
{
    QSqlQuery query;    //查询出当前记录的所有字段
    query.prepare("select USERNAME,PASSWORD from User where USERNAME = :USER");
    query.bindValue(":USER",userName);
    query.exec();
    if(query.first()&&query.value("username").isValid()){
        QString passwd = query.value("password").toString();
        if(passwd==password){
            qDebug()<<"loginOK";
            return "loginOK";
        }
        else{
            qDebug()<<"wrong Password";
            return "wrongPassword";
        }
    }else{
        qDebug()<<"wrongUsername";
        return "wrongUsername";

    }
}

iDataBase::iDataBase(QObject *parent) : QObject(parent)
{
    initDatabase();
}
