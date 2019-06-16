#ifndef SALES_H
#define SALES_H

#include <QWidget>
#include <mainwindow.h>

namespace Ui {
class sales;
}

class sales : public QWidget
{
    Q_OBJECT

public:
    explicit sales(QWidget *parent = 0);
    ~sales();

private slots:

    void on_back_clicked();

private:
    Ui::sales *ui;
};

#endif // SALES_H
