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
    indexWay  = CNT_NOT_FOUND_WAY;
    addTank = false;
    changeRotate = false;
    numberDeaths = 0;
    _previousPoint.x = 0;
    _previousPoint.y = 0;
    timerFoundNewWay    = new QTimer(this);
    timerFoundNewWay->setObjectName("timer");

    //QObject::connect( timerFoundNewWay, SIGNAL(timeout())                          , this, SLOT(slotForStartSearchPath()            ));
    QObject::connect( this            , SIGNAL(signalOneSearchWay(int,int,int,int)), this, SLOT(slotSearchPath(int,int,int,int)     ));

    QObject::connect( this            , SIGNAL(signalSearchNewWay(bool))           , this, SLOT(slotSearchNewWayAfterCollision(bool)));
}

void TankBot::setModeOfAtack(TankBot::MODE_ATACK M_A)
{
    MODE_OF_ATACK = M_A;
}

void TankBot::slotForStartSearchPath()
{
    if ((this->objectName() == OBJ_NAME_BOT_3) ||  (this->objectName() == OBJ_NAME_BOT_4))
    {
        emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL);
    }
}

void TankBot::slotSearchPath(int x_begin, int y_begin, int x_end, int y_end)
{
    searchWay = true; // состоялся поиск пути
    indexWay = CNT_NOT_FOUND_WAY;

    algorithmSearchWay  = new algorithmLI(x_begin, y_begin, x_end, y_end, this->objectName());

    if (
        (algorithmSearchWay->vectorFoundWay.size() == 0) ||
        (algorithmSearchWay->vectorFoundWay.size() == 1)
       )
    {
        emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, y_end/SIZE_WALL, x_end/SIZE_WALL);
    }
    else
    {
        vectorFoundWay.resize(algorithmSearchWay->vectorFoundWay.size());
        copy(algorithmSearchWay->vectorFoundWay.begin(), algorithmSearchWay->vectorFoundWay.end(),
        vectorFoundWay.begin()); // копирование пути в вектор этого класса с класса нахождения пути
    }
}

// поиск пути для игроков
void TankBot::Atack(int xPlayer, int yPlayer) {

   _xPlayer = xPlayer;
   _yPlayer = yPlayer;

    if (indexWay == 0) // если достигли финиша
    {
        qDebug() << "finish";
        searchWay = false;
        indexWay = CNT_NOT_FOUND_WAY;
        _searchWayNow = false;
    }
    if (searchWay)                         // был найден путь
    {
        if (indexWay == CNT_NOT_FOUND_WAY)
        {
            indexWay = vectorFoundWay.size() - 2;           // получаем предпоследний елемент пути

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
            }
        else
        {
            if (_xPlayer % 2 != 0)
            {
                ++_xPlayer;
            }
            if (_yPlayer % 2 != 0)
            {
                ++_yPlayer;
            }

            emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL); // поиск пути
            return;
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
    if (indexWay == 0 )// если достигли финиша
    {
        qDebug() << "finish";
        searchWay = false;
        indexWay = CNT_NOT_FOUND_WAY;
    }
    if (searchWay)                         // был найден путь
    {
        if (indexWay == CNT_NOT_FOUND_WAY) // и бот находится вконце пути
        {
            indexWay = vectorFoundWay.size() - 2;           // получаем предпоследний елемент пути
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
    }
    else
    {
        emit signalSearchNewWay(false);
        return;
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
                        xPlayer = rand() % 440 + 380;
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
        yPlayer = rand() % 450 + 100;
    }

    _xPlayer = xPlayer;
    _yPlayer = yPlayer;

    if (_xPlayer % 2 != 0)
    {
        ++_xPlayer;
    }
    if (_yPlayer % 2 != 0)
    {
        ++_yPlayer;
    }

    changeRotate = true;
    emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL);
}

void TankBot::outMap(/*const int map[CNT_ROWS_MAP][CNT_COLS_MAP]*/) {
    for (int i = 0; i < CNT_ROWS_MAP; ++i) {
        for (int j = 0; j < CNT_COLS_MAP; ++j) {
            qDebug() << map[i][j];
        }
        qDebug() << endl;
    }
}

TankBot::~TankBot()
{
    deleteLater();
}
