#include "View/mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":Assets/rocket.png"));

    QFile stylesheet(":Assets/styles.qss");
    stylesheet.open(QFile::ReadOnly);
    a.setStyleSheet(QLatin1String(stylesheet.readAll()));

    View::MainWindow w;
    w.show();


    return a.exec();
}
