#include "widget.h"
#include <QDebug>
#include <qdebug.h>
#include <qpushbutton.h>
#include <qrandom.h>
#include <qtimer.h>
#include <qwidget.h>

Widget::Widget()
{
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
        qDebug() << "读取失败";
    else
        qDebug() << "读取成功";

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

    while (!nameFile.atEnd()) {
        namelists << nameFile.readLine();
        num++;
    }

    return true;
}

void Widget::caller()
{
    qint32 i = QRandomGenerator::global()->bounded(0, num);    
    label->setText(namelists[i]);
}

void Widget::play_lists()
{
    if(pushButton->isCheckable())
        label->setText(namelists[j++]);

    if(j >= num)
        j = 0;
}
