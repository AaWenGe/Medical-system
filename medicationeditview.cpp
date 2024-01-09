#include "medicationeditview.h"
#include "ui_medicationeditview.h"

MedicationEditView::MedicationEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::MedicationEditView)
{
    ui->setupUi(this);
    dataMapper =new QDataWidgetMapper();
    QSqlTableModel *tableModel = iDataBase::getInstance().medicationTabModel;
    dataMapper->setModel(iDataBase::getInstance().medicationTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    dataMapper->addMapping(ui->dbEditID,tableModel->fieldIndex("MedicationID"));
    dataMapper->addMapping(ui->dbEditName,tableModel->fieldIndex("Mname"));
    dataMapper->addMapping(ui->dbEditDosage,tableModel->fieldIndex("Dosage"));
    dataMapper->addMapping(ui->dbEditStock,tableModel->fieldIndex("Stock"));

    dataMapper->setCurrentIndex(index);


//    ui->dbEditID->setEnabled(false);
//    ui->dbCreatedTimeStamp->setEnabled(false);
    qDebug()<<"medicationEdit,index :"<<index;

}

MedicationEditView::~MedicationEditView()
{
    delete ui;
}

void MedicationEditView::on_btSave_clicked()
{
    if(!iDataBase::getInstance().submitMedicationEdit()){
        qDebug()<<"submit fail";
    }else{
        qDebug()<<"submit success";

    }
    emit goPreviousView();
}

void MedicationEditView::on_btCancel_clicked()
{
    iDataBase::getInstance().revertMedicationEdit();
    emit goPreviousView();
}




