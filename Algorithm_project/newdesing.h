#ifndef NEWDESING_H
#define NEWDESING_H

#include <QWidget>

namespace Ui {
class newdesing;
}

class newdesing : public QWidget
{
    Q_OBJECT

public:
    explicit newdesing(QWidget *parent = 0);
    ~newdesing();

private:
    Ui::newdesing *ui;
};

#endif // NEWDESING_H
