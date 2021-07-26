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
   w.on_Liste_Activated();// on appelle le metode publique on_Liste_Activated() avec le Widget w
    return a.exec();
}
