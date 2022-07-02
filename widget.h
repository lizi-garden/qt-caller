#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QList>
#include <QRandomGenerator>
#include <QTimer>
#include <qapplication.h>
#include <qfont.h>
#include <qglobal.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <qlist.h>
#include <qnamespace.h>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qwindowdefs.h>

class Widget : public QWidget 
{
    public:
        Widget();
        ~Widget();

    private:
        //声明控件
        QGridLayout *layout = new QGridLayout(this);
        QPushButton *pushButton = new QPushButton("开始");
        QLabel *label = new QLabel("预备备");

        //名单读取
        bool loadtxt();
        qint8 num = 0;
        QList<QString> namelists;

        //点名
        void caller();
        QTimer *timer = new QTimer(this);
        qint8 j = 0;

    private slots:
        //按钮事件
        void on_pushButton_clicked(bool checked);

        //播放名单
        void play_lists();
};
