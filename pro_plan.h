#ifndef PRO_PLAN_H
#define PRO_PLAN_H

#include <QWidget>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include "xlsxdocument.h"
#include "xlsxworkbook.h"
#include "QDateTime"


namespace Ui {
class Pro_plan;
}

class Pro_plan : public QWidget
{
    Q_OBJECT

public:
    explicit Pro_plan(QWidget *parent = nullptr,int type=0);

//    void Table2Excel(QTableWidget *table,QString title);
    ~Pro_plan();

private slots:
    void on_add_clicked();

    void on_del_clicked();

    void on_modify_clicked();

    void on_btn_import_clicked();

    void on_btn_output_clicked();

private:
    Ui::Pro_plan *ui;
};

#endif // PRO_PLAN_H
