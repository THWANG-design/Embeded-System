#include "mainwindow.h"

MainForm::MainForm(QWidget *parent) : QMainWindow(parent)
{
    tip = new QLabel(this);
    tip->setText("hi");
}
