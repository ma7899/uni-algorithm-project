#ifndef SALES_H
#define SALES_H

#include <QWidget>
#include <mainwindow.h>
#include <money.h>
#include <nearest.h>

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

    void on_money_buy_clicked();

    void on_nearmarket_clicked();

private:
    Ui::sales *ui;
};

#endif // SALES_H
