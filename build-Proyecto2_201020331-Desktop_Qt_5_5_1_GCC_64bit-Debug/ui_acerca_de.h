/********************************************************************************
** Form generated from reading UI file 'acerca_de.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACERCA_DE_H
#define UI_ACERCA_DE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Acerca_de
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Acerca_de)
    {
        if (Acerca_de->objectName().isEmpty())
            Acerca_de->setObjectName(QStringLiteral("Acerca_de"));
        Acerca_de->resize(400, 300);
        label = new QLabel(Acerca_de);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 50, 231, 111));
        pushButton = new QPushButton(Acerca_de);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 190, 80, 23));

        retranslateUi(Acerca_de);

        QMetaObject::connectSlotsByName(Acerca_de);
    } // setupUi

    void retranslateUi(QWidget *Acerca_de)
    {
        Acerca_de->setWindowTitle(QApplication::translate("Acerca_de", "Form", 0));
        label->setText(QApplication::translate("Acerca_de", "<html><head/><body><p>CRISTIAN ALEXANDER AZURDIA AJU</p><p>201020331</p><p>SEGUNDO SEMESTRE 2015</p></body></html>", 0));
        pushButton->setText(QApplication::translate("Acerca_de", "Cerrar", 0));
    } // retranslateUi

};

namespace Ui {
    class Acerca_de: public Ui_Acerca_de {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACERCA_DE_H
