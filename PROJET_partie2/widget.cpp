#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QLineEdit>
#include <QDir>
#include <QMessageBox>
#include <QFileInfo>


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
     this->close();// pour fermer la fenetre
}

void Widget::on_pushButton_2_clicked()
{
    //bouton enregistrer 
    
    // L'opération consistant à créer le fichier texte se déroule en trois
    // étapes.

    // ETAPE 1: on définit le *nom* et l'*emplacement* (répertoire) du fichier dans
    // lequel seront enregistrés fiches.
    QString filename=QFileDialog::getSaveFileName(this,tr("Exporter dans un fichier texte"),FilesRootPath,tr("Fichiers Textes (*.txt)"));
    // filename contient le chemin absolu du fichier !

    // on instancie un objet QFile en invoquant le constructeur simple prenant
    // en argument le chemin (relatif ou absolu) du fichier que l'on souhaite
    // créer / modifier / lire.
    QFile file(filename);

    // ETAPE 2: on ouvre en écriture le fichier texte en appelant la méthode open
    // NOTE. S'il n'est pas possible d'ouvrir en écriture le fichier, la méthode retourne
    // false sinon elle retourne true
    if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
        return; // en cas d'échec d'ouverture en écriture, on ne fait rien !

//Un fichier ouvert en écriture ne veut pas dire qu'il est créé tant
// qu'il n'a pas été fermé à l'aide de la méthode close().

// ETAPE 3: on écrit les contenus des zones de texte dans le fichier texte,
// Pour cela, on va utiliser un objet QTextStream comme mémoire tampon pour écrire
// les fiches de lecture dans le fichier texte.

// La classe QTextStream fait partie de la famille des classes appelées
// flux (std::cout est un flux en sortie)

// En particulier, il est possible d'enregistrer simplement des
// données dans un flux à l'aide de l'opérateur <<

// En utilisant le constructeur prenant en argument un pointeur QFile*,
// on pourra  écrire dans le fichier texte (objet file) à travers le flux
// out.

// Le nom du flux est libre; c'est moi qui ait choisit de l'appeler
// out
QTextStream out(&file);
// pour recupérer le contenue de chaque zone de text on utilise la methode toPlainText()  appliqué sur l'un des text edit
out <<  ui->textEdit_2->toPlainText() << endl;
out <<   ui->textEdit ->toPlainText() <<  endl;
out <<  ui->textEdit_3->toPlainText() << endl;


file.close();// fermer le fichier
QString nomDuFichier = QFileInfo(file).fileName();// pour recupérer juste le nom du fichier.txt à l'aide de la methode QFileInfo(file) prenant en argument le fichier creé
ui->Liste->addItem(nomDuFichier);// pour l'ajouter dans la liste
}


void Widget::on_pushButton_clicked()
{
    //Bouton voir
    QString textEditStr= ui->Liste->currentItem()->text();// récupèrer la fiche selectionné  de la liste comme un  QString

    QString filename=FilesRootPath+ textEditStr;//pour récupèrer le chemain absolu de  la fiche à selectionner
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly| QIODevice::Text))

        return;

       QTextStream in(&file);
        ui->textEdit_2->setText(in.readLine());
       ui->textEdit->setText(in.readLine());
       ui->textEdit_3->setText(in.readLine());
 file.close();// fermer le fichier

}

void Widget::on_pushButton_3_clicked()
{
    //bouton nouveau
    
    ui->textEdit->clear();
       ui->textEdit_2->clear();
          ui->textEdit_3->clear();

}
void Widget::on_pushButton_5_clicked()
{
// boputon supprimer
    QString textEditStr= ui->Liste->currentItem()->text();// récupèrer la fiche selectionné de la liste

     if( !QFile::remove(FilesRootPath + textEditStr))// on supprime la fiche enregistré dans le dossier à l'aide de la methode remove()

           QMessageBox::critical(NULL,"Erreur","impossible de supprimer la fiche");
       else{
         for (int i = 0; i<ui->Liste->count(); ++i)
             {
                 if(ui->Liste->item(i)->isSelected())
                 {
             delete ui->Liste->takeItem(i);
                     ui->textEdit->setText("");
                     ui->textEdit_2->setText("");
                     ui->textEdit_3->setText("");
                 }}

         QMessageBox::critical(NULL,"OK","la fiche est bien supprimer!");/* Au moment ou on clique sur le bouton supprimer la fiche selectionné sera supprimer de la liste avec  delete ui->Liste->takeItem(i);
  la suppression est bien faite une boite de dialogue apparait en mentionnant que 'la fiche est bien supprimée' sinon 'impossible de supprimer la fiche'  */    }

    }


void Widget::on_Liste_Activated()
{ //La classe QDir donne accès aux structures de répertoires et à leur contenu
    QDir directory(FilesRootPath);
    QStringList liste=directory.entryList( QStringList ());//Renvoie une liste des noms de tous les fichiers du repertoire
     ui->Liste->addItems(liste);//en suite on rajoute ces fichiers dans la liste

}

