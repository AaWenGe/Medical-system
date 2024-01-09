#include "medicationview.h"
#include "ui_medicationview.h"
#include "idatabase.h"
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>

MedicationView::MedicationView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MedicationView)
{
    ui->setupUi(this);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);          //不可修改
    ui->tableView->setAlternatingRowColors(true);

    iDataBase &iDataBase = iDataBase::getInstance();
    if(iDataBase.initMedicationModel()){
        ui->tableView->setModel(iDataBase.medicationTabModel);
        ui->tableView->setSelectionModel(iDataBase.medicationSelection);
    }
}

MedicationView::~MedicationView()
{
    delete ui;
}

void MedicationView::on_btAdd_clicked()
{
    emit goMedicationEditView();
}


void MedicationView::on_btChange_clicked()
{

}


void MedicationView::on_btDelete_clicked()
{
    iDataBase::getInstance().deleteCurrentMedication();
}


void MedicationView::on_btSrearch_clicked()
{
    QString filter= QString("Mname like '%%1%'").arg(ui->lineEdit->text());
    iDataBase::getInstance().searchMedication(filter);
}

