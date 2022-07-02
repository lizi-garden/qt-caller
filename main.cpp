#include <QWidget>
#include <QApplication>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget win;

    //设置窗口大小
    win.setMinimumSize(380,200);

    win.show();
    return app.exec();
}
