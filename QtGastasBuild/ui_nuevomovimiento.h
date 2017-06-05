/********************************************************************************
** Form generated from reading UI file 'nuevomovimiento.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVOMOVIMIENTO_H
#define UI_NUEVOMOVIMIENTO_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NuevoMovimiento
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboCateg;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboCuentas;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioGasto;
    QRadioButton *radioIngreso;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineImporte;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineDes;
    QGroupBox *groupBox;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QComboBox *comboPeriocidad;
    QLabel *label_5;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QDialog *NuevoMovimiento)
    {
        if (NuevoMovimiento->objectName().isEmpty())
            NuevoMovimiento->setObjectName(QStringLiteral("NuevoMovimiento"));
        NuevoMovimiento->resize(304, 415);
        buttonBox = new QDialogButtonBox(NuevoMovimiento);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(100, 350, 181, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(NuevoMovimiento);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 60, 166, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        comboCateg = new QComboBox(layoutWidget);
        comboCateg->setObjectName(QStringLiteral("comboCateg"));

        horizontalLayout->addWidget(comboCateg);

        layoutWidget1 = new QWidget(NuevoMovimiento);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(31, 21, 149, 29));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        comboCuentas = new QComboBox(layoutWidget1);
        comboCuentas->setObjectName(QStringLiteral("comboCuentas"));

        horizontalLayout_2->addWidget(comboCuentas);

        layoutWidget2 = new QWidget(NuevoMovimiento);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(30, 100, 157, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioGasto = new QRadioButton(layoutWidget2);
        radioGasto->setObjectName(QStringLiteral("radioGasto"));

        horizontalLayout_3->addWidget(radioGasto);

        radioIngreso = new QRadioButton(layoutWidget2);
        radioIngreso->setObjectName(QStringLiteral("radioIngreso"));

        horizontalLayout_3->addWidget(radioIngreso);

        layoutWidget3 = new QWidget(NuevoMovimiento);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(31, 131, 161, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lineImporte = new QLineEdit(layoutWidget3);
        lineImporte->setObjectName(QStringLiteral("lineImporte"));

        horizontalLayout_4->addWidget(lineImporte);

        layoutWidget4 = new QWidget(NuevoMovimiento);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 170, 234, 29));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lineDes = new QLineEdit(layoutWidget4);
        lineDes->setObjectName(QStringLiteral("lineDes"));

        horizontalLayout_5->addWidget(lineDes);

        groupBox = new QGroupBox(NuevoMovimiento);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 220, 321, 111));
        layoutWidget5 = new QWidget(groupBox);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(30, 70, 230, 29));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget5);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        comboPeriocidad = new QComboBox(layoutWidget5);
        comboPeriocidad->setObjectName(QStringLiteral("comboPeriocidad"));

        horizontalLayout_7->addWidget(comboPeriocidad);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 30, 103, 31));
        dateTimeEdit = new QDateTimeEdit(groupBox);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(130, 30, 131, 27));
        dateTimeEdit->setDateTime(QDateTime(QDate(2015, 1, 1), QTime(0, 0, 0)));
        dateTimeEdit->setDate(QDate(2015, 1, 1));
        dateTimeEdit->setMaximumDate(QDate(3000, 12, 28));
        dateTimeEdit->setMinimumDate(QDate(1788, 9, 14));
        dateTimeEdit->setCurrentSection(QDateTimeEdit::DaySection);
        dateTimeEdit->setCalendarPopup(true);
        groupBox->raise();
        buttonBox->raise();

        retranslateUi(NuevoMovimiento);
        QObject::connect(buttonBox, SIGNAL(accepted()), NuevoMovimiento, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NuevoMovimiento, SLOT(reject()));

        QMetaObject::connectSlotsByName(NuevoMovimiento);
    } // setupUi

    void retranslateUi(QDialog *NuevoMovimiento)
    {
        NuevoMovimiento->setWindowTitle(QApplication::translate("NuevoMovimiento", "Nuevo Movimiento", 0));
        label_2->setText(QApplication::translate("NuevoMovimiento", "Categorias", 0));
        label->setText(QApplication::translate("NuevoMovimiento", "Cuentas", 0));
        radioGasto->setText(QApplication::translate("NuevoMovimiento", "gasto", 0));
        radioIngreso->setText(QApplication::translate("NuevoMovimiento", "ingreso", 0));
        label_3->setText(QApplication::translate("NuevoMovimiento", "Importe", 0));
        label_4->setText(QApplication::translate("NuevoMovimiento", "Descripcion", 0));
        groupBox->setTitle(QApplication::translate("NuevoMovimiento", "Opcional", 0));
        label_6->setText(QApplication::translate("NuevoMovimiento", "Periocidad:", 0));
        comboPeriocidad->clear();
        comboPeriocidad->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("NuevoMovimiento", "Cada mes", 0)
         << QApplication::translate("NuevoMovimiento", "Cada dos meses", 0)
         << QApplication::translate("NuevoMovimiento", "Cada a\303\261o", 0)
        );
        label_5->setText(QApplication::translate("NuevoMovimiento", "Programaci\303\263n: ", 0));
        dateTimeEdit->setDisplayFormat(QApplication::translate("NuevoMovimiento", "dd/MM/yyyy", 0));
    } // retranslateUi

};

namespace Ui {
    class NuevoMovimiento: public Ui_NuevoMovimiento {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVOMOVIMIENTO_H
