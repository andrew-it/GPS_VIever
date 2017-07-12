#include "field.h"


field::field(QObject *parent):
    QGraphicsScene(parent)
{
    TrackList = new QVector<MyTrack *>;
    addTrackPoint = false;
}



void field::addTrackToScene()
{
    for(int i = 0; i < TrackList->size(); i++)
    {
        currentTrack = TrackList->at(i);
        currentTrack->getStorage()->first();
        for(currentTrack->getStorage()->first();
            !currentTrack->getStorage()->eol();
            currentTrack->getStorage()->next())
        {
            addItem(currentTrack->getStorage()->getCurrentObject()->getData());
        }
    }

}

void field::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    MyPoint * point = dynamic_cast<TrackPoint*>(itemAt(event->scenePos(),QTransform()));
    if(dynamic_cast<TrackPoint*>(itemAt(event->scenePos(),QTransform())))
    {
        point = dynamic_cast<TrackPoint*>(itemAt(event->scenePos(),QTransform()));
        //qDebug() << "CLICK on SinglePoint";
    }
    if(dynamic_cast<SinglePoint*>(itemAt(event->scenePos(),QTransform())))
    {
        point = dynamic_cast<SinglePoint*>(itemAt(event->scenePos(),QTransform()));
        //qDebug() << "CLICK on SinglePoint";
    }
    //MyPoint * point = dynamic_cast<MyPoint*>(itemAt(event->scenePos(),QTransform()));// тут будут проблемы
    if(point != NULL)
    {
        setCurTrack(point->getParent());
        sendEvent(itemAt(event->scenePos(),QTransform()), event);
        emit this->putDataTypeInLabel(point->getDataType());
        emit this->putHeightInSpinBox(point->getHeight()/100);
        emit this->putDateInDateBox(point->getDate());
        emit this->putTimeInTimeBox(point->getTime());
        emit this->putLatitudeInLineEdit(QString::number((int)(point->getLatitude())));
        emit this->putLongitudeInLineEdit(QString::number((int)(point->getLongitude())));
        currentTrack->getStorage()->setCurrentObject(point);
        //qDebug() << TrackList->contains(currentTrack);
    }
    else
    {
        if(event->button() == Qt::LeftButton)
        {
            if(addTrackPoint == true && !currentTrack != NULL)
            {
                MyPoint *p = new TrackPoint(this->currentTrack);
                p->setPos(event->scenePos());
                p->setLatitude(event->scenePos().y()+MyPoint::y_max);
                p->setLongitude(event->scenePos().x()+MyPoint::x_max);
                p->setHeightBySpinBox(currentTrack->getMinHeight());
                currentTrack->getStorage()->insertAtBack(p);
                addTrackPoint = false;
                addItem(p);
                p->setConnect();
                qDebug() << "add";
            }
        }
        if(event->button() == Qt::RightButton)
        {
            if(this->addTrackPoint == false && currentTrack->getStorage()->getCurrentObject()->getData()){
                this->removeItem(currentTrack->getStorage()->getCurrentObject()->getData());
                currentTrack->getStorage()->removeCurr();
                currentTrack->computeMinMaxHeight();
            }
            else{
                addTrackPoint = false;
            }
        }


    }
}

void field::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //MyPoint * point = dynamic_cast<TrackPoint*>(itemAt(event->scenePos(),QTransform()));
    MyPoint * point = dynamic_cast<TrackPoint*>(itemAt(event->scenePos(),QTransform()));
    if(dynamic_cast<TrackPoint*>(itemAt(event->scenePos(),QTransform())))
    {
        point = dynamic_cast<TrackPoint*>(itemAt(event->scenePos(),QTransform()));
        //qDebug() << "MOVE on SinglePoint";
    }
    if(dynamic_cast<SinglePoint*>(itemAt(event->scenePos(),QTransform())))
    {
        point = dynamic_cast<SinglePoint*>(itemAt(event->scenePos(),QTransform()));
        //qDebug() << "MOVE on SinglePoint";
    }
    if(point != NULL){
        sendEvent(itemAt(event->scenePos(),QTransform()), event);
        emit this->putLatitudeInLineEdit(QString::number((int)(point->getLatitude())));
        emit this->putLongitudeInLineEdit(QString::number((int)(point->getLongitude())));
    }
    else{
        //qDebug() << "CAN'not dynamic_cast to MyPoint*";
    }
}

MyTrack *field::getNewTrack()
{
    MyTrack *t = new MyTrack(this);
    this->setCurTrack(t);
    t->setDataType("Track");
    this->getTrackList()->push_back(t);
    return t;
}

void field::setCurTrack(MyTrack *t)
{
    if(TrackList->isEmpty() || TrackList->contains(t))
        currentTrack = t;
    else
        currentTrack = TrackList->at(0);
    //qDebug() << "field::setCurTrack";
}

