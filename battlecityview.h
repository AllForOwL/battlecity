#ifndef BATTLECITYVIEW_H
#define BATTLECITYVIEW_H

#include <QGraphicsView>
#include <QObject>
#include <QGraphicsItemGroup>

#include "battlecitymap.h"
#include "constants.h"
#include "switchbetweenlevels.h"

class BattleCityView : public QGraphicsView
{
    Q_OBJECT
public:
    BattleCityView(int regimeGame, bool _friend, UdpClient* client);
    ~BattleCityView();

    void ShowWalls(const QString &strTypeWall, int numberTypeWall, const QString &pathToImage);
    void ShowStatistic();
    void ShowNameLevel();

    int _map[WINDOW_WIDTH][WINDOW_HEIGHT];

private:
    BattleCityMap* map;

    SwitchBetweenLevels* m_SwitchBetweenLevels;
    QGraphicsView      * m_viewSwitchLevels;

    QGraphicsTextItem* m_txtLevel;
    QGraphicsTextItem* m_txtCountLife;

    QList<QGraphicsPixmapItem*> listTank;

    bool m_blShowNameLevel;
    QGraphicsRectItem* m_rectShowNameLevel;
    QGraphicsItemGroup* m_groupLevel;
    QGraphicsTextItem*  m_txtNameLevel;

    int m_iCountLevel;

public slots:
    void slotClose(int numberKillsOnePlayer, int numberKillsTwoPlayer);

    void slotKillBotStatistic();
    void slotKillPlayer();

    void slotShowNextLevel();

};

#endif // BATTLECITYVIEW_H
