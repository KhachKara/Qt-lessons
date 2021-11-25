#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
# include <QMessageBox>


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
    double x = 0.0, res = 0.0;
    bool f = false;
    QString res_text = "";

    x = ui->lineEdit->text().toDouble(&f);
    if(f) {
        res = pow(x, 5);
        res_text = "Ответ: " + QString::number(res);
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Результат");
        msgBox.setText(res_text);
        msgBox.exec();
    } else {
        res_text = "введён не корректный X";
        QMessageBox::warning(this, "Результат", res_text);
    }

}

