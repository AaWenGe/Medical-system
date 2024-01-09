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


// 初始化病人模型的方法
bool iDataBase::initPatientModel()
{
    patientTabModel = new QSqlTableModel(this,database); // 创建一个QSqlTableModel对象
    patientTabModel->setTable("patient");                // 设置操作的表格为"patient"
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit); // 设置数据保存策略为手动提交
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder); // 根据姓名字段升序排序
    if(!(patientTabModel->select())) {                   // 尝试查询数据
        return false;                                       // 如果查询失败，返回false
    }
    patientSelection = new QItemSelectionModel(patientTabModel); // 创建一个QItemSelectionModel对象
    return true;                                            // 如果查询成功，返回true
}


// 添加新病人的方法
int iDataBase::addNewPatient()
{
    patientTabModel->insertRow(patientTabModel->rowCount(),QModelIndex()); // 在模型末尾添加新行
    QModelIndex curIndex = patientTabModel->index(patientTabModel->rowCount()-1,1); // 获取新添加行的索引
    int curRecNo=curIndex.row();                         // 获取行号
    QSqlRecord curRec=patientTabModel->record(curRecNo); // 获取当前记录
    curRec.setValue("CREATEDTIME",QDateTime::currentDateTime().toString("yyyy-MM-dd")); // 设置创建时间
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces)); // 设置ID为生成的UUID
    patientTabModel->setRecord(curRecNo,curRec);        // 设置当前记录
    return curIndex.row();                               // 返回新添加行的行号
}

// 搜索病人的方法
bool iDataBase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);                  // 设置搜索过滤器
    return patientTabModel->select();                   // 执行搜索
}

bool iDataBase::deleteCurrentPatient()
{
    QModelIndex curIndex = patientSelection->currentIndex(); // 获取当前选中的病人记录的索引
    patientTabModel->removeRow(curIndex.row());          // 从模型中删除该行
    patientTabModel->submitAll();                       // 提交所有更改
    patientTabModel->select();                          // 重新选择当前行
    return true;                                       // 返回成功标志
}

// 提交病人编辑的方法
bool iDataBase::submitPatientEdit()
{
    return patientTabModel->submitAll();                 // 提交所有行编辑
}
// 撤销病人编辑的方法
void iDataBase::revertPatientEdit()
{
    patientTabModel->revertAll();                       // 撤销所有行的编辑
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


//**********************************医生部分***********************************
bool iDataBase::initDoctorModel()
{
    // 创建一个QSqlTableModel对象
    doctorTabModel = new QSqlTableModel(this, database);
    doctorTabModel->setTable("doctor"); // 设置操作的表格为"doctor"
    doctorTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit); // 设置数据保存策略为手动提交
    doctorTabModel->setSort(doctorTabModel->fieldIndex("Dname"),Qt::AscendingOrder); // 根据姓名字段升序排序
    if(!(doctorTabModel->select())) {                   // 尝试查询数据
        return false;                                       // 如果查询失败，返回false
    }
    doctorSelection = new QItemSelectionModel(doctorTabModel); // 创建一个QItemSelectionModel对象
    return true; // 初始化成功
}


int iDataBase::addNewDoctor()
{

    doctorTabModel->insertRow(doctorTabModel->rowCount(),QModelIndex()); // 在模型末尾添加新行
    QModelIndex curIndex = doctorTabModel->index(doctorTabModel->rowCount()-1,1); // 获取新添加行的索引
    int curRecNo=curIndex.row();                         // 获取行号
    QSqlRecord curRec=doctorTabModel->record(curRecNo); // 获取当前记录
    curRec.setValue("CREATEDTIME",QDateTime::currentDateTime().toString("yyyy-MM-dd")); // 设置创建时间
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces)); // 设置ID为生成的UUID
    doctorTabModel->setRecord(curRecNo,curRec);        // 设置当前记录
    return curIndex.row();
}

bool iDataBase::searchDoctor(QString filter)
{
    doctorTabModel->setFilter(filter);                  // 设置搜索过滤器
    return doctorTabModel->select();                   // 执行搜索
}

bool iDataBase::deleteCurrentDoctor()
{
    QModelIndex curIndex = doctorSelection->currentIndex(); // 获取当前选中的病人记录的索引
    doctorTabModel->removeRow(curIndex.row());          // 从模型中删除该行
    doctorTabModel->submitAll();                       // 提交所有更改
    doctorTabModel->select();                          // 重新选择当前行
    return true;
}

bool iDataBase::submitDoctorEdit()
{
    return doctorTabModel->submitAll();                 // 提交所有行编辑
}

void iDataBase::revertDoctorEdit()
{
    doctorTabModel->revertAll();                       // 撤销所有行的编辑
}



//**********************************就诊记录部分***********************************
bool iDataBase::initVisitModel()
{
    // 创建一个QSqlTableModel对象
    visitTabModel = new QSqlTableModel(this, database);
    visitTabModel->setTable("visit"); // 设置操作的表格为"visit"
    visitTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit); // 设置数据保存策略为手动提交
    visitTabModel->setSort(visitTabModel->fieldIndex("VisitID"),Qt::AscendingOrder); // 根据姓名字段升序排序
    if(!(visitTabModel->select())) {                   // 尝试查询数据
        return false;                                       // 如果查询失败，返回false
    }
    visitSelection = new QItemSelectionModel(visitTabModel); // 创建一个QItemSelectionModel对象
    return true; // 初始化成功
}


int iDataBase::addNewVisit()
{

    visitTabModel->insertRow(visitTabModel->rowCount(),QModelIndex()); // 在模型末尾添加新行
    QModelIndex curIndex = visitTabModel->index(visitTabModel->rowCount()-1,1); // 获取新添加行的索引
    int curRecNo=curIndex.row();                         // 获取行号
    QSqlRecord curRec=visitTabModel->record(curRecNo); // 获取当前记录
    curRec.setValue("CREATEDTIME",QDateTime::currentDateTime().toString("yyyy-MM-dd")); // 设置创建时间
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces)); // 设置ID为生成的UUID
    visitTabModel->setRecord(curRecNo,curRec);        // 设置当前记录
    return curIndex.row();
}

bool iDataBase::searchVisit(QString filter)
{
    visitTabModel->setFilter(filter);                  // 设置搜索过滤器
    return visitTabModel->select();                   // 执行搜索
}

bool iDataBase::deleteCurrentVisit()
{
    QModelIndex curIndex = visitSelection->currentIndex(); // 获取当前选中的病人记录的索引
    visitTabModel->removeRow(curIndex.row());          // 从模型中删除该行
    visitTabModel->submitAll();                       // 提交所有更改
    visitTabModel->select();                          // 重新选择当前行
    return true;
}

bool iDataBase::submitVisitEdit()
{
    return visitTabModel->submitAll();                 // 提交所有行编辑
}

void iDataBase::revertVisitEdit()
{
    visitTabModel->revertAll();                       // 撤销所有行的编辑
}


//**********************************药品部分***********************************
bool iDataBase::initMedicationModel()
{
    // 创建一个QSqlTableModel对象
    medicationTabModel = new QSqlTableModel(this, database);
    medicationTabModel->setTable("medication"); // 设置操作的表格为"medication"
    medicationTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit); // 设置数据保存策略为手动提交
    medicationTabModel->setSort(medicationTabModel->fieldIndex("Mname"),Qt::AscendingOrder); // 根据姓名字段升序排序
    if(!(medicationTabModel->select())) {                   // 尝试查询数据
        return false;                                       // 如果查询失败，返回false
    }
    medicationSelection = new QItemSelectionModel(medicationTabModel); // 创建一个QItemSelectionModel对象
    return true; // 初始化成功
}


int iDataBase::addNewMedication()
{

    medicationTabModel->insertRow(medicationTabModel->rowCount(),QModelIndex()); // 在模型末尾添加新行
    QModelIndex curIndex = medicationTabModel->index(medicationTabModel->rowCount()-1,1); // 获取新添加行的索引
    int curRecNo=curIndex.row();                         // 获取行号
    QSqlRecord curRec=medicationTabModel->record(curRecNo); // 获取当前记录
    curRec.setValue("CREATEDTIME",QDateTime::currentDateTime().toString("yyyy-MM-dd")); // 设置创建时间
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces)); // 设置ID为生成的UUID
    medicationTabModel->setRecord(curRecNo,curRec);        // 设置当前记录
    return curIndex.row();
}

bool iDataBase::searchMedication(QString filter)
{
    medicationTabModel->setFilter(filter);                  // 设置搜索过滤器
    return medicationTabModel->select();                   // 执行搜索
}

bool iDataBase::deleteCurrentMedication()
{
    QModelIndex curIndex = medicationSelection->currentIndex(); // 获取当前选中的病人记录的索引
    medicationTabModel->removeRow(curIndex.row());          // 从模型中删除该行
    medicationTabModel->submitAll();                       // 提交所有更改
    medicationTabModel->select();                          // 重新选择当前行
    return true;
}

bool iDataBase::submitMedicationEdit()
{
    return medicationTabModel->submitAll();                 // 提交所有行编辑
}

void iDataBase::revertMedicationEdit()
{
    medicationTabModel->revertAll();                       // 撤销所有行的编辑
}

