#include "qconsultor.h"
#include "ui_qconsultor.h"
#include <cmath>

QConsultor::QConsultor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QConsultor)
{
    ui->setupUi(this);
}

QConsultor::~QConsultor()
{
    CerrarDB();
    delete ui;
}

bool QConsultor::AbrirDB()
{
    bool state;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("baseDatos.sqlite");

    // Abrimos la base de datos.
    if (!db.open())
    {
        qDebug() << "Error de conexión con " << db.databaseName();
        state = false;
    }
    else
    {
        qDebug() << "Conexión establecida con " << db.databaseName();
        state = true;
    }

    return state;
}

void QConsultor::CerrarDB()
{
    db.close();
}

//NUEVO MOVIMIENTO
void QConsultor::NuevoMovimiento(QString nombreCuenta, QString tipoMov, QString nombreCategoria, QString importe, QString descripcion, QString fechaProg, QString periocidad)
{
    // Realizamos la consulta para insertar un nuevo valor
    QSqlDatabase::database().transaction();

    //consulta
    QSqlQuery query;

    //comprobar gastos
    int limitePasado = 0;


    query.prepare("SELECT idCuenta FROM cuentas WHERE nombreCuenta = :nCuenta");
    query.bindValue(":nCuenta",nombreCuenta);
    query.exec();
    int cuentaId;
    while(query.next()){
        cuentaId = query.value(0).toInt();
    }

    //comprobar que no nos emos pasado con los gastos (limite) en este dia
   if(tipoMov == QString::fromUtf8("gasto")){

       QDate now = QDate::currentDate();
       int dia, mes, ano, limite;
       double totalGastado;
       QString diaQ, mesQ, anoQ;

       dia = now.day();
       mes = now.month();
       ano = now.year();

       if(dia<10)
        diaQ = "0" + QString::number(dia);
       else
        diaQ = QString::number(dia);

       if(mes < 10)
            mesQ = "0" + QString::number(mes);
       else
            mesQ = QString::number(mes);

         anoQ = QString::number(ano);


       QString s = diaQ + "/" + mesQ + "/" + anoQ + "%";

       query.prepare("SELECT round(sum(importe),2) "
                  " FROM movimientos where data like :string "
                  " and tipoMov = 'gasto' and cuentaId = :id ");

       query.bindValue(":string",s);
       query.bindValue(":id",cuentaId);

       if(!query.exec()){
           qDebug() << query.lastError().text() << endl;
           qDebug() << query.lastQuery() << endl;
       }else{
           qDebug() << query.lastQuery() << endl;
       }

       while (query.next()) {
          totalGastado = query.value(0).toDouble();
       }


       query.prepare("SELECT limite from cuentas "
                     " where nombreCuenta =   :nombre ");

       query.bindValue(":nombre",nombreCuenta);

       if(!query.exec())
           qDebug() << query.lastError().text() << endl;
       else
           qDebug() << query.lastQuery() << endl;

       while (query.next()) {
          limite = query.value(0).toInt();

       }


       //si lo gastado en ese dia mas el importe nuevo es mayor que el limite
       if( (std::abs(totalGastado + importe.toDouble())) > limite ){

           limitePasado = 1; //se ha pasado el limite, no se insertara


           QMessageBox msgBox;
           msgBox.setText("Hoy ya te has pasado con los gastos de la cuenta seleccionada");
           msgBox.exec();

           // Lanzamos una señal para indicar que la tabla ha sido actualizada
           emit tablaMovActualizada();

       }


    }//fin comprobar gastos

    if(limitePasado == 0){

        query.prepare("SELECT idCateg FROM categorias WHERE nombreCateg = :nCategoria");
        query.bindValue(":nCategoria",nombreCategoria);
        query.exec();
        int categoria;
        while(query.next()){
            categoria = query.value(0).toInt();
        }

        if(periocidad.isEmpty()){
            query.prepare("INSERT INTO movimientos(cuentaId,tipoMov,categId,importe,descripcion,data)"
                   "VALUES(:cuentaId,:tipoMov,:categId,:importe,:desc,strftime('%d/%m/%Y %H:%M:%S','now'))");

            query.bindValue(":cuentaId",cuentaId);
            query.bindValue(":tipoMov",tipoMov);
            query.bindValue(":categId",categoria);
            query.bindValue(":importe",importe);
            query.bindValue(":desc",descripcion);
        }
        else{
            query.prepare("INSERT INTO movimientos(cuentaId,tipoMov,categId,importe,descripcion,data,dataProgramada,periocidad)"
                   "VALUES(:cuentaId,:tipoMov,:categId,:importe,:desc,strftime('%d/%m/%Y %H:%M:%S','now'),"
                      ":prog,:per)");

            query.bindValue(":cuentaId",cuentaId);
            query.bindValue(":tipoMov",tipoMov);
            query.bindValue(":categId",categoria);
            query.bindValue(":importe",importe);
            query.bindValue(":desc",descripcion);
            query.bindValue(":prog",fechaProg);
            query.bindValue(":per",periocidad);

         }

         QMessageBox msgBox;

         if(query.exec()){

             msgBox.setText("Se ha insertado un nuevo movimiento");
             msgBox.exec();

             // Lanzamos una señal para indicar que la tabla ha sido actualizada
             emit tablaMovActualizada();

         }else{

             msgBox.setText("Movimiento mal insertado");
             msgBox.exec();

             qDebug() << query.lastError().text() << endl;

         }

    }//fin if limitePasado == 0


     // Termina la transacción
     QSqlDatabase::database().commit();


}
/////////////////////////////////////////////////////////////////////////////////////
//NUEVA CUENTA
void QConsultor::NuevaCuenta(QString nombreCuenta, QString limiteCuenta, QString ingresoIni)
{

    // Realizamos la consulta para insertar un nuevo valor
    QSqlDatabase::database().transaction();

    //consulta
    QSqlQuery query;

    query.prepare("INSERT INTO cuentas (nombreCuenta, limite, ingresoInicial)"
                  "VALUES(:ncuenta,:limCuenta,:ingInicial)");

    query.bindValue(":ncuenta",nombreCuenta);
    query.bindValue(":limCuenta",limiteCuenta);
    query.bindValue(":ingInicial",ingresoIni);

    QMessageBox msgBox;

    if(query.exec()){
        msgBox.setText("Se ha insertado una nueva cuenta");
        msgBox.exec();

        // Lanzamos una señal para indicar que la tabla ha sido actualizada
        emit tablaCuentasActualizada();

    }else{

        msgBox.setText("Cuenta mal insertada");
        msgBox.exec();
    }
    // Termina la transacción
    QSqlDatabase::database().commit();

}

//NUEVA CATEGORIA
void QConsultor::NuevaCategoria(QString nombreCateg){



    // Realizamos la consulta para insertar un nuevo valor
    QSqlDatabase::database().transaction();

    //consulta
    QSqlQuery query;

    int idCategoriaPadre = 0;


    query.prepare("INSERT INTO categorias(idCategPadre,nivel,nombreCateg)"
                  "VALUES(:idPadre,:niv,:nCateg)");

    query.bindValue(":idPadre",idCategoriaPadre);
    query.bindValue(":niv",0);
    query.bindValue(":nCateg",nombreCateg);


    QMessageBox msgBox;

    if(query.exec()){
        msgBox.setText("Se ha insertado una nueva categoria");
        msgBox.exec();

        // Lanzamos una señal para indicar que la tabla ha sido actualizada
        emit tablaCategActualizada();

    }else{

        msgBox.setText("Categoria mal insertada");
        msgBox.exec();
    }


    // Termina la transacción
    QSqlDatabase::database().commit();


}

//NUEVA SUBCATEGORIA
void QConsultor::NuevaSubcategoria(QString nombreSub, QString padre)
{
    // Realizamos la consulta para insertar un nuevo valor
    QSqlDatabase::database().transaction();

    //consulta
    QSqlQuery query;

    int idCategoriaPadre;

    query.prepare("SELECT idCateg FROM categorias WHERE nombreCateg = :p");

    query.bindValue(":p",padre);

    if(!query.exec())
        qDebug() << query.lastError().text() << endl;

    while(query.next()){
        idCategoriaPadre = query.value(0).toInt();
    }


    query.prepare("INSERT INTO categorias(idCategPadre,nivel,nombreCateg)"
                  "VALUES(:idPadre,:niv,:nCateg)");

    query.bindValue(":idPadre",idCategoriaPadre);
    query.bindValue(":niv",1);
    query.bindValue(":nCateg",nombreSub);


    QMessageBox msgBox;

    if(query.exec()){
        msgBox.setText("Se ha insertado una nueva categoria");
        msgBox.exec();

        // Lanzamos una señal para indicar que la tabla ha sido actualizada
        emit tablaCategSubActualizada();

    }else{

        msgBox.setText("Categoria mal insertada");
        msgBox.exec();
    }


    // Termina la transacción
    QSqlDatabase::database().commit();
}

//NUEVA SUB SUBCATEGORIA
void QConsultor::NuevaSubSubcategoria(QString nombreSub, QString padre)
{
    // Realizamos la consulta para insertar un nuevo valor
    QSqlDatabase::database().transaction();

    //consulta
    QSqlQuery query;

    int idCategoriaPadre;

    query.prepare("SELECT idCateg FROM categorias WHERE nombreCateg = :p");

    query.bindValue(":p",padre);

    if(!query.exec())
        qDebug() << query.lastError().text() << endl;

    while(query.next()){
        idCategoriaPadre = query.value(0).toInt();
    }


    query.prepare("INSERT INTO categorias(idCategPadre,nivel,nombreCateg)"
                  "VALUES(:idPadre,:niv,:nCateg)");

    query.bindValue(":idPadre",idCategoriaPadre);
    query.bindValue(":niv",2);
    query.bindValue(":nCateg",nombreSub);


    QMessageBox msgBox;

    if(query.exec()){
        msgBox.setText("Se ha insertado una nueva categoria");
        msgBox.exec();

    }else{

        msgBox.setText("Categoria mal insertada");
        msgBox.exec();
    }


    // Termina la transacción
    QSqlDatabase::database().commit();
}


