#include "circule.h"

circule::circule(int xx,int yy, int ll_size){
    a=xx; b=yy; c=ll_size;
}

circule::~circule(){}

void circule::draw(QPainter * painter)
{
    painter->drawEllipse(a,b,c,c);
}
