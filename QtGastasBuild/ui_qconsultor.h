/********************************************************************************
** Form generated from reading UI file 'qconsultor.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QCONSULTOR_H
#define UI_QCONSULTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QConsultor
{
public:

    void setupUi(QWidget *QConsultor)
    {
        if (QConsultor->objectName().isEmpty())
            QConsultor->setObjectName(QStringLiteral("QConsultor"));
        QConsultor->resize(400, 300);

        retranslateUi(QConsultor);

        QMetaObject::connectSlotsByName(QConsultor);
    } // setupUi

    void retranslateUi(QWidget *QConsultor)
    {
        QConsultor->setWindowTitle(QApplication::translate("QConsultor", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class QConsultor: public Ui_QConsultor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QCONSULTOR_H
