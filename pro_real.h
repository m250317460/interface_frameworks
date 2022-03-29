#ifndef PRO_REAL_H
#define PRO_REAL_H

#include <QWidget>
#include <QtCharts/QtCharts>
#include <QTime>

namespace Ui {
class Pro_real;
}

class Pro_real : public QWidget
{
    Q_OBJECT

public:
    explicit Pro_real(QWidget *parent = nullptr);
    ~Pro_real();

    void graph1_data();
    QBarSeries* GetSeries(int type);
    QBarCategoryAxis * GetAxis(int type);

    void sleep(unsigned int msec);

private:
    Ui::Pro_real *ui;
};

#endif // PRO_REAL_H
