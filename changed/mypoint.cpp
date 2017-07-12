#include <QPainter>

#include "mypoint.h"

int MyPoint::x_max = 0;
int MyPoint::y_max = 0;

MyPoint::MyPoint(MyTrack *t):
    m_height(1000), m_width(1000)
{
    setFlags(ItemIsSelectable | ItemIsMovable);
    color = Qt::green;
    parentTrack = t;
    dataTypeString = "MyPoint";
}

void MyPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::black);
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF MyPoint::boundingRect() const
{
    return QRectF(-m_width/2, -m_height/2,
                  m_width, m_height);
}

void MyPoint::pushDataByString(QString s)
{
    QString gxLong, gxLat, gxHei;
    for(int i=0; i<s.size(); ++i)
    {
        if(s[i] == '.') continue;
        if(i<10) gxLat.append(s[i]);
        else if(i<21 && i>10) gxLong.append(s[i]);
        else if(i>21 && i<s.size()) gxHei.append(s[i]);
    }
    while(gxHei.size() < 5)
        gxHei.append('0');
    this->gxCoordLatitude = gxLat.toDouble();
    this->gxCoordLongitude = gxLong.toDouble();
    this->gxHeight = gxHei.toDouble();
    //qDebug() << gxLat << gxLong << gxHei;
    //qDebug() << gxCoordLatitude << gxCoordLongitude << gxHeight;
}

void MyPoint::pushTimeDataByString(QString str)
{
    timeStringData = str;
}

double MyPoint::getLongitude() { return gxCoordLongitude;}

double MyPoint::getLatitude() {return gxCoordLatitude;}

double MyPoint::getHeight() { return gxHeight;}

QString MyPoint::getDataInString(char c = ' ')
{
    switch (c) {
    case ' ': c = ' '; break;
    case ',': c = ','; break;
    default: c = ' ';
        break;
    }
    QString tmp = "";
    tmp += QString::number((int)gxCoordLatitude).insert(2,'.');
    tmp += c;
    tmp += QString::number((int)gxCoordLongitude).insert(2,'.');
    tmp += c;
    QString str = QString::number(gxHeight*0.01);
    if(str.size() < 6)
    {
        if(str.size() == 3)
            str.append('.');
        while(str.size() < 6)
            str.append('0');
    }
    tmp += str;
    return tmp;
}

///////
QString MyPoint::getTimeStringData() { return timeStringData;}

void MyPoint::setTimeStringData(QString s){ timeStringData = s;}

void MyPoint::setDateByQDate(QDate d){ date = d;}

void MyPoint::setTimeByQTime(QTime t){ time = t;}

void MyPoint::setHeightBySpinBox(double d) {gxHeight = d;}

void MyPoint::setLongitude(int i){ gxCoordLongitude = i;}

void MyPoint::setLatitude(int i){ gxCoordLatitude = i;}

void MyPoint::setColor(QColor c){ color = c;}

void MyPoint::setDataType(QString s){dataTypeString = s;}

QString MyPoint::getDataType(){return dataTypeString;}

QTime MyPoint::getTime() { return time;}

QDate MyPoint::getDate() { return date;}
////////////

void MyPoint::setDateTimeByString()
{
    QString yyyy(""),mm(""),dd(""),hh(""),mi(""),ss("");
    for(int i = 0; i<4; ++i)
        yyyy.append(timeStringData[i]);
    for(int i = 5; i < 7; ++i)
        mm.append(timeStringData[i]);
    for(int i = 8; i < 10; ++i)
        dd.append(timeStringData[i]);
    for(int i = 11; i < 13; ++i)
        hh.append(timeStringData[i]);
    for(int i = 14; i < 16; ++i)
        mi.append(timeStringData[i]);
    for(int i = 17; i < 19; ++i)
        ss.append(timeStringData[i]);
    //qDebug() << yyyy << mm << dd << hh << mi << ss;
    time.setHMS(hh.toInt(),mi.toInt(),ss.toInt());
    date.setDate(yyyy.toInt(),mm.toInt(),dd.toInt());
    //qDebug() << date << time;
}

void MyPoint::convertDateTimeToString()
{
    QString str("");
    str += date.toString("yyyy-MM-dd");
    str += "T";
    str += time.toString();
    str += "z";
    timeStringData = str;
    //qDebug() << timeStringData;
}

void MyPoint::setConnect()
{

}

void MyPoint::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    gxCoordLongitude = (event->scenePos().x() + MyPoint::x_max);
    gxCoordLatitude = (event->scenePos().y() + MyPoint::y_max);
    this->setPos(event->scenePos().x(),event->scenePos().y());
    //qDebug() << gxCoordLongitude << gxCoordLatitude;
}



