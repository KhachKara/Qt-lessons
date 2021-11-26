#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    int min; // минимальное значение
    int indx_min; // индекс минимального значения
    int count; // счетчик вводимых чисел
    int positivs_count; // счетчик положительных чисел
    int negativs_count; // счетчик отрицательных чисел
};
#endif // MAINWINDOW_H
