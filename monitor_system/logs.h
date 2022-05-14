#ifndef LOGS_H
#define LOGS_H

#include <QWidget>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include "xlsxdocument.h"
#include "xlsxworkbook.h"
#include "QDateTime"

namespace Ui {
class logs;
}

class logs : public QWidget
{
    Q_OBJECT

public:
    explicit logs(QWidget *parent = nullptr);
    ~logs();

private slots:
    void on_add_clicked();

    void on_del_clicked();

    void on_modify_clicked();
    void on_btn_import_clicked();

    void on_btn_output_clicked();

private:
    Ui::logs *ui;
};

#endif // LOGS_H
