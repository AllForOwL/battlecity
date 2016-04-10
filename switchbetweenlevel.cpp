#include "switchbetweenlevel.h"

SwitchBetweenLevel::SwitchBetweenLevel(QObject* parent):QGraphicsScene(parent)
{
    this->setBackgroundBrush(Qt::gray);
    this->setSceneRect(0, 0, WINDOW_WIDTH+100, WINDOW_HEIGHT);

    m_txtNameLevel = new QGraphicsTextItem();
    m_txtNameLevel->setPlainText("Level 1");
    m_txtNameLevel->setFont(QFont("Serif", 25, QFont::Bold));
    m_txtNameLevel->setDefaultTextColor(Qt::black);
    m_txtNameLevel->setPos(230, 150);

    this->addItem(m_txtNameLevel);

}

SwitchBetweenLevel::~SwitchBetweenLevel()
{

}

void SwitchBetweenLevel::SetNameLevel(const QString &nameLevel)
{
    this->m_txtNameLevel->setPlainText(nameLevel);
}

void SwitchBetweenLevel::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
    {
        emit this->signalShowNextLevel();
    }
}


