#include "tankbot.h"
#include <QKeyEvent>
#include "constants.h"
#include <iostream>
#include <iomanip>
#include <QDebug>

using namespace std;

TankBot::TankBot(const QList<QString> fileNames): Tank(fileNames) {
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
    timerFoundNewWay = new QTimer(this);

    timerFoundNewWay->start(1000);

    QObject::connect(timerFoundNewWay, SIGNAL(timeout())                          , this, SLOT(slotForStartSearchPath()        ));
    QObject::connect(this            , SIGNAL(signalOneSearchWay(int,int,int,int)), this, SLOT(slotSearchPath(int,int,int,int) ));

    QObject::connect( this           , SIGNAL(signalSearchNewWay())               , this, SLOT(slotSearchNewWayAfterCollision()));
}

void TankBot::setModeOfAtack(TankBot::MODE_ATACK M_A) {
    MODE_OF_ATACK = M_A;
}

void TankBot::slotForStartSearchPath()
{
    emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL);
}

void TankBot::slotSearchPath(int x_begin, int y_begin, int x_end, int y_end) {
    
    searchWay = true; // состоялся поиск пути
    indexWay = CNT_NOT_FOUND_WAY;
    algorithmSearchWay  = new algorithmLI(x_begin, y_begin, x_end, y_end);
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
    }
    if (searchWay)                         // был найден путь
    {
        if (indexWay == CNT_NOT_FOUND_WAY) // и бот находится вконце пути
        {
            if (
                (algorithmSearchWay->vectorFoundWay.size() == 0) ||
                (algorithmSearchWay->vectorFoundWay.size() == 1)
               )
            {
                emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL);
                return;
            }

            vectorFoundWay.resize(algorithmSearchWay->vectorFoundWay.size());
            copy(algorithmSearchWay->vectorFoundWay.begin(), algorithmSearchWay->vectorFoundWay.end(),
                 vectorFoundWay.begin()); // копирование пути в вектор этого класса с класса нахождения пути

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

        if ((this->x() == x_end) && (this->y() == y_end)) // когда текущие x і y ровны елементу пути
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


        if (_previousStep.size() == 7)
        {
            if ((this->x() == _previousStep[0].x) && (this->y() == _previousStep[0].y))
            {
                _previousStep.clear();

                int xPlayer = 0;
                int yPlayer = 0;

                switch (this->_rotate)
                {
                case 0:
                    {
                        if (this->x() >= 250)
                        {
                            xPlayer = rand() % (int)(this->x()+32) + 128;
                            yPlayer = this->y();
                        }
                        else
                        {
                            xPlayer = rand() % 480 + 128;
                            yPlayer = this->y();
                        }
                    break;
                    }
                case 90:
                    {
                        if (this->y() >= 250)
                        {
                            xPlayer = this->x();
                            yPlayer = rand() % (int)(this->y() + 34) + 128;
                        }
                        else
                        {
                            xPlayer = this->x();
                            yPlayer = rand() % 480 + (this->y() + 34);
                        }
                    break;
                    }
                case 180:
                    {
                        if (this->x() >= 250)
                        {
                            xPlayer = rand() % (int)(this->x() + 32) + 128;
                            yPlayer = this->y();
                        }
                        else
                        {
                            xPlayer = rand() % 480 + 128;
                            yPlayer = this->y();
                        }
                    break;
                    }
                case 270:
                    {
                        if (this->y() >= 250)
                        {
                            xPlayer = this->x();
                            yPlayer = rand() % (int)(this->y() + 34) + 128;
                        }
                        else
                        {
                            xPlayer = this->x();
                            yPlayer = rand() % 480 + (this->y() + 34);
                        }
                    break;
                    }
                default:
                    {
                        xPlayer = rand() % 450 + 100;
                        yPlayer = rand() % 480 + 100;
                    break;
                    }
                }

                _xPlayer = xPlayer;
                _yPlayer = yPlayer;

                emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL);
                changeRotate = true;
                return;
            }
            else
            {
                _previousStep.clear();
            }
        }

        _previousPoint.x = this->x();
        _previousPoint.y = this->y();
        _previousStep.push_back(_previousPoint);

    }
    else
    {
        qDebug() << "search for bot-player";
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
    if (indexWay == 0) // если достигли финиша
    {
        qDebug() << "finish";
        searchWay = false;
        indexWay = CNT_NOT_FOUND_WAY;
    }
    if (searchWay)                         // был найден путь
    {
        if (indexWay == CNT_NOT_FOUND_WAY) // и бот находится вконце пути
        {
            if (
                    (algorithmSearchWay->vectorFoundWay.size() == 0) ||
                    (algorithmSearchWay->vectorFoundWay.size() == 1)
                    )
            {
                int xPlayer = 0;
                int yPlayer = 0;

                xPlayer = rand() % 450 + 50;
                yPlayer = rand() % 480 + 100;
                _xPlayer = xPlayer;
                _yPlayer = yPlayer;

                emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL); // поиск пути

                return;
            }

            vectorFoundWay.resize(algorithmSearchWay->vectorFoundWay.size());
            copy(algorithmSearchWay->vectorFoundWay.begin(), algorithmSearchWay->vectorFoundWay.end(),
                 vectorFoundWay.begin()); // копирование пути в вектор этого класса с класса нахождения пути

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

        if ((this->x() == x_end) && (this->y() == y_end)) // когда текущие x і y ровны елементу пути
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

        if (_previousStep.size() == 7)
        {
            if ((this->x() == _previousStep[0].x) && (this->y() == _previousStep[0].y))
            {
                _previousStep.clear();

                int xPlayer = 0;
                int yPlayer = 0;

                switch (this->_rotate)
                {
                case 0:
                    {
                        if (this->x() >= 250)
                        {
                            xPlayer = rand() % (int)(this->x()+32) + 128;
                            yPlayer = this->y();
                        }
                        else
                        {
                            xPlayer = rand() % 480 + 128;
                            yPlayer = this->y();
                        }
                    break;
                    }
                case 90:
                    {
                        if (this->y() >= 250)
                        {
                            xPlayer = this->x();
                            yPlayer = rand() % (int)(this->y() + 34) + 128;
                        }
                        else
                        {
                            xPlayer = this->x();
                            yPlayer = rand() % 480 + (this->y() + 34);
                        }
                    break;
                    }
                case 180:
                    {
                        if (this->x() >= 250)
                        {
                            xPlayer = rand() % (int)(this->x() + 32) + 128;
                            yPlayer = this->y();
                        }
                        else
                        {
                            xPlayer = rand() % 480 + 128;
                            yPlayer = this->y();
                        }
                    break;
                    }
                case 270:
                    {
                        if (this->y() >= 250)
                        {
                            xPlayer = this->x();
                            yPlayer = rand() % (int)(this->y() + 34) + 128;
                        }
                        else
                        {
                            xPlayer = this->x();
                            yPlayer = rand() % 480 + (this->y() + 34);
                        }
                    break;
                    }
                default:
                    {
                        xPlayer = rand() % 450 + 100;
                        yPlayer = rand() % 480 + 100;
                    break;
                    }
                }

                _xPlayer = xPlayer;
                _yPlayer = yPlayer;

                emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL);
                changeRotate = true;
                return;
            }
            else
            {
                _previousStep.clear();
            }
        }

        _previousPoint.x = this->x();
        _previousPoint.y = this->y();
        _previousStep.push_back(_previousPoint);

    }
    else
    {
        int xPlayer = 0;
        int yPlayer = 0;

        xPlayer = rand() % 450 + 50;
        yPlayer = rand() % 480 + 100;
        _xPlayer = xPlayer;
        _yPlayer = yPlayer;
qDebug() << "search for bot";
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

void TankBot::slotSearchNewWayAfterCollision()
{
    _previousStep.clear();

    int xPlayer = 0;
    int yPlayer = 0;

    switch (this->_rotate)
    {
    case 0:
    {
        if (this->x() >= 250)
        {
            xPlayer = rand() % (int)(this->x()+32) + 128;
            yPlayer = this->y();
        }
        else
        {
            xPlayer = rand() % 480 + 128;
            yPlayer = this->y();
        }
        break;
    }
    case 90:
    {
        if (this->y() >= 250)
        {
            xPlayer = this->x();
            yPlayer = rand() % (int)(this->y() + 34) + 128;
        }
        else
        {
            xPlayer = this->x();
            yPlayer = rand() % 480 + (this->y() + 34);
        }
        break;
    }
    case 180:
    {
        if (this->x() >= 250)
        {
            xPlayer = rand() % (int)(this->x() + 32) + 128;
            yPlayer = this->y();
        }
        else
        {
            xPlayer = rand() % 480 + 128;
            yPlayer = this->y();
        }
        break;
    }
    case 270:
    {
        if (this->y() >= 250)
        {
            xPlayer = this->x();
            yPlayer = rand() % (int)(this->y() + 34) + 128;
        }
        else
        {
            xPlayer = this->x();
            yPlayer = rand() % 480 + (this->y() + 34);
        }
        break;
    }
    default:
    {
        xPlayer = rand() % 450 + 100;
        yPlayer = rand() % 480 + 100;
        break;
    }
    }

    _xPlayer = xPlayer;
    _yPlayer = yPlayer;

    emit signalOneSearchWay(this->y()/SIZE_WALL, this->x()/SIZE_WALL, _yPlayer/SIZE_WALL, _xPlayer/SIZE_WALL);
    changeRotate = true;
    Atack();
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
