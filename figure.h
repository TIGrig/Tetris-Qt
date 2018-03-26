#ifndef FIGURE_H
#define FIGURE_H
#include <QColor>
#include <QPainter>

class Figure
{
    QColor sprite[3];
    uint  W;
    uint indexRow;
    uint indexCol;
    bool figureDropped;

 public:
    Figure(uint size);
    Figure();
    void setIndexRow(uint i) { indexRow = i; }
    void setIndexCol(uint j) { indexCol = j; }
    void setDrop() {figureDropped = true;}
    bool getDrop() {return figureDropped;}
    uint getIndexRow() { return indexRow; }
    uint getIndexCol() { return indexCol; }
    QColor getColor(int i) {return sprite[i];}
    void shiftColor(int key);
    void makeRandomColors();
    void paintFigure(QPainter& p);

};

#endif // FIGURE_H
