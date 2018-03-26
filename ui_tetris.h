/********************************************************************************
** Form generated from reading UI file 'tetris.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRIS_H
#define UI_TETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <nextfigure.h>
#include "glass.h"

QT_BEGIN_NAMESPACE

class Ui_Tetris
{
public:
    QAction *actionExit;
    QAction *actionNewgame;
    QAction *actionInfo;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    Glass *widgetGlass;
    QVBoxLayout *verticalLayout;
    QLabel *labelNext;
    NextFigure *widget;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *buttonNewGame;
    QPushButton *buttonExit;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLCDNumber *score;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tetris)
    {
        if (Tetris->objectName().isEmpty())
            Tetris->setObjectName(QStringLiteral("Tetris"));
        Tetris->resize(645, 557);
        QIcon icon;
        icon.addFile(QStringLiteral(":/pref/img/tetris.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Tetris->setWindowIcon(icon);
        actionExit = new QAction(Tetris);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pref/img/iconExit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionNewgame = new QAction(Tetris);
        actionNewgame->setObjectName(QStringLiteral("actionNewgame"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/pref/img/iconNewGame.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewgame->setIcon(icon2);
        actionInfo = new QAction(Tetris);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/pref/img/iconInfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionInfo->setIcon(icon3);
        centralWidget = new QWidget(Tetris);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widgetGlass = new Glass(centralWidget);
        widgetGlass->setObjectName(QStringLiteral("widgetGlass"));
        widgetGlass->setFocusPolicy(Qt::StrongFocus);
        widgetGlass->setProperty("rows", QVariant(20u));
        widgetGlass->setProperty("columns", QVariant(10u));

        verticalLayout_2->addWidget(widgetGlass);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelNext = new QLabel(centralWidget);
        labelNext->setObjectName(QStringLiteral("labelNext"));
        labelNext->setAlignment(Qt::AlignCenter);
        labelNext->setMargin(5);

        verticalLayout->addWidget(labelNext);

        widget = new NextFigure(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 200));

        verticalLayout->addWidget(widget);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        buttonNewGame = new QPushButton(centralWidget);
        buttonNewGame->setObjectName(QStringLiteral("buttonNewGame"));

        verticalLayout_3->addWidget(buttonNewGame);

        buttonExit = new QPushButton(centralWidget);
        buttonExit->setObjectName(QStringLiteral("buttonExit"));

        verticalLayout_3->addWidget(buttonExit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);
        label->setMargin(5);

        verticalLayout_3->addWidget(label);

        score = new QLCDNumber(centralWidget);
        score->setObjectName(QStringLiteral("score"));
        score->setMinimumSize(QSize(100, 50));

        verticalLayout_3->addWidget(score);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_3, 0, 3, 2, 1);

        Tetris->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tetris);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 645, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        Tetris->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tetris);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Tetris->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tetris);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Tetris->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionNewgame);
        menu->addAction(actionExit);
        menu_2->addAction(actionInfo);
        mainToolBar->addAction(actionExit);
        mainToolBar->addAction(actionNewgame);
        mainToolBar->addAction(actionInfo);

        retranslateUi(Tetris);
        QObject::connect(buttonExit, SIGNAL(clicked()), Tetris, SLOT(close()));
        QObject::connect(actionExit, SIGNAL(triggered()), Tetris, SLOT(close()));
        QObject::connect(buttonNewGame, SIGNAL(clicked()), widgetGlass, SLOT(glassNewGameSlot()));
        QObject::connect(actionNewgame, SIGNAL(triggered()), widgetGlass, SLOT(glassNewGameSlot()));
        QObject::connect(widgetGlass, SIGNAL(drawPattern(Figure*)), widget, SLOT(drawNextFigure(Figure*)));
        QObject::connect(widgetGlass, SIGNAL(setScore(int)), score, SLOT(display(int)));

        QMetaObject::connectSlotsByName(Tetris);
    } // setupUi

    void retranslateUi(QMainWindow *Tetris)
    {
        Tetris->setWindowTitle(QApplication::translate("Tetris", "Tetris", Q_NULLPTR));
        actionExit->setText(QApplication::translate("Tetris", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        actionNewgame->setText(QApplication::translate("Tetris", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", Q_NULLPTR));
        actionNewgame->setShortcut(QApplication::translate("Tetris", "Ctrl+N", Q_NULLPTR));
        actionInfo->setText(QApplication::translate("Tetris", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        actionInfo->setShortcut(QApplication::translate("Tetris", "Ctrl+I", Q_NULLPTR));
        labelNext->setText(QApplication::translate("Tetris", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\260\321\217", Q_NULLPTR));
        buttonNewGame->setText(QApplication::translate("Tetris", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", Q_NULLPTR));
        buttonExit->setText(QApplication::translate("Tetris", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
        label->setText(QApplication::translate("Tetris", "\320\241\321\207\320\265\321\202", Q_NULLPTR));
        menu->setTitle(QApplication::translate("Tetris", "&\320\230\320\263\321\200\320\260", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("Tetris", "&\320\241\320\277\321\200\320\260\320\262\320\272\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Tetris: public Ui_Tetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRIS_H
