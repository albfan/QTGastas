#ifndef NUEVACATEGORIA_H
#define NUEVACATEGORIA_H

#include <QDialog>
#include "qconsultor.h"

namespace Ui {
class NuevaCategoria;
}

class NuevaCategoria : public QDialog
{
    Q_OBJECT

public:
    explicit NuevaCategoria(QWidget *parent = 0);
    ~NuevaCategoria();

     void SetModelCateg(QSqlTableModel *m);
     void SetModelSubCateg(QSqlTableModel *m);
     void SetConsultor(QConsultor *c);

private slots:

     void on_anadirCateg_clicked();

     void on_anadirSub_clicked();

     void on_anadirSubSub_clicked();

     void on_pushButton_clicked();

private:
    Ui::NuevaCategoria *ui;
    QConsultor *consultorFormCuenta;
};

#endif // NUEVACATEGORIA_H
