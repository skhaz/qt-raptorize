#ifndef _MainWindow_h
#define _MainWindow_h

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QPixmap>
#include <QLabel>
#include <QSequentialAnimationGroup>
#include <QApplication>
#include <QEvent>
#include <Phonon>

#include "keysequence.h"



class MainWindow : public QWidget
{
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    public slots:
        void raptorize();

    private:
        Q_OBJECT

        QSequentialAnimationGroup *animation;
        Phonon::MediaObject *mediaObject;
        QLabel *raptor;
        KeySequence *sequence;
};

#endif
