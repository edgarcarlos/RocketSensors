#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile stylesheet(":/styles.qss");
    stylesheet.open(QFile::ReadOnly);
    a.setStyleSheet(QLatin1String(stylesheet.readAll()));

    MainWindow w;
    w.show();


    return a.exec();
}
