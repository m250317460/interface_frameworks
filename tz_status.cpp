#include "tz_status.h"
#include "ui_tz_status.h"

Tz_Status::Tz_Status(QWidget *parent,int pic) :
    QWidget(parent),
    ui(new Ui::Tz_Status)
{
    ui->setupUi(this);
    ChangeStatus(pic);

    /*钢筋绑扎；混凝土浇筑；混凝土浇筑完成；养护；蒸汽养护；
    养护完成；预应力张拉；预应力张拉完成；T梁起吊*/

}


void Tz_Status::ChangeStatus(int i)
{
    QString style1 = "background-color:rgb(84,139,84);color: rgb(255, 255, 255);";
    QString style2 = "background-color:rgb(0,0,205);";
    QString style3 = "";
    QString base1 = "sta_fir_";


//    pic1
    if(i==1){
        ui->sta_fir_1->setText("蒸汽养护");
        ui->sta_fir_2->setText("钢筋绑扎");
        ui->sta_fir_3->setText("养护");
        ui->sta_fir_4->setText("养护");
        ui->sta_fir_5->setText("蒸汽养护");
        ui->sta_sec_1->setText("蒸汽养护");
        ui->sta_sec_2->setText("张拉");
        ui->sta_sec_3->setText("养护");
        ui->sta_sec_4->setText("蒸汽养护");
        ui->sta_sec_5->setText("蒸汽养护");
        ui->sta_thi_1->setText("浇筑");
        ui->sta_thi_2->setText("养护");
        ui->sta_thi_3->setText("蒸汽养护");
        ui->sta_thi_4->setText("蒸汽养护");
        ui->sta_thi_5->setText("蒸汽养护");
        ui->sta_fou_1->setText("浇筑完成");
        ui->sta_fou_2->setText("养护");
        ui->sta_fou_3->setText("蒸汽养护");
        ui->sta_fou_4->setText("蒸汽养护");
        ui->sta_fou_5->setText("蒸汽养护");
        ui->sta_fiv_1->setText("养护");
        ui->sta_fiv_2->setText("养护");
        ui->sta_fiv_3->setText("养护");
        ui->sta_fiv_4->setText("钢筋绑扎");
        ui->sta_fiv_5->setText("空闲");
    }else if (i==2) {
        ui->sta_fir_1->setText("蒸汽养护");
        ui->sta_fir_2->setText("蒸汽养护");
        ui->sta_fir_3->setText("钢筋绑扎");
        ui->sta_fir_4->setText("空闲");
        ui->sta_fir_5->setText("养护");

        ui->sta_sec_1->setText("空闲");
        ui->sta_sec_2->setText("养护");
        ui->sta_sec_3->setText("钢筋绑扎");
        ui->sta_sec_4->setText("蒸汽养护");
        ui->sta_sec_5->setText("蒸汽养护");

        ui->sta_thi_1->setText("蒸汽养护");
        ui->sta_thi_2->setText("蒸汽养护");
        ui->sta_thi_3->setText("蒸汽养护");
        ui->sta_thi_4->setText("蒸汽养护");
        ui->sta_thi_5->setText("空闲");

        ui->sta_fou_1->setText("蒸汽养护");
        ui->sta_fou_2->setText("蒸汽养护");
        ui->sta_fou_3->setText("蒸汽养护");
        ui->sta_fou_4->setText("养护");
        ui->sta_fou_5->setText("空闲");

        ui->sta_fiv_1->setText("养护");
        ui->sta_fiv_2->setText("养护");
        ui->sta_fiv_3->setText("养护");
        ui->sta_fiv_4->setText("蒸汽养护");
        ui->sta_fiv_5->setText("钢筋绑扎");
    }else if (i == 3) {
        ui->sta_fir_1->setText("蒸汽养护");
        ui->sta_fir_2->setText("蒸汽养护");
        ui->sta_fir_3->setText("钢筋绑扎");
        ui->sta_fir_4->setText("空闲");
        ui->sta_fir_5->setText("养护");

        ui->sta_sec_1->setText("张拉");
        ui->sta_sec_2->setText("养护");
        ui->sta_sec_3->setText("钢筋绑扎");
        ui->sta_sec_4->setText("蒸汽养护");
        ui->sta_sec_5->setText("蒸汽养护");

        ui->sta_thi_1->setText("蒸汽养护");
        ui->sta_thi_2->setText("蒸汽养护");
        ui->sta_thi_3->setText("蒸汽养护");
        ui->sta_thi_4->setText("蒸汽养护");
        ui->sta_thi_5->setText("蒸汽养护");

        ui->sta_fou_1->setText("蒸汽养护");
        ui->sta_fou_2->setText("蒸汽养护");
        ui->sta_fou_3->setText("蒸汽养护");
        ui->sta_fou_4->setText("养护");
        ui->sta_fou_5->setText("养护");

        ui->sta_fiv_1->setText("养护");
        ui->sta_fiv_2->setText("养护");
        ui->sta_fiv_3->setText("养护");
        ui->sta_fiv_4->setText("蒸汽养护");
        ui->sta_fiv_5->setText("钢筋绑扎");
    }else {
        ui->sta_fir_1->setText("蒸汽养护");
        ui->sta_fir_2->setText("蒸汽养护");
        ui->sta_fir_3->setText("浇筑完成");
        ui->sta_fir_4->setText("空闲");
        ui->sta_fir_5->setText("养护");

        ui->sta_sec_1->setText("张拉");
        ui->sta_sec_2->setText("养护");
        ui->sta_sec_3->setText("钢筋绑扎");
        ui->sta_sec_4->setText("蒸汽养护");
        ui->sta_sec_5->setText("蒸汽养护");

        ui->sta_thi_1->setText("蒸汽养护");
        ui->sta_thi_2->setText("蒸汽养护");
        ui->sta_thi_3->setText("蒸汽养护");
        ui->sta_thi_4->setText("蒸汽养护");
        ui->sta_thi_5->setText("蒸汽养护");

        ui->sta_fou_1->setText("蒸汽养护");
        ui->sta_fou_2->setText("蒸汽养护");
        ui->sta_fou_3->setText("蒸汽养护");
        ui->sta_fou_4->setText("养护");
        ui->sta_fou_5->setText("养护");

        ui->sta_fiv_1->setText("养护");
        ui->sta_fiv_2->setText("养护");
        ui->sta_fiv_3->setText("养护");
        ui->sta_fiv_4->setText("蒸汽养护");
        ui->sta_fiv_5->setText("钢筋绑扎");

    }

//    pic2

//    pic3

//    pic4


    if(ui->sta_fir_1->text()=="空闲")ui->sta_fir_1->setStyleSheet(style1);else ui->sta_fir_1->setStyleSheet(style3);
    if(ui->sta_fir_2->text()=="空闲")ui->sta_fir_2->setStyleSheet(style1);else ui->sta_fir_2->setStyleSheet(style3);
    if(ui->sta_fir_3->text()=="空闲")ui->sta_fir_3->setStyleSheet(style1);else ui->sta_fir_3->setStyleSheet(style3);
    if(ui->sta_fir_4->text()=="空闲")ui->sta_fir_4->setStyleSheet(style1);else ui->sta_fir_4->setStyleSheet(style3);
    if(ui->sta_fir_5->text()=="空闲")ui->sta_fir_5->setStyleSheet(style1);else ui->sta_fir_5->setStyleSheet(style3);

    if(ui->sta_sec_1->text()=="空闲")ui->sta_sec_1->setStyleSheet(style1);else ui->sta_sec_1->setStyleSheet(style3);
    if(ui->sta_sec_2->text()=="空闲")ui->sta_sec_2->setStyleSheet(style1);else ui->sta_sec_2->setStyleSheet(style3);
    if(ui->sta_sec_3->text()=="空闲")ui->sta_sec_3->setStyleSheet(style1);else ui->sta_sec_3->setStyleSheet(style3);
    if(ui->sta_sec_4->text()=="空闲")ui->sta_sec_4->setStyleSheet(style1);else ui->sta_sec_4->setStyleSheet(style3);
    if(ui->sta_sec_5->text()=="空闲")ui->sta_sec_5->setStyleSheet(style1);else ui->sta_sec_5->setStyleSheet(style3);

    if(ui->sta_thi_1->text()=="空闲")ui->sta_thi_1->setStyleSheet(style1);else ui->sta_thi_1->setStyleSheet(style3);
    if(ui->sta_thi_2->text()=="空闲")ui->sta_thi_2->setStyleSheet(style1);else ui->sta_thi_2->setStyleSheet(style3);
    if(ui->sta_thi_3->text()=="空闲")ui->sta_thi_3->setStyleSheet(style1);else ui->sta_thi_3->setStyleSheet(style3);
    if(ui->sta_thi_4->text()=="空闲")ui->sta_thi_4->setStyleSheet(style1);else ui->sta_thi_4->setStyleSheet(style3);
    if(ui->sta_thi_5->text()=="空闲")ui->sta_thi_5->setStyleSheet(style1);else ui->sta_thi_5->setStyleSheet(style3);

    if(ui->sta_fou_1->text()=="空闲")ui->sta_fou_1->setStyleSheet(style1);else ui->sta_fou_1->setStyleSheet(style3);
    if(ui->sta_fou_2->text()=="空闲")ui->sta_fou_2->setStyleSheet(style1);else ui->sta_fou_2->setStyleSheet(style3);
    if(ui->sta_fou_3->text()=="空闲")ui->sta_fou_3->setStyleSheet(style1);else ui->sta_fou_3->setStyleSheet(style3);
    if(ui->sta_fou_4->text()=="空闲")ui->sta_fou_4->setStyleSheet(style1);else ui->sta_fou_4->setStyleSheet(style3);
    if(ui->sta_fou_5->text()=="空闲")ui->sta_fou_5->setStyleSheet(style1);else ui->sta_fou_5->setStyleSheet(style3);

    if(ui->sta_fiv_1->text()=="空闲")ui->sta_fiv_1->setStyleSheet(style1);else ui->sta_fiv_1->setStyleSheet(style3);
    if(ui->sta_fiv_2->text()=="空闲")ui->sta_fiv_2->setStyleSheet(style1);else ui->sta_fiv_2->setStyleSheet(style3);
    if(ui->sta_fiv_3->text()=="空闲")ui->sta_fiv_3->setStyleSheet(style1);else ui->sta_fiv_3->setStyleSheet(style3);
    if(ui->sta_fiv_4->text()=="空闲")ui->sta_fiv_4->setStyleSheet(style1);else ui->sta_fiv_4->setStyleSheet(style3);
    if(ui->sta_fiv_5->text()=="空闲")ui->sta_fiv_5->setStyleSheet(style1);else ui->sta_fiv_5->setStyleSheet(style3);

    repaint();



}
Tz_Status::~Tz_Status()
{
    delete ui;
}
