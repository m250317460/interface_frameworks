#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QTableWidget>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include "xlsxdocument.h"
#include "xlsxworkbook.h"
#include "QDateTime"

namespace Ui {
class Signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();


private slots:
    void on_add_clicked();

    void on_del_clicked();

    void on_modify_clicked();
    void on_btn_import_clicked();

    void on_btn_output_clicked();

private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H
