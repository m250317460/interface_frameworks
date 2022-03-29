#include "pro_update.h"
#include "ui_pro_update.h"

#include <QFile>
#include <QTextStream>
#include "qdebug.h"

Pro_update::Pro_update(QWidget *parent,int type) :
    QWidget(parent),
    ui(new Ui::Pro_update)
{
    ui->setupUi(this);
//    创建

    ui->tableWidget->horizontalHeader()->setFixedHeight(50);
    QFont f1 = QFont("song",20);
    QFont f2 = QFont("song",14);
    f1.setBold(true);

    ui->tableWidget->horizontalHeader()->setFont(f1);
    ui->tableWidget->setFont(f2);


    //设置表格的列数，必须要先设置，不然表格显示不出来
    ui->tableWidget->setColumnCount(6);
//    ui->tableWidget->setRowCount(4);
    //建立表头
    QStringList header;
    if(type == 0)
    {
        header << "日报进度名称" << "开始时间" << "结束时间" << "创建时间"<<"创建单位"<<"创建人";
    }else if (type == 1) {
        header << "周报进度名称" << "开始时间" << "结束时间" << "创建时间"<<"创建单位"<<"创建人";
    }else {
        header << "月报进度名称" << "开始时间" << "结束时间" << "创建时间"<<"创建单位"<<"创建人";
    }

    ui->tableWidget->setHorizontalHeaderLabels(header);
    //设置表头显示模式,这里设置的是拉伸模式
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setStyleSheet("alternate-background-color:#e3f3ff;");


    //从文件读取数据
    QFile f("/home/mhw/test.txt");

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

        for(int i = 0; i < 4; i++)
        {
            ui->tableWidget->setItem(rowCount,i,new QTableWidgetItem(lineList[i]));
//            ui->tableWidget->setItem(rowCount,i,new QTableWidgetItem("test"));
        }
    }
    f.close();//关闭文件
}

Pro_update::~Pro_update()
{
    delete ui;
}
void Pro_update::on_add_clicked()
{
    int cols = ui->tableWidget->columnCount();
    int rows = ui->tableWidget->rowCount();
    qDebug()<<rows;
    ui->tableWidget->insertRow(rows);
    for (int i=0;i<cols;i++) {
//        ui->tableWidget->setItem(rows,i,new QTableWidgetItem("new"+QString::number(rows)));
        ui->tableWidget->setItem(rows,i,new QTableWidgetItem(""));
    }
    ui->tableWidget->selectRow(rows);
}

void Pro_update::on_del_clicked()
{
    QTableWidgetItem* item = ui->tableWidget->currentItem();
    if(item ==Q_NULLPTR) return;
    ui->tableWidget->removeRow(item->row());
}

void Pro_update::on_modify_clicked()
{
    if(ui->modify->text()=="Modify")
    {
        ui->tableWidget->setEditTriggers(QAbstractItemView::CurrentChanged);
        ui->modify->setText("Save");
    }else {
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->modify->setText("Modify");
    }


    /*QModelIndex index = ui->tableWidget->currentIndex();

    QList<QTableWidgetItem*> listItem = ui->tableWidget->selectedItems();

    if(listItem.count()==0) return;
    foreach (QTableWidgetItem* item,listItem){
        item->setText("modify");
    }*/
}
