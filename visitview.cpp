#include "visitview.h"
#include "ui_visitview.h"

VisitView::VisitView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisitView)
{
    ui->setupUi(this);
}

VisitView::~VisitView()
{
    delete ui;
}
