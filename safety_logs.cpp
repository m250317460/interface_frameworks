#include "safety_logs.h"
#include "ui_safety_logs.h"
#include <QFile>
#include <QTextStream>
#include "qdebug.h"

Safety_logs::Safety_logs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Safety_logs)
{
    ui->setupUi(this);

    //设置表格的列数，必须要先设置，不然表格显示不出来
    ui->tableWidget->setColumnCount(8);
//    ui->tableWidget->setRowCount(4);


    ui->tableWidget->horizontalHeader()->setFixedHeight(50);
    QFont f1 = QFont("song",20);
    QFont f2 = QFont("song",14);
    f1.setBold(true);

    ui->tableWidget->horizontalHeader()->setFont(f1);
    ui->tableWidget->setFont(f2);
    //建立表头
    QStringList header;

    header << "检查单位" << "检查人" << "检查时间" << "检查情况"<<"整改责任人"<<"整改情况"<<"操作时间"<<"操作人";


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

Safety_logs::~Safety_logs()
{
    delete ui;
}
void Safety_logs::on_add_clicked()
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

void Safety_logs::on_del_clicked()
{
    QTableWidgetItem* item = ui->tableWidget->currentItem();
    if(item ==Q_NULLPTR) return;
    ui->tableWidget->removeRow(item->row());
}

void Safety_logs::on_modify_clicked()
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

void Safety_logs::on_btn_import_clicked()
{
    QString path = "/home/mhw/QtProjects/Import.xlsx";
//    if(currentSciptIndex ==-1) return;
    QXlsx::Document xlsx(path);
    qDebug()<<path;
    QXlsx::Workbook *workBook = xlsx.workbook();

    QXlsx::Worksheet *workSheet = static_cast<QXlsx::Worksheet*>(workBook->sheet(0));
    qDebug()<<workSheet->dimension().rowCount();
    qDebug()<<workSheet->dimension().columnCount();
    ui->tableWidget->setRowCount(workSheet->dimension().rowCount());
    ui->tableWidget->setColumnCount(6);
    QString value;
//    for (int i = 6; i <= workSheet->dimension().rowCount(); i++)
    for (int i = 1; i <= workSheet->dimension().rowCount(); i++)
    {
        for (int j = 1; j <= workSheet->dimension().columnCount(); j++)
        {
            QXlsx::Cell *cell = workSheet->cellAt(i, j);
            if (cell==nullptr) continue;
            if (cell->isDateTime())//日期
            {
                if (cell->dateTime().date().year()==1899) continue;
                value = cell->dateTime().toString("yyyy/MM/dd hh:mm");
            }
            else
            {
                value = cell->value().toString();
                qDebug()<<"import_success";

            }
//            ui->tableWidgesetItemValue(i - 6, j - 1, value);
//            ui->tableWidget->setItem(i - 6, j - 1, value);
//            qDebug()<<i-6<<","<<j-1<<","<<value;
            qDebug()<<i<<","<<j<<","<<value;
//            ui->tableWidget->item(i -6, j-1 )->setText(value);
            ui->tableWidget->item(i-1, j-1)->setText(value);
        }
    }
    for (int i = ui->tableWidget->rowCount() - 1; i >= 0; i--)//删除末尾空白行
    {
        QTableWidgetItem *item = ui->tableWidget->item(i, 0);
        if (item==NULL)
            ui->tableWidget->removeRow(i);
        else break;
    }
}

void Safety_logs::on_btn_output_clicked()
{
    QXlsx::Document xlsx;
    QString value;
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        for (int j = 0;j < ui->tableWidget->columnCount();j++)
        {
            QTableWidgetItem *item = ui->tableWidget->item(i,j);
            if(item==NULL)
            {
                value = "";
            }else
            {
                value = item->text();
            }
            xlsx.write(i+1,j+1,value);
        }
    }
    if (xlsx.saveAs("/home/mhw/QtProjects/"+ui->btn_import->text()+".xlsx"));
        QMessageBox::information(this,"save","successful!",QMessageBox::Ok);
}
