#include "nuevacategoria.h"
#include "ui_nuevacategoria.h"

NuevaCategoria::NuevaCategoria(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::NuevaCategoria)
{
    ui->setupUi(this);
    ui->newCateg->setMaxLength(10);
    ui->newCateg2->setMaxLength(10);
    ui->newCateg3->setMaxLength(10);
}

NuevaCategoria::~NuevaCategoria()
{
    delete ui;
}

void NuevaCategoria::SetModelCateg(QSqlTableModel *m)
{
    ui->boxcateg->setModel(m);
    ui->boxcateg->setModelColumn(1);
    ui->boxcateg->setCurrentIndex(-1);
}

void NuevaCategoria::SetModelSubCateg(QSqlTableModel *m)
{
    ui->boxSub->setModel(m);
    ui->boxSub->setModelColumn(1);
    ui->boxSub->setCurrentIndex(-1);
}

void NuevaCategoria::SetConsultor(QConsultor *c)
{
    consultorFormCuenta = c;
}

void NuevaCategoria::on_anadirCateg_clicked()
{

    if(ui->newCateg->text().isEmpty()){
            QMessageBox msgBox;
            msgBox.setText("Introduce una categoria");
            msgBox.exec();
    }

    else{
        consultorFormCuenta->NuevaCategoria(ui->newCateg->text());
        ui->newCateg->clear();
    }
}

void NuevaCategoria::on_anadirSub_clicked()
{


    if(ui->newCateg2->text().isEmpty() || ui->boxcateg->currentText().isEmpty()){
            QMessageBox msgBox;
            msgBox.setText("Introduzca todos los campos de la subcategoria");
            msgBox.exec();
    }

    else{
        consultorFormCuenta->NuevaSubcategoria(ui->newCateg2->text(),ui->boxcateg->currentText());
        ui->newCateg2->clear();
        ui->boxcateg->setCurrentIndex(-1);
    }
}

void NuevaCategoria::on_anadirSubSub_clicked()
{
    if(ui->newCateg3->text().isEmpty() || ui->boxSub->currentText().isEmpty()){
            QMessageBox msgBox;
            msgBox.setText("Introduzca todos los campos de la (sub)subcategoria");
            msgBox.exec();
    }

    else{
        consultorFormCuenta->NuevaSubSubcategoria(ui->newCateg3->text(),ui->boxSub->currentText());
        ui->newCateg3->clear();
        ui->boxSub->setCurrentIndex(-1);
    }
}

void NuevaCategoria::on_pushButton_clicked()
{
    delete ui;
    this->close();
}
