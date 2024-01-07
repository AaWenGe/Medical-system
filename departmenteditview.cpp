#include "departmenteditview.h"
#include "ui_departmenteditview.h"

departmentEditView::departmentEditView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::departmentEditView)
{
    ui->setupUi(this);
}

departmentEditView::~departmentEditView()
{
    delete ui;
}
