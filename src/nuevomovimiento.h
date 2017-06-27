#ifndef NUEVOMOVIMIENTO_H
#define NUEVOMOVIMIENTO_H

#include <QDialog>
#include "qconsultor.h"

namespace Ui {
class NuevoMovimiento;
}

class NuevoMovimiento : public QDialog
{
    Q_OBJECT

public:
    explicit NuevoMovimiento(QWidget *parent = 0);
    ~NuevoMovimiento();

    void SetModelCateg(QSqlTableModel *m);
    void SetModelCuentas(QSqlTableModel *m);
    void SetConsultor(QConsultor *c);

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::NuevoMovimiento *ui;
    QConsultor *consultorMov;
};

#endif // NUEVOMOVIMIENTO_H
