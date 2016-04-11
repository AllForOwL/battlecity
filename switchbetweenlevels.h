#ifndef SWITCCHBETWEENLEVELS_H
#define SWITCCHBETWEENLEVELS_H

#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsTextItem>

#include "constants.h"

class SwitchBetweenLevels : public QGraphicsScene
{
    Q_OBJECT
public:
    SwitchBetweenLevels(QObject* parent = 0);
    ~SwitchBetweenLevels();

    void SetNameLevel(const QString& nameLevel);

protected:
    virtual void keyPressEvent(QKeyEvent* event);

private:
    QGraphicsTextItem* m_txtNameLevel;

signals:
    void signalShowNextLevel();

};

#endif // SWITCCHBETWEENLEVELS_H
