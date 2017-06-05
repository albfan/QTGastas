#include "nuevomovimiento.h"
#include "ui_nuevomovimiento.h"
#include <QDoubleValidator>

NuevoMovimiento::NuevoMovimiento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NuevoMovimiento)
{
    ui->setupUi(this);

    ui->lineImporte->setValidator( new QDoubleValidator(0, 10, 2, this));
    ui->lineImporte->setMaxLength(10);
    ui->lineDes->setMaxLength(15);
}

NuevoMovimiento::~NuevoMovimiento()
{
    delete ui;
}

void NuevoMovimiento::SetModelCateg(QSqlTableModel *m)
{
    ui->comboCateg->setModel(m);
    ui->comboCateg->setModelColumn(3);
    ui->comboCateg->setCurrentIndex(-1);
}

void NuevoMovimiento::SetModelCuentas(QSqlTableModel *m)
{
    ui->comboCuentas->setModel(m);
    ui->comboCuentas->setModelColumn(1);
    ui->comboCuentas->setCurrentIndex(-1);
}

void NuevoMovimiento::SetConsultor(QConsultor *c)
{
    consultorMov = c;
}



void NuevoMovimiento::on_buttonBox_accepted()
{
    QString nombreCuenta = ui->comboCuentas->currentText();
    QString nombreCategoria = ui->comboCateg->currentText();
    QString fechaProgramada = ui->dateTimeEdit->text();
    QString periocidad = ui->comboPeriocidad->currentText();

    QString importe = ui->lineImporte->text();

    QString tipoMov;
    if(ui->radioGasto->isChecked()){
        tipoMov = "gasto";
        importe = "-"+importe;
    }
    if(ui->radioIngreso->isChecked())
        tipoMov = "ingreso";

    QString descripcion = ui->lineDes->text();

    //validar sie se ha rellenado todo
    if(ui->comboCuentas->currentText().isEmpty()
            || ui->comboCateg->currentText().isEmpty()
            || (!ui->radioGasto->isChecked() && !ui->radioIngreso->isChecked())
            || ui->lineImporte->text().isEmpty()
            || ui->lineDes->text().isEmpty()){

        QMessageBox msgBox;

        msgBox.setText("Falta algun campo por rellenar");
        msgBox.exec();

    }
    else{

        //se crea una nueva consulta para insertar el nuevo movimento
        consultorMov->NuevoMovimiento(nombreCuenta,tipoMov,
                                      nombreCategoria,importe,
                                      descripcion, fechaProgramada, periocidad);

        ui->comboCuentas->setCurrentIndex(0);
        ui->comboCateg->setCurrentIndex(0);
        ui->lineDes->clear();
        ui->lineImporte->clear();

        ui->radioGasto->setAutoExclusive(false);
        ui->radioGasto->setChecked(false);
        ui->radioGasto->setAutoExclusive(true);

        ui->radioIngreso->setAutoExclusive(false);
        ui->radioIngreso->setChecked(false);
        ui->radioIngreso->setAutoExclusive(true);
    }

}

void NuevoMovimiento::on_buttonBox_rejected()
{
    ui->comboCuentas->setCurrentIndex(0);
    ui->comboCateg->setCurrentIndex(0);
    ui->lineDes->clear();
    ui->lineImporte->clear();

    ui->radioGasto->setAutoExclusive(false);
    ui->radioGasto->setChecked(false);
    ui->radioGasto->setAutoExclusive(true);

    ui->radioIngreso->setAutoExclusive(false);
    ui->radioIngreso->setChecked(false);
    ui->radioIngreso->setAutoExclusive(true);
}
