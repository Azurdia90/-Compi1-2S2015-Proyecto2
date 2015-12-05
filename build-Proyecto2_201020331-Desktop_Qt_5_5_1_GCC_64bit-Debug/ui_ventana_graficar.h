/********************************************************************************
** Form generated from reading UI file 'ventana_graficar.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANA_GRAFICAR_H
#define UI_VENTANA_GRAFICAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ventana_graficar
{
public:

    void setupUi(QWidget *Ventana_graficar)
    {
        if (Ventana_graficar->objectName().isEmpty())
            Ventana_graficar->setObjectName(QStringLiteral("Ventana_graficar"));
        Ventana_graficar->resize(400, 300);

        retranslateUi(Ventana_graficar);

        QMetaObject::connectSlotsByName(Ventana_graficar);
    } // setupUi

    void retranslateUi(QWidget *Ventana_graficar)
    {
        Ventana_graficar->setWindowTitle(QApplication::translate("Ventana_graficar", "Figuras", 0));
    } // retranslateUi

};

namespace Ui {
    class Ventana_graficar: public Ui_Ventana_graficar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANA_GRAFICAR_H
