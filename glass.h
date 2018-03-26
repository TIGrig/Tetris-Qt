#ifndef GLASS_H
#define GLASS_H
#include <QWidget>
#include <QVector>
#include <QColor>
#include "Figure.h"
#include <QKeyEvent>
#include <QTimer>
#define baseColor QColor(150,150,150)

class Glass : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(uint rows READ rows WRITE setRows)
    Q_PROPERTY(uint columns READ columns WRITE setColumns)
    QVector<QVector<QColor>> glassArray;
    static const uint tileSize = 30;
    uint timerInterval;
    uint m_rows;
    uint m_columns;
    bool gameOn, isSpace;
    uint score;
    Figure* cur;
    Figure* next;
    QTimer timer;
    uint idTimer;

public:
    explicit Glass(QWidget *parent = nullptr);
    ~Glass();

    uint rows() const
    {
        return m_rows;
    }

    uint columns() const
    {
        return m_columns;
    }
    void clearGlass();
    void checkGlass();
    virtual void paintEvent(QPaintEvent* event)override;
    virtual void keyPressEvent(QKeyEvent* event)override;
    virtual void timerEvent(QTimerEvent* event)override;
    void repaintArrayHoriz(int k, int row, int col);
    void repaintArrayVert(int k, int row, int col);

signals:
    void glassInitSignal();
    void setScore(int);

public slots:
    void setRows(uint rows)
    {
        m_rows = rows;
    }

    void setColumns(uint columns)
    {
        m_columns = columns;
    }
    void glassInitSlot();
    void glassNewGameSlot();

signals:
    void drawPattern(Figure* next);
};

#endif // GLASS_H
