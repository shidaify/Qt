#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include "mypushbutton.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *btn = new QPushButton;
    //创建第一个按钮
    btn->setParent(this);
    btn->setText("第一个按钮");
    btn->resize(100,20);
    //创建第二个按钮
    QPushButton *btn2 = new QPushButton("第二个按钮",this);
    //移动btn2按钮位置
    btn2->move(100,100);
    //重置窗口大小
    resize(600,400);
    //设置固定的窗口大小
    setFixedSize(600,400);
    //设置窗口标题
    setWindowTitle("第一个窗口");

    MypushButton *myBtn = new MypushButton;
    myBtn->setText("我自己的按钮");
    myBtn->resize(100,25);
    myBtn->move(200,0);
    myBtn->setParent(this);

    //需求，点击我自己的按钮关闭窗口。
    //参数1 信号的发送者 参数2 发送的信号(函数地址) 参数3 信号的接收者 信号4 槽函数(函数的地址)
    //connect(myBtn,&MypushButton::clicked,this,&MypushButton::close);
    connect(myBtn,&QPushButton::clicked,this,&QWidget::close);

}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug()<<"myWidget的析构调用";
    //虽然输出的是这一行先输出，但实际上是先析构自己的按钮。
    //因为这里先运行到这，输出后看子类有没有需要析构的，有的话去析构子类，直到子类全部析构完成，这里才算析构完成
}

