#include "widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
