#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "design.h"
#include "qpixmap.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon des1(":/resources/Images/Carpet_9.png);");
    ui->Desing_but->setIcon(des1);
    ui->Desing_but->setIconSize(QSize(236,513));
    //236 513
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
