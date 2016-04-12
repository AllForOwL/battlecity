#include "switchbetweenlevels.h"

SwitchBetweenLevels::SwitchBetweenLevels(QObject *parent) : QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::gray);                        // Встановлення фонового кольору
    this->setSceneRect(0, 0, WINDOW_WIDTH+100, WINDOW_HEIGHT);      // Встановлення розміру сцени з початковими координатами 0,0

    m_txtNameLevel = new QGraphicsTextItem("Level 1");

    m_txtNameLevel->setFont(QFont("Serif", 25, QFont::Bold));
    m_txtNameLevel->setDefaultTextColor(Qt::black);
    m_txtNameLevel->setPos(230, 150);

    this->addItem(m_txtNameLevel);

}

void SwitchBetweenLevels::SetNameLevel(const QString& nameLevel)
{
    m_txtNameLevel->setPlainText(nameLevel);
}

void SwitchBetweenLevels::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        emit signalShowNextLevel();
    }
}
