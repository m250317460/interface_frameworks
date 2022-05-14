#ifndef SAFETY_LOGS_H
#define SAFETY_LOGS_H

#include <QWidget>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include "xlsxdocument.h"
#include "xlsxworkbook.h"
#include "QDateTime"

namespace Ui {
class Safety_logs;
}

class Safety_logs : public QWidget
{
    Q_OBJECT

public:
    explicit Safety_logs(QWidget *parent = nullptr);
    ~Safety_logs();


private slots:
    void on_add_clicked();

    void on_del_clicked();

    void on_modify_clicked();
    void on_btn_import_clicked();

    void on_btn_output_clicked();

private:
    Ui::Safety_logs *ui;
};

#endif // SAFETY_LOGS_H
