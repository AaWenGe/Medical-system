#include "welcomeview.h"
#include "ui_welcomeview.h"


WelcomeView::WelcomeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeView)
{
    ui->setupUi(this);
    qDebug()<<"create WelcomeView";
}

WelcomeView::~WelcomeView()
{
    delete ui;
    qDebug()<<"destory WelcomeView";

}

void WelcomeView::on_btDepartment_clicked()
{
    emit goDepartmentView();
}

void WelcomeView::on_btDoctor_clicked()
{
    emit goDoctorView();
}

void WelcomeView::on_btPatient_clicked()
{
    emit goPatientView();
}

void WelcomeView::on_btMedication_clicked()
{
    emit goMedicationView();
}

void WelcomeView::on_btVisit_clicked()
{
    emit goVisitView();
}

