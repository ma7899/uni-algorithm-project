#include "changedes.h"
#include "ui_changedes.h"

ChangeDes::ChangeDes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeDes)
{
    ui->setupUi(this);
}

ChangeDes::~ChangeDes()
{
    delete ui;
}

void ChangeDes::on_chooseImage_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images ( *.png *.jpg *.jpeg *.bmp *.gif "));
    if(QString::compare(filename, QString()) !=0)
    {
        bool valid = image.load(filename);

        if(valid)
        {
            ui->im_label->setPixmap(QPixmap::fromImage(image));
        }
        else
        {

        }
    }
}

void ChangeDes::on_back_clicked()
{
    hide();
    MainWindow* main = new MainWindow;
    main->show();
}

void ChangeDes::on_Change_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Images ( *.png *.jpg *.jpeg *.bmp *.gif "));
    if(QString::compare(filename, QString()) !=0)
    {
        bool valid = filterimage.load(filename);

        if(valid)
        {
            ui->im_label->setPixmap(QPixmap::fromImage(filterimage));
        }
        else
        {

        }
    }
    int width = image.width();
    int height = image.height();
    int *matrix = new int [width*height];

    for(int j = 0; j < height; j++)
    {
      for(int i = 0; i < width; i++)
      {
        matrix[j*width+i] = qGray(image.pixel(i,j));
      }
    }



}
