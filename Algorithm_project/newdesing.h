#ifndef NEWDESING_H
#define NEWDESING_H

#include <QWidget>
#include <sales.h>
#include <mainwindow.h>

namespace Ui {
class newdesing;
}

class newdesing : public QWidget
{
    Q_OBJECT

public:
    explicit newdesing(QWidget *parent = 0);
    ~newdesing();

private slots:
    void on_back_clicked();

private:
    Ui::newdesing *ui;
};

#endif // NEWDESING_H
