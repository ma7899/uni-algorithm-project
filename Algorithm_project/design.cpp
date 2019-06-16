#include "design.h"
#include "ui_design.h"

Design::Design(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Design)
{
    ui->setupUi(this);
    ui->changedes->setStyleSheet("background-image: url(:/resources/Images/change.jpg);");
    ui->newdes->setStyleSheet("background-image: url(:/resources/Images/newdes.jpg);");

}

Design::~Design()
{
    delete ui;
}




void Design::on_back_clicked()
{
    hide();
    MainWindow* main = new MainWindow;
    main->show();
}

void Design::on_changedes_clicked()
{
    hide();
    ChangeDes* changedes = new ChangeDes;
    changedes->show();
}
