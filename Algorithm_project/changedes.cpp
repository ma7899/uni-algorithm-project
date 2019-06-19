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

    long long int matrix[300][400];


        for(int i = 0; i < 300; i++)
        {
            for(int j = 0; j < 400; j++)
            {
                matrix[i][j] = qGray(image.pixel(i,j));
            }
        }



      long long int filtermatrix[300][400];


          for(int i = 0; i < 300; i++)
          {
              for(int j = 0; j < 400; j++)
              {
                  filtermatrix[i][j] = qGray(filterimage.pixel(i,j));
              }
          }

}


void Matrix_Multiply(int** A, int** B, int** C) {
     for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
           C[i][j] = 0;
           for(int t=0; t<2; t++) {
              C[i][j] = C[i][j] + A[i][t]*B[t][j];
           }
        }
     }
}




void ChangeDes::Strassen(int m,long long int** A,long long int** B,long long int** C)
{
    const int n=m;
         long long int** A11 = new long long int*[n];
         long long int** A12 = new long long int*[n];
         long long int** A21 = new long long int*[n];
         long long int** A22 = new long long int*[n];
         long long int** B11 = new long long int*[n];
         long long int** B12 = new long long int*[n];
         long long int** B21 = new long long int*[n];
         long long int** B22 = new long long int*[n];
         long long int** C11 = new long long int*[n];
         long long int** C12 = new long long int*[n];
         long long int** C21 = new long long int*[n];
         long long int** C22 = new long long int*[n];
         long long int** M1 = new long long int*[n];
         long long int** M2 = new long long int*[n];
         long long int** M3 = new long long int*[n];
         long long int** M4 = new long long int*[n];
         long long int** M5 = new long long int*[n];
         long long int** M6 = new long long int*[n];
         long long int** M7 = new long long int*[n];
         long long int** AA = new long long int*[n];
         long long int** BB = new long long int*[n];

         if(n == 2) {
            Matrix_Multiply(A, B, C);
         }
         else {
            for(int i=0; i<n/2; i++) {
               for(int j=0; j<n/2; j++) {
                  A11[i][j] = A[i][j];
                  A12[i][j] = A[i][j+n/2];
                  A21[i][j] = A[i+n/2][j];
                  A22[i][j] = A[i+n/2][j+n/2];

                  B11[i][j] = B[i][j];
                  B12[i][j] = B[i][j+n/2];
                  B21[i][j] = B[i+n/2][j];
                  B22[i][j] = B[i+n/2][j+n/2];
               }
            }

            Matrix_Add(n/2, A11, A22, AA);
            Matrix_Add(n/2, B11, B22, BB);
            Strassen(n/2, AA, BB, M1);

            Matrix_Add(n/2, A21, A22, AA);
            Strassen(n/2, AA, B11, M2);

            Matrix_Sub(n/2, B12, B22, BB);
            Strassen(n/2, A11, BB, M3);

            Matrix_Sub(n/2, B21, B11, BB);
            Strassen(n/2, A22, BB, M4);

            Matrix_Add(n/2, A11, A12, AA);
            Strassen(n/2, AA, B22, M5);

            Matrix_Sub(n/2, A21, A11, AA);
            Matrix_Add(n/2, B11, B12, BB);
            Strassen(n/2, AA, BB, M6);

            Matrix_Sub(n/2, A12, A22, AA);
            Matrix_Add(n/2, B21, B22, BB);
            Strassen(n/2, AA, BB, M7);

            Matrix_Add(n/2, M1, M4, AA);
            Matrix_Sub(n/2, M7, M5, BB);
            Matrix_Add(n/2, AA, BB, C11);

            Matrix_Add(n/2, M3, M5, C12);

            Matrix_Add(n/2, M2, M4, C21);

            Matrix_Sub(n/2, M1, M2, AA);
            Matrix_Add(n/2, M3, M6, BB);
            Matrix_Add(n/2, AA, BB, C22);

            for(int i=0; i<n/2; i++) {
               for(int j=0; j<n/2; j++) {
                  C[i][j] = C11[i][j];
                  C[i][j+n/2] = C12[i][j];
                  C[i+n/2][j] = C21[i][j];
                  C[i+n/2][j+n/2] = C22[i][j];
               }
            }
         }

}





