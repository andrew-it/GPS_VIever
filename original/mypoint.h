#ifndef MYPOINT_H
#define MYPOINT_H

#include <QGraphicsItem>
#include <QtXml>
#include <QGraphicsSceneMouseEvent>
#include <QTime>
#include <QDate>

#include "mytrack.h"

class MyTrack;

class MyPoint : public QGraphicsItem
{

public:
    explicit MyPoint(MyTrack *t);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual QRectF boundingRect() const;
    void pushDataByString(QString);
    void pushTimeDataByString(QString);
    double getLongitude();
    double getLatitude();
    double getHeight();
    QString getDataInString(char);
    QString getTimeStringData();
    void setTimeStringData(QString s);
    void setDateByQDate(QDate d);
    void setTimeByQTime(QTime t);
    void setHeightBySpinBox(double d);
    void setLongitude(int i);
    void setLatitude(int i);
    void setColor(QColor c);
    void setDataType(QString s);
    QString getDataType();
    QTime getTime();
    QDate getDate();
    void setDateTimeByString();
    void convertDateTimeToString();
    void setConnect();
    void setName(QString str){name = str;}
    QString getName(){return name;}
    void setRadius(int r){m_height = r; m_width = r;}

    static int x_max;
    static int y_max;

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);


    MyTrack * getParent(){return parentTrack;}

protected:
    int m_height, m_width;
    double gxCoordLongitude, gxCoordLatitude, gxHeight;
    QString timeStringData, dataTypeString;
    QColor color;
    QTime time;
    QDate date;
    MyTrack * parentTrack;
    QString name;
};

class TrackPoint :public MyPoint
{
public:
    TrackPoint(MyTrack *t);

protected:
    TrackPoint * prevPoint;
    TrackPoint * nextPoint;
};

class SinglePoint : public MyPoint
{
public:
    SinglePoint(MyTrack *t);
    QString getDescriptionData(){return descriptionData;}
    void setDescriptionData(QString str){ descriptionData = str;}
protected:
    QString descriptionData;
};

#endif // MYPOINT_H
