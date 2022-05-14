#ifndef TEM_SHOW_H
#define TEM_SHOW_H

#include <QWidget>

namespace Ui {
class Tem_show;
}

class Tem_show : public QWidget
{
    Q_OBJECT

public:
    explicit Tem_show(QWidget *parent = nullptr);
    ~Tem_show();

    void ChangeStatus();

private:
    Ui::Tem_show *ui;
};

#endif // TEM_SHOW_H
