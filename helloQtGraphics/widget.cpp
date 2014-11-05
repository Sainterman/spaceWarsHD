#include "widget.h"

void Widget::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Up)
        pmap->moveBy(0,-20);
    if(event->key()==Qt::Key_Down)
        pmap->moveBy(0,20);
    if(event->key()==Qt::Key_Right)
        pmap->moveBy(20,0);
    if(event->key()==Qt::Key_Left)
        pmap->moveBy(-20,0);

    QString msj="posicion(" + QString::number(pmap->x())+", "+QString::number(pmap->y())+")";
    emit mensaje(msj);

    //Widget::keyPressEvent(event);
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFocusPolicy(Qt::ClickFocus);
    _scene= new QGraphicsScene(this);

     pmap =_scene->addPixmap(QPixmap("://nave.png"));
    _view= new QGraphicsView(_scene,this);

    _view->setFocusPolicy(Qt::NoFocus);

    QPushButton *btn= new QPushButton("dont Press this button",this);
    connect(btn,SIGNAL(clicked()),this,SLOT (btnClicked()));
    QLabel *lbl=new QLabel("Hola mundo",this);
    connect(this,SIGNAL(mensaje(QString)),lbl,SLOT(setText(QString)));

    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addWidget(lbl);
    mainLayout->addWidget(btn);
    mainLayout->addWidget(_view);


    this->setLayout(mainLayout);
}

Widget::~Widget()
{

}

void Widget::btnClicked()
{
    pmap->setRotation(pmap->rotation()+10);
}
