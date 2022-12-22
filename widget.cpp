#include "widget.h"
#include <QWidget>
#include <QPushButton>
#include <QRandomGenerator>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>

Widget::Widget()
{
    //声明控件
    layout = new QGridLayout(this);
    pushButton = new QPushButton("开始");
    label = new QLabel("预备备");

    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("border: 2px solid blue");
    label->setScaledContents(true);

    //设置字体大小
    QFont font;
    font.setPointSize(36);
    label->setFont(font);

    //添加控件至界面布局
    layout->addWidget(label, 0, 0, 1, 2);
    layout->addWidget(pushButton, 1, 0, 1, 2);

    //加载名单
    if(!loadtxt())
    {
        QMessageBox::information(this, "读取失败", "请将文件存放于当前程序运行目录，再重新启动程序");
    }
    else
    {
        QMessageBox::information(this, "读取成功", "读取名单成功，请点击继续");
    }

    //连接按钮事件
    connect(pushButton,&QPushButton::clicked,this,&Widget::on_pushButton_clicked);

    //循环显示名单
    connect(timer,&QTimer::timeout,this,&Widget::play_lists);
    timer->start(100);

}


Widget::~Widget()
{
    //释放内存
    delete(pushButton);
    delete(label);
    delete(layout);
}

void Widget::on_pushButton_clicked(bool checked)
{
    if(checked == true)
    {
        pushButton->setText("开始");
        caller();
        pushButton->setCheckable(false);
    }
    else
    {
        pushButton->setText("停止");
        pushButton->setCheckable(true);
    }
}

bool Widget::loadtxt(void)
{
    QFile file("namelists.txt");    
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    
    QTextStream nameFile(&file);

    while (!nameFile.atEnd())
    {
        namelists << nameFile.readLine();
    }

        return true;

}

void Widget::caller()
{
    if(namelists.isEmpty())
        return;

    qint32 i = QRandomGenerator::global()->bounded(0, namelists.size());
    label->setText(namelists[i]);
}

void Widget::play_lists()
{
    if(namelists.isEmpty())
        return;

    if(pushButton->isCheckable())
        label->setText(namelists[j++]);

    if(j >= namelists.size())
        j = 0;
}
