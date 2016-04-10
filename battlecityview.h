#ifndef BATTLECITYVIEW_H
#define BATTLECITYVIEW_H

#include <QGraphicsView>
#include <QObject>

#include "battlecitymap.h"
#include "constants.h"
#include "switchbetweenlevel.h"

class BattleCityView : public QGraphicsView
{
    Q_OBJECT
public:
    BattleCityView(int regimeGame, bool _friend, UdpClient* client);
    ~BattleCityView();

    void ShowWalls(const QString &strTypeWall, int numberTypeWall, const QString &pathToImage);
    void ShowStatistic();
    void BuildNextLevel();
    void ShowNameLevel();

    int _map[WINDOW_WIDTH][WINDOW_HEIGHT];

private:
    BattleCityMap* map;
    BattleCityMap* map_2;
    BattleCityMap* map_3;
    BattleCityMap* map_4;
    QGraphicsTextItem*  m_txtLevel;
    QGraphicsTextItem*  m_txtCountLife;
    SwitchBetweenLevel* m_sceneSwitchBetweenLevels;

    QList<QGraphicsPixmapItem*> listTank;

    int m_iCountLevel;

    int m_iarrMap[CNT_ROWS_MAP][CNT_COLS_MAP];      // розмер карты

public slots:

    void slotClose(int numberKillsOnePlayer, int numberKillsTwoPlayer);

    void slotKillBotStatistic();
    void slotKillPlayer();

    void slotShowNextLevel();
};

#endif // BATTLECITYVIEW_H
