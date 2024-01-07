#include "medicationview.h"
#include "ui_medicationview.h"

MedicationView::MedicationView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MedicationView)
{
    ui->setupUi(this);
}

MedicationView::~MedicationView()
{
    delete ui;
}
