#include "figure.h"
#include <QDebug>
#include <QPainter>
#define baseColor QColor(150,150,150)
Figure::Figure(uint size)
{
   W = size;
   indexCol = 0;
   indexRow = 0;
   for(int k = 0; k < 3; k++)
   {
       sprite[k]=baseColor;
   }

}
Figure::Figure()
{
    indexCol = 0;
    indexRow = 0;
}
void Figure::shiftColor(int key)
{
  QColor tmp[3] = this->sprite;
    switch(key)
    {
        case Qt::Key_Up:

            sprite[0] = tmp[1];
            sprite[1] = tmp[2];
            sprite[2] = tmp[0];
            break;
        case Qt::Key_Down:
            sprite[0] = tmp[2];
            sprite[1] = tmp[0];
            sprite[2] = tmp[1];
            break;
    }
}
void Figure::makeRandomColors()
{
    for(int i = 0; i < 3; i++)
    {
        int tmp = qrand() % 4 + 1;
        switch(tmp)
        {
            case 1: sprite[i] = Qt::red;
                break;
            case 2: sprite[i] = Qt::green;
                break;
            case 3: sprite[i] = Qt::blue;
                break;
            case 4: sprite[i] = Qt::yellow;
                break;
        }
    }
}
void Figure::paintFigure(QPainter& p)
{
    uint startRow = this->getIndexRow();
    uint startCol = this->getIndexCol();
    QPen pen("#000000");
    p.setPen(pen);
   for(int i = 0; i < 1; i++)
   {
     for(int j =0; j<3; j++)
       {
            QBrush brush(this->sprite[j]);
            p.setBrush(brush);
            p.drawRect(startCol+i*W, startRow+j*W, W, W);
       }
   }
}
