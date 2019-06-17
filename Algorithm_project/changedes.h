#ifndef CHANGEDES_H
#define CHANGEDES_H

#include <QWidget>
#include <QFileDialog>
#include <design.h>
#include <mainwindow.h>
#include <QFile>
#include <QTextStream>
#include <iostream>

namespace Ui {
class ChangeDes;
}

class ChangeDes : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeDes(QWidget *parent = 0);

    void Strassen(int m,long long int** A,long long int** B,long long int** C);
    void Matrix_Sub(int n,long long int** X,long long int** Y,long long int** Z)
    {
      for(int i=0; i<n; i++) {
         for(int j=0; j<n; j++) {
            Z[i][j] = X[i][j] - Y[i][j];
         }
      }
    }
    void Matrix_Add(int n,long long int** X,long long int** Y,long long int** Z)
    {
        for(int i=0; i<n; i++) {
           for(int j=0; j<n; j++) {
              Z[i][j] = X[i][j] + Y[i][j];
           }
        }
    }
    void Matrix_Multiply(long long int** A,long long int** B,long long int** C) {
         for(int i=0; i<2; i++) {
           for(int j=0; j<2; j++) {
             C[i][j] = 0;
             for(int t=0; t<2; t++) {
                 C[i][j] = C[i][j] + A[i][t]*B[t][j];
             }
          }
       }
  }


    QImage image,filterimage;
    ~ChangeDes();

private slots:
    void on_chooseImage_clicked();

    void on_back_clicked();

    void on_Change_clicked();

private:
    Ui::ChangeDes *ui;
};

#endif // CHANGEDES_H
