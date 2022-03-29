/*#include "mycheckbox.h"

MyCheckBox::MyCheckBox()
{

}*/

#include "mycheckbox.h"

MyCheckBox::MyCheckBox(QString text,QWidget *parent)
    : QCheckBox(text,parent)
{

}

MyCheckBox::MyCheckBox(QWidget *parent)
    : QCheckBox(parent)
{

}

void MyCheckBox::mouseReleaseEvent(QMouseEvent *e)
{
    setChecked(!isChecked());
    emit clicked(isChecked());
}
