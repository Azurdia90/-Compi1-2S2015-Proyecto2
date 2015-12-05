/********************************************************************************
** Form generated from reading UI file 'ventana_errores.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_ERRORES_H
#define UI_VENTANA_ERRORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ventana_errores
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *ventana_errores)
    {
        if (ventana_errores->objectName().isEmpty())
            ventana_errores->setObjectName(QStringLiteral("ventana_errores"));
        ventana_errores->resize(614, 278);
        tableWidget = new QTableWidget(ventana_errores);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 621, 281));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        retranslateUi(ventana_errores);

        QMetaObject::connectSlotsByName(ventana_errores);
    } // setupUi

    void retranslateUi(QWidget *ventana_errores)
    {
        ventana_errores->setWindowTitle(QApplication::translate("ventana_errores", "Tabla de Errores", 0));
    } // retranslateUi

};

namespace Ui {
    class ventana_errores: public Ui_ventana_errores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_ERRORES_H
