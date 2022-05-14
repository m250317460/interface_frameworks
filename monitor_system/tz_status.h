#ifndef TZ_STATUS_H
#define TZ_STATUS_H

#include <QWidget>

namespace Ui {
class Tz_Status;
}

class Tz_Status : public QWidget
{
    Q_OBJECT

public:
    explicit Tz_Status(QWidget *parent = nullptr,int pic=1);
    ~Tz_Status();


    void ChangeStatus(int i);
private:
    Ui::Tz_Status *ui;
};

#endif // TZ_STATUS_H
