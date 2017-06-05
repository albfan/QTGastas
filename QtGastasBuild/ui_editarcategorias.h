/********************************************************************************
** Form generated from reading UI file 'editarcategorias.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITARCATEGORIAS_H
#define UI_EDITARCATEGORIAS_H

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

class Ui_editarCategorias
{
public:
    QPushButton *pushButton;
    QPushButton *borrarCateg;
    QTableView *tablaCateg;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *editarCategorias)
    {
        if (editarCategorias->objectName().isEmpty())
            editarCategorias->setObjectName(QStringLiteral("editarCategorias"));
        editarCategorias->resize(413, 286);
        pushButton = new QPushButton(editarCategorias);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 230, 71, 27));
        borrarCateg = new QPushButton(editarCategorias);
        borrarCateg->setObjectName(QStringLiteral("borrarCateg"));
        borrarCateg->setGeometry(QRect(220, 150, 161, 51));
        tablaCateg = new QTableView(editarCategorias);
        tablaCateg->setObjectName(QStringLiteral("tablaCateg"));
        tablaCateg->setGeometry(QRect(20, 20, 161, 241));
        plainTextEdit = new QPlainTextEdit(editarCategorias);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(220, 30, 151, 101));
        plainTextEdit->setUndoRedoEnabled(true);
        plainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        retranslateUi(editarCategorias);

        QMetaObject::connectSlotsByName(editarCategorias);
    } // setupUi

    void retranslateUi(QDialog *editarCategorias)
    {
        editarCategorias->setWindowTitle(QApplication::translate("editarCategorias", "Editar Categorias", 0));
        pushButton->setText(QApplication::translate("editarCategorias", "Salir", 0));
        borrarCateg->setText(QApplication::translate("editarCategorias", "Eliminar Seleciconada", 0));
        plainTextEdit->setPlainText(QApplication::translate("editarCategorias", "Para modificar la categoria hacer doble click en la tabla de la izquierda.", 0));
    } // retranslateUi

};

namespace Ui {
    class editarCategorias: public Ui_editarCategorias {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITARCATEGORIAS_H
