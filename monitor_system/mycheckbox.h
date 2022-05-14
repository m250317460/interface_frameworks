#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QCheckBox>

class MyCheckBox : public QCheckBox
{
public:
    MyCheckBox(QString text,QWidget *parent = Q_NULLPTR);
    MyCheckBox(QWidget *parent = Q_NULLPTR);

protected:
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // MYCHECKBOX_H
