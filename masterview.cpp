#include "masterview.h"
#include "ui_masterview.h"

MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    goLoginView();

}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{
    qDebug()<<"goLoginView";
    loginView = new LoginView(this);
    ui->stackedWidget->addWidget(loginView);
    pushWidgetToStackView(loginView);

    connect(loginView,&LoginView::loginSuccess,this,&MasterView::goWelcomeView);

 }

void MasterView::goWelcomeView()
{
    qDebug()<<"goWelcomView";
    welcomeView = new WelcomeView(this);
    ui->stackedWidget->addWidget(welcomeView);
    pushWidgetToStackView(welcomeView);

    connect(welcomeView,&WelcomeView::goDoctorView,this,&MasterView::goDoctorView);
    connect(welcomeView,&WelcomeView::goDepartmentView,this,&MasterView::goDepartmentView);
    connect(welcomeView,&WelcomeView::goPatientView,this,&MasterView::goPatientView);

}

void MasterView::goDoctorView()
{
    qDebug()<<"goDoctorView";
    doctorView = new DoctorView(this);
    ui->stackedWidget->addWidget(doctorView);

    pushWidgetToStackView(doctorView);
}

void MasterView::goDepartmentView()
{
    qDebug()<<"goDepartmentView";
    departmentView = new DepartmentView(this);
    ui->stackedWidget->addWidget(departmentView);

    pushWidgetToStackView(departmentView);
}

void MasterView::goPatientView()
{
    qDebug()<<"goPatientView";
    patientView = new PatientView(this);
    ui->stackedWidget->addWidget(patientView);

    pushWidgetToStackView(patientView);
    connect(patientView,&PatientView::goPatientEditView,this,&MasterView::goPatientEditView);
}


void MasterView::goPatientEditView()
{
    qDebug()<<"goPatientEditView";
    patientEditView = new PatientEditView(this);
    ui->stackedWidget->addWidget(patientEditView);

    pushWidgetToStackView(patientEditView);
}

void MasterView::goPreviousView()
{
    int count = ui->stackedWidget->count();

    if(count>1){
        ui->stackedWidget->setCurrentIndex(count - 2);
        ui->label->setText(ui->stackedWidget->currentWidget()->windowTitle());
    }

    //把原窗口删除
    QWidget *widget = ui->stackedWidget->widget(count-1);
    ui->stackedWidget->removeWidget(widget);
    delete widget;
}

void MasterView::pushWidgetToStackView(QWidget* widget)
{
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count-1);    //总是显示最新加入的view
    ui->label->setText(widget->windowTitle());
}


void MasterView::on_btBack_clicked()
{
    goPreviousView();
}

void MasterView::on_stackedWidget_currentChanged(int arg1)
{
    int count=ui->stackedWidget->count();
    if(count>1){
        ui->btBack->setEnabled(true);
    }else{
        ui->btBack->setEnabled(false);
    }

    if(ui->stackedWidget->currentWidget()->windowTitle()=="欢迎"){
        ui->btLogout->setEnabled(true);
        ui->btBack->setEnabled(false);
    }else{
        ui->btLogout->setEnabled(false);
    }

}

void MasterView::on_btLogout_clicked()
{
    goPreviousView();
}
