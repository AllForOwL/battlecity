#ifndef SWITCHBETWEENLEVEL_H
#define SWITCHBETWEENLEVEL_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QObject>

#include "constants.h"

class SwitchBetweenLevel : public QGraphicsScene
{
    Q_OBJECT
public:

    SwitchBetweenLevel(QObject* parent = 0);
    ~SwitchBetweenLevel();

    void SetNameLevel(const QString& nameLevel);

protected:
    virtual void keyPressEvent(QKeyEvent* event);

private:

    QGraphicsTextItem* m_txtNameLevel;

signals:

    void signalShowNextLevel();

};

#endif // SWITCHBETWEENLEVEL_H
