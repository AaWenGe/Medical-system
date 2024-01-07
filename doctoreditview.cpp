#include "doctoreditview.h"
#include "ui_doctoreditview.h"

doctorEditView::doctorEditView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doctorEditView)
{
    ui->setupUi(this);
}

doctorEditView::~doctorEditView()
{
    delete ui;
}
