/********************************************************************************
** Form generated from reading UI file 'ventana_tabla.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_TABLA_H
#define UI_VENTANA_TABLA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ventana_tabla
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *Ventana_tabla)
    {
        if (Ventana_tabla->objectName().isEmpty())
            Ventana_tabla->setObjectName(QStringLiteral("Ventana_tabla"));
        Ventana_tabla->resize(751, 346);
        tableWidget = new QTableWidget(Ventana_tabla);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 751, 351));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        retranslateUi(Ventana_tabla);

        QMetaObject::connectSlotsByName(Ventana_tabla);
    } // setupUi

    void retranslateUi(QWidget *Ventana_tabla)
    {
        Ventana_tabla->setWindowTitle(QApplication::translate("Ventana_tabla", "Tabla de Simbolos", 0));
    } // retranslateUi

};

namespace Ui {
    class Ventana_tabla: public Ui_Ventana_tabla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_TABLA_H
