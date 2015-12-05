#ifndef ACERCA_DE_H
#define ACERCA_DE_H

#include <QWidget>

namespace Ui {
class Acerca_de;
}

class Acerca_de : public QWidget
{
    Q_OBJECT

public:
    explicit Acerca_de(QWidget *parent = 0);
    ~Acerca_de();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Acerca_de *ui;
};

#endif // ACERCA_DE_H
