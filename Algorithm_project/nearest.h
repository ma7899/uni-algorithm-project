#ifndef NEAREST_H
#define NEAREST_H

#include <QWidget>
#include <sales.h>
#define V 10
namespace Ui {
class nearest;
}

class nearest : public QWidget
{
    Q_OBJECT

public:
    explicit nearest(QWidget *parent = 0);
    int * dijkstra(int graph[][V], int src);
    int minDistance(int* dist, bool* sptSet);
    int matrix[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                          {4, 0, 8, 0, 0, 0, 0, 11, 0},
                          {0, 8, 0, 7, 0, 4, 0, 0, 2},
                          {0, 0, 7, 0, 9, 14, 0, 0, 0},
                          {0, 0, 0, 9, 0, 10, 0, 0, 0},
                          {0, 0, 4, 14, 10, 0, 2, 0, 0},
                          {0, 0, 0, 0, 0, 2, 0, 1, 6},
                          {8, 11, 0, 0, 0, 0, 1, 0, 7},
                          {0, 0, 2, 0, 0, 0, 6, 7, 0}
                         };

    ~nearest();

private slots:
    void on_back_clicked();

    void on_pushButton_clicked();

private:
    Ui::nearest *ui;
};

#endif // NEAREST_H
