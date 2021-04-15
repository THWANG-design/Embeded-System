#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include<QLabel>

namespace Ui {
class MainForm;
}

class MainForm : public QWidget
{
    Q_OBJECT
     QLabel *tip;

public:
    explicit MainForm(QWidget *parent = nullptr);
    ~MainForm();

private:
    Ui::MainForm *ui;
};

#endif // MAINFORM_H
