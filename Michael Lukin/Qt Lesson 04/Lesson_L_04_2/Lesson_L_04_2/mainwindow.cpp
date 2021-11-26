#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // иницилдизация элементов главного окна

    ui->setupUi(this);

    // обнуление полей
    min = 0;
    indx_min = 0;
    count = 0;
    positivs_count = 0;
    negativs_count = 0;

    // создание валидатора
    QIntValidator *validator = new QIntValidator (-100, 1000, this);

    // привязка поля ввода и валидатора
    ui->lineEdit->setValidator(validator);

    // деактивация кнопки "Подтвердить"
    ui->pushButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // подтвердить

    // текущее значение
    int x = ui->lineEdit->text().toInt();

    ++ count;
    if(x > 0) ++ positivs_count;
    else if(x < 0) ++ negativs_count;

    if(min == 1) {
        min = x;
        indx_min = 1;
    } else if (x < min) {
        min = x;
        indx_min = count;
    }
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    // Завершить и вычислить
    QString res_text = "";

    res_text.append("номер минимума: " + QString::number(indx_min) + "\n");
    res_text.append("кол-во числе: " + QString::number(count) + "\n");
    res_text.append("положительных: " + QString::number(positivs_count) + "\n");
    res_text.append("отрицательных: " + QString::number(negativs_count));

    // вывод результатов
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Результат");
    msgBox.setText(res_text);
    msgBox.exec();

    // сброс счсиков
    count = 0;
    min = 0;
    indx_min = 0;

}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    // обработка изменения текста

    // активность кнопки зависит от валидности введёных даных
    bool enabled = ui->lineEdit->hasAcceptableInput();
    ui->pushButton->setEnabled(enabled);
}

