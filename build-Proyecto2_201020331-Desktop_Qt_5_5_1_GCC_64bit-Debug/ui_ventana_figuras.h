/********************************************************************************
** Form generated from reading UI file 'ventana_figuras.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_FIGURAS_H
#define UI_VENTANA_FIGURAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ventana_figuras
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *Ventana_figuras)
    {
        if (Ventana_figuras->objectName().isEmpty())
            Ventana_figuras->setObjectName(QStringLiteral("Ventana_figuras"));
        Ventana_figuras->resize(1290, 426);
        tableWidget = new QTableWidget(Ventana_figuras);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 1301, 431));

        retranslateUi(Ventana_figuras);

        QMetaObject::connectSlotsByName(Ventana_figuras);
    } // setupUi

    void retranslateUi(QWidget *Ventana_figuras)
    {
        Ventana_figuras->setWindowTitle(QApplication::translate("Ventana_figuras", "Tabla de Figuras", 0));
    } // retranslateUi

};

namespace Ui {
    class Ventana_figuras: public Ui_Ventana_figuras {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_FIGURAS_H
