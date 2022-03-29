#ifndef TEMP_2_H
#define TEMP_2_H

#include <QWidget>

namespace Ui {
class temp_2;
}

class temp_2 : public QWidget
{
    Q_OBJECT

public:
    explicit temp_2(QWidget *parent = nullptr);
    ~temp_2();

private:
    Ui::temp_2 *ui;
};

#endif // TEMP_2_H
