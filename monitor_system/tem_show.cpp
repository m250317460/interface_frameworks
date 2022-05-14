#include "tem_show.h"
#include "ui_tem_show.h"

Tem_show::Tem_show(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tem_show)
{
    ui->setupUi(this);
    ChangeStatus();
}



void Tem_show::ChangeStatus()
{
    QString style1 = "background-color:rgb(84,139,84)";
    QString style2 = "background-color:rgb(0,0,205);";
    QString base1 = "sta_fir_";
    if(ui->sta_fir_1->text()=="空闲")
        ui->sta_fir_1->setStyleSheet(style1);
//    else {
//        ui->sta_fir_1->setStyleSheet(style2);
//    }
    if(ui->sta_fir_2->text()=="空闲")
        ui->sta_fir_2->setStyleSheet(style1);
//    else {
//        ui->sta_fir_2->setStyleSheet(style2);
//    }
    if(ui->sta_fir_3->text()=="空闲")
        ui->sta_fir_3->setStyleSheet(style1);
//    else {
//        ui->sta_fir_3->setStyleSheet(style2);
//    }



}
Tem_show::~Tem_show()
{
    delete ui;
}
