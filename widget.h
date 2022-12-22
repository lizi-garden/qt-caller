#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QList>
#include <QRandomGenerator>
#include <QTimer>

class QGridLayout;
class QPushButton;
class QLabel;

class Widget : public QWidget 
{
    public:
        Widget();
        ~Widget();

    private:
        //声明控件
        QGridLayout *layout;
        QPushButton *pushButton;
        QLabel *label;

        //名单读取
        bool loadtxt();
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
