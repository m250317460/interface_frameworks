#ifndef PRO_LOGS_H
#define PRO_LOGS_H

#include <QWidget>

namespace Ui {
class Pro_logs;
}

class Pro_logs : public QWidget
{
    Q_OBJECT

public:
    explicit Pro_logs(QWidget *parent = nullptr);
    ~Pro_logs();

private:
    Ui::Pro_logs *ui;
};

#endif // PRO_LOGS_H
