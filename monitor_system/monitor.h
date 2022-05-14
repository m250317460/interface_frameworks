#ifndef MONITOR_H
#define MONITOR_H

#include <QWidget>
#include "tz_status.h"
#include "tem_show.h"
#include "temp_2.h"
#include "QTimer"

#include <QtCharts/QtCharts>



namespace Ui {
class Monitor;
}

class Monitor : public QWidget
{
    Q_OBJECT

public:
    explicit Monitor(QWidget *parent = nullptr);
    ~Monitor();

    void graph1_data();
    void graph2_data(int pic);
    void graph3_data(int pic);
    QBarSeries* GetSeries(int type,int pic);
    QBarCategoryAxis * GetAxis(int type);
    QPieSeries* GetSeries_pie(int pic);


private slots:
    void ChangeWidget();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Monitor *ui;
    Tz_Status *TzS;
    Tem_show *TeS;
    temp_2 *temp;
    QTimer *timer;
};

#endif // MONITOR_H
