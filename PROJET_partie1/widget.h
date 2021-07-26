#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
/* Option 2 : Editeur de fiche de lecture
Membres:
Akkoura aniesse 39014594
Aissatou Barry 39013121
*/
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
const QString FilesRootPath = "C:/Users/AMBER/Desktop/PROJET_partie1/PROJET_test1/fiches/";// le chemin absolu des fiches



