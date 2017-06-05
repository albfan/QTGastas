/********************************************************************************
** Form generated from reading UI file 'nuevacategoria.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUEVACATEGORIA_H
#define UI_NUEVACATEGORIA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NuevaCategoria
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout_2;
    QLineEdit *newCateg;
    QLabel *label_5;
    QPushButton *anadirCateg;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *newCateg3;
    QWidget *layoutWidget_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QComboBox *boxSub;
    QPushButton *anadirSubSub;
    QGroupBox *groupBox_3;
    QPushButton *anadirSub;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *newCateg2;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *boxcateg;
    QPushButton *pushButton;

    void setupUi(QDialog *NuevaCategoria)
    {
        if (NuevaCategoria->objectName().isEmpty())
            NuevaCategoria->setObjectName(QStringLiteral("NuevaCategoria"));
        NuevaCategoria->resize(415, 500);
        groupBox = new QGroupBox(NuevaCategoria);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 291, 121));
        layoutWidget_6 = new QWidget(groupBox);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 30, 253, 52));
        gridLayout_2 = new QGridLayout(layoutWidget_6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        newCateg = new QLineEdit(layoutWidget_6);
        newCateg->setObjectName(QStringLiteral("newCateg"));

        gridLayout_2->addWidget(newCateg, 0, 1, 1, 1);

        label_5 = new QLabel(layoutWidget_6);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        anadirCateg = new QPushButton(groupBox);
        anadirCateg->setObjectName(QStringLiteral("anadirCateg"));
        anadirCateg->setGeometry(QRect(100, 90, 91, 21));
        groupBox_2 = new QGroupBox(NuevaCategoria);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(40, 300, 341, 131));
        layoutWidget_3 = new QWidget(groupBox_2);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 60, 301, 33));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        newCateg3 = new QLineEdit(layoutWidget_3);
        newCateg3->setObjectName(QStringLiteral("newCateg3"));

        horizontalLayout_4->addWidget(newCateg3);

        layoutWidget_7 = new QWidget(groupBox_2);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(10, 30, 262, 33));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_7);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_7);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_5->addWidget(label_7);

        boxSub = new QComboBox(layoutWidget_7);
        boxSub->setObjectName(QStringLiteral("boxSub"));

        horizontalLayout_5->addWidget(boxSub);

        anadirSubSub = new QPushButton(groupBox_2);
        anadirSubSub->setObjectName(QStringLiteral("anadirSubSub"));
        anadirSubSub->setGeometry(QRect(100, 100, 101, 21));
        groupBox_3 = new QGroupBox(NuevaCategoria);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 160, 341, 141));
        anadirSub = new QPushButton(groupBox_3);
        anadirSub->setObjectName(QStringLiteral("anadirSub"));
        anadirSub->setGeometry(QRect(100, 100, 101, 21));
        layoutWidget_5 = new QWidget(groupBox_3);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 60, 294, 33));
        gridLayout_3 = new QGridLayout(layoutWidget_5);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_5);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        newCateg2 = new QLineEdit(layoutWidget_5);
        newCateg2->setObjectName(QStringLiteral("newCateg2"));

        gridLayout_3->addWidget(newCateg2, 0, 1, 1, 1);

        layoutWidget_2 = new QWidget(groupBox_3);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 30, 301, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        boxcateg = new QComboBox(layoutWidget_2);
        boxcateg->setObjectName(QStringLiteral("boxcateg"));
        boxcateg->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_3->addWidget(boxcateg);

        pushButton = new QPushButton(NuevaCategoria);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 460, 99, 27));

        retranslateUi(NuevaCategoria);

        QMetaObject::connectSlotsByName(NuevaCategoria);
    } // setupUi

    void retranslateUi(QDialog *NuevaCategoria)
    {
        NuevaCategoria->setWindowTitle(QApplication::translate("NuevaCategoria", "Nueva Categoria", 0));
        groupBox->setTitle(QApplication::translate("NuevaCategoria", "Categoria", 0));
        label_5->setText(QApplication::translate("NuevaCategoria", "Nueva Categoria:", 0));
        anadirCateg->setText(QApplication::translate("NuevaCategoria", "A\303\261adir", 0));
        groupBox_2->setTitle(QApplication::translate("NuevaCategoria", "Sub SubCategoria", 0));
        label_6->setText(QApplication::translate("NuevaCategoria", "Nueva SubSubcategoria: ", 0));
        label_7->setText(QApplication::translate("NuevaCategoria", "Selecciona Subcategoria:", 0));
        anadirSubSub->setText(QApplication::translate("NuevaCategoria", "A\303\261adir", 0));
        groupBox_3->setTitle(QApplication::translate("NuevaCategoria", "SubCategoria", 0));
        anadirSub->setText(QApplication::translate("NuevaCategoria", "A\303\261adir", 0));
        label_3->setText(QApplication::translate("NuevaCategoria", "Nueva Subcategoria:   ", 0));
        label_4->setText(QApplication::translate("NuevaCategoria", "Selecciona Categoria:", 0));
        pushButton->setText(QApplication::translate("NuevaCategoria", "Salir", 0));
    } // retranslateUi

};

namespace Ui {
    class NuevaCategoria: public Ui_NuevaCategoria {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUEVACATEGORIA_H
