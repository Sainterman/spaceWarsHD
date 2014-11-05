#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QKeyEvent>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT
   QGraphicsScene *_scene;

    QGraphicsView *_view;
    QGraphicsPixmapItem *pmap;
protected:
    virtual void keyPressEvent(QKeyEvent * event);


public:

    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void btnClicked();
signals:
    void mensaje(QString s);


};

#endif // WIDGET_H
