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
