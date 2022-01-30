#include "Widget.h"

#include <QDebug>
#include <QMutex>


MyThread::MyThread()
{
    isStop = false;
}
 
void MyThread::closeThread()
{
    isStop = true;
}

void MyThread::run()
{
    while (1)
    {
        if(isStop)
            return;

        qDebug() << tr("mythread QThread::currentThreadId()==") << QThread::currentThreadId();
        sleep(1);

        //
//        setEventDispatcher
        //enter event loop
//        exec();
        //exit event loop
//        exit();
    }
}

bool MyThread::event(QEvent *ev)
{
    qDebug() << "event..";

    // Make sure the rest of events are handled
    return true;
}


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    createView();
}

Widget::~Widget()
{
}
 
void Widget::createView()
{
    /*添加界面*/    
    QPushButton *openThreadBtn = new QPushButton(tr("open"));
    QPushButton *closeThreadBtn = new QPushButton(tr("close"));
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(openThreadBtn);
    mainLayout->addWidget(closeThreadBtn);
    mainLayout->addStretch();
    connect(openThreadBtn,SIGNAL(clicked(bool)),this,SLOT(openThreadBtnSlot()));
    connect(closeThreadBtn,SIGNAL(clicked(bool)),this,SLOT(closeThreadBtnSlot()));    

    /*线程初始化*/
    thread1 = new MyThread;
    connect(thread1,SIGNAL(finished()),this,SLOT(finishedThreadBtnSlot()));
}

void Widget::openThreadBtnSlot()
{
    /*开启一个线程*/    
    thread1->start();
    qDebug()<<"main thread id："<<QThread::currentThreadId();
}

void Widget::closeThreadBtnSlot()
{
    /*关闭多线程*/
    thread1->closeThread();
    qDebug() << "+wait 5s to until run returns" ;

    bool bRet = thread1->wait( 5000 );

    qDebug() << "-wait() return: " << bRet;
}

void Widget::finishedThreadBtnSlot()
{
    qDebug()<<tr("finished triggering signal");
}