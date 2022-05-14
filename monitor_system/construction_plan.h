#ifndef CONSTRUCTION_PLAN_H
#define CONSTRUCTION_PLAN_H

#include <QWidget>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include "xlsxdocument.h"
#include "xlsxworkbook.h"
#include "QDateTime"

namespace Ui {
class Construction_plan;
}

class Construction_plan : public QWidget
{
    Q_OBJECT

public:
    explicit Construction_plan(QWidget *parent = nullptr);
    ~Construction_plan();

private slots:
    void on_add_clicked();

    void on_del_clicked();

    void on_modify_clicked();
    void on_btn_import_clicked();

    void on_btn_output_clicked();

private:
    Ui::Construction_plan *ui;
};

#endif // CONSTRUCTION_PLAN_H
