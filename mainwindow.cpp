
#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
: QWidget(parent)
{
    raptor = new QLabel(this);
    QPixmap pixmap(":/raptor.png");
    raptor->resize(pixmap.size());
    raptor->setPixmap(pixmap);
    raptor->hide();
    animation = new QSequentialAnimationGroup();

    KeySequence::KeyList konamiCode;
    konamiCode << Qt::Key_Up << Qt::Key_Up;
    konamiCode << Qt::Key_Down << Qt::Key_Down;
    konamiCode << Qt::Key_Left << Qt::Key_Right;
    konamiCode << Qt::Key_Left << Qt::Key_Right;
    konamiCode << Qt::Key_B << Qt::Key_A;

    sequence = new KeySequence(konamiCode, this);

    connect(sequence, SIGNAL(trigger()), this, SLOT(raptorize()));
    installEventFilter(sequence);

    // mediaObject = new Phonon::MediaObject(this);
    // mediaObject->setCurrentSource(Phonon::MediaSource(":/raptor-sound.ogg"));
    // Phonon::AudioOutput *audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    // Phonon::Path path = Phonon::createPath(mediaObject, audioOutput);
}

MainWindow::~MainWindow()
{
    // delete mediaObject;
    delete animation;
}

void MainWindow::raptorize()
{
    QPropertyAnimation *anim1 = new QPropertyAnimation(raptor, "pos");
    anim1->setEasingCurve(QEasingCurve::InOutElastic);
    anim1->setDuration(2000);
    anim1->setStartValue(QPoint(width()- raptor->width(), height()));
    anim1->setEndValue(QPoint(width()- raptor->width(), (height() - raptor->height()) + 100));
    animation->addAnimation(anim1);

    QPropertyAnimation *anim2 = new QPropertyAnimation(raptor, "pos");
    anim2->setEasingCurve(QEasingCurve::Linear);
    anim2->setDuration(1000);
    anim2->setStartValue(QPoint(width() - raptor->width(), (height() - raptor->height()) + 100));
    anim2->setEndValue(QPoint(width() * -1, (height() - raptor->height()) + 100));
    animation->addAnimation(anim2);

    animation->start();
    // mediaObject->play();

    raptor->show();
}

