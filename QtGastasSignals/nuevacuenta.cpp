#include "nuevacuenta.h"
#include "ui_nuevacuenta.h"

NuevaCuenta::NuevaCuenta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NuevaCuenta)
{
    ui->setupUi(this);
    ui->limite->setValidator( new QDoubleValidator(0, 10, 2, this));
    ui->ingresoIni->setValidator( new QDoubleValidator(0, 10, 2, this));
    ui->limite->setMaxLength(5);
    ui->ingresoIni->setMaxLength(5);
    ui->nombre->setMaxLength(10);
}

NuevaCuenta::~NuevaCuenta()
{
    delete ui;
}

void NuevaCuenta::SetConsultor(QConsultor *c)
{
    consultorFormCuenta = c;
}

void NuevaCuenta::on_buttonBox_accepted()
{

    //comprobar que se han ingresado todos los datos
    if(ui->nombre->text().isEmpty()
       || ui->limite->text().isEmpty()
       || ui->ingresoIni->text().isEmpty()){

        QMessageBox msgBox;

        msgBox.setText("Falta algun campo por rellenar");
        msgBox.exec();

    }else{

           consultorFormCuenta->NuevaCuenta(ui->nombre->text(),ui->limite->text(),ui->ingresoIni->text());
           ui->nombre->clear();
           ui->limite->clear();
           ui->ingresoIni->clear();
   }

}

void NuevaCuenta::on_buttonBox_rejected()
{
    ui->nombre->clear();
    ui->limite->clear();
    ui->ingresoIni->clear();
}
