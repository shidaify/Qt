#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
//Teacher类 老师类
//Student类 学生类
//下课后，老师会触发一个信号，饿了，学生响应信号，请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建一个老师对象
    this->teacher = new Teacher(this);
    //创建一个学生对象
    this->student = new Student(this);
    //老师饿了学生请客的连接
//    connect(teacher,&Teacher::hungry,student,&Student::treat);
//    ClassIsOver();

    //连接带参数的信号和槽
    //指针->地址 函数指针->函数地址
    //void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    //void(Student:: *studentSlot)(QString) = &Student::treat;
    //connect(teacher,teacherSignal,student,studentSlot);
    //ClassIsOver();

    QPushButton *btn = new QPushButton("下课",this);
    btn->move(250,200);
    this->resize(600,400);
    //connect(btn,&QPushButton::clicked,this,&Widget::ClassIsOver);

    //无参信号和槽
    void(Teacher:: *teacherSignal2)() = &Teacher::hungry;
    void(Student:: *studentSlot2)() = &Student::treat;
    connect(teacher,teacherSignal2,student,studentSlot2);

    //信号连接信号
    connect(btn,&QPushButton::clicked,teacher,teacherSignal2);
    //断开
    //disconnect(teacher,teacherSignal2,student,studentSlot2);

    //一个信号可以连接多个槽函数
    connect(btn,&QPushButton::clicked,this,&QWidget::close);
    //信号和槽函数类型必须一一对应
    //信号的参数个数可以多于槽的个数的.
    //lambda表达式
    [btn](){
        btn->setText("aaa");
    }();
}

void Widget::ClassIsOver()
{
    //下课函数，调用后触发老师饿了。
    //emit teacher->hungry();//emit自定义触发需要使用
    emit teacher->hungry("宫保鸡丁");//emit会将参数传递,信号的参数和槽的参数类型要一致，但是数信号的参数个数要大于等于槽的。
}
Widget::~Widget()
{
    delete ui;
}

