#include "nextfigure.h"

NextFigure::NextFigure(QWidget *parent) : QWidget(parent)
{
    figure=new Figure(30);
}

void NextFigure::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    QSize qws=this->size();
    painter.translate(qws.width()/2-10,5);
    figure->paintFigure(painter);
}

void NextFigure::drawNextFigure(Figure *next)
{
    figure = next;
    repaint();
}
