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
        QImage image;
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
