#include "mainwindow.h"
#include <QApplication>
#include <QtSingleApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);


    QtSingleApplication a(argc, argv);
    if(a.isRunning())
    {
        a.sendMessage("process is already in running");
        return EXIT_SUCCESS;
    }

    QLocale locale;
    QTranslator translator;
    if (locale.language() == QLocale::English)
    {
        translator.load("/home/oneai/.config/language_tool/language_tool_en_US.qm");
        a.installTranslator(&translator);
    }

    MainWindow w;
    w.show();

    QObject::connect(&a, &QtSingleApplication::messageReceived, &w, &MainWindow::showNormal);

    return a.exec();
}
