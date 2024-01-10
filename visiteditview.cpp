#include "visiteditview.h"
#include "ui_visiteditview.h"

VisitEditView::VisitEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::VisitEditView)
{
    ui->setupUi(this);

    dataMapper =new QDataWidgetMapper();
    QSqlTableModel *tableModel = iDataBase::getInstance().visitTabModel;
    dataMapper->setModel(iDataBase::getInstance().visitTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);


    dataMapper->addMapping(ui->dbEditID,tableModel->fieldIndex("VisitID"));
    dataMapper->addMapping(ui->dbEditDname,tableModel->fieldIndex("Dname"));
    dataMapper->addMapping(ui->dbEditPname,tableModel->fieldIndex("Pname"));
    dataMapper->addMapping(ui->dbEditMedicationList,tableModel->fieldIndex("MedicationList"));
    dataMapper->addMapping(ui->dbEditDiagnosis,tableModel->fieldIndex("Diagnosis"));
    dataMapper->addMapping(ui->dbEditDate,tableModel->fieldIndex("VisitDate"));

    dataMapper->setCurrentIndex(index);


    qDebug()<<"visitEdit,index :"<<index;


}

VisitEditView::~VisitEditView()
{
    delete ui;
}

void VisitEditView::on_btSave_clicked()
{
    if(!iDataBase::getInstance().submitVisitEdit()){
        qDebug()<<"submit fail";
    }else{
        qDebug()<<"submit success";

    }
    emit goPreviousView();
}

void VisitEditView::on_btCancel_clicked()
{
    iDataBase::getInstance().revertVisitEdit();
    emit goPreviousView();
}

