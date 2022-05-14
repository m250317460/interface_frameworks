#include "pro_table.h"
#include "ui_pro_table.h"

Pro_table::Pro_table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pro_table)
{
    ui->setupUi(this);


    graph1_data();

    ui->tableWidget->horizontalHeader()->setFixedHeight(50);
    QFont f1 = QFont("song",20);
    QFont f2 = QFont("song",14);
    f1.setBold(true);
    ui->tableWidget->horizontalHeader()->setFont(f1);
    ui->tableWidget->setFont(f2);
    //设置表格的列数，必须要先设置，不然表格显示不出来
    ui->tableWidget->setColumnCount(6);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->tableWidget->setEditTriggers(QAbstractItemView::EditKeyPressed);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);


//    ui->tableWidget->setRowCount(4);
    //建立表头
    QStringList header;

    header << "序号" << "项目" << "工程类型" << "单位"<<"实时检测数量"<<"当日检测数量统计";


    ui->tableWidget->setHorizontalHeaderLabels(header);
    //设置表头显示模式,这里设置的是拉伸模式
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents);
//    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setStyleSheet("alternate-background-color:#e3f3ff;");


    //从文件读取数据
    QFile f("/home/mhw/test1.txt");

    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream output(&f);
    output.setCodec("UTF-8");
    QHash<QString, QString> varHash;
    QString lineStr;//文件的每一行的字符串
    QStringList lineList; //整行字符串，分割处理为单个字符串，存入到表中
    varHash.clear();
    lineList.clear();//操作前，清空


    //遍历文件
    while(!output.atEnd())
    {
        lineStr = output.readLine(); //读取文件的一行
        lineList = lineStr.split('\t'); //去除换行符获取字符串，存放到表中
//        qDebug()<<lineStr;
        //向表里面动态添加参数
        int rowCount = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(rowCount);

        for(int i = 0; i < 6; i++)
        {
            ui->tableWidget->setItem(rowCount,i,new QTableWidgetItem(lineList[i]));
//            ui->tableWidget->setItem(rowCount,i,new QTableWidgetItem("test"));
        }
    }
    f.close();//关闭文件
}

Pro_table::~Pro_table()
{
    delete ui;
}


void Pro_table::graph1_data()
{
    // 这边是不同类别
    QBarSeries* series = GetSeries(0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QBarCategoryAxis* axis = GetAxis(0);
    chart->createDefaultAxes();//创建默认的左侧的坐标轴（根据 QBarSet 设置的值）
    chart->setAxisX(axis, series);//设置坐标轴
    chart->legend()->setVisible(true); //设置图例为显示状态
    chart->legend()->setAlignment(Qt::AlignBottom);//设置图例的显示位置在底部
    ui->chart1->setChart(chart);


}
QBarSeries* Pro_table::GetSeries(int type)
{
    if(type==0){
        QBarSet *set0 = new QBarSet("tempture");
        QBarSet *set1 = new QBarSet("humidity");
        *set0 << 1 << 2 << 3 ;
        *set1 << 3 << 2 << 1 ;
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        return series;
    }else if (type==1)
    {
        QBarSet *set0 = new QBarSet("进入");

        *set0 << 1 << 0 << 17 << 1 << 4 << 0;


        QBarSeries *series = new QBarSeries();
        series->append(set0);

        return series;
    }

}



QBarCategoryAxis* Pro_table::GetAxis(int type)
{
    if(type==0){
        // 这边是时段
        QStringList categories;
//        categories << "抓拍人脸" << "行人" << "自行车" << "摩托车" << "三轮车" << "小汽车" << "大型汽车" << "卡车" << "拖拉机" << "中巴/大巴" ;
        categories << "max" << "medium" << "min"  ;
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        return axis;
    }else if(type ==1){
        // 这边是时段
        QStringList categories;
        categories << "A" << "B" << "C" << "D" << "E" << "F" ;
//        categories << "tempture" << "humidity"  ;
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        return axis;
    }
}
