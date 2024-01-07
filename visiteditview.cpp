#include "visiteditview.h"
#include "ui_visiteditview.h"

VisitEditView::VisitEditView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisitEditView)
{
    ui->setupUi(this);
}

VisitEditView::~VisitEditView()
{
    delete ui;
}
