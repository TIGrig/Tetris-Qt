#include "tetris.h"
#include "ui_tetris.h"
#include <QMessageBox>

Tetris::Tetris(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tetris)
{
    ui->setupUi(this);
}

Tetris::~Tetris()
{
    delete ui;
}


void Tetris::on_actionInfo_triggered()
{
    QString title("Управление");
    QString text("Up/Down/Left/Right - движение тайла\n"
                "Space - сбросить тайл вниз\n"
                "Ctrl+N - начать новую игру\n"
                "Ctrl+E - выход из игры\n"
                "Ctrl+I - вывести справку");
    QMessageBox::about(this,title,text);
}
