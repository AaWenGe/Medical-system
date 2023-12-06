#include "patientview.h"
#include "ui_patientview.h"

PatientView::PatientView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientView)
{
    ui->setupUi(this);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);          //不可修改
    ui->tableView->setAlternatingRowColors(true);

    iDataBase &iDataBase = iDataBase::getInstance();
    if(iDataBase.initPatientModel()){
        ui->tableView->setModel(iDataBase.patientTabModel);
        ui->tableView->setSelectionModel(iDataBase.patientSelection);
    }
}

PatientView::~PatientView()
{
    delete ui;
}

void PatientView::on_btAdd_clicked()
{
    int currow = iDataBase::getInstance().addNewPatient();
    emit goPatientEditView(currow);
}

void PatientView::on_btSrearch_clicked()
{
    QString filter= QString("name like '%%1%'").arg(ui->lineEdit->text());
    iDataBase::getInstance().searchPatient(filter);
}

void PatientView::on_btDelete_clicked()
{
    iDataBase::getInstance().deleteCurrentPatient();
}

void PatientView::on_btChange_clicked()
{
    QModelIndex curIndex =iDataBase::getInstance().patientSelection->currentIndex();
    emit goPatientEditView(curIndex.row());
}

