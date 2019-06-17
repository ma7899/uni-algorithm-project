#include "newdesing.h"
#include "ui_newdesing.h"

newdesing::newdesing(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newdesing)
{
    ui->setupUi(this);
}

newdesing::~newdesing()
{
    delete ui;
}

void newdesing::on_back_clicked()
{
    hide();
    sales* sale=new sales;
    sale->show();
}
