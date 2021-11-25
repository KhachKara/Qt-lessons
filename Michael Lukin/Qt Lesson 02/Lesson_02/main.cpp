#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    QFont font;
    font.setPointSize(14);

    QLabel label;
    label.setFont(font);
    label.setText("Hello World!");
    label.show();
    label.resize(400, 400);
    label.setAlignment(Qt::AlignCenter);
        return a.exec();
}
