#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>

#include "xlsxdocument.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    /*QXlsx::Document xlsx;
    xlsx.write("A1","Hello QT");
    xlsx.saveAs("/home/mhw/QtProjects/Monitor_system/test.xlsx");

    return 0;*/


//    QFile f("/home/mhw/QtProjects/Monitor_system/qdarkstyle/dark/style.qss");
//    printf(f);
    QFile f(":qdarkstyle/light/style.qss");

    if(!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }else{
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }

    w.show();

    return a.exec();
}
