#include "patienteditview.h"
#include "ui_patienteditview.h"

PatientEditView::PatientEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::PatientEditView)
{
    ui->setupUi(this);

    dataMapper =new QDataWidgetMapper();
    QSqlTableModel *tableModel = iDataBase::getInstance().patientTabModel;
    dataMapper->setModel(iDataBase::getInstance().patientTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);


    dataMapper->addMapping(ui->dbEditID,tableModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditName,tableModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->dbEditIDCard,tableModel->fieldIndex("ID_CARD"));
    dataMapper->addMapping(ui->dbSpinHeight,tableModel->fieldIndex("HEIGHT"));
    dataMapper->addMapping(ui->dbSpinWeight,tableModel->fieldIndex("WEIGHT"));
    dataMapper->addMapping(ui->dbEditPhone,tableModel->fieldIndex("MOBILEPHONE"));
    dataMapper->addMapping(ui->dbDateEditDOB,tableModel->fieldIndex("DOB"));
    dataMapper->addMapping(ui->dbComboSex,tableModel->fieldIndex("SEX"));
    dataMapper->addMapping(ui->dbCreatedTimeStamp,tableModel->fieldIndex("CREATEDTIME"));
    dataMapper->setCurrentIndex(index);

    ui->dbEditID->setEnabled(false);
    ui->dbCreatedTimeStamp->setEnabled(false);
    qDebug()<<"patientEdit,index :"<<index;
}

PatientEditView::~PatientEditView()
{
    delete ui;
}

void PatientEditView::on_btSave_clicked()
{
    if(!iDataBase::getInstance().submitPatientEdit()){
        qDebug()<<"submit fail";
    }else{
        qDebug()<<"submit success";

    }
    emit goPreviousView();
}

void PatientEditView::on_btCancel_clicked()
{
    iDataBase::getInstance().revertPatientEdit();
    emit goPreviousView();
}
