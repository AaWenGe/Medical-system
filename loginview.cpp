#include "loginview.h"
#include "ui_loginview.h"

LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);

}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_btSignIn_clicked()
{
    QString status=iDataBase::getInstance().userLogin(ui->inputName->text(),ui->inputPsw->text());
    if(status=="loginOK")
        emit loginSuccess();
}

void LoginView::on_btSignup_clicked()
{

}

void LoginView::on_btAbout_clicked()
{
    QMessageBox::about(this,"关于","开发者:陈静文\n学号:2021414120201");
}

