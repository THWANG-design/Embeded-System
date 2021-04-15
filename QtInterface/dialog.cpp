#include "dialog.h"
#include "ui_dialog.h"
#include<QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->userNameLEt->setPlaceholderText("请输入账号");
    ui->pswLEt->setPlaceholderText("请输入密码");
    ui->pswLEt->setEchoMode(QLineEdit::Password);
    connect(ui->LoginBtn,&QPushButton::clicked,this,&Dialog::Login);
    connect(ui->ExitBtn,&QPushButton::clicked,this,&Dialog::close);

}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::Login()
{
    if(ui->userNameLEt->text().trimmed() == tr("wang") && ui->pswLEt->text() == "123456")
       {
            accept();
       }
       else
       {
           QMessageBox::warning(this,QString("警告"),QString("ERROR"), QMessageBox::Ok);
           ui->userNameLEt->clear();
           ui->pswLEt->clear();
           ui->userNameLEt->setFocus();
       }
}

