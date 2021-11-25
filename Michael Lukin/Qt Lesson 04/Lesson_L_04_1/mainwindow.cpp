#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // максимум
    double x1 = 0, x2 = 0, x3 = 0;
    bool x1_ok = false, x2_ok = false, x3_ok = false;
    QString res_text = "";
    x1 = ui -> lineEdit -> text().toDouble(&x1_ok);
    x2 = ui -> lineEdit_2 -> text().toDouble(&x2_ok);
    x3 = ui -> lineEdit_3 -> text().toDouble(&x3_ok);

    if(x1_ok && x2_ok && x3_ok) {
        double max = x1;
        res_text = "x1 - максимум";
        if((x1 == x2) && (x2 == x3)) {
            res_text = "Ввели одинаковые значения.";
        } else {
            if (max < x2) {
                max = x2;
                res_text = "x2 - максимум";
            }
            if (max < x3) {
                max = x3;
                res_text = "x3 - максимум";
            }
        }
    } else {
        res_text = "Ввели некоррктные значения.";
    }
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Результат");
    msgBox.setText(res_text);
    msgBox.exec();

}


void MainWindow::on_pushButton_2_clicked()
{
    // закрыть
    close();
}

