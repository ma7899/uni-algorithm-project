#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "design.h"
#include "qpixmap.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Desing_but->setStyleSheet("background-image: url(:/resources/Images/Desing (2).jpg);");
    ui->pushButton_5->setStyleSheet("background-image: url(:/resources/Images/sales.jpg)");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Desing_but_clicked()
{
    Design* des=new Design;
    hide();
    des->show();

}

void MainWindow::on_pushButton_5_clicked()
{
    sales * sel = new sales;
    hide();
    sel->show();
}
