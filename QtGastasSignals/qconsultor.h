#ifndef QCONSULTOR_H
#define QCONSULTOR_H

#include <QWidget>
#include <QtSql>
#include <QDateTime>
#include <QMessageBox>


namespace Ui {
class QConsultor;
}

class QConsultor : public QWidget
{
    Q_OBJECT

public:
    explicit QConsultor(QWidget *parent = 0);
    ~QConsultor();

    // Base de datos
    QSqlDatabase db;

    bool AbrirDB();         // Abrir Base de datos
    void CerrarDB();        // Cerrar Base de datos

    void NuevoMovimiento(QString nombreCuenta, QString tipoMov,
                         QString nombreCategoria, QString importe,
                         QString descripcion,QString fechaProg, QString periocidad);

    void NuevaCuenta(QString nombreCuenta, QString limiteCuenta, QString ingresoIni);

    void NuevaCategoria(QString nombreCateg);
    void NuevaSubcategoria(QString nombreSub, QString padre);
    void NuevaSubSubcategoria(QString nombreSub, QString padre);

signals:

    void tablaMovActualizada();
    void tablaCuentasActualizada();
    void tablaCategActualizada();
    void tablaCategSubActualizada();

private:
    Ui::QConsultor *ui;
};

#endif // QCONSULTOR_H
