/********************************************************************************
** Form generated from reading UI file 'editarmovimientos.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITARMOVIMIENTOS_H
#define UI_EDITARMOVIMIENTOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_editarMovimientos
{
public:
    QTableView *tablaMov;
    QPushButton *borrarMov;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *editarMovimientos)
    {
        if (editarMovimientos->objectName().isEmpty())
            editarMovimientos->setObjectName(QStringLiteral("editarMovimientos"));
        editarMovimientos->resize(595, 373);
        editarMovimientos->setLayoutDirection(Qt::LeftToRight);
        tablaMov = new QTableView(editarMovimientos);
        tablaMov->setObjectName(QStringLiteral("tablaMov"));
        tablaMov->setGeometry(QRect(30, 40, 541, 221));
        borrarMov = new QPushButton(editarMovimientos);
        borrarMov->setObjectName(QStringLiteral("borrarMov"));
        borrarMov->setGeometry(QRect(260, 290, 161, 51));
        plainTextEdit = new QPlainTextEdit(editarMovimientos);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(30, 280, 191, 81));
        plainTextEdit->setUndoRedoEnabled(true);
        plainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);
        pushButton = new QPushButton(editarMovimientos);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(470, 300, 99, 27));

        retranslateUi(editarMovimientos);

        QMetaObject::connectSlotsByName(editarMovimientos);
    } // setupUi

    void retranslateUi(QDialog *editarMovimientos)
    {
        editarMovimientos->setWindowTitle(QApplication::translate("editarMovimientos", "Editar Movimientos", 0));
        borrarMov->setText(QApplication::translate("editarMovimientos", "Eliminar Seleciconada", 0));
        plainTextEdit->setPlainText(QApplication::translate("editarMovimientos", "Para modificar el movimeinto hacer doble click en la tabla de arriba.", 0));
        pushButton->setText(QApplication::translate("editarMovimientos", "Salir", 0));
    } // retranslateUi

};

namespace Ui {
    class editarMovimientos: public Ui_editarMovimientos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITARMOVIMIENTOS_H
