#include "sales.h"
#include "ui_sales.h"

sales::sales(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sales)
{
    ui->setupUi(this);
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
