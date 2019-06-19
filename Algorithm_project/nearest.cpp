#include "nearest.h"
#include "ui_nearest.h"

nearest::nearest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nearest)
{
    ui->setupUi(this);
//    for(int i = 0; i < 5; i++)
//        for(int j = 0; j < 5; j++)
//            matrix[i][j] = -1;
//    matrix[0][0] = 0;
//    matrix[0][1] = 5;
//    matrix[0][3] = 3;
//    matrix[1][0] = 5;
//    matrix[3][0] = 3;
//    matrix[3][2] = 7;
//    matrix[2][3] = 5;
//    matrix[4][3] = 9;
//    matrix[3][4] = 9;
}

nearest::~nearest()
{
    delete ui;
}

void nearest::on_back_clicked()
{
    hide();
    sales* sale = new sales;
    sale->show();
}

void nearest::on_pushButton_clicked()
{
    int src = ui->lineEdit->text().toInt();
    int* dist = dijkstra(matrix,src);
    for (int i = 0; i < 10; i++)
        ui->label->setText(ui->label->text() + dist[i]);
}

int * nearest::dijkstra(int graph[][V], int src)
{
     int dist[V];

     bool sptSet[V];

     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     dist[src] = 0;

     for (int count = 0; count < V-1; count++)
     {
       int u = minDistance(dist, sptSet);

       sptSet[u] = true;

       for (int v = 0; v < V; v++)
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
   return dist;
}

int nearest::minDistance(int* dist, bool* sptSet)
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}
