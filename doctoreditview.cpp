#include "doctoreditview.h"
#include "ui_doctoreditview.h"

DoctorEditView::DoctorEditView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::doctorEditView)
{
    ui->setupUi(this);
}

DoctorEditView::~DoctorEditView()
{
    delete ui;
}
