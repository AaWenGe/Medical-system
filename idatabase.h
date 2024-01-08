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


        QSqlTableModel *doctorTabModel; // 医生表格模型
        QItemSelectionModel *doctorSelection;

        bool initDoctorModel();
        int addNewDoctor();
        bool searchDoctor(QString filter);
        bool deleteCurrentDoctor();
        bool submitDoctorEdit();
        void revertDoctorEdit();
        bool updateDoctor();
        bool deleteDoctor();

        //就诊记录
        bool initVisitModel();
        QSqlTableModel *visitTabModel;       //数据模型
        QItemSelectionModel *visitSelection;  //选择模型

        int addNewVisit();
        bool searchVisit(QString filter);
        bool deleteCurrentVisit();
        bool submitVisitEdit();
        void revertVisitEdit();


        //药品
        bool initMedicationModel();
        QSqlTableModel *medicationTabModel;       //数据模型
        QItemSelectionModel *medicationSelection;  //选择模型

        int addNewMedication();
        bool searchMedication(QString filter);
        bool deleteCurrentMedication();
        bool submitMedicationEdit();
        void revertMedicationEdit();


signals:
private:
        explicit iDataBase(QObject *parent = nullptr);



        iDataBase(iDataBase const&)               = delete;
        void operator=(iDataBase const&)  = delete;
        QSqlDatabase database;


};

#endif // IDATABASE_H
