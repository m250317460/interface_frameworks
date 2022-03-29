#ifndef PRODUCTION_MANAGEMENT_H
#define PRODUCTION_MANAGEMENT_H

#include <QWidget>
#include "pro_plan.h"
#include "pro_update.h"
#include "pro_real.h"
#include "pro_table.h"
#include "pro_logs.h"

namespace Ui {
class Production_management;
}

class Production_management : public QWidget
{
    Q_OBJECT

public:
    explicit Production_management(QWidget *parent = nullptr);
    ~Production_management();

private slots:
//    void on_pro_plan_clicked();

//    void on_pro_update_clicked();

    void on_pro_real_clicked();

    void on_week_plan_clicked();

    void on_month_plan_clicked();

    void on_day_repo_clicked();

    void on_week_repo_clicked();

    void on_month_repo_clicked();

    void on_pro_log_clicked();

    void on_pro_table_clicked();

    void on_checkBox_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

    void on_checkBox_3_clicked(bool checked);

    void on_checkBox_4_clicked(bool checked);

private:
    Ui::Production_management *ui;
    Pro_plan *pp,*month_pp;
    Pro_real *pr;
    Pro_update *pu,*week_pu,*month_pu;
    Pro_logs *pl;
    Pro_table *pt;
};

#endif // PRODUCTION_MANAGEMENT_H
