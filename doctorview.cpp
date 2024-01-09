#include "doctorview.h"
#include "ui_doctorview.h"
#include "idatabase.h"
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>

DoctorView::DoctorView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorView)
{
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);          //不可修改
    ui->tableView->setAlternatingRowColors(true);

    iDataBase &iDataBase = iDataBase::getInstance();
    if(iDataBase.initDoctorModel()){
        ui->tableView->setModel(iDataBase.doctorTabModel);
        ui->tableView->setSelectionModel(iDataBase.doctorSelection);
    }
}

DoctorView::~DoctorView()
{
    delete ui;
}

void DoctorView::on_btAdd_clicked()
{
    emit goDoctorEditView();
}


void DoctorView::on_btChange_clicked()
{

}


void DoctorView::on_btDelete_clicked()
{
    iDataBase::getInstance().deleteCurrentDoctor();
}


void DoctorView::on_btSrearch_clicked()
{
    QString filter= QString("Dname like '%%1%'").arg(ui->lineEdit->text());
    iDataBase::getInstance().searchDoctor(filter);
}

