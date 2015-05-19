#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <mainwindow.h>
#include <QFile>
#include <QTextStream>
#include <QDataStream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::fillList(){
    QFile file("C://Users//H123186/Documents/github/test/wahluigi/pokemon.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList fields = line.split(' ');

            QString id = fields.takeFirst();
            QString name = fields.takeFirst();
            QString type = fields.takeFirst();
            QString type2 = fields.takeFirst();
            ui->pokeBox->addItem(name);
            ui->idBlock->addItem(id);
           }

           file.close();
    }
    else{
         ui->pokeBox->addItem("No");
         ui->pokeBox->addItem("Luck");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateType(){
    ui->typeText->setText("Wah");
}

void MainWindow::on_typeText_textChanged(const QString &arg1)
{
    QFile file("C://Users//H123186/Documents/github/test/wahluigi/pokemon.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList fields = line.split(' ');

            QString id = fields.takeFirst();
            QString name = fields.takeFirst();
            QString type = fields.takeFirst();
            QString type2 = fields.takeFirst();

            if(name == arg1 || id == arg1){
                ui->typeText->setText(type);
                ui->type2Text->setText(type2);
                ui->pokeBox->setCurrentText(name);
                ui->idBlock->setCurrentText(id);
                double weak[18];
                double weak2[18];
                findType(type, weak);
                findType(type2, weak2);
                double weakness[18] = { weak[0] * weak2[0], weak[1] * weak2[1], weak[2] * weak2[2], weak[3] * weak2[3], weak[4] * weak2[4], weak[5] * weak2[5], weak[6] * weak2[6], weak[7] * weak2[7], weak[8] * weak2[8], weak[9] * weak2[9], weak[10] * weak2[10], weak[11] * weak2[11], weak[12] * weak2[12], weak[13] * weak2[13], weak[14] * weak2[14], weak[15] * weak2[15], weak[16] * weak2[16], weak[17] * weak2[17] };
                ui->normalWeak->setText(QString::number(weakness[0]));
                ui->fightWeak->setText(QString::number(weakness[1]));
                ui->flyingWeak->setText(QString::number(weakness[2]));
                ui->poisonWeak->setText(QString::number(weakness[3]));
                ui->groundWeak->setText(QString::number(weakness[4]));
                ui->rockWeak->setText(QString::number(weakness[5]));
                ui->bugWeak->setText(QString::number(weakness[6]));
                ui->ghostWeak->setText(QString::number(weakness[7]));
                ui->steelWeak->setText(QString::number(weakness[8]));
                ui->fireWeak->setText(QString::number(weakness[9]));
                ui->waterWeak->setText(QString::number(weakness[10]));
                ui->grassWeak->setText(QString::number(weakness[11]));
                ui->electricWeak->setText(QString::number(weakness[12]));
                ui->psychicWeak->setText(QString::number(weakness[13]));
                ui->iceWeak->setText(QString::number(weakness[14]));
                ui->dragonWeak->setText(QString::number(weakness[15]));
                ui->darkWeak->setText(QString::number(weakness[16]));
                ui->fairyWeak->setText(QString::number(weakness[17]));
            }
        }

           file.close();
    }
}

void MainWindow::findType(QString type, double* ptr){

    if (type == "Normal"){
        double weakness[18] = { 1, 2, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Fighting"){
        double weakness[18] = {1, 1, 2, 1, 1, .5, .5, 1, 1, 1, 1, 1, 1, 2, 1, 1, .5, 2};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Flying"){
        double weakness[18] = {1, .5, 1, 1, 0, 2, .5, 1, 1, 1, 1, .5, 2, 1, 2, 1, 1, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Poison"){
        double weakness[18] = {1, .5, 1, .5, 2, 1, .5, 1, 1 ,1, 1, .5, 1, 2, 1, 1, 1, .5};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Ground"){
        double weakness[18] = {1, 1, 1, .5, 1, .5, 1, 1, 1, 1, 2, 2, 0, 1, 2, 1, 1, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Rock"){
        double weakness[18] = {.5, 2, .5, .5, 2, 1, 1, 1, 2, .5, 2, 2, 1, 1, 1, 1, 1, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Bug"){
        double weakness[18] = {1, .5, 2, 1, .5, 2, 1, 1, 1, 2, 1, .5, 1, 1, 1, 1, 1, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Ghost"){
        double weakness[18] = {0, 0, 1, .5, 1, 1, .5, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Steel"){
        double weakness[18] = {.5, 2, .5, 0, 2, .5, .5, 1, .5, 2, 1, .5, 1, .5, .5, .5, 1, .5};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Fire"){
        double weakness[18] = {1, 1, 1, 1, 2, 2, .5, 1, .5, .5, 2, .5, 1, 1, .5, 1, 1, .5};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Water"){
        double weakness[18] = {1, 1, 1, 1, 1, 1, 1, 1, .5, .5, .5, 2, 2, 1, .5, 1, 1, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Grass"){
        double weakness[18] = {1, 1, 2, 2, .5, 1, 2, 1, 1, 2, .5, .5, .5, 1, 2, 1, 1, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Electric"){
        double weakness[18] = {1, 1, .5, 1, 2, 1, 1, 1, .5, 1, 1, 1, .5, 1, 1, 1, 1, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Psychic"){
        double weakness[18] = {1, .5, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, .5, 1, 1, 2, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Ice"){
        double weakness[18] = {1, 2, 1, 1, 1, 2, 1, 1, 2, 2, 1, 1, 1, 1, .5, 1, 1, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Dragon"){
        double weakness[18] = {1, 1, 1, 1, 1, 1, 1, 1, 1, .5, .5, .5, .5, 1, 2, 2, 1, 2};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Dark"){
        double weakness[18] = {1, 2, 1, 1, 1, 1, 2, .5, 1, 1, 1, 1, 1, 0, 1, 1, .5, 2};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else if (type == "Fairy"){
        double weakness[18] = {1, .5, 1, 2, 1, 1, .5, 1, 2, 1, 1, 1, 1, 1, 1, 0, .5, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
    else{
        int weakness[18] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for (int i = 0; i < 18; i++){
            ptr[i] = weakness[i];
        }
    }
}
