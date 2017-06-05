/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tabMov;
    QTableView *tablaMov;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxCuentas;
    QPushButton *resetMov;
    QPushButton *nuevoMov;
    QPushButton *borrarMov;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *totalPasta;
    QPushButton *modificarMov;
    QLabel *label_3;
    QComboBox *boxFiltroData;
    QWidget *layoutWidget2;
    QFormLayout *formLayout;
    QRadioButton *radioGastos;
    QRadioButton *radioIngresos;
    QWidget *tab_3;
    QTableView *tablaMovProg;
    QPushButton *modificarMov_3;
    QPushButton *borrarMov_3;
    QPushButton *nuevoMov_3;
    QWidget *tabCateg;
    QTableView *tablaCuentas;
    QPushButton *nuevaCuenta;
    QPushButton *borrarCuenta;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox;
    QPushButton *dineroGlobal;
    QComboBox *tabCuentasBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *tabCuentasTotal;
    QPushButton *pushButton;
    QWidget *tab;
    QTableView *tablaCateg;
    QPushButton *nuevaCategoria;
    QPushButton *borrarCateg;
    QPushButton *modificarCat;
    QWidget *tabCuentas;
    QTableView *tablaSub;
    QPushButton *nuevaCategoria_3;
    QPushButton *modificarCat_3;
    QPushButton *borrarCateg_3;
    QWidget *tab_2;
    QTableView *tablaSubSub;
    QPushButton *nuevaCategoria_4;
    QPushButton *modificarCat_4;
    QPushButton *borrarCateg_4;
    QPushButton *generatePdf;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(698, 587);
        MainWindow->setInputMethodHints(Qt::ImhNone);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 50, 641, 411));
        tabMov = new QWidget();
        tabMov->setObjectName(QStringLiteral("tabMov"));
        tablaMov = new QTableView(tabMov);
        tablaMov->setObjectName(QStringLiteral("tablaMov"));
        tablaMov->setGeometry(QRect(10, 10, 621, 221));
        tablaMov->setEditTriggers(QAbstractItemView::NoEditTriggers);
        layoutWidget = new QWidget(tabMov);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 240, 223, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBoxCuentas = new QComboBox(layoutWidget);
        comboBoxCuentas->setObjectName(QStringLiteral("comboBoxCuentas"));

        horizontalLayout_2->addWidget(comboBoxCuentas);

        resetMov = new QPushButton(tabMov);
        resetMov->setObjectName(QStringLiteral("resetMov"));
        resetMov->setGeometry(QRect(500, 330, 121, 41));
        nuevoMov = new QPushButton(tabMov);
        nuevoMov->setObjectName(QStringLiteral("nuevoMov"));
        nuevoMov->setGeometry(QRect(20, 330, 141, 41));
        borrarMov = new QPushButton(tabMov);
        borrarMov->setObjectName(QStringLiteral("borrarMov"));
        borrarMov->setGeometry(QRect(340, 330, 141, 41));
        layoutWidget1 = new QWidget(tabMov);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(450, 280, 181, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        totalPasta = new QLineEdit(layoutWidget1);
        totalPasta->setObjectName(QStringLiteral("totalPasta"));
        totalPasta->setLayoutDirection(Qt::LeftToRight);
        totalPasta->setAutoFillBackground(false);
        totalPasta->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        totalPasta->setReadOnly(true);

        horizontalLayout->addWidget(totalPasta);

        modificarMov = new QPushButton(tabMov);
        modificarMov->setObjectName(QStringLiteral("modificarMov"));
        modificarMov->setGeometry(QRect(180, 330, 131, 41));
        label_3 = new QLabel(tabMov);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(300, 240, 108, 31));
        boxFiltroData = new QComboBox(tabMov);
        boxFiltroData->setObjectName(QStringLiteral("boxFiltroData"));
        boxFiltroData->setGeometry(QRect(414, 241, 171, 27));
        layoutWidget2 = new QWidget(tabMov);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(21, 281, 172, 28));
        formLayout = new QFormLayout(layoutWidget2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        radioGastos = new QRadioButton(layoutWidget2);
        radioGastos->setObjectName(QStringLiteral("radioGastos"));
        radioGastos->setChecked(false);
        radioGastos->setAutoExclusive(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, radioGastos);

        radioIngresos = new QRadioButton(layoutWidget2);
        radioIngresos->setObjectName(QStringLiteral("radioIngresos"));
        radioIngresos->setCheckable(true);
        radioIngresos->setChecked(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, radioIngresos);

        tabWidget->addTab(tabMov, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tablaMovProg = new QTableView(tab_3);
        tablaMovProg->setObjectName(QStringLiteral("tablaMovProg"));
        tablaMovProg->setGeometry(QRect(10, 10, 621, 251));
        tablaMovProg->setEditTriggers(QAbstractItemView::NoEditTriggers);
        modificarMov_3 = new QPushButton(tab_3);
        modificarMov_3->setObjectName(QStringLiteral("modificarMov_3"));
        modificarMov_3->setGeometry(QRect(250, 290, 131, 41));
        borrarMov_3 = new QPushButton(tab_3);
        borrarMov_3->setObjectName(QStringLiteral("borrarMov_3"));
        borrarMov_3->setGeometry(QRect(450, 290, 141, 41));
        nuevoMov_3 = new QPushButton(tab_3);
        nuevoMov_3->setObjectName(QStringLiteral("nuevoMov_3"));
        nuevoMov_3->setGeometry(QRect(40, 290, 141, 41));
        tabWidget->addTab(tab_3, QString());
        tabCateg = new QWidget();
        tabCateg->setObjectName(QStringLiteral("tabCateg"));
        tablaCuentas = new QTableView(tabCateg);
        tablaCuentas->setObjectName(QStringLiteral("tablaCuentas"));
        tablaCuentas->setGeometry(QRect(10, 10, 291, 351));
        nuevaCuenta = new QPushButton(tabCateg);
        nuevaCuenta->setObjectName(QStringLiteral("nuevaCuenta"));
        nuevaCuenta->setGeometry(QRect(400, 150, 161, 41));
        borrarCuenta = new QPushButton(tabCateg);
        borrarCuenta->setObjectName(QStringLiteral("borrarCuenta"));
        borrarCuenta->setGeometry(QRect(400, 90, 161, 41));
        plainTextEdit = new QPlainTextEdit(tabCateg);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(330, 20, 291, 61));
        plainTextEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        groupBox = new QGroupBox(tabCateg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(360, 210, 251, 141));
        dineroGlobal = new QPushButton(groupBox);
        dineroGlobal->setObjectName(QStringLiteral("dineroGlobal"));
        dineroGlobal->setGeometry(QRect(20, 60, 71, 27));
        tabCuentasBox = new QComboBox(groupBox);
        tabCuentasBox->setObjectName(QStringLiteral("tabCuentasBox"));
        tabCuentasBox->setGeometry(QRect(100, 60, 121, 27));
        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 110, 201, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        tabCuentasTotal = new QLineEdit(layoutWidget3);
        tabCuentasTotal->setObjectName(QStringLiteral("tabCuentasTotal"));
        tabCuentasTotal->setLayoutDirection(Qt::LeftToRight);
        tabCuentasTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabCuentasTotal->setReadOnly(true);

        horizontalLayout_3->addWidget(tabCuentasTotal);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 30, 81, 21));
        tabWidget->addTab(tabCateg, QString());
        groupBox->raise();
        tablaCuentas->raise();
        nuevaCuenta->raise();
        borrarCuenta->raise();
        plainTextEdit->raise();
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tablaCateg = new QTableView(tab);
        tablaCateg->setObjectName(QStringLiteral("tablaCateg"));
        tablaCateg->setGeometry(QRect(10, 10, 331, 351));
        tablaCateg->setEditTriggers(QAbstractItemView::NoEditTriggers);
        nuevaCategoria = new QPushButton(tab);
        nuevaCategoria->setObjectName(QStringLiteral("nuevaCategoria"));
        nuevaCategoria->setGeometry(QRect(390, 20, 161, 71));
        borrarCateg = new QPushButton(tab);
        borrarCateg->setObjectName(QStringLiteral("borrarCateg"));
        borrarCateg->setGeometry(QRect(390, 270, 161, 71));
        modificarCat = new QPushButton(tab);
        modificarCat->setObjectName(QStringLiteral("modificarCat"));
        modificarCat->setGeometry(QRect(390, 150, 161, 71));
        tabWidget->addTab(tab, QString());
        tabCuentas = new QWidget();
        tabCuentas->setObjectName(QStringLiteral("tabCuentas"));
        tablaSub = new QTableView(tabCuentas);
        tablaSub->setObjectName(QStringLiteral("tablaSub"));
        tablaSub->setGeometry(QRect(10, 10, 321, 361));
        tablaSub->setEditTriggers(QAbstractItemView::NoEditTriggers);
        nuevaCategoria_3 = new QPushButton(tabCuentas);
        nuevaCategoria_3->setObjectName(QStringLiteral("nuevaCategoria_3"));
        nuevaCategoria_3->setGeometry(QRect(400, 20, 161, 71));
        modificarCat_3 = new QPushButton(tabCuentas);
        modificarCat_3->setObjectName(QStringLiteral("modificarCat_3"));
        modificarCat_3->setGeometry(QRect(400, 140, 161, 71));
        borrarCateg_3 = new QPushButton(tabCuentas);
        borrarCateg_3->setObjectName(QStringLiteral("borrarCateg_3"));
        borrarCateg_3->setGeometry(QRect(400, 260, 161, 71));
        tabWidget->addTab(tabCuentas, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tablaSubSub = new QTableView(tab_2);
        tablaSubSub->setObjectName(QStringLiteral("tablaSubSub"));
        tablaSubSub->setGeometry(QRect(10, 10, 311, 351));
        tablaSubSub->setEditTriggers(QAbstractItemView::NoEditTriggers);
        nuevaCategoria_4 = new QPushButton(tab_2);
        nuevaCategoria_4->setObjectName(QStringLiteral("nuevaCategoria_4"));
        nuevaCategoria_4->setGeometry(QRect(390, 20, 161, 71));
        modificarCat_4 = new QPushButton(tab_2);
        modificarCat_4->setObjectName(QStringLiteral("modificarCat_4"));
        modificarCat_4->setGeometry(QRect(390, 140, 161, 71));
        borrarCateg_4 = new QPushButton(tab_2);
        borrarCateg_4->setObjectName(QStringLiteral("borrarCateg_4"));
        borrarCateg_4->setGeometry(QRect(390, 270, 161, 71));
        tabWidget->addTab(tab_2, QString());
        generatePdf = new QPushButton(centralWidget);
        generatePdf->setObjectName(QStringLiteral("generatePdf"));
        generatePdf->setGeometry(QRect(230, 470, 281, 61));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 698, 29));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QtGastas", 0));
        label_2->setText(QApplication::translate("MainWindow", "Selecionar Cuenta: ", 0));
        resetMov->setText(QApplication::translate("MainWindow", "Reset/Actualizar", 0));
        nuevoMov->setText(QApplication::translate("MainWindow", "Nuevo", 0));
        borrarMov->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        label->setText(QApplication::translate("MainWindow", "Total dinero:", 0));
        totalPasta->setText(QApplication::translate("MainWindow", "0", 0));
        modificarMov->setText(QApplication::translate("MainWindow", "Modificar", 0));
        label_3->setText(QApplication::translate("MainWindow", "Filtrar Por Data:", 0));
        boxFiltroData->clear();
        boxFiltroData->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Origen aplicaci\303\263n", 0)
         << QApplication::translate("MainWindow", "\303\232ltimo a\303\261o", 0)
         << QApplication::translate("MainWindow", "\303\232ltimos tres meses", 0)
         << QApplication::translate("MainWindow", "\303\232ltimo mes", 0)
        );
        radioGastos->setText(QApplication::translate("MainWindow", "Gastos", 0));
        radioIngresos->setText(QApplication::translate("MainWindow", "Ingresos", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMov), QApplication::translate("MainWindow", "Movimientos", 0));
        modificarMov_3->setText(QApplication::translate("MainWindow", "Modificar", 0));
        borrarMov_3->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        nuevoMov_3->setText(QApplication::translate("MainWindow", "Nuevo", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Mov. Prog.", 0));
        nuevaCuenta->setText(QApplication::translate("MainWindow", "Nueva", 0));
        borrarCuenta->setText(QApplication::translate("MainWindow", "Eliminar Seleciconada", 0));
        plainTextEdit->setPlainText(QApplication::translate("MainWindow", "Para modificar la cuenta hacer doble click en la tabla izquerda.", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Seleccionar Cuenta", 0));
        dineroGlobal->setText(QApplication::translate("MainWindow", "TODAS", 0));
        label_4->setText(QApplication::translate("MainWindow", "Total dinero:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Actualizar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabCateg), QApplication::translate("MainWindow", " Cuentas", 0));
        nuevaCategoria->setText(QApplication::translate("MainWindow", "Nueva", 0));
        borrarCateg->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        modificarCat->setText(QApplication::translate("MainWindow", "Modificar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Categorias", 0));
        nuevaCategoria_3->setText(QApplication::translate("MainWindow", "Nueva", 0));
        modificarCat_3->setText(QApplication::translate("MainWindow", "Modificar", 0));
        borrarCateg_3->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabCuentas), QApplication::translate("MainWindow", "SubCategorias", 0));
        nuevaCategoria_4->setText(QApplication::translate("MainWindow", "Nueva", 0));
        modificarCat_4->setText(QApplication::translate("MainWindow", "Modificar", 0));
        borrarCateg_4->setText(QApplication::translate("MainWindow", "Eliminar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "(Sub)SubCategorias", 0));
        generatePdf->setText(QApplication::translate("MainWindow", "Generar PDF Movimientos Actuales", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
