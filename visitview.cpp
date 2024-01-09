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
    int currow = iDataBase::getInstance().addNewVisit();
    emit goVisitEditView(currow);
}



void VisitView::on_btChange_clicked()
{
    QModelIndex curIndex =iDataBase::getInstance().visitSelection->currentIndex();
    emit goVisitEditView(curIndex.row());
}


void VisitView::on_btDelete_clicked()
{
    iDataBase::getInstance().deleteCurrentVisit();
}


void VisitView::on_btSrearch_clicked()
{
    QString filter= QString("VisitID like '%%1%'").arg(ui->lineEdit->text());
    iDataBase::getInstance().searchVisit(filter);
}

