#include "medicationeditview.h"
#include "ui_medicationeditview.h"

MedicationEditView::MedicationEditView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MedicationEditView)
{
    ui->setupUi(this);
}

MedicationEditView::~MedicationEditView()
{
    delete ui;
}
