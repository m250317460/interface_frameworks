#include "pro_logs.h"
#include "ui_pro_logs.h"

#include <QFile>
#include <QTextStream>
#include "qdebug.h"

Pro_logs::Pro_logs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Pro_logs)
{
    ui->setupUi(this);

//    ui->logs_panel->

    //从文件读取数据
    QFile f("/home/mhw/logs.txt");

    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream output(&f);
    output.setCodec("UTF-8");

    QString lineStr;//文件的每一行的字符串
    while (!output.atEnd()) {
        lineStr = output.readLine(); //读取文件的一行
        ui->textBrowser->append(lineStr);

    }
    ui->textBrowser->append("-------------------------------------------------------------");





    /*ui->tableWidget->horizontalHeader()->setFixedHeight(50);
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

    header << "xuhao" << "check_dw" << "checker" << "time"<<"checked_dw"<<"person"<<"check_situation"<<"modify_situation"<<"recheck"<<"time"<<"o_person"<<"beizhu";


    ui->tableWidget->setHorizontalHeaderLabels(header);
    //设置表头显示模式,这里设置的是拉伸模式
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setStyleSheet("alternate-background-color:#e3f3ff;");*/
}

Pro_logs::~Pro_logs()
{
    delete ui;
}
