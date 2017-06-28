#include "editarmovimientos.h"
#include "ui_editarmovimientos.h"



editarMovimientos::editarMovimientos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editarMovimientos)
{
    ui->setupUi(this);

    actualizarTabla();
}

editarMovimientos::~editarMovimientos()
{
    delete ui;
}

void editarMovimientos::actualizarTabla()
{

    ui->tablaMov->setShowGrid(false);//no enseñar lineas separacion
    ui->tablaMov->setSelectionBehavior(QAbstractItemView::SelectRows);//para seleccionar la fila entera
    ui->tablaMov->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablaMov->verticalHeader()->hide();//esconder los numeros verticales
    ui->tablaMov->setAlternatingRowColors(true);//alternar colores

    tabla = new QSqlTableModel(this);
    tabla->setTable("movimientos");
    tabla->select();
    ui->tablaMov->setModel(tabla);
    ui->tablaMov->setColumnHidden(0,true);
}



void editarMovimientos::on_borrarMov_clicked()
{
    tabla->removeRow(ui->tablaMov->currentIndex().row());
    tabla->select();
}

void editarMovimientos::on_pushButton_clicked()
{
    delete ui;
    this->close();
}
