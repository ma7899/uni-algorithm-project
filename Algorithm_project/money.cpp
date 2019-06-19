#include "money.h"
#include "ui_money.h"

money::money(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::money)
{
    ui->setupUi(this);
    carpets.append(30);
    carpets.append(50);
    carpets.append(60);
    carpets.append(80);
    carpets.append(100);
}

money::~money()
{
    delete ui;
}

void money::on_back_clicked()
{
    hide();
    sales* sale= new sales;
    sale->show();
}

void money::on_calculate_clicked()
{

}

void money::on_pushButton_clicked()
{
    QString answer="";
    QList <int> index;
    int ind=0;
    QList<int>::iterator it;
    int mon,sum =0;
    mon=ui->lineEdit->text().toInt();

        for(it = carpets.begin(); it != carpets.end(); ++it)
        {
            if(*it+sum<=mon)
            {
                sum+= *it;
                index.append(ind);
                answer.append(QString::number(ind+1));
                answer.append(", ");
            }
            else break;
             ind++;

        }
    ui->answer->setText(answer);
}
