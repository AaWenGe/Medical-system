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
    connect(welcomeView,&WelcomeView::goMedicationView,this,&MasterView::goMedicationView);
    connect(welcomeView,&WelcomeView::goVisitView,this,&MasterView::goVisitView);

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
    connect(patientView,SIGNAL(goPatientEditView(int)),this,SLOT(goPatientEditView(int)));
}


void MasterView::goPatientEditView(int rowNo)
{
    qDebug()<<"goPatientEditView";
    patientEditView = new PatientEditView(this,rowNo);
    ui->stackedWidget->addWidget(patientEditView);

    pushWidgetToStackView(patientEditView);
    connect(patientEditView,&PatientEditView::goPreviousView,this,&MasterView::goPreviousView);
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

void MasterView::goDoctorView()
{
    qDebug()<<"goDoctorView";
    doctorView = new DoctorView(this);
    ui->stackedWidget->addWidget(doctorView);

    pushWidgetToStackView(doctorView);
    connect(doctorView,SIGNAL(goDoctorEditView(int)),this,SLOT(goDoctorEditView(int)));
}

void MasterView::goDoctorEditView(int rowNo)
{
    qDebug()<<"goDoctorEditView";
    doctorEditView = new DoctorEditView(this,rowNo);
    ui->stackedWidget->addWidget(doctorEditView);

    pushWidgetToStackView(doctorEditView);
    connect(doctorEditView,&DoctorEditView::goPreviousView,this,&MasterView::goPreviousView);
}

void MasterView::goVisitView()
{
    qDebug()<<"goVisitView";
    visitView = new VisitView(this);
    ui->stackedWidget->addWidget(visitView);

    pushWidgetToStackView(visitView);
    connect(visitView,SIGNAL(goVisitEditView(int)),this,SLOT(goVisitEditView(int)));
}

void MasterView::goVisitEditView(int rowNo)
{
    qDebug()<<"goVisitEditView";
    visitEditView = new VisitEditView(this,rowNo);
    ui->stackedWidget->addWidget(visitEditView);

    pushWidgetToStackView(visitEditView);
    connect(visitEditView,&VisitEditView::goPreviousView,this,&MasterView::goPreviousView);
}

void MasterView::goMedicationView()
{
    qDebug()<<"goMedicationView";
    medicationView = new MedicationView(this);
    ui->stackedWidget->addWidget(medicationView);

    pushWidgetToStackView(medicationView);
    connect(medicationView,SIGNAL(goMedicationEditView(int)),this,SLOT(goMedicationEditView(int)));

}

void MasterView::goMedicationEditView(int rowNo)
{
    qDebug()<<"goMedicationEditView";
    medicationEditView = new MedicationEditView(this,rowNo);
    ui->stackedWidget->addWidget(medicationEditView);

    pushWidgetToStackView(medicationEditView);
    connect(medicationEditView,&MedicationEditView::goPreviousView,this,&MasterView::goPreviousView);
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
        ui->btBack->setEnabled(false);
    }
}

void MasterView::on_btLogout_clicked()
{
    if(ui->stackedWidget->currentWidget()->windowTitle()=="登录")
       this->close();
    goPreviousView();
}
