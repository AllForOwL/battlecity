#include "tankbot.h"
#include <QKeyEvent>
#include "constants.h"
#include <iostream>
#include <iomanip>
#include <QDebug>
#include <time.h>
#include <QTime>

using namespace std;

TankBot::TankBot(const QList<QString> fileNames): Tank(fileNames)
{
    MODE_OF_ATACK = FREE;
//    MODE_OF_ATACK = KILL_FLAG;
    setRotate(270);
    searchWay = false;
    indexWay  = 0;
    addTank = false;
    changeRotate = false;
    numberDeaths = 0;
    _previousPoint.x = 0;
    _previousPoint.y = 0;
    algorithmSearchWay = new algorithmLI;

    QObject::connect(this, SIGNAL (signalOneSearchWay(int,int,int,int)), this, SLOT (slotSearchPath(int,int,int,int)));
    QObject::connect(this, SIGNAL (signalSearchNewWay(bool)),            this, SLOT (slotSearchNewWayAfterCollision(bool)));
}

void TankBot::setModeOfAtack(TankBot::MODE_ATACK M_A)
{
    MODE_OF_ATACK = M_A;
}

void TankBot::slotSearchPath(int x_begin, int y_begin, int x_end, int y_end)
{
    algorithmSearchWay->AuditSearchWay(x_begin, y_begin, x_end, y_end);

    if (
        (algorithmSearchWay->vectorFoundWay.size() == 0) ||
        (algorithmSearchWay->vectorFoundWay.size() == 1)
       )
    {
        return;
    }
    else
    {
        vectorFoundWay.resize(algorithmSearchWay->vectorFoundWay.size());
        copy(algorithmSearchWay->vectorFoundWay.begin(), algorithmSearchWay->vectorFoundWay.end(),
        vectorFoundWay.begin()); // копирование пути в вектор этого класса с класса нахождения пути

        indexWay = CNT_FOUND_WAY;
    }
}

// поиск пути для игроков
void TankBot::Atack(int xPlayer, int yPlayer)
{
   _xPlayer = xPlayer;
   _yPlayer = yPlayer;

    if (indexWay == 0) // если достигли финиша
    {
        emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL);
        return;
    }
        if (indexWay == CNT_FOUND_WAY)
        {
            indexWay = vectorFoundWay.size()-1;           // получаем предпоследний елемент пути

            x_end = vectorFoundWay[indexWay].y * SIZE_WALL; // получаем x и y предпоследнего
            y_end = vectorFoundWay[indexWay].x * SIZE_WALL; // елемента пути

            if (x_end == this->x())      // когда текущий x и x - следующего елемента пути ровны
            {
                if (y_end < this->y())   // если текущий y больше y - следующего шага пути
                {
                    this->_rotate = 0;   // едем вверх
                }
                else
                {
                    this->_rotate = 180; // едем вниз
                }
            }
            else
            {
                if (x_end > this->x())   // если текущий x менше x следующего елемента пути
                {
                    this->_rotate = 90;  // едем вправо
                }
                else
                {
                    this->_rotate = 270; // едем влево
                }
            }
        }
        else if (this->x() == x_end && this->y() == y_end) // когда текущие x і y ровны елементу пути
                {
                    --indexWay;                                   // переходим к следующему елементу пути
                    x_end = vectorFoundWay[indexWay].y * SIZE_WALL;
                    y_end = vectorFoundWay[indexWay].x * SIZE_WALL;

                    if (x_end == this->x())
                    {
                        if (y_end < this->y())
                        {
                            this->_rotate = 0;
                        }
                        else
                        {
                            this->_rotate = 180;
                        }
                    }
                    else if (y_end == this->y())
                    {
                        if (x_end > this->x())
                        {
                            this->_rotate = 90;
                        }
                        else
                        {
                            this->_rotate = 270;
                        }
                    }
               }
                else
                 {
                    x_end = vectorFoundWay[indexWay].y * SIZE_WALL;
                    y_end = vectorFoundWay[indexWay].x * SIZE_WALL;

                    if (x_end == this->x())      // когда текущий x и x - следующего елемента пути ровны
                    {
                        if (y_end < this->y())   // если текущий y больше y - следующего шага пути
                        {
                            this->_rotate = 0;   // едем вверх
                        }
                        else
                        {
                            this->_rotate = 180; // едем вниз
                        }
                    }
                    else
                    {
                        if (x_end > this->x())   // если тaекущий x менше x следующего елемента пути
                        {
                            this->_rotate = 90;  // едем вправо
                        }
                        else
                        {
                            this->_rotate = 270; // едем влево
                        }
                    }
                 }

    activeKey.clear();
    switch (MODE_OF_ATACK) {
        case FREE: {
            switch (this->_rotate) {
            case 0:
                    activeKey.push_back(Qt::Key_Up);
                break;
            case 90:
                    activeKey.push_back(Qt::Key_Right);
                break;
            case 180:
                    activeKey.push_back(Qt::Key_Down);
                break;
            case 270:
                    activeKey.push_back(Qt::Key_Left);
                break;
        }
        break;
        }
        case KILL_PLAYER: {
            break;
        }
        case KILL_FLAG: {
            break;
        }
    }
      emit slotMoveTank();
      emit slotTankShot(this->objectName());
}

// поиск пути для ботов
void TankBot::Atack()
{
    if (indexWay == 0) // если достигли финиша
    {
        emit signalSearchNewWay(false);
        return;
    }

        if (indexWay == CNT_FOUND_WAY)
        {
            indexWay = vectorFoundWay.size()-1;           // получаем предпоследний елемент пути

            x_end = vectorFoundWay[indexWay].y * SIZE_WALL; // получаем x и y предпоследнего
            y_end = vectorFoundWay[indexWay].x * SIZE_WALL; // елемента пути

            if (x_end == this->x())      // когда текущий x и x - следующего елемента пути ровны
            {
                if (y_end < this->y())   // если текущий y больше y - следующего шага пути
                {
                    this->_rotate = 0;   // едем вверх
                }
                else
                {
                    this->_rotate = 180; // едем вниз
                }
            }
            else
            {
                if (x_end > this->x())   // если текущий x менше x следующего елемента пути
                {
                    this->_rotate = 90;  // едем вправо
                }
                else
                {
                    this->_rotate = 270; // едем влево
                }
            }

        }
        else if (this->x() == x_end && this->y() == y_end) // когда текущие x і y ровны елементу пути
                {
                    --indexWay;                                   // переходим к следующему елементу пути
                    x_end = vectorFoundWay[indexWay].y * SIZE_WALL;
                    y_end = vectorFoundWay[indexWay].x * SIZE_WALL;

                    if (x_end == this->x())
                    {
                        if (y_end < this->y())
                        {
                            this->_rotate = 0;
                        }
                        else
                        {
                            this->_rotate = 180;
                        }
                    }
                    else if (y_end == this->y())
                    {
                        if (x_end > this->x())
                        {
                            this->_rotate = 90;
                        }
                        else
                        {
                            this->_rotate = 270;
                        }
                    }
               }
                else
                 {
                    x_end = vectorFoundWay[indexWay].y * SIZE_WALL;
                    y_end = vectorFoundWay[indexWay].x * SIZE_WALL;

                    if (x_end == this->x())      // когда текущий x и x - следующего елемента пути ровны
                    {
                        if (y_end < this->y())   // если текущий y больше y - следующего шага пути
                        {
                            this->_rotate = 0;   // едем вверх
                        }
                        else
                        {
                            this->_rotate = 180; // едем вниз
                        }
                    }
                    else
                    {
                        if (x_end > this->x())   // если тaекущий x менше x следующего елемента пути
                        {
                            this->_rotate = 90;  // едем вправо
                        }
                        else
                        {
                            this->_rotate = 270; // едем влево
                        }
                    }
                 }

    activeKey.clear();
    switch (MODE_OF_ATACK) {
    case FREE: {
        switch (this->_rotate) {
        case 0:
            activeKey.push_back(Qt::Key_Up);
            break;
        case 90:
            activeKey.push_back(Qt::Key_Right);
            break;
        case 180:
            activeKey.push_back(Qt::Key_Down);
            break;
        case 270:
            activeKey.push_back(Qt::Key_Left);
            break;
        }
        break;
    }
    case KILL_PLAYER: {
        break;
    }
    case KILL_FLAG: {
        break;
    }
    }

    emit slotMoveTank();
    emit slotTankShot(this->objectName());
}

void TankBot::slotSearchNewWayAfterCollision(bool useRotate)
{
    int xPlayer = 0;
    int yPlayer = 0;

    if (useRotate)
    {
        if (this->y() <= 250)
        {
            switch (this->_rotate)
            {
                case 0:
                {qDebug() << "0";
                    if (this->x() >= 250)
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = rand() % 128 + 64 ;
                        yPlayer = this->y();
                    }
                    else
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = rand() % 440 + 380;
                        yPlayer = this->y();
                    }
                    break;
                }
                case 90:
                {qDebug() << "90";
                    if (this->y() >= 250)
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = this->x();
                        yPlayer = rand() % 128 + 64;
                    }
                    else
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = this->x();
                        yPlayer = rand() % 440 + 380;
                    }
                    break;
                }
                case 180:
                {qDebug() << "180";
                    if (this->x() >= 250)
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = rand() % 128 + 64;
                        yPlayer = this->y();
                    }
                    else
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = rand() % 440 + 380;
                        yPlayer = this->y();
                    }
                    break;
                }
                case 270:
                {qDebug() << "270";
                    if (this->y() >= 250)
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = this->x();
                        yPlayer = rand() % 128 + 64;
                    }
                    else
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = this->x();
                        yPlayer = rand() % 440 + 380;
                    }
                    break;
                }
                default:
                {
                    qsrand(QTime::currentTime().msec());
                    xPlayer = rand() % 450 + 100;
                    yPlayer = rand() % 450 + 100;
                    break;
                }
            }
         }
        else
        {
            switch (this->_rotate)
            {
                case 0:
                {qDebug() << "90";
                    if (this->y() >= 250)
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = this->x();
                        yPlayer = rand() % 128 + 64;
                    }
                    else
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = this->x();
                        yPlayer = rand() % 440 + 380;
                    }
                    break;
                }
                    case 90:
                    {qDebug() << "0";
                        if (this->x() >= 250)
                        {
                            qsrand(QTime::currentTime().msec());
                            xPlayer = rand() % 128 + 64;
                            yPlayer = this->y();
                        }
                        else
                        {
                            qsrand(QTime::currentTime().msec());
                            xPlayer = rand() % 440 + 380;
                            yPlayer = this->y();
                        }
                        break;
                    }


                    case 180:
                    {qDebug() << "270";
                        if (this->y() >= 250)
                        {
                            qsrand(QTime::currentTime().msec());
                            xPlayer = this->x();
                            yPlayer = rand() % 128 + 64;
                        }
                        else
                        {
                            qsrand(QTime::currentTime().msec());
                            xPlayer = this->x();
                            yPlayer = rand() % 440 + 380;
                        }
                        break;
                    }
                case 270:
                {qDebug() << "180";
                    if (this->x() >= 250)
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = rand() % 128 + 64;
                        yPlayer = this->y();
                    }
                    else
                    {
                        qsrand(QTime::currentTime().msec());
                        xPlayer = rand() % 440 + 340;
                        yPlayer = this->y();
                    }
                    break;
                }
            }
        }
    }
    else
    {

        qsrand(QTime::currentTime().msec());
        xPlayer = rand() % 450 + 100;
        yPlayer = rand() % 450 + 200;
    }

    _xPlayer = xPlayer;
    _yPlayer = yPlayer;

    emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL);
}

TankBot::~TankBot()
{
    deleteLater();
}
