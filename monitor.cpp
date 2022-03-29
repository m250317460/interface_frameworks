#include "monitor.h"
#include "ui_monitor.h"


Monitor::Monitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Monitor)
{
    ui->setupUi(this);

    ui->alert_panel->setVisible(false);
    ui->chart1->setVisible(false);

    TzS = new Tz_Status(this);
    TeS = new Tem_show(this);
    temp = new temp_2(this);

    ui->label_31->setVisible(false);
    ui->label_32->setVisible(false);


    ui->stackedWidget->addWidget(TzS);
    ui->stackedWidget->addWidget(TeS);
    ui->stackedWidget->addWidget(temp);
    ui->stackedWidget->setCurrentWidget(TzS);





    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(ChangeWidget()));
    timer->start(5000);

    graph1_data();
    graph2_data(1);
    graph3_data(1);


}


void Monitor::ChangeWidget()
{
    if(ui->stackedWidget->currentWidget() == TzS)
    {
        ui->stackedWidget->setCurrentWidget(TeS);
    }else {
        ui->stackedWidget->setCurrentWidget(TzS);
    }
}

void Monitor::graph1_data()
{
    // 这边是不同类别
    QBarSeries* series = GetSeries(0,1);
    QChart *chart = new QChart();
    chart->addSeries(series);



    chart->setTitle("温度、湿度预警统计");

    chart->setTheme(QChart::ChartThemeLight);
    chart->setBackgroundBrush(QColor(220,220,220));

//    chart->axisX()->setLabelsColor(Qt::black);

    QFont ft;
    ft.setPixelSize(20);
    chart->setTitleFont(ft);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QBarCategoryAxis* axis = GetAxis(0);
    chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
    chart->setAxisX(axis, series);//设置坐标轴

    QValueAxis  *axisY = new QValueAxis;
    axisY->setRange(0,10);
    axisY->setTitleText("num");
    axisY->setTickCount(6);

    chart->setAxisY(axisY,series);

    chart->legend()->setVisible(true); //设置图例为显示状态
    chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部
    ui->chart1->setChart(chart);


}

void Monitor::graph2_data(int pic)
{
    QBarSeries* series2 = GetSeries(1,pic);
    QChart *chart2 = new QChart();
    chart2->addSeries(series2);
    chart2->setTitle("台座状态统计");
    chart2->setTheme(QChart::ChartThemeLight);
    chart2->setBackgroundBrush(QColor(220,220,220));
//    chart2->axisX()->setLabelsColor(Qt::black);
    QFont ft;
    ft.setPixelSize(20);
    chart2->setTitleFont(ft);



    chart2->setAnimationOptions(QChart::SeriesAnimations);
    QBarCategoryAxis* axis2 = GetAxis(1);
    chart2->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）

    chart2->setAxisX(axis2, series2);//设置坐标轴

    QFont f2 = QFont("song",14);
    chart2->axisX()->setLabelsFont(f2);

    QValueAxis  *axisY = new QValueAxis;
    axisY->setRange(0,20);
    axisY->setTitleText("num");
    axisY->setTickCount(6);
//    axisY->setMinorTickCount(2);

    chart2->setAxisY(axisY,series2);

    chart2->legend()->setVisible(true); //设置图例为显示状态
    chart2->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部
    ui->chart2->setChart(chart2);
}
void Monitor::graph3_data(int pic)
{
    QPieSeries *pie = GetSeries_pie(pic);


    QChart *chart2 = new QChart();
    chart2->addSeries(pie);
    chart2->setTitle("台座使用率");
    chart2->setTheme(QChart::ChartThemeLight);
    chart2->setBackgroundBrush(QColor(220,220,220));

    /*chart2->axisX()->setLabelsColor(Qt::black);*/
    QFont ft;
    ft.setPixelSize(20);
    chart2->setTitleFont(ft);
    chart2->setAnimationOptions(QChart::SeriesAnimations);

//    QBarCategoryAxis* axis2 = GetAxis(2);
    chart2->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
//    chart2->setAxisX(axis2, series2);//设置坐标轴
    chart2->legend()->setVisible(true); //设置图例为显示状态
    chart2->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部
    ui->chart3->setChart(chart2);

}


QBarSeries* Monitor::GetSeries(int type,int pic)
{
    if(type==0){
        QBarSet *set0 = new QBarSet("温度预警");
        QBarSet *set1 = new QBarSet("湿度预警");
      /*  *set0 << 1 << 2 << 3 ;
        *set1 << 3 << 2 << 1 ;*/
        *set0 << 0 << 0 << 0 ;
        *set1 << 0 << 0 << 0 ;
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        return series;
    }else if (type==1)
    {
        QBarSet *set0 = new QBarSet("数量");

//        *set0 << 1 << 0 << 17 << 1 << 4 << 0<<5<<6<<8<<0;
        if(pic ==1){
            *set0 << 2 << 1 <<1 << 8 <<11<<1<<0<<1;
        }else if (pic ==2) {
            *set0 << 3 << 0 <<0 << 6 <<12<<0<<0<<4;
        }else if (pic ==3) {
            *set0 << 3 << 0 <<0 << 7 <<13<<1<<0<<1;
        }else {
            *set0 << 2 << 0 <<1 << 7 <<13<<1<<0<<1;
        }



        QBarSeries *series = new QBarSeries();

        set0->setLabelColor(QColor(0,0,0));


        series->append(set0);
        series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);
        series->setLabelsVisible(true);


        return series;
    }

}



QBarCategoryAxis* Monitor::GetAxis(int type)
{
    if(type==0){
        // 这边是时段
        QStringList categories;
//        categories << "抓拍人脸" << "行人" << "自行车" << "摩托车" << "三轮车" << "小汽车" << "大型汽车" << "卡车" << "拖拉机" << "中巴/大巴" ;
        categories << "重大预警" << "较大预警" << "一般预警"  ;
        QBarCategoryAxis *axis = new QBarCategoryAxis();

        axis->append(categories);
        return axis;
    }else if(type ==1){
        // 这边是时段
        QStringList categories;
        categories << "绑扎" << "浇筑" << "浇筑完成" << "养护" << "蒸养"  <<"张拉"  <<"起吊"<<"空闲";
//        categories << "tempture" << "humidity"  ;
        QBarCategoryAxis *axis = new QBarCategoryAxis();

        axis->append(categories);


        return axis;
    }
}

QPieSeries* Monitor::GetSeries_pie(int pic)
{
    QPieSeries *pie = new QPieSeries();
    /*pie->append("使用",0.75);
    pie->append("空闲",0.25);*/

    if(pic ==1){
        qreal a = 0.04;
        pie->append("使用",1-a);
        pie->append("空闲",a);
    }else if (pic ==2) {
        qreal a = 0.16;
        pie->append("使用",1-a);
        pie->append("空闲",a);
    }else if (pic ==3) {
        qreal a = 0.04;
        pie->append("使用",1-a);
        pie->append("空闲",a);
    }else{
        qreal a = 0.04;
        pie->append("使用",1-a);
        pie->append("空闲",a);
    }


    pie->setLabelsPosition(QPieSlice::LabelInsideHorizontal);
    pie->setLabelsVisible(true);



    return pie;
}
Monitor::~Monitor()
{
    delete ui;
}

void Monitor::on_pushButton_clicked()
{
    if(ui->pushButton->text()=="开\n始\n检\n测")    ui->pushButton->setText("暂\n停\n检\n测");
    else ui->pushButton->setText("开\n始\n检\n测");
}

void Monitor::on_pushButton_2_clicked()
{
    QString OpenFile, OpenFilePath;
        QImage image;

        OpenFile = QFileDialog::getOpenFileName(this,
            "please choose an image file",
            "",
            "Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");
        if (OpenFile != "")
        {
            if (image.load(OpenFile))
            {
                //仅仅只是导入之后的图片仍然是原来的大小，这个时候我们需要缩放
                ui->video_panel->setPixmap(QPixmap::fromImage(image).scaled(ui->video_panel->size()));
            }

        }
        if(OpenFile=="/home/mhw/QtProjects/Monitor_system/pic1.jpg"){
            TzS->ChangeStatus(1);
            graph2_data(1);
            graph3_data(1);

        }else if (OpenFile=="/home/mhw/QtProjects/Monitor_system/pic2.jpg") {
            TzS->ChangeStatus(2);
            graph2_data(2);
            graph3_data(2);
        }else if (OpenFile=="/home/mhw/QtProjects/Monitor_system/pic3.jpg") {
            TzS->ChangeStatus(3);
            graph2_data(3);
            graph3_data(3);
        }else {
            TzS->ChangeStatus(4);
            graph2_data(4);
            graph3_data(4);
        }

}
