#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_4_clicked()
{
     this->close();// pour fermer l’interface
}

void Widget::on_pushButton_2_clicked()
{
    // L'opération consistant à créer le fichier texte se déroule en trois
    // étapes.

    // ETAPE 1: on définit le *nom* et l'*emplacement* (répertoire) du fichier dans
    // lequel seront enregistrés fiches de lecture.
    QString filename=QFileDialog::getSaveFileName(this,tr("Exporter dans un fichier texte"),FilesRootPath ,tr("Fichiers Textes (*.txt)"));
    //  filename contient le chemin absolu du fichier !

    // on instancie un objet QFile en invoquant le constructeur simple prenant
    // en argument le chemin (relatif ou absolu) du fichier que l'on souhaite
    // créer / modifier / lire.
    QFile file(filename);

    // ETAPE 2: on ouvre en écriture le fichier texte en appelant la méthode open
    // NOTE. S'il n'est pas possible d'ouvrir en écriture le fichier, la méthode retourne
    // false sinon elle retourne true
    if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
        return; // en cas d'échec d'ouverture en écriture, on ne fait rien !

// ATTENTION. Un fichier ouvert en écriture ne veut pas dire qu'il est créé tant
// qu'il n'a pas été fermé à l'aide de la méthode close().

// ETAPE 3: on écrit les contenus des zones de texte dans le fichier texte,
// Pour cela, on va utiliser un objet QTextStream comme mémoire tampon pour écrire
// les notes dans le fichier texte.

// La classe QTextStream fait partie de la famille des classes appelées
// flux (std::cout est un flux en sortie)

// En particulier, il est possible d'enregistrer simplement des
// données dans un flux à l'aide de l'opérateur <<

// En utilisant le constructeur prenant en argument un pointeur QFile*,
// on pourra  écrire dans le fichier texte (objet file) à travers le flux
// out.

// Le nom du flux est libre; c'est moi qui ait choisit de l'appeler
// out pour output
QTextStream out(&file);
// pour recupéerer le contenue de chaque zone de text on utilise la methode toPlainText()  appliqué sur l'un des text edit
out <<  ui->textEdit_2->toPlainText() << endl;
out <<   ui->textEdit ->toPlainText() <<  endl;
out << ui->textEdit_3->toPlainText() << endl;



file.close(); //  fermer fichier
}


void Widget::on_pushButton_clicked()
{
    // L'opération consistant ouvrrir  le fichier texte se déroule en trois
    // étapes.

    // ETAPE 1: on définit le *nom* et l'*emplacement* (répertoire) du fichier dans
    // lequel sont enregistrés les fiches .
    QString filename=QFileDialog::getOpenFileName(this,tr("Importer depuis un fichier texte"),FilesRootPath ,tr("Fichiers Textes (*.txt)"));
    // ATTENTION. filename contient le chemin absolu du fichier !

    // on instancie un objet QFile en invoquant le constructeur simple prenant
    // en argument le chemin (relatif ou absolu) du fichier que l'on souhaite
    // créer / modifier.
    QFile file(filename);
    // ATTENTION. le fichier n'est pas ouvert en lecture à ce stade

    // ETAPE 2: on ouvre en lecture le fichier texte en appelant la méthode open
    // NOTE. S'il n'est pas possible d'ouvrir en lecture le fichier, la méthode retourne
    // false sinon elle retourne true
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))

        return;

    // ETAPE 3: on recopie les fiches enregistrées dans le fichier texte dans les
    // zones de texte dédiées.

    // Pour cela, on va utiliser un objet QTextStream comme mémoire tampon pour lire
    // les fiches enregistrées dans le fichier texte.

    // En utilisant le constructeur prenant en argument un pointeur QFile*,
    // on pourra lire le fichier texte (objet file) à travers le flux
    // in.

    // Le nom du flux est libre; c'est moi qui ait choisit de l'appeler
    // in
    QTextStream in(&file);
    //on utilie la methode setText() pour placer le text lu par (in.readLine()) dans chaqu'un des textedit

    ui->textEdit_2->setText(in.readLine());
    ui->textEdit->setText(in.readLine());
    ui->textEdit_3->setText(in.readLine());



    file.close();// fermer le fichier
}

void Widget::on_pushButton_3_clicked()
{
   ui->textEdit->clear();// pour effacer le text qui est dans le textEdit
      ui->textEdit_2->clear();
         ui->textEdit_3->clear();

}
