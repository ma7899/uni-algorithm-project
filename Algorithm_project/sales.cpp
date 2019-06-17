#include "sales.h"
#include "ui_sales.h"

sales::sales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sales)
{
    ui->setupUi(this);
    ui->nearmarket->setStyleSheet("background-image: url(:/resources/Images/map.png);");
    ui->money_buy->setStyleSheet("background-image: url(:/resources/Images/money.jpg);");
    ui->search->setStyleSheet("background-image: url(:/resources/Images/search.jpg);");

}

sales::~sales()
{
    delete ui;
}


void sales::on_back_clicked()
{
    hide();
    MainWindow* main = new MainWindow;
    main->show();
}

void sales::on_money_buy_clicked()
{
    hide();
    money* mon = new money;
    mon->show();
}
