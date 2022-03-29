#ifndef PRO_UPDATE_H
#define PRO_UPDATE_H

#include <QWidget>

namespace Ui {
class Pro_update;
}

class Pro_update : public QWidget
{
    Q_OBJECT

public:
    explicit Pro_update(QWidget *parent = nullptr,int type=0);
    ~Pro_update();


private slots:
    void on_add_clicked();

    void on_del_clicked();

    void on_modify_clicked();
private:
    Ui::Pro_update *ui;
};

#endif // PRO_UPDATE_H
