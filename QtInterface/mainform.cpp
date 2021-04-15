#include "mainform.h"
#include "ui_mainform.h"
#include<QMenuBar>
#include<QToolBar>

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    resize(731,500);
    ui->stackedWidget->setCurrentIndex(1);
    connect(ui->HomeBtn, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->InformationBtn, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->NavigationBtn, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->SOSBtn, &QPushButton::clicked, [=](){
        ui->stackedWidget->setCurrentIndex(3);
    });









}

MainForm::~MainForm()
{
    delete ui;



}
