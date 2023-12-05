#include "idatabase.h"

void iDataBase::initDatabase()
{
    database=QSqlDatabase::addDatabase("QSQLITE"); //添加sql lite数据库驱动
    QString aFile="../../libqtlab4a.db";
    database.setDatabaseName(aFile);//设置数据库路径，不存在则创建

    if(database.open()){
        qDebug()<<"open database is ok!";
    }
    else{
        qDebug()<<"failed to open database";
    }

}

iDataBase::iDataBase(QObject *parent) : QObject(parent)
{
    initDatabase();
}
