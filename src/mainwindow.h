#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "nuevomovimiento.h"
#include "nuevacategoria.h"
#include "nuevacuenta.h"
#include "editarmovimientos.h"
#include "editarcategorias.h"

#include <QPrinter>
#include <QPainter>

#include <QDesktopServices>

#include "qconsultor.h"
#include <QMainWindow>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_nuevaCuenta_clicked();
    void on_borrarCuenta_clicked();

    void on_nuevoMov_clicked();
    void on_modificarMov_clicked();
    void on_borrarMov_clicked();

    void on_nuevoMov_3_clicked();
    void on_modificarMov_3_clicked();
    void on_borrarMov_3_clicked();

    void on_nuevaCategoria_clicked();
    void on_borrarCateg_clicked();
    void on_modificarCat_clicked();

    void actualizarInfoMov();
    void actualizarInfoCuentas();
    void actualizarInfoCateg();
    void actualizarInfoSubCateg();
    void actualizarInfoSubSubCateg();

    void on_resetMov_clicked();
    void CrearFormulariosEditar();

    void ComprobarFiltros();

    void on_nuevaCategoria_3_clicked();
    void on_modificarCat_3_clicked();
    void on_borrarCateg_3_clicked();
    void on_nuevaCategoria_4_clicked();
    void on_modificarCat_4_clicked();
    void on_borrarCateg_4_clicked();

    void actualizarDineroTotalCuenta(QString filtro);

    void on_dineroGlobal_clicked();

    void on_generatePdf_clicked();



    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    //formularios
    NuevoMovimiento *formMov;
    NuevaCategoria *formCat;
    NuevaCuenta *formCuenta;

    editarMovimientos *formEditMov;
    editarCategorias *formEditCat;

    // Consultor de la base de datos
    QConsultor *consultor;

    //QSqlQueryModel *modeloFiltro;
    QSqlTableModel *modeloTablaMov;
    QSqlTableModel *modeloTablaMovProg;
    QSqlTableModel *modeloTablaCuentas;
    QSqlTableModel *modeloTodasCateg;
    QSqlTableModel *modeloTablaCateg;
    QSqlTableModel *modeloTablaSubCateg;
    QSqlTableModel *modeloTablaSubSubCateg;

    QSqlQueryModel *modeloBoxCuentas;


    //configurar tablas
    void SetTablaMovimientos();
    void SetTablaCuentas();
    void SetTablaCategorias();
    void SetTablaSubCategorias();
    void SetTablaSubSubcategorias();

    void SetFiltroCuentas();
    void SetFiltroCuentas2();

    // Creación de ventanas
    void CreateFormularios();

    // Creación de conexiones
    void SetConexiones();


    //Comprobar periocidad movimientos por si toca insertar alguno
    void ComprobarPeriocidad();

};

#endif // MAINWINDOW_H
