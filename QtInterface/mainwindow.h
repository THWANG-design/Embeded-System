#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>

class MainForm : public QMainWindow
{
private:
    QLabel *tip;
    Q_OBJECT
public:
    explicit MainForm(QWidget *parent = nullptr);

signals:

public slots:
};

#endif //
