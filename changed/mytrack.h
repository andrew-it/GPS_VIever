#ifndef MYTRACK_H
#define MYTRACK_H


#include <QFile>
#include <QDebug>
#include <QStringList>
#include <QtXml>
#include <QTextStream>
#include <QObject>

#include "trackpoint.h"
#include "storage.h"
#include "field.h"

class MyPoint;
class field;

class MyTrack
{
public:
    MyTrack(field * f);
    MyTrack(QFile *, field *);
    ~MyTrack();

    QFile *getFile(int);
    bool createTrackByFile(QFile *file);
    void traverseNode(const QDomNode& node);
    Storage<MyPoint> * getStorage(){return &pointsList;}
    void setTrackPos();
    void setColorByHeight();
    void setColor(QColor);
    void saveInFile(QFile *f);
    void setDataType(QString s){dataTypeString = s;}
    QString getDataType(){return dataTypeString;}
    void computeMinMaxHeight();
    void updateAllTrack();
    double getMinHeight(){ return minHeight;}
    field * getParent(){return myParent;}

    QString getDescriptionData(){return descriptionData;}
    void setDescriptionData(QString str){ descriptionData = str;}

protected:
    field * myParent;
    Storage <MyPoint> pointsList;
    QFile *InputFile, *OutputFile;
    QStringList TrackInString, TimeInString;
    QDomDocument TrackInDom;
    double maxHeight, minHeight;
    QString dataTypeString;
    QString descriptionData;
};


#endif // MYTRACK_H
