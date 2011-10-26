#include "keysequence.h"

#include <QtDebug>


KeySequence::KeySequence(QObject *parent)
: QObject(parent)
{
}

KeySequence::KeySequence(const QList<Qt::Key> &sequence, QObject *parent)
: QObject(parent)
, _sequence(sequence)
{
    reset();
}

void KeySequence::reset()
{
    _pointer = 0;
}

bool KeySequence::eventFilter(QObject *target, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        qDebug() << _pointer << qPrintable(_sequence[_pointer]) << qPrintable(keyEvent->key());

        if (_sequence[_pointer++] == keyEvent->key()) {
            if (_pointer >= _sequence.size()) {
                reset();
                emit trigger();
            }
        }

        else {
            reset();
        }

        return true;
    }

    return false;
}
