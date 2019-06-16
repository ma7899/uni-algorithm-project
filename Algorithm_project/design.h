#ifndef DESIGN_H
#define DESIGN_H

#include <QWidget>
#include <QDialog>
#include <mainwindow.h>
#include <changedes.h>

namespace Ui {
class Design;
}

class Design : public QWidget
{
    Q_OBJECT

public:
    explicit Design(QWidget *parent = 0);
    ~Design();

private slots:


    void on_back_clicked();

    void on_changedes_clicked();

private:
    Ui::Design *ui;
};

#endif // DESIGN_H
