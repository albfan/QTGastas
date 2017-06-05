#include "editarcategorias.h"
#include "ui_editarcategorias.h"

editarCategorias::editarCategorias(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editarCategorias)
{
    ui->setupUi(this);

    actualizarTabla();
}

editarCategorias::~editarCategorias()
{
    delete ui;
}

void editarCategorias::actualizarTabla()
{

    ui->tablaCateg->setShowGrid(false);//no enseñar lineas separacion
    ui->tablaCateg->setSelectionBehavior(QAbstractItemView::SelectRows);//para seleccionar la fila entera
    ui->tablaCateg->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablaCateg->verticalHeader()->hide();//esconder los numeros verticales
    ui->tablaCateg->setAlternatingRowColors(true);//alternar colores

    tabla = new QSqlTableModel(this);
    tabla->setTable("categorias");
    tabla->select();
    ui->tablaCateg->setModel(tabla);
    ui->tablaCateg->setColumnHidden(0,true);
    ui->tablaCateg->setColumnHidden(1,true);
    ui->tablaCateg->setColumnHidden(2,true);

}

void editarCategorias::on_pushButton_clicked()
{
    this->close();
}

void editarCategorias::on_borrarCateg_clicked()
{

    int fila = ui->tablaCateg->currentIndex().row();

    QString dato = ui->tablaCateg->model()->data(ui->tablaCateg->model()->index(fila,0)).toString();

    QSqlQuery q;

    //comprobar que no haya subcategorias en la categoria
    q.exec("SELECT * FROM categorias where idCategPadre = '" + dato + "'");

    int cont = 0;

    while(q.next())
            cont ++;

    if(cont != 0){//si se a encontrado algun registro
        QMessageBox msgBox;
        msgBox.setText("La categoria seleccionada contiene subcategorias, no se borrará");
        msgBox.exec();
    }else{
        QMessageBox msgBox;
        msgBox.setText("La categoria seleccionada ha sido borrada");
        msgBox.exec();

        tabla->removeRow(fila);
        tabla->select();
    }
}
