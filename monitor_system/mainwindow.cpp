#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ui_monitor.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->label_5->adjustSize();
//    ui->label_31->setText("test111");
    monitor = new Monitor(this);
    pm = new Production_management(this);
    DC = new Data_center(this);

    ui->stackedWidget->addWidget(monitor);
    ui->stackedWidget->addWidget(pm);
    ui->stackedWidget->addWidget(DC);
    ui->stackedWidget->setCurrentWidget(monitor);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_page1_clicked()
{
    ui->stackedWidget->setCurrentWidget(monitor);
}

void MainWindow::on_page2_clicked()
{
    ui->stackedWidget->setCurrentWidget(pm);
}

void MainWindow::on_page3_clicked()
{
    ui->stackedWidget->setCurrentWidget(DC);
}

