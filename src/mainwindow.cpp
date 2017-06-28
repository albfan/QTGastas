#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Creamos un objeto que realizará las conexiones a la base de datos.
    consultor = new QConsultor();
    consultor->AbrirDB();

    //comprobarmos si hay que insertar algun movimiento programado anteriormente
    ComprobarPeriocidad();

    //configuramos las tablas para mostrar los datos
    SetTablaMovimientos();
    SetTablaCuentas();
    SetTablaCategorias();
    SetTablaSubCategorias();
    SetTablaSubSubcategorias();

    SetFiltroCuentas();//combobox cuentas
    SetFiltroCuentas2();//combobox cunentas tab cuentas

    ComprobarFiltros();

    // Creamos los formularios
    CreateFormularios();

    CrearFormulariosEditar();

    // Establecemos las conexiones SIGNALS-SLOTS
    SetConexiones();

    //tab cuentas
    on_dineroGlobal_clicked();
}

// Establecemos las conexiones SIGNALS-SLOTS
void MainWindow::SetConexiones()
{
  ////////////////////////////////////////////////////////
 //                     MOVIMIENTOS                    //
////////////////////////////////////////////////////////

    //Actualizacion de la tabla de movimientos
    connect(consultor, SIGNAL(tablaMovActualizada()),
            this, SLOT(actualizarInfoMov()));

    // Filtro de movimientos según la cuenta seleccionada
    connect(ui->comboBoxCuentas, SIGNAL(currentTextChanged(QString)),
            this, SLOT(ComprobarFiltros()));

    // Filtro de movimientos según el tipo seleccionado
    connect(ui->radioGastos, SIGNAL(clicked()),
            this, SLOT(ComprobarFiltros()));

    // Filtro de movimientos según el tipo seleccionado
    connect(ui->radioIngresos, SIGNAL(clicked()),
            this, SLOT(ComprobarFiltros()));

    //Filtro de movimientos segun el filtro de data seleccionado
    connect(ui->boxFiltroData, SIGNAL(currentTextChanged(QString)),
            this, SLOT(ComprobarFiltros()));

    ////////////////////////////////////////////////////////
   //                     CUENTAS                        //
  ////////////////////////////////////////////////////////

    //Actualizacion de la tabla de cuentas
    connect(consultor, SIGNAL(tablaCuentasActualizada()),
             this, SLOT(actualizarInfoCuentas()));

    // Filtro de movimientos según la cuenta seleccionada
    connect(ui->tabCuentasBox, SIGNAL(currentTextChanged(QString)),
            this, SLOT(actualizarDineroTotalCuenta(QString)));


    ////////////////////////////////////////////////////////
   //                     CATEGORIAS                     //
  ////////////////////////////////////////////////////////

    //Actualizacion de la tabla de categorias
    connect(consultor, SIGNAL(tablaCategActualizada()),
             this, SLOT(actualizarInfoCateg()));

    //Actualizacion de la tabla de subcategorias
    connect(consultor, SIGNAL(tablaCategSubActualizada()),
             this, SLOT(actualizarInfoSubCateg()));

}


//destructor mainWindow
MainWindow::~MainWindow()
{
    consultor->CerrarDB();
    delete ui;
}

//////////////////////////////////////////////////////////////////////////////////////////
 // Creamos el formulario para AÑADIR Nuevos Clientes
void MainWindow::CreateFormularios()
{
    //Movimientos
    formMov  = new NuevoMovimiento();
    formMov->SetConsultor(consultor);
    modeloTodasCateg = new QSqlTableModel(this);
    modeloTodasCateg->setTable("Categorias");
    modeloTodasCateg->select();
    formMov->SetModelCateg(modeloTodasCateg);
    formMov->SetModelCuentas(modeloTablaCuentas);

    //categorias
    formCat = new NuevaCategoria();
    formCat->SetModelCateg(modeloTablaCateg);
    formCat->SetModelSubCateg(modeloTablaSubCateg);
    formCat->SetConsultor(consultor);

    //cuentas
    formCuenta = new NuevaCuenta();
    formCuenta->SetConsultor(consultor);

}
/////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
//Mostrar los movimientos
void MainWindow::SetTablaMovimientos(){

    //Configuracion Tabla visualizacion de movimientos
    ui->tablaMov->setShowGrid(false);//no enseñar lineas separacion
    ui->tablaMov->setSelectionBehavior(QAbstractItemView::SelectRows);//para seleccionar la fila entera
    ui->tablaMov->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablaMov->verticalHeader()->hide();//esconder los numeros verticales
    ui->tablaMov->setAlternatingRowColors(true);//alternar colores

    //modelo para controlar la tabla de movimientos
    modeloTablaMov = new QSqlTableModel(this);
    modeloTablaMov->setTable("VistaMovimientos");
    modeloTablaMov->select();
    ui->tablaMov->setModel(modeloTablaMov);

    //model para la tabla de mov programados
    modeloTablaMovProg = new QSqlTableModel(this);
    modeloTablaMovProg->setTable("VistaProgramada");
    modeloTablaMovProg->select();
    ui->tablaMovProg->setModel(modeloTablaMovProg);



}
//Mostrar las cuentas
void MainWindow::SetTablaCuentas()
{
    //Configuracion Tabla visualizacion de movimientos
    ui->tablaCuentas->setShowGrid(false);//no enseñar lineas separacion
    ui->tablaCuentas->setSelectionBehavior(QAbstractItemView::SelectRows);//para seleccionar la fila entera
    ui->tablaCuentas->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablaCuentas->verticalHeader()->hide();//esconder los numeros verticales
    ui->tablaCuentas->setAlternatingRowColors(true);//alternar colores

    //modelo para controlar la tabla de movimientos
    modeloTablaCuentas = new QSqlTableModel(this);
    modeloTablaCuentas->setTable("Cuentas");
    modeloTablaCuentas->select();
    ui->tablaCuentas->setVisible(false);
    ui->tablaCuentas->setModel(modeloTablaCuentas);
    ui->tablaCuentas->resizeColumnsToContents();
    ui->tablaCuentas->setVisible(true);
    ui->tablaCuentas->setColumnHidden(0,true);



}

//Mostrar las categorias
void MainWindow::SetTablaCategorias()
{
    //Configuracion Tabla visualizacion de movimientos
    ui->tablaCateg->setShowGrid(false);//no enseñar lineas separacion
    ui->tablaCateg->setSelectionBehavior(QAbstractItemView::SelectRows);//para seleccionar la fila entera
    ui->tablaCateg->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablaCateg->verticalHeader()->hide();//esconder los numeros verticales
    ui->tablaCateg->setAlternatingRowColors(true);//alternar colores


    //modelo para controlar la tabla de movimientos
    modeloTablaCateg = new QSqlTableModel(this);
    modeloTablaCateg->setTable("VistaCategorias");
    modeloTablaCateg->select();
    ui->tablaCateg->setModel(modeloTablaCateg);
}

void MainWindow::SetTablaSubCategorias()
{
    //Configuracion Tabla visualizacion de movimientos
    ui->tablaSub->setShowGrid(false);//no enseñar lineas separacion
    ui->tablaSub->setSelectionBehavior(QAbstractItemView::SelectRows);//para seleccionar la fila entera
    ui->tablaSub->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablaSub->verticalHeader()->hide();//esconder los numeros verticales
    ui->tablaSub->setAlternatingRowColors(true);//alternar colores


    //modelo para controlar la tabla de movimientos
    modeloTablaSubCateg = new QSqlTableModel(this);
    modeloTablaSubCateg->setTable("VistaFinalSub");
    modeloTablaSubCateg->select();
    ui->tablaSub->setModel(modeloTablaSubCateg);
}

void MainWindow::SetTablaSubSubcategorias()
{
    //Configuracion Tabla visualizacion de movimientos
    ui->tablaSubSub->setShowGrid(false);//no enseñar lineas separacion
    ui->tablaSubSub->setSelectionBehavior(QAbstractItemView::SelectRows);//para seleccionar la fila entera
    ui->tablaSubSub->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tablaSubSub->verticalHeader()->hide();//esconder los numeros verticales
    ui->tablaSubSub->setAlternatingRowColors(true);//alternar colores


    //modelo para controlar la tabla de movimientos
    modeloTablaSubSubCateg = new QSqlTableModel(this);
    modeloTablaSubSubCateg->setTable("VistaFinalSubSub");
    modeloTablaSubSubCateg->select();
    ui->tablaSubSub->setModel(modeloTablaSubSubCateg);

}

////////////////////////////////////////////////////////////////////////////////////

///////////////////ACTUALIZACIONES DE TABLAS////////////////////////////////////////////////////////////
//Actualizamos los movimientos
void MainWindow::actualizarInfoMov()
{
    modeloTablaMov->select();
    modeloTablaMovProg->select();
}
//Actualizamos las categorias
void MainWindow::actualizarInfoCateg()
{
    modeloTablaCateg->select();
    modeloTodasCateg->select();
}

void MainWindow::actualizarInfoSubCateg()
{
    modeloTablaSubCateg->select();
    modeloTodasCateg->select();
}

void MainWindow::actualizarInfoSubSubCateg()
{
    modeloTablaSubSubCateg->select();
    modeloTodasCateg->select();
}
//Actualizamos las cuentas
void MainWindow::actualizarInfoCuentas()
{
    modeloTablaCuentas->select();
    SetFiltroCuentas();
    SetFiltroCuentas2();
}
////////////////////////////////////////////////////////////////

//////////////FILTROS//////////////////////////////////////////////////

void MainWindow::on_resetMov_clicked()
{
    modeloTablaMov->setFilter("");
    ui->comboBoxCuentas->setCurrentIndex(-1);
    ui->boxFiltroData->setCurrentIndex(0);

    ui->radioGastos->setAutoExclusive(false);
    ui->radioGastos->setChecked(false);
    ui->radioGastos->setAutoExclusive(true);

    ui->radioIngresos->setAutoExclusive(false);
    ui->radioIngresos->setChecked(false);
    ui->radioIngresos->setAutoExclusive(true);

    SetFiltroCuentas();

    ComprobarFiltros();


}

/////////////////////////////////////////////////////////////////////
/// COMPROBAR FILTROS SELECCIONADOS
///
void MainWindow::ComprobarFiltros()
{

    QString cuenta = ui->comboBoxCuentas->currentText();

    QString tipoMov = "";


    if(ui->radioGastos->isChecked())
        tipoMov = "gasto";

    else if(ui->radioIngresos->isChecked())
        tipoMov = "ingreso";


    QString tiempo = ui->boxFiltroData->currentText();

    QString filtroTiempo;

    QSqlQuery q;//para el ssentencia sum del dinero


    //si hay algo puesto en el filtro tiempo
    if(tiempo != NULL){

        //se coje la fecha actual
                QDate now = QDate::currentDate();

                QString mesActual, mesAnt, mesAntAnt;

                int m = now.month();
                int m2 = m-1;//anterior mes
                int m3 = m-2;//anterior del anterior

                if(m<10)
                     mesActual = "0" + QString::number(m);
                else
                     mesActual = QString::number(m);

                if(m2<10)
                     mesAnt = "0" + QString::number(m2);//mes anterior
                 else
                     mesAnt = QString::number(m2);//mes anterior
                if(m3<10)
                    mesAntAnt = "0" + QString::number(m3);//mes ante ant
                 else
                     mesAntAnt = QString::number(m3);//mes ante ant


                int y = now.year();//año
                QString year = QString::number(y);

                if(tiempo == QString::fromUtf8("Origen aplicación"))
                    filtroTiempo = "fecha like '%'" ;
                else if(tiempo == QString::fromUtf8("Último año"))
                    filtroTiempo = "fecha like '__/__/"+year+"%'";
                else if(tiempo == QString::fromUtf8("Últimos tres meses"))
                    filtroTiempo = "fecha like '__/" + mesActual + "/" + year + "%'"
                                               " or fecha like '__/"+ mesAnt + "/" + year + "%'"
                                               " or fecha like '__/" + mesAntAnt + "/" + year + "%'";
                else if(tiempo == QString::fromUtf8("Último mes"))
                    filtroTiempo = "fecha like '__/" + mesActual +"/" + year + "%'";

    }


    //Combinaciones 8 -> 2^3 (cuenta,tipo,fecha)

    // 0 0 0
    if(cuenta == NULL && tipoMov == NULL && tiempo == NULL){

        modeloTablaMov->setFilter("");

        q.prepare("select round(sum(importe),2)"
                     " from VistaMovimientos");

    // 0 0 1
    }else if(cuenta == NULL && tipoMov == NULL && tiempo != NULL){

         modeloTablaMov->setFilter(filtroTiempo);

         q.prepare("select round(sum(importe),2)"
                      " from VistaMovimientos where "+filtroTiempo );


    //0 1 0
    }else if(cuenta == NULL && tipoMov != NULL && tiempo == NULL){

        QString filtroFinal = "tipo = '" + tipoMov + "'";
        modeloTablaMov->setFilter(filtroFinal);

        q.prepare("select round(sum(importe),2)"
                     " from VistaMovimientos where "+filtroFinal);


    //0 1 1
    }else if(cuenta == NULL && tipoMov != NULL && tiempo != NULL){

         QString filtroFinal = "tipo = '" + tipoMov + "' and " + filtroTiempo;
         modeloTablaMov->setFilter(filtroFinal);


         q.prepare("select round(sum(importe),2)"
                      " from VistaMovimientos where "+filtroFinal);



    //1 0 0
    }else if(cuenta != NULL && tipoMov == NULL && tiempo == NULL){

        QString filtroFinal = "cuenta = '" + cuenta + "'";
        modeloTablaMov->setFilter(filtroFinal);


        q.prepare("select round(sum(importe),2)"
                     " from VistaMovimientos where "+filtroFinal);


    // 1 0 1
    }else if(cuenta != NULL && tipoMov == NULL && tiempo != NULL){

        QString filtroFinal = "cuenta = '" + cuenta + "' and " + filtroTiempo;
        modeloTablaMov->setFilter(filtroFinal);


        q.prepare("select round(sum(importe),2)"
                     " from VistaMovimientos where "+filtroFinal);


    //1 1 0
    }else if(cuenta != NULL && tipoMov != NULL && tiempo == NULL){

        QString filtroFinal = "tipo = '" + tipoMov + "' and cuenta = '" + cuenta + "'";
        modeloTablaMov->setFilter(filtroFinal);


        q.prepare("select round(sum(importe),2)"
                     " from VistaMovimientos where "+filtroFinal);

    // 1 1 1
    }else if(cuenta != NULL && tipoMov != NULL && tiempo != NULL){

        QString filtroFinal = "tipo = '" + tipoMov + "' and cuenta = '" + cuenta + "' and " + filtroTiempo +"";
        modeloTablaMov->setFilter(filtroFinal);


        q.prepare("select round(sum(importe),2)"
                     " from VistaMovimientos where "+filtroFinal);

    }

    //EJECUTAR LA SENTENCIA PARA SUMAR EL DINERO FILTRADO
    if(!q.exec())
        qDebug() << q.lastError().text() << q.lastQuery() << endl;
    else
       qDebug() <<  q.lastQuery() << endl;

    double total = 0;
    while(q.next()){
        total = q.value(0).toDouble();
    }

    ui->totalPasta->setText(QString::number(total)+QString::fromUtf8("€"));


}
//////////////////////////////////////////////////////////////////////////////


////////////////COMBOBOX CUENTAS////////////////////////////////////////////////////////////
void MainWindow::SetFiltroCuentas()
{
    modeloBoxCuentas = new QSqlQueryModel(this);
    modeloBoxCuentas->setQuery("select nombreCuenta from cuentas");
    ui->comboBoxCuentas->setModel(modeloBoxCuentas);
    ui->comboBoxCuentas->setCurrentIndex(-1);
}
void MainWindow::SetFiltroCuentas2()
{
    modeloBoxCuentas = new QSqlQueryModel(this);
    modeloBoxCuentas->setQuery("select nombreCuenta from cuentas");
    ui->tabCuentasBox->setModel(modeloBoxCuentas);
    ui->tabCuentasBox->setCurrentIndex(-1);

}
//actualizar
void MainWindow::on_pushButton_clicked()
{
    SetFiltroCuentas();
    SetFiltroCuentas2();
}
/////////////////////////////////////////////////////////////////////////////

////////////ABRIR DIALOGOS//////////////////////////////////////////////////////////////////
//Abrir dialogo nueva cuenta
void MainWindow::on_nuevaCuenta_clicked()
{
    formCuenta->exec();
    actualizarInfoCuentas();
}

//Abrir dialogo nuevo movimiento
void MainWindow::on_nuevoMov_clicked()
{
    formMov->exec();
    CrearFormulariosEditar();
    on_resetMov_clicked();
}
//modificar mov
void MainWindow::on_modificarMov_clicked()
{
    formEditMov->exec();
    actualizarInfoMov();
    on_resetMov_clicked();
}
//borrar Mov
void MainWindow::on_borrarMov_clicked()
{
    formEditMov->exec();
    actualizarInfoMov();
    on_resetMov_clicked();

}

////////////////////////////////////////////////
/// MOVIMIENTOS PROGRAMADOS
///

void MainWindow::on_nuevoMov_3_clicked()
{
    formMov->exec();
    CrearFormulariosEditar();
    on_resetMov_clicked();
}

void MainWindow::on_modificarMov_3_clicked()
{
    formEditMov->exec();
    actualizarInfoMov();
    on_resetMov_clicked();
}

void MainWindow::on_borrarMov_3_clicked()
{
    formEditMov->exec();
    actualizarInfoMov();
    on_resetMov_clicked();
}

//////////////////////////////////////////////////
//Abrir dialogo categ
void MainWindow::on_nuevaCategoria_clicked()
{
    CrearFormulariosEditar();
    formCat->exec();

}
//Mod categorias
void MainWindow::on_modificarCat_clicked()
{
    CrearFormulariosEditar();
    formEditCat->exec();
    actualizarInfoCateg();
    actualizarInfoMov();
}
//borrar categ
void MainWindow::on_borrarCateg_clicked()
{
    CrearFormulariosEditar();
    formEditCat->exec();
    actualizarInfoCateg();
    actualizarInfoMov();
}
////////////////////////////////////////////////////////////////////////////////

///////////BORRADO DE DATOS CUENTA///////////////////////////////////////////////


void MainWindow::on_borrarCuenta_clicked()
{

    int fila = ui->tablaCuentas->currentIndex().row();

    QString dato = ui->tablaCuentas->model()->data(ui->tablaCuentas->model()->index(fila,0)).toString();

    QSqlQuery q;

    //comprobar que no haya movimientos en la cuenta
    q.exec("select * from movimientos where cuentaId = '" + dato + "'");

    int cont = 0;

    while(q.next())
            cont ++;

    if(cont != 0){//si se a encontrado algun registro
        QMessageBox msgBox;
        msgBox.setText("La cuenta seleccionada contiene movimientos, no se borrara");
        msgBox.exec();
    }else{
        //se borra
        modeloTablaCuentas->removeRow(fila);
        //se actualiza
        actualizarInfoCuentas();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::CrearFormulariosEditar(){
    formEditMov = new editarMovimientos();
    formEditCat = new editarCategorias();
}


/////////////////////SUBCATEGORIAS///////////////////////////////////////////////////////////

void MainWindow::on_nuevaCategoria_3_clicked()
{
    on_nuevaCategoria_clicked();
}


void MainWindow::on_borrarCateg_3_clicked()
{
    on_borrarCateg_clicked();
}

void MainWindow::on_modificarCat_3_clicked()
{
   on_borrarCateg_clicked();
}

void MainWindow::on_nuevaCategoria_4_clicked()
{
    on_nuevaCategoria_clicked();
}

void MainWindow::on_modificarCat_4_clicked()
{
   on_borrarCateg_clicked();
}

void MainWindow::on_borrarCateg_4_clicked()
{
    on_borrarCateg_clicked();
}

/////////////////////////////////////////////////////
/// Actualizar line text cuenta selecionada tab cuentas
///
void MainWindow::actualizarDineroTotalCuenta(QString filtro)
{
    QSqlQuery q;
    double total;
    QString filtroFinal = "cuenta = '" + filtro + "'";


    q.prepare("select round(sum(importe),2)"
                 " from VistaMovimientos where "+filtroFinal);

    if(!q.exec())
        qDebug() << "Error seleccionar cuenta." << endl;


    while(q.next()){
        total = q.value(0).toDouble();
    }

    ui->tabCuentasTotal->setText(QString::number(total)+QString::fromUtf8("€"));


}
//tab cuentas
void MainWindow::on_dineroGlobal_clicked()
{
    QSqlQuery q;
    double total;

    q.prepare("select round(sum(importe),2)"
                 " from VistaMovimientos ");

    if(!q.exec())
        qDebug() << "Error seleccionar cuenta." << endl;


    while(q.next()){
        total = q.value(0).toDouble();
    }

    ui->tabCuentasTotal->setText(QString::number(total)+QString::fromUtf8("€"));

}
////////////////////////////////////////////////////////////////////////////
/// GENERAR PDF
///
void MainWindow::on_generatePdf_clicked()
{


     int rowCount = ui->tablaMov->model()->rowCount();
     int columnCount = ui->tablaMov->model()->columnCount();

    QPrinter printer;
    QPainter painter;

        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("movimientos.pdf");


        if (! painter.begin(&printer)) { // failed to open file
            qWarning("failed to open file, is it writable?");
        }

        //cordenadas pdf x
        int des = 50, tip = 250, imp = 330, categ = 450, cuenta = 550, fecha = 620;

        //titulo de las columnas
        painter.drawText(des, 20, "DESCRIPCIÓN");
        painter.drawText(tip, 20, "TIPO");
        painter.drawText(imp, 20, "IMPORTE");
        painter.drawText(categ, 20, "CATEGORÍA");
        painter.drawText(cuenta, 20, "CUENTA");
        painter.drawText(fecha, 20, "FECHA");

        //cordenadas pdf y
        int y = 50;

        int column;

        //se recorre la tabla
        for (int row = 0; row < rowCount; row++) {
               for ( column = 0; column < columnCount; column++) {
                   if (!ui->tablaMov->isColumnHidden(column)) {
                       QString dato = ui->tablaMov->model()->data(ui->tablaMov->model()->index(row, column)).toString().simplified();

                       if(column == 0)
                          painter.drawText(des, y, dato);
                       if(column == 1)
                          painter.drawText(tip, y, dato);
                       if(column == 2)
                          painter.drawText(imp, y, dato);
                       if(column == 3)
                          painter.drawText(categ, y, dato);
                       if(column == 4)
                          painter.drawText(cuenta, y, dato);
                       if(column == 5)
                          painter.drawText(fecha, y, dato);

                      }
               }

               y = y + 20;//se suma 20 pos para la fila siguinte

           }

        QString total = ui->totalPasta->text();

        painter.drawText(50, y + 50, "SUMA TOTAL: " + total);

        painter.end();

        QMessageBox msgBox;
        msgBox.setText("Pdf creado con los movimientos actuales de la tabla");
        msgBox.exec();

        //abrir luego el pdf

        QFileInfo checkFile("movimientos.pdf");

            if (checkFile.exists() && checkFile.isFile()) {
               QDesktopServices::openUrl(QUrl("movimientos.pdf"));
            } else {
                QMessageBox msgBox;
                msgBox.setText("El pdf no existe");
                msgBox.exec();
            }

}
/////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////
// COMPROBAR PERIOCIDAD MOVIMIENTOS
///////////

void MainWindow::ComprobarPeriocidad()
{

    QDate now = QDate::currentDate();
    QString year, mProg, dProg, yProg;
    int mesEnteroActual, diaEnteroActual;
    int insertado = 0;

    QSqlQuery queryMov, query;

    mesEnteroActual = now.month();//se coje el mes actual

    diaEnteroActual = now.day(); //se coje el dia actual

    year = QString::number(now.year());//se coje el año actual

    queryMov.prepare("select * from movimientos");
        if(!queryMov.exec())
        qDebug() << queryMov.lastError().text() << endl;

    while(queryMov.next()){
        //cojer los dato de cada fila
        QString idMov = queryMov.value(0).toString();
        QString cuentaId = queryMov.value(1).toString();
        QString tipoMov = queryMov.value(2).toString();
        QString cateId = queryMov.value(3).toString();
        QString importe = queryMov.value(4).toString();
        QString descrip = queryMov.value(5).toString();
        QString dataProg = queryMov.value(7).toString();
        QString periocidad = queryMov.value(8).toString();

        if(!periocidad.isEmpty()){
                QDate date;
                std::string val_string = dataProg.toStdString();
                QString s = QString::fromStdString(val_string.substr(0, 19));
                s.replace(QRegExp("[/]"), "-");
                date = QDate::fromString(s,"dd-MM-yyyy");

                int mesEnteroProg = date.month();
                int diaEnteroProg = date.day();
                int yearEntero = date.year();


                yProg = QString::number(date.year());//se coje el año actual

                if(periocidad == QString::fromUtf8("Cada mes")){
                      //si el dia y el mes actual coinciden con el programado
                      if(diaEnteroActual == diaEnteroProg && mesEnteroActual == mesEnteroProg){
                            mesEnteroProg = mesEnteroProg + 1;//siguiente programacion
                            if(mesEnteroProg > 12) //si se ha pasado de 12 en el mes
                                mesEnteroProg = 1;
                            insertado = 1;
                      }

                }else if(periocidad == QString::fromUtf8("Cada dos meses")){
                    //si el dia y el mes actual coinciden con el programado
                    if(diaEnteroActual == diaEnteroProg && mesEnteroActual == mesEnteroProg){
                          mesEnteroProg = mesEnteroProg + 2;//siguiente programacion
                          if(mesEnteroProg == 13) //si se ha pasado de 12 en el mes
                              mesEnteroProg = 1;
                          if(mesEnteroProg == 14) //si se ha pasado de 12 en el mes
                              mesEnteroProg = 2;
                          insertado = 1;
                    }

                }else  if(periocidad == QString::fromUtf8("Cada año")){
                    //si el dia y el mes y el año coinciden con el programado
                    if(diaEnteroActual == diaEnteroProg && mesEnteroActual == mesEnteroProg
                            && year == yProg ){
                          yearEntero = yearEntero + 1;
                          insertado = 1;
                    }

                 }

                //si los meses o dias son menores a 10 se le pone un "0" delante
                if(mesEnteroProg<10)
                     mProg = "0" + QString::number(mesEnteroProg);//se coje el mes programado
                else
                     mProg =  QString::number(mesEnteroProg);//se coje el mes programado


                if(diaEnteroProg<10)
                     dProg = "0" + QString::number(diaEnteroProg);//se coje el dia programado
                else
                     dProg =  QString::number(diaEnteroProg);//se coje el dia programa

                yProg = QString::number(yearEntero);//nuevo year

                //cambiar el de la proxima programacion
                QString m1 = mProg.mid(0,1);
                QString m2 = mProg.mid(1,2);
                char ch = m1.at(0).toLatin1();
                char ch2 = m2.at(0).toLatin1();
                dataProg[3] = ch;
                dataProg[4] = ch2;

                //cambiar el year de la proxima programacion
                 QString y1, y2, y3, y4;
                 y1 = yProg.mid(0,1);
                 y2 = yProg.mid(1,2);
                 y3 = yProg.mid(2,3);
                 y4 = yProg.mid(3,4);
                 char c = y1.at(0).toLatin1();
                 char c2 = y2.at(0).toLatin1();
                 char c3 = y3.at(0).toLatin1();
                 char c4 = y4.at(0).toLatin1();
                 dataProg[6] = c;
                 dataProg[7] = c2;
                 dataProg[8] = c3;
                 dataProg[9] = c4;


                //si se ha cumplido alguna condicion anterior inserta un nuevo mov
                if(insertado == 1){

                    query.prepare("INSERT INTO movimientos(cuentaId,tipoMov,categId,importe,descripcion,data,dataProgramada,periocidad)"
                           "VALUES(:cuentaId,:tipoMov,:categId,:importe,:desc,strftime('%d/%m/%Y %H:%M:%S','now'),"
                              ":prog,:per)");

                    query.bindValue(":cuentaId",cuentaId);
                    query.bindValue(":tipoMov",tipoMov);
                    query.bindValue(":categId",cateId);
                    query.bindValue(":importe",importe);
                    query.bindValue(":desc",descrip);
                    query.bindValue(":prog",dataProg);
                    query.bindValue(":per",periocidad);

                   if(!query.exec())
                       qDebug() << query.lastError().text() << endl;
                   else{

                       QMessageBox msgBox;
                       msgBox.setText("Se insertado un movimiento id(" + idMov + ") programado");
                       msgBox.exec();

                   }


                   //pone la periocidad del mov leido a empty para no volverlo a leer-insertar
                   //si se va otra vez a comprobar su periocidad

                   query.prepare("update movimientos set periocidad = null where idMov = '"+ idMov + "'");

                   if(!query.exec())
                       qDebug() << query.lastError().text() << endl;


                }

                insertado = 0;

         }//fin periocidad.isempty


     }//fin while

}

