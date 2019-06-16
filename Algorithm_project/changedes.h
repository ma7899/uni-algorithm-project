#ifndef CHANGEDES_H
#define CHANGEDES_H

#include <QWidget>
#include <QFileDialog>
#include <design.h>
#include <mainwindow.h>

namespace Ui {
class ChangeDes;
}

class ChangeDes : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeDes(QWidget *parent = 0);
    ~ChangeDes();

private slots:
    void on_chooseImage_clicked();

private:
    Ui::ChangeDes *ui;
};

#endif // CHANGEDES_H
