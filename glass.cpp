#include "glass.h"
#include <QDebug>
#include <QPainter>
#include <QMessageBox>

Glass::Glass(QWidget *parent) : QWidget(parent)
{
    cur = new Figure(tileSize);
    next = new Figure(tileSize);
    connect(this, SIGNAL(glassInitSignal()),this, SLOT(glassInitSlot()),Qt::QueuedConnection);
    emit glassInitSignal();
    emit drawPattern(next);
}
Glass::~Glass()
{
    delete cur;
    delete next;
}
void Glass::clearGlass()
{
    QVector<QVector<QColor>>::iterator ib = glassArray.begin(), ie = glassArray.end();
    for(;ib!=ie;++ib)
    {
        ib->fill(baseColor);
    }
    score = 0;
    //timerInterval = 5;
}
void Glass::glassInitSlot()
{
    glassArray.resize(this->rows());
    for(uint i = 0; i< this->rows(); i++)
    {
        glassArray[i].resize(this->columns());
    }
    QVector<QVector<QColor>>::iterator ib = glassArray.begin(), ie = glassArray.end();
    for(;ib!=ie;++ib)
    {
        ib->fill(baseColor);
    }
    QSize size(this->columns()*tileSize, this->rows()*tileSize);
    this->setFixedSize(size);

//    qDebug()<<"CAPACITY: "<< glassArray.capacity();
//    qDebug()<<"LENGTH: "<< glassArray.length();
//    qDebug()<<"LENGTH 0: "<< glassArray[0].length();
}
void Glass::glassNewGameSlot()
{
    gameOn = true;
    this->clearGlass();
    cur->makeRandomColors();
    next->makeRandomColors();
    emit drawPattern(next);
    cur->setIndexRow(0);
    cur->setIndexCol(150);
    this->setFocus();
    idTimer = this->startTimer(250);
    repaint();

}
void Glass::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPen pen("#000000");
    painter.setPen(pen);
    for(uint i = 0; i < this->columns(); i++)
    {
        for(uint j = 0; j< this->rows(); j++)
        {
                QBrush brush(glassArray[j][i]);
                painter.setBrush(brush);
            painter.drawRect(i*tileSize,j*tileSize,tileSize,tileSize);
        }
    }
    if(gameOn)
    {
        cur->paintFigure(painter);
    }
}
void Glass::keyPressEvent(QKeyEvent* event)
{
    if(gameOn)
    {
       uint col;
        switch(event->key())
        {
            case Qt::Key_Left:
            if(cur->getIndexCol()!=0 && glassArray[cur->getIndexRow()/30+3][cur->getIndexCol()/30-1]==baseColor)
            {
                col = cur->getIndexCol()-30;
                cur->setIndexCol(col);
                repaint();
            }
                break;
            case Qt::Key_Right:
            if(cur->getIndexCol() != 270 && glassArray[cur->getIndexRow()/30+3][cur->getIndexCol()/30+1]==baseColor)
            {
                col = cur->getIndexCol()+30;
                cur->setIndexCol(col);
                repaint();
            }
                break;
            case Qt::Key_Up:
                cur->shiftColor(event->key());
                repaint();
                break;
            case Qt::Key_Down:
                cur->shiftColor(event->key());
                repaint();
               break;
            case Qt::Key_Space:
            isSpace = true;
            this->killTimer(idTimer);
            idTimer=this->startTimer(5);
            break;
           default: QWidget::keyPressEvent(event); break;
         }
    }
    else
    {
        QWidget::keyPressEvent(event);
    }
}


void Glass::checkGlass()
{
    //horizont
    uint k =0;
    for(uint i = this->rows()-1; i > 0; i--)
    {
        for(uint j = 0; j< this->columns(); j++)
        {
            if((j+1 == this->columns())||
                    ((j+1<this->columns())&&
                     (glassArray[i][j]!=glassArray[i][j+1])))
            {
                if(k>0)
                {
                    repaintArrayHoriz(k,i,j);
                    j = 0;
                    k = 0;
                }
            }
            else if((j+2<this->columns())&&
                    (glassArray[i][j]!=baseColor)&&
                    (glassArray[i][j]==glassArray[i][j+1])&&
                    (glassArray[i][j]==glassArray[i][j+2]))
            {
                k++;
            }
        }
    }
    k=0;
    //vertical
    for(uint j = 0; j< this->columns(); j++)
    {
        for(uint i = this->rows()-1; i>2; i--)
        {
            if((glassArray[i-1][j]==baseColor)||(glassArray[i-1][j]!=glassArray[i][j]))
            {
                if(k>0)
                {
                    repaintArrayVert(k,i,j);
                    i = this->rows()-1;
                }
                k=0;
            }
            else if((glassArray[i][j]==glassArray[i-1][j])&&(glassArray[i][j]==glassArray[i-2][j])&&(glassArray[i][j]!=baseColor))
            {
                k++;
            }
        }
    }
}
void Glass::repaintArrayHoriz(int k, int row, int col)
{
    for(int i = row; i > 1; i--)
    {
        for(int j = col; j> col-k-2; j--)
        {
            glassArray[i][j] = glassArray[i-1][j];
        }
    }
    score+=2+k;
    this->repaint();
}
void Glass::repaintArrayVert(int k, int row, int col)
{
    for(int j = row+k+1; j>2+k; j--)
    {
        glassArray[j][col] = glassArray[j-2-k][col];
    }
    score+=2+k;
    this->repaint();
}
void Glass::timerEvent(QTimerEvent* event)
{
    if(glassArray[3][cur->getIndexCol()/30]!=baseColor)
    {
       this->killTimer(idTimer);
       idTimer = -1;
       QMessageBox::information(this, "Information", "Game over");
       gameOn=false;
    }
    else if( (cur->getIndexRow() == 510)||
             (cur->getIndexRow()/30 >= this->rows()-3)||
             (glassArray[cur->getIndexRow()/30+3][cur->getIndexCol()/30]!=baseColor) )
            {
                for(int i =0; i< 3; i++)
                glassArray[cur->getIndexRow()/30+i][cur->getIndexCol()/30] = cur->getColor(i);

                Figure* tmp =cur;
                cur = next;
                delete tmp;
                cur->setIndexCol(150);
                checkGlass();

                next = new Figure(tileSize);
                next->makeRandomColors();

                emit drawPattern(next);
                emit setScore(score);
                if(isSpace)
                {
                    isSpace = false;
                    this->killTimer(idTimer);
                    idTimer = this->startTimer(250);
                }
            }
    else if (glassArray[cur->getIndexRow()/30+3][cur->getIndexCol()/30]==baseColor && cur->getIndexRow()/30 < this->rows()-3)
            {
                cur->setIndexRow(cur->getIndexRow()+30);
            }
    this->update();
}
