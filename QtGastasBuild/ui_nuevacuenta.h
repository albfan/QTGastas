/********************************************************************************
** Form generated from reading UI file 'nuevacuenta.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVACUENTA_H
#define UI_NUEVACUENTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_NuevaCuenta
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *ingresoIni;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *limite;
    QLabel *label_3;
    QLineEdit *nombre;

    void setupUi(QDialog *NuevaCuenta)
    {
        if (NuevaCuenta->objectName().isEmpty())
            NuevaCuenta->setObjectName(QStringLiteral("NuevaCuenta"));
        NuevaCuenta->resize(400, 300);
        buttonBox = new QDialogButtonBox(NuevaCuenta);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(190, 240, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        ingresoIni = new QLineEdit(NuevaCuenta);
        ingresoIni->setObjectName(QStringLiteral("ingresoIni"));
        ingresoIni->setGeometry(QRect(190, 140, 113, 27));
        label = new QLabel(NuevaCuenta);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 60, 67, 17));
        label_2 = new QLabel(NuevaCuenta);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 100, 67, 17));
        limite = new QLineEdit(NuevaCuenta);
        limite->setObjectName(QStringLiteral("limite"));
        limite->setGeometry(QRect(190, 100, 113, 27));
        label_3 = new QLabel(NuevaCuenta);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 150, 101, 17));
        nombre = new QLineEdit(NuevaCuenta);
        nombre->setObjectName(QStringLiteral("nombre"));
        nombre->setGeometry(QRect(190, 60, 113, 27));

        retranslateUi(NuevaCuenta);
        QObject::connect(buttonBox, SIGNAL(accepted()), NuevaCuenta, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NuevaCuenta, SLOT(reject()));

        QMetaObject::connectSlotsByName(NuevaCuenta);
    } // setupUi

    void retranslateUi(QDialog *NuevaCuenta)
    {
        NuevaCuenta->setWindowTitle(QApplication::translate("NuevaCuenta", "Nueva Cuenta", 0));
        label->setText(QApplication::translate("NuevaCuenta", "Nombre", 0));
        label_2->setText(QApplication::translate("NuevaCuenta", "Limite", 0));
        label_3->setText(QApplication::translate("NuevaCuenta", "Ingreso Inicial", 0));
    } // retranslateUi

};

namespace Ui {
    class NuevaCuenta: public Ui_NuevaCuenta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVACUENTA_H
