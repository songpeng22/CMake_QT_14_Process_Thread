#pragma once
#include <QThread>

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMutex>

#include <QThread>
 
class MyThread : public QThread
{
public:
    MyThread();
    void closeThread();
 
protected:
    virtual void run();
    virtual bool event(QEvent *event);
 
private:
    volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明
};

class Widget : public QWidget
{
    Q_OBJECT
 
public:
    Widget(QWidget *parent = 0);
    ~Widget();
    void createView();

private slots:
    void openThreadBtnSlot();
    void closeThreadBtnSlot();
    void finishedThreadBtnSlot();
//    void testBtnSlot();

 
private:
    QVBoxLayout *mainLayout;
    MyThread *thread1;
};



