#include "doctoreditview.h"
#include "ui_doctoreditview.h"

DoctorEditView::DoctorEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::doctorEditView)
{
    ui->setupUi(this);

    dataMapper =new QDataWidgetMapper();
    QSqlTableModel *tableModel = iDataBase::getInstance().doctorTabModel;
    dataMapper->setModel(iDataBase::getInstance().doctorTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->dbEditID,tableModel->fieldIndex("DoctorID"));
    dataMapper->addMapping(ui->dbEditName,tableModel->fieldIndex("Dname"));
    dataMapper->addMapping(ui->dbEditAge,tableModel->fieldIndex("Age"));
    dataMapper->addMapping(ui->dbComboSex,tableModel->fieldIndex("Gender"));
    dataMapper->addMapping(ui->dbEditLicenseNumber,tableModel->fieldIndex("LicenseNumber"));
    dataMapper->setCurrentIndex(index);

    //只有获得焦点才会保存到数据库

    ui->dbComboSex->setFocus();
//    ui->dbEditID->setFocus();

//    ui->dbEditID->setEnabled(false);
//    ui->dbCreatedTimeStamp->setEnabled(false);
    qDebug()<<"doctorEdit,index :"<<index;
}

DoctorEditView::~DoctorEditView()
{
    delete ui;
}

void DoctorEditView::on_btSave_clicked()
{
    if(!iDataBase::getInstance().submitDoctorEdit()){
        qDebug()<<"submit fail";
    }else{
        qDebug()<<"submit success";

    }
    emit goPreviousView();
}


void DoctorEditView::on_btCancel_clicked()
{
    iDataBase::getInstance().revertDoctorEdit();
    emit goPreviousView();
}

