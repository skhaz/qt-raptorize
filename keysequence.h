#ifndef _KeySequence_h
#define _KeySequence_h

#include <QObject>
#include <QList>
#include <QKeyEvent>



class KeySequence : public QObject
{
    public:
        typedef QList<Qt::Key> KeyList;

        explicit KeySequence(QObject *parent = 0);

        KeySequence(const KeyList& sequence, QObject *parent = 0);

    public slots:
        void reset();

    signals:
        void trigger();

    protected:
        virtual bool eventFilter(QObject *, QEvent *);

    private:
        Q_OBJECT

        KeyList _sequence;
        int _pointer;
};

#endif
