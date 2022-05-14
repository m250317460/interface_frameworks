#ifndef PRO_TABLE_H
#define PRO_TABLE_H

#include <QWidget>

#include <QtCharts/QtCharts>
namespace Ui {
class Pro_table;
}

class Pro_table : public QWidget
{
    Q_OBJECT

public:
    explicit Pro_table(QWidget *parent = nullptr);
    ~Pro_table();

    void graph1_data();
    QBarSeries* GetSeries(int type);
    QBarCategoryAxis * GetAxis(int type);

private:
    Ui::Pro_table *ui;
};

#endif // PRO_TABLE_H
