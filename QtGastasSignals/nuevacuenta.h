#ifndef NUEVACUENTA_H
#define NUEVACUENTA_H

#include <QDialog>
#include "qconsultor.h"

namespace Ui {
class NuevaCuenta;
}

class NuevaCuenta : public QDialog
{
    Q_OBJECT

public:
    explicit NuevaCuenta(QWidget *parent = 0);
    ~NuevaCuenta();

    void SetConsultor(QConsultor *c);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NuevaCuenta *ui;
    QConsultor *consultorFormCuenta;
};

#endif // NUEVACUENTA_H
