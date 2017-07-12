#include "mytrack.h"

MyTrack::MyTrack(field * f)
{
    qDebug() << "MyTrack::MyTrack()";
    myParent = f;
}

MyTrack::MyTrack(QFile * file, field * f)
{
    InputFile = file;
    //qDebug() << "MyTrack::MyTrack(QFile * file)";
    if(!InputFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "DON't OPEN FILE";
        return;
    }
    else
    {
        myParent = f;
        createTrackByFile(InputFile);

    }
}

MyTrack::~MyTrack()
{
    qDebug() << "MyTrack::~MyTrack()";
    InputFile->close();
    OutputFile->close();
}

QFile *MyTrack::getFile(int str = 'I')
{
    switch (str) {
    case 'I': return InputFile; break;
    case 'O': return OutputFile; break;
    default: return InputFile; break;
        break;
    }
}

bool MyTrack::createTrackByFile(QFile *file)
{
    //int k = 0;
    QString line;
    QString str = "";
    //qDebug() << "MyTrack::createTrackByFile";
    // Считывание файла в список QString
    while(!file->atEnd()){
        line = file->readLine();
        TrackInString.append(line);
        str+=line;
        //qDebug() << k++ << line;
    }
    //qDebug() << str;

    if(TrackInDom.setContent(str))
    {
        //qDebug() << "TrackInDom.setContent(file)";
        QDomElement domElement = TrackInDom.documentElement();
        traverseNode(domElement);
    }
    qDebug() << "PointList.size() = " << pointsList.getSize();
    int i = 0;
    for(pointsList.first(); !pointsList.eol(); pointsList.next())
    {
        if(pointsList.getCurrentObject() != NULL)
        {
            pointsList.getCurrentObject()->getData()->setTimeStringData(TimeInString.at(i));
            pointsList.getCurrentObject()->getData()->setDateTimeByString();
            ++i;
        }
        else
        {
            qDebug() << "ERROR in MyTrack::createTrackByFile()" << TimeInString.at(i) << i;
            break;
        }
    }
    i = 0;
    for(pointsList.first(); !pointsList.eol(); pointsList.next())
    {
        //qDebug() << pointsList.getCurrentObject()->getData()->getTimeStringData() << i;
        ++i;
    }
    file->close();
    qDebug() << this->getParent()->getTrackList()->size();
    return true;
}

void MyTrack::traverseNode(const QDomNode &node)
{
    //MyPoint * p;
    //qDebug() << "MyTrack::traverseNode";
    QDomNode domNode = node.firstChild();
    while(!domNode.isNull()){
        if(domNode.isElement()) {
            QDomElement nihilElement = domNode.toElement();
            if(!nihilElement.isNull()){
                if(nihilElement.tagName() == "Folder"){
                    //qDebug() << "Flooder";
                    QDomNode tmpNode = domNode.firstChild();
                    if(tmpNode.isElement()){
                        QDomElement unumElement = tmpNode.toElement();
                        if(unumElement.tagName() == "name"){qDebug() << "name:" << unumElement.text();
                            if(unumElement.text() == "Waypoints"){////// создаём точки
                                tmpNode = tmpNode.nextSibling(); /// Placemark
                                QDomElement duoElement = tmpNode.toElement();
                                while(duoElement.tagName() == "Placemark")
                                {
                                    MyTrack * newTrack = this->getParent()->getNewTrack();
                                    MyPoint * sPoint = new SinglePoint(newTrack);
                                    tmpNode = tmpNode.firstChild();/// name
                                    duoElement = tmpNode.toElement();
                                    if(!duoElement.isNull()){
                                        if(duoElement.tagName() == "name"){qDebug() << "\tname:" << duoElement.text();
                                            /// пишем в точку имя
                                            sPoint->setName(duoElement.text());
                                        }
                                    }
                                    while(duoElement.tagName() != "description")
                                    {
                                        tmpNode = tmpNode.nextSibling();
                                        duoElement = tmpNode.toElement();
                                        if(!duoElement.isNull()){
                                            if(duoElement.tagName() == "description"){//qDebug() << "\tdescription:" << duoElement.text();
                                                /// пишем в точку описание
                                                dynamic_cast<SinglePoint*>(sPoint)->setDescriptionData(duoElement.text());
                                                break;
                                            }
                                        }else {qDebug()<<"BAD FILE description";break;}
                                    }
                                    while(duoElement.tagName() != "Point")
                                    {
                                        tmpNode = tmpNode.nextSibling();
                                        duoElement = tmpNode.toElement();
                                        if(duoElement.tagName() == "Point")
                                        {
                                            QDomElement tresElement = domNode.toElement();
                                            tmpNode = tmpNode.firstChild();
                                            while(tresElement.tagName() != "coordinates")
                                            {
                                                tmpNode = tmpNode.nextSibling();
                                                tresElement = tmpNode.toElement();
                                                if(!tresElement.isNull()){
                                                    if(tresElement.tagName() == "coordinates"){//qDebug() << "\tcoordinates:" << tresElement.text();
                                                        /// пишем в точку координаты
                                                        sPoint->pushDataByString(tresElement.text());
                                                        break;
                                                    }
                                                }else {qDebug()<<"BAD FILE coordinates"; break;}
                                            }
                                        }
                                    }
                                    tmpNode = tmpNode.parentNode();
                                    tmpNode = tmpNode.parentNode();
                                    tmpNode = tmpNode.nextSibling();
                                    //qDebug() << tmpElement.tagName();
                                    duoElement = tmpNode.toElement();

                                    newTrack->getStorage()->insertAtBack(sPoint);
                                    //this->getParent()->addTrackToScene();
                                    //newTrack->setTrackPos();
                                }
                            }
                            //////////////////////////////////////////////
                            if(unumElement.text() == "Tracks"){/// создаём трек

                                tmpNode = tmpNode.nextSibling(); /// Placemark
                                QDomElement duoElement = tmpNode.toElement();
                                tmpNode = tmpNode.firstChild();/// name
                                duoElement = tmpNode.toElement();
                                if(!duoElement.isNull()){
                                    if(duoElement.tagName() == "name"){//qDebug() << "\tname:" << duoElement.text();
                                        /// пишем в трек имя
                                    }
                                }
                                while(duoElement.tagName() != "description")
                                {
                                    tmpNode = tmpNode.nextSibling();
                                    duoElement = tmpNode.toElement();
                                    if(!duoElement.isNull()){
                                        if(duoElement.tagName() == "description"){//qDebug() << "\tdescription:" << duoElement.text();
                                            /// пишем в трек описание
                                            break;
                                        }
                                    }else {qDebug()<<"BAD FILE description";break;}
                                }
                                while(duoElement.tagName() != "gx:Track")
                                {
                                    tmpNode = tmpNode.nextSibling();
                                    duoElement = tmpNode.toElement();
                                    if(duoElement.tagName() == "gx:Track")
                                    {
                                        /// создаём точку
                                        MyPoint *p;

                                        QDomElement tresElement = domNode.toElement();
                                        tmpNode = tmpNode.firstChild();
                                        tresElement = tmpNode.toElement();
                                        //QDomElement tmpElement = tmpNode.toElement(); qDebug() << tmpElement.text();
                                        //tmpNode = tmpNode.nextSibling();
                                        while(tresElement.tagName() == "when")
                                        {
                                            tresElement = tmpNode.toElement();
                                            if(!tresElement.isNull()){
                                                if(tresElement.tagName() == "when"){//qDebug() << "\twhen:" << tresElement.text();
                                                    /// пишем в точку время
                                                    TimeInString << tresElement.text();
                                                }
                                            }else {qDebug()<<"BAD FILE coordinates"; break;}
                                            tmpNode = tmpNode.nextSibling();
                                        }
                                        //qDebug() << "middle";
                                        while(tresElement.tagName() == "gx:coord")
                                        {
                                            p = new TrackPoint(this);
                                            tresElement = tmpNode.toElement();
                                            if(!tresElement.isNull()){
                                                if(tresElement.tagName() == "gx:coord"){//qDebug() << "\tgx:coord:" << tresElement.text();
                                                    /// пишем в точку координаты
                                                    p->pushDataByString(tresElement.text());
                                                }
                                            }else {qDebug()<<"BAD FILE coordinates"; break;}
                                            tmpNode = tmpNode.nextSibling();
                                            /// добавляем точку
                                            pointsList.insertAtBack(p);
                                        }
                                    }
                                }

                                /////////////////////////
                            }

                        }
                    }
                }

            }
        }
        traverseNode(domNode);
        domNode = domNode.nextSibling();
    }
    //qDebug() << "TimeInString.size = " << TimeInString.size();
}

void MyTrack::setTrackPos()
{
    int x_min(INT_MAX), y_min(INT_MAX);
    for(pointsList.first(); !pointsList.eol(); pointsList.next())
    {
        if(x_min > pointsList.getCurrentObject()->getData()->getLongitude())
            x_min = pointsList.getCurrentObject()->getData()->getLongitude();
        if(y_min > pointsList.getCurrentObject()->getData()->getLatitude())
            y_min = pointsList.getCurrentObject()->getData()->getLatitude();
    }
    for(pointsList.first(); !pointsList.eol(); pointsList.next())
    {
        int x = (int)(pointsList.getCurrentObject()->getData()->getLongitude() -
                      x_min)%10000000;
        int y = (int)(pointsList.getCurrentObject()->getData()->getLatitude() -
                      y_min)%10000000;
        pointsList.getCurrentObject()->getData()->setPos(x,y);


    }
    this->computeMinMaxHeight();
    if(pointsList.getSize() > 1)
    {
        MyPoint::x_max = x_min;
        MyPoint::y_max = y_min;
    }
}

void MyTrack::computeMinMaxHeight()
{
    maxHeight = 0;
    minHeight = INT_MAX;
    for(pointsList.first(); !pointsList.eol(); pointsList.next())
    {
        if(pointsList.getCurrentObject()->getData()->getHeight() > maxHeight)
            maxHeight = pointsList.getCurrentObject()->getData()->getHeight();
        if(pointsList.getCurrentObject()->getData()->getHeight() < minHeight)
            minHeight = pointsList.getCurrentObject()->getData()->getHeight();
    }
}

void MyTrack::updateAllTrack()
{
    for(pointsList.first(); !pointsList.eol(); pointsList.next())
        pointsList.getCurrentObject()->getData()->update();
}

void MyTrack::setColorByHeight()
{
    int dHeight = 0;
    QColor col;
    for(pointsList.first(); !pointsList.eol(); pointsList.next())
    {
        dHeight = ((maxHeight - pointsList.getCurrentObject()->getData()->getHeight())/maxHeight)*255;
        col.setBlue(dHeight);
        col.setRed(255-dHeight);
        col.setGreen(0);
        pointsList.getCurrentObject()->getData()->setColor(col);
        //qDebug() << dHeight;
    }
    this->updateAllTrack();
}

void MyTrack::setColor(QColor col)
{
    for(pointsList.first(); !pointsList.eol(); pointsList.next())
    {
        pointsList.getCurrentObject()->getData()->setColor(col);
    }
    this->updateAllTrack();
}

void MyTrack::saveInFile(QFile *f)
{
    OutputFile = f;
    if(!OutputFile->open(QIODevice::WriteOnly))
    {
        qDebug() << "DON't OPEN FILE to save";
        return;
    }
    else
    {
        qDebug() << "Save to file";
        QString str = "";
        str += "<?xml version=";
        str += '"';
        str += "1.0";
        str += '"';
        str += " encoding=";
        str += '"';
        str += "UTF-8";
        str += '"';
        str += " ?>\n";
        str += "<Document>";
        str += "<Folder>\n";
        str += "<name>Waypoints</name>\n";
        for(int i = 0; i < this->getParent()->getTrackList()->size(); ++i)
        {
            if(this->getParent()->getTrackList()->at(i)->getStorage()->at(0)->getData()->getDataType() == "SinglePoint")
            {
                str+= "<Placemark>\n";
                str+= "<name><![CDATA[" +
                        this->getParent()->getTrackList()->at(i)->getStorage()->at(0)->getData()->getName();
                str+= "]]></name>\n";
                str+= "<description><![CDATA[" +
                        this->getParent()->getTrackList()->at(i)->getDescriptionData();
                str+= "]]></description>\n";
                str+= "<Point>\n<coordinates>"+this->getParent()->getTrackList()->at(i)->getStorage()->at(0)->getData()->getDataInString(',');
                str+= "</coordinates>\n</Point>\n";
                str+= "</Placemark>\n";
            }
        }
        str += "</Folder>\n";
        str += "<Folder>\n";
        str += "<name>Tracks</name>\n<Placemark>\n";
        str += "<name><![CDATA[";
        str += "Название";
        str += "]]></name>\n<description><![CDATA[";
        str += "Описание";
        str += "]]></description>\n";
        str += "<gx:Track>\n";
        for(int i = 0; i < this->getParent()->getTrackList()->size(); ++i)
        {
            if(this->getParent()->getTrackList()->at(i)->getStorage()->at(0)->getData()->getDataType() == "TrackPoint")
            {
                for(this->getParent()->getTrackList()->at(i)->getStorage()->first();
                    !this->getParent()->getTrackList()->at(i)->getStorage()->eol();
                    this->getParent()->getTrackList()->at(i)->getStorage()->next())
                {
                    str += "<when>";
                    this->getParent()->getTrackList()->at(i)->getStorage()->getCurrentObject()->getData()->convertDateTimeToString();
                    str += this->getParent()->getTrackList()->at(i)->getStorage()->getCurrentObject()->getData()->getTimeStringData();
                    str += "</when>\n";
                    //qDebug() << pointsList.getCurrentObject()->getData()->getTimeStringData();
                }
                for(this->getParent()->getTrackList()->at(i)->getStorage()->first();
                    !this->getParent()->getTrackList()->at(i)->getStorage()->eol();
                    this->getParent()->getTrackList()->at(i)->getStorage()->next())
                {
                    str += "<gx:coord>";
                    str += this->getParent()->getTrackList()->at(i)->getStorage()->getCurrentObject()->getData()->getDataInString(' ');
                    str += "</gx:coord>\n";
                }
                str += "</gx:Track>\n";
                str += "</Placemark>\n";
                str += "</Folder>\n";
                str += "<Folder>\n";
                str += "<coordinates>\n";
                for(this->getParent()->getTrackList()->at(i)->getStorage()->first();
                    !this->getParent()->getTrackList()->at(i)->getStorage()->eol();
                    this->getParent()->getTrackList()->at(i)->getStorage()->next())
                {
                    str += this->getParent()->getTrackList()->at(i)->getStorage()->getCurrentObject()->getData()->getDataInString(',');
                    str += "\n";
                }
            }
        }
        str += "</coordinates>\n";
        str += "</Folder>\n";
        str += "</Document>";
        QTextStream out(OutputFile);
        out << str;
    }
    f->close();
}





