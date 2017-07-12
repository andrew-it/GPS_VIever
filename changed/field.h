#ifndef FIELD_H
#define FIELD_H

#include <QObject>
#include <QGraphicsScene>
#include <QVector>

#include "mytrack.h"
#include "mypoint.h"

class MyPoint;
class MyTrack;

class field : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit field(QObject *parent = 0);

    inline QVector<MyTrack *> *getTrackList(){return TrackList;}
    void addTrackToScene();
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    bool addTrackPoint;
    MyTrack * getCurrentTrack(){return currentTrack;}
    MyTrack *getNewTrack();
protected:
    QVector<MyTrack *> * TrackList;
    MyTrack * currentTrack;

signals:
    void putDataTypeInLabel(QString);
    void putHeightInSpinBox(double);
    void putTimeInTimeBox(QTime);
    void putDateInDateBox(QDate);
    void putLongitudeInLineEdit(QString);
    void putLatitudeInLineEdit(QString);
public slots:
    void setCurTrack(MyTrack *);

};



#endif // FIELD_H
