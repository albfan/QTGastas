#ifndef EDITARCATEGORIAS_H
#define EDITARCATEGORIAS_H

#include <QDialog>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlQuery>

namespace Ui {
class editarCategorias;
}

class editarCategorias : public QDialog
{
    Q_OBJECT

public:
    explicit editarCategorias(QWidget *parent = 0);
    ~editarCategorias();

private slots:
    void on_pushButton_clicked();

    void actualizarTabla();

    void on_borrarCateg_clicked();

private:
    Ui::editarCategorias *ui;

    QSqlTableModel *tabla;
};

#endif // EDITARCATEGORIAS_H
