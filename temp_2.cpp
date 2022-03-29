#include "temp_2.h"
#include "ui_temp_2.h"

temp_2::temp_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::temp_2)
{
    ui->setupUi(this);
}

temp_2::~temp_2()
{
    delete ui;
}
