#ifndef INNOVATION_H
#define INNOVATION_H

#include <QWidget>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include "xlsxdocument.h"
#include "xlsxworkbook.h"
#include "QDateTime"

namespace Ui {
class Innovation;
}

class Innovation : public QWidget
{
    Q_OBJECT

public:
    explicit Innovation(QWidget *parent = nullptr);
    ~Innovation();

private slots:
    void on_add_clicked();

    void on_del_clicked();

    void on_modify_clicked();
    void on_btn_import_clicked();

    void on_btn_output_clicked();

private:
    Ui::Innovation *ui;
};

#endif // INNOVATION_H
