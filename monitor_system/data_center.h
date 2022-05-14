#ifndef DATA_CENTER_H
#define DATA_CENTER_H

#include <QWidget>
#include "construction_plan.h"
#include "innovation.h"
#include "safety_rules.h"
#include "safety_logs.h"
#include "signup.h"
#include "logs.h"

namespace Ui {
class Data_center;
}

class Data_center : public QWidget
{
    Q_OBJECT

public:
    explicit Data_center(QWidget *parent = nullptr);
    ~Data_center();

private slots:
    void on_pro_plan_clicked();

    void on_Innovation_clicked();

    void on_safe_rules_clicked();

    void on_safe_logs_clicked();

    void on_signup_clicked();

    void on_logs_clicked();

    void on_checkBox_clicked(bool checked);

    void on_checkBox_2_clicked(bool checked);

    void on_checkBox_3_clicked(bool checked);

private:
    Ui::Data_center *ui;
    Construction_plan *cp;
    Innovation *inva;
    Safety_rules *sr;
    Safety_logs *sl;
    Signup *sign;
    logs *lgs;
};

#endif // DATA_CENTER_H
