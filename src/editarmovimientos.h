#ifndef EDITARMOVIMIENTOS_H
#define EDITARMOVIMIENTOS_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class editarMovimientos;
}

class editarMovimientos : public QDialog
{
    Q_OBJECT

public:
    explicit editarMovimientos(QWidget *parent = 0);
    ~editarMovimientos();

    void actualizarTabla();

private slots:
    void on_borrarMov_clicked();

    void on_pushButton_clicked();

private:
    Ui::editarMovimientos *ui;

    QSqlTableModel *tabla;
};

#endif // EDITARMOVIMIENTOS_H
