#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "production_management.h"
#include "monitor.h"
#include "data_center.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_page1_clicked();

    void on_page2_clicked();

    void on_page3_clicked();



private:
    Ui::MainWindow *ui;
    Production_management *pm;
    Monitor *monitor;
    Data_center *DC;

};

#endif // MAINWINDOW_H
