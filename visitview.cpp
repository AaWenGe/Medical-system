#include "visitview.h"
#include "ui_visitview.h"

VisitView::VisitView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisitView)
{
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);          //不可修改
    ui->tableView->setAlternatingRowColors(true);

    iDataBase &iDataBase = iDataBase::getInstance();
    if(iDataBase.initVisitModel()){
        ui->tableView->setModel(iDataBase.visitTabModel);
        ui->tableView->setSelectionModel(iDataBase.visitSelection);
    }
}


VisitView::~VisitView()
{
    delete ui;
}

void VisitView::on_btAdd_clicked()
{
    emit goVisitEditView();
}



void VisitView::on_btChange_clicked()
{

}


void VisitView::on_btDelete_clicked()
{

}


void VisitView::on_btSrearch_clicked()
{

}

