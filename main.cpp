#include <QWidget>
#include <QApplication>
#include <qwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget win;
    win.show();
    return a.exec();
}
