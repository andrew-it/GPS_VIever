#include "singlepoint.h"

SinglePoint::SinglePoint(MyTrack *t):
    MyPoint(t)
{
    dataTypeString = "SinglePoint";
    this->setColor(Qt::darkYellow);
    this->setRadius(10000);
}

