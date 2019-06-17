#ifndef MONEY_H
#define MONEY_H

#include <QWidget>
#include <QList>
#include <sales.h>
#include <mainwindow.h>

namespace Ui {
class money;
}

class money : public QWidget
{
    Q_OBJECT

public:
    explicit money(QWidget *parent = 0);
    QList <int> carpets;
    ~money();

private slots:
    void on_back_clicked();

    void on_calculate_clicked();

private:
    Ui::money *ui;
};

#endif // MONEY_H
