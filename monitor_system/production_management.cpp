#include "production_management.h"
#include "ui_production_management.h"
#include <QFile>
#include <QTextStream>
#include "qdebug.h"

Production_management::Production_management(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Production_management)
{
    ui->setupUi(this);
    /*ui->toolBox->setItemText(0,"进度管理");
    ui->toolBox->setItemText(1,"台座管理");

    ui->toolBox_2->setItemText(0,"进度计划");
    ui->toolBox_2->setItemText(1,"进度填报");*/

    ui->widget->setVisible(false);
    ui->widget_2->setVisible(false);
    ui->widget_3->setVisible(false);
    ui->widget_4->setVisible(false);

    pp = new Pro_plan(this);
    month_pp = new Pro_plan(this,1);
    pr = new Pro_real(this);
    pu = new Pro_update(this);
    week_pu = new Pro_update(this,1);
    month_pu = new Pro_update(this,2);
//    preal = new Pro_real(this);
    pl = new Pro_logs(this);
    pt = new Pro_table(this);



    ui->stackedWidget->addWidget(pp);
    ui->stackedWidget->addWidget(month_pp);
    ui->stackedWidget->addWidget(pu);
    ui->stackedWidget->addWidget(week_pu);
    ui->stackedWidget->addWidget(month_pu);
    ui->stackedWidget->addWidget(pr);
    ui->stackedWidget->addWidget(pl);
    ui->stackedWidget->addWidget(pt);

    ui->stackedWidget->setCurrentWidget(pp);


}

Production_management::~Production_management()
{
    delete ui;
}


//void Production_management::on_pro_plan_clicked()
//{
//    ui->stackedWidget->setCurrentWidget(pp);
//}

//void Production_management::on_pro_update_clicked()
//{
//    ui->stackedWidget->setCurrentWidget(pu);
//}

void Production_management::on_pro_real_clicked()
{
    ui->stackedWidget->setCurrentWidget(pr);
}

void Production_management::on_week_plan_clicked()
{
    ui->stackedWidget->setCurrentWidget(pp);
}

void Production_management::on_month_plan_clicked()
{
    ui->stackedWidget->setCurrentWidget(month_pp);
}

void Production_management::on_day_repo_clicked()
{
    ui->stackedWidget->setCurrentWidget(pu);
}




void Production_management::on_week_repo_clicked()
{
    ui->stackedWidget->setCurrentWidget(week_pu);
}

void Production_management::on_month_repo_clicked()
{
    ui->stackedWidget->setCurrentWidget(month_pu);
}

void Production_management::on_pro_log_clicked()
{
    ui->stackedWidget->setCurrentWidget(pl);
}

void Production_management::on_pro_table_clicked()
{
    ui->stackedWidget->setCurrentWidget(pt);
    update();
}

void Production_management::on_checkBox_clicked(bool checked)
{
    ui->widget->setVisible(checked);

}

void Production_management::on_checkBox_2_clicked(bool checked)
{
    ui->widget_2->setVisible(checked);
}

void Production_management::on_checkBox_3_clicked(bool checked)
{
    ui->widget_3->setVisible(checked);
}

void Production_management::on_checkBox_4_clicked(bool checked)
{
    ui->widget_4->setVisible(checked);
}
