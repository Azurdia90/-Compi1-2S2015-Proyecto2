/********************************************************************************
** Form generated from reading UI file 'venatana_graficar.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENATANA_GRAFICAR_H
#define UI_VENATANA_GRAFICAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Venatana_graficar
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QDialog *Venatana_graficar)
    {
        if (Venatana_graficar->objectName().isEmpty())
            Venatana_graficar->setObjectName(QStringLiteral("Venatana_graficar"));
        Venatana_graficar->resize(1070, 530);
        graphicsView = new QGraphicsView(Venatana_graficar);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1081, 531));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);

        retranslateUi(Venatana_graficar);

        QMetaObject::connectSlotsByName(Venatana_graficar);
    } // setupUi

    void retranslateUi(QDialog *Venatana_graficar)
    {
        Venatana_graficar->setWindowTitle(QApplication::translate("Venatana_graficar", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class Venatana_graficar: public Ui_Venatana_graficar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENATANA_GRAFICAR_H
