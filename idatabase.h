#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include <QDataWidgetMapper>
#include <QUuid>
//单例模式
class iDataBase : public QObject
{
    Q_OBJECT
public:
        static iDataBase& getInstance()
        {
            static iDataBase    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }

        QString userLogin(QString userName,QString password);
        void initDatabase();
        bool initPatientModel();
        QSqlTableModel *patientTabModel;       //数据模型
        QItemSelectionModel *patientSelection;  //选择模型

        int addNewPatient();
        bool searchPatient(QString filter);
        bool deleteCurrentPatient();
        bool submitPatientEdit();
        void revertPatientEdit();
signals:
private:
        explicit iDataBase(QObject *parent = nullptr);



        iDataBase(iDataBase const&)               = delete;
        void operator=(iDataBase const&)  = delete;
        QSqlDatabase database;

};

#endif // IDATABASE_H
