#include "dialog.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainForm *main = new MainForm();
    main->setWindowTitle("Hello");

    Dialog Login;
    if(Login.exec() == QDialog::Accepted)
    {
        main->show();
        return a.exec();
    }
    else return 0;

}
