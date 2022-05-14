#include "data_center.h"
#include "ui_data_center.h"

Data_center::Data_center(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Data_center)
{
    ui->setupUi(this);



    ui->widget->setVisible(false);
    ui->widget_2->setVisible(false);
    ui->widget_3->setVisible(false);
    /*ui->toolBox->setItemText(0,"skill管理");
//    ui->toolBox->setItemText(1,"safety管理");
//    ui->toolBox->setItemText(2,"shebei管理");



    ui->toolBox_2->setItemText(0,"safety管理");
//    ui->toolBox_2->removeItem(0);
    ui->toolBox_3->setItemText(0,"shebei管理");*/
    cp = new Construction_plan(this);
    inva = new Innovation(this);
    sr = new Safety_rules(this);
    sl = new Safety_logs(this);
    sign = new Signup(this);
    lgs = new logs(this);

    ui->stackedWidget->addWidget(cp);
    ui->stackedWidget->addWidget(inva);
    ui->stackedWidget->addWidget(sr);
    ui->stackedWidget->addWidget(sl);
    ui->stackedWidget->addWidget(sign);
    ui->stackedWidget->addWidget(lgs);
    ui->stackedWidget->setCurrentWidget(cp);
}

Data_center::~Data_center()
{
    delete ui;
}

void Data_center::on_pro_plan_clicked()
{
    ui->stackedWidget->setCurrentWidget(cp);
}

void Data_center::on_Innovation_clicked()
{
    ui->stackedWidget->setCurrentWidget(inva);
}

void Data_center::on_safe_rules_clicked()
{
    ui->stackedWidget->setCurrentWidget(sr);
}

void Data_center::on_safe_logs_clicked()
{
    ui->stackedWidget->setCurrentWidget(sl);
}

void Data_center::on_signup_clicked()
{
    ui->stackedWidget->setCurrentWidget(sign);
}

void Data_center::on_logs_clicked()
{
    ui->stackedWidget->setCurrentWidget(lgs);
}

void Data_center::on_checkBox_clicked(bool checked)
{
    ui->widget->setVisible(checked);
}

void Data_center::on_checkBox_2_clicked(bool checked)
{
    ui->widget_2->setVisible(checked);
}

void Data_center::on_checkBox_3_clicked(bool checked)
{
    ui->widget_3->setVisible(checked);
}
