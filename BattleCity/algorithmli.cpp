#include <QtDebug>
#include <QException>
#include "algorithmli.h"

algorithmLI::algorithmLI()
{
    p_ReadFromFile = new Parsing();
    p_ReadFromFile->ParsTextFile(":/log_parsing.txt", n_map);   // Завантаження карти з файлу
}

bool algorithmLI::SearchWay(int x, int y, int end_x, int end_y)
{
    _begin_x  = x;
    _begin_y  = y;
    _end_x    = end_x;
    _end_y    = end_y;

    int numberAllPassableElement = 0; // счётчик по всем елементам вектора
    int distance = 10;
    int tempNumberPassable = 0;

    bool added = false;
    bool size  = true;

    point begin;
    begin.x     = x;
    begin.y     = y;
    begin.index = 9;

    vectorPassableElement.push_back(begin); // добавляем начало в список

    n_map[x][y] = 9;

    while (added || size)
    {
        // получаем текущие координаты
        x = vectorPassableElement[numberAllPassableElement].x;
        y = vectorPassableElement[numberAllPassableElement].y;

        added = false;
        size  = false;

        if (x == end_x && y == end_y) // если текущие координаты есть конечными выйти из функции
        {
            vectorFoundWay.push_back(vectorPassableElement[numberAllPassableElement]);
            return true;
        }

        ++numberAllPassableElement;

        if (x != 0) // если не на границе матрицы
        {
            if (
                (n_map[x-1][y] == 0) ||
                (n_map[x-1][y] == 2) ||
                (n_map[x-1][y] == 3) ||
                (n_map[x-1][y] == 4)
               )  // если проходимый елемент
            {
                tempNumberPassable = numberAllPassableElement;
                --tempNumberPassable;

                if (distance == vectorPassableElement[tempNumberPassable].index) // если предыдущий индекс такой же как и этот
                {
                    ++distance;                                                  // увеличиваем индекс
                }

                n_map[x-1][y] = distance;               // установливаем индекс в матрицу
                begin.x = x-1;                          // координаты
                begin.y = y;                            // индекса
                begin.index = distance;                 // индекс
                vectorPassableElement.push_back(begin); // добавляем текущую точку в вектор проходимых
                added = true;                           // есть возможность подальшего продвижения
            }
        }
        if (y < CNT_COLS_MAP-1)
        {
            if (
                (n_map[x][y+1] == 0) ||
                (n_map[x][y+1] == 2) ||
                (n_map[x][y+1] == 3) ||
                (n_map[x][y+1] == 4)
               )
            {
                tempNumberPassable = numberAllPassableElement;
                --tempNumberPassable;

                if (distance == vectorPassableElement[tempNumberPassable].index)
                {
                    ++distance;
                }

                n_map[x][y+1] = distance;
                begin.x = x;
                begin.y = y+1;
                begin.index = distance;
                vectorPassableElement.push_back(begin);
                added = true;
            }
        }

        if (x < CNT_COLS_MAP - 1)
        {
            if (
                (n_map[x+1][y] == 0) ||
                (n_map[x+1][y] == 2) ||
                (n_map[x+1][y] == 3) ||
                (n_map[x+1][y] == 4)
               )
            {
                tempNumberPassable = numberAllPassableElement;
                --tempNumberPassable;

                if (distance == vectorPassableElement[tempNumberPassable].index)
                {
                    ++distance;
                }

                n_map[x+1][y] = distance;
                begin.x = x+1;
                begin.y = y;
                begin.index = distance;
                vectorPassableElement.push_back(begin);
                added = true;
            }
        }
        if (y > 0)
        {
            if (
                (n_map[x][y-1] == 0) ||
                (n_map[x][y-1] == 2) ||
                (n_map[x][y-1] == 3) ||
                (n_map[x][y-1] == 4)
               )
            {
                tempNumberPassable = numberAllPassableElement;
                --tempNumberPassable;

                if (distance == vectorPassableElement[tempNumberPassable].index)
                {
                    ++distance;
                }

                n_map[x][y-1] = distance;
                begin.x = x;
                begin.y = y-1;
                begin.index = distance;
                vectorPassableElement.push_back(begin);
                added = true;
            }
        }

        if (distance == 10) // если первый проход
        {
            ++distance;
        }

        if (numberAllPassableElement >= vectorPassableElement.size()) // если елементов для проверки нет
        {
            return false;                                             // выходим из  функции
        }
        else
        {
            size = true;
        }
    }
    return false; // если пути не нашли
}

bool algorithmLI::AuditSearchWay(int x_begin, int y_begin, int x_end, int y_end, QString nameBot)
{
    _nameBot = nameBot;

    int _i = 0;
    if (SearchWay(x_begin, y_begin, x_end, y_end))
    {
        if (_nameBot == OBJ_NAME_BOT_3 || _nameBot == OBJ_NAME_BOT_4)
        {
            begin_x_Three_Four_Bot = x_begin;
            begin_y_Three_Four_Bot = y_begin;
            end_x_Three_Four_Bot = x_end;
            end_y_Three_Four_Bot = y_end;
        }

        while (vectorFoundWay[_i].index >= 10) // пока не достигли начала
        {
            int tempStep;

            tempStep = vectorFoundWay[_i].index;
            --tempStep;

            for (int i(vectorPassableElement.size()-1); i >= 0; i--)
                {
                    if (vectorPassableElement[i].index == tempStep)
                    {
                        if (_nameBot != OBJ_NAME_BOT_3 && _nameBot != OBJ_NAME_BOT_4)
                        {
                           if (
                                (( vectorPassableElement[i].x == vectorFoundWay[_i].x-1 ) && ( vectorPassableElement[i].y == vectorFoundWay[_i].y   )) ||
                                (( vectorPassableElement[i].x == vectorFoundWay[_i].x   ) && ( vectorPassableElement[i].y == vectorFoundWay[_i].y+1 )) ||
                                (( vectorPassableElement[i].x == vectorFoundWay[_i].x+1 ) && ( vectorPassableElement[i].y == vectorFoundWay[_i].y   )) ||
                                (( vectorPassableElement[i].x == vectorFoundWay[_i].x   ) && ( vectorPassableElement[i].y == vectorFoundWay[_i].y-1 ))
                               )
                            {
                                vectorFoundWay.push_back(vectorPassableElement[i]);
                                break;
                            }
                        } else
                            {
                                if (
                                    (( vectorPassableElement[i].x == vectorFoundWay[_i].x    &&  vectorPassableElement[i].y == vectorFoundWay[_i].y-1) && (vectorPassableElement[i].y >= begin_y_Three_Four_Bot && vectorPassableElement[i].y <= end_y_Three_Four_Bot)) ||
                                    (( vectorPassableElement[i].x == vectorFoundWay[_i].x-1  &&  vectorPassableElement[i].y == vectorFoundWay[_i].y)   && (vectorPassableElement[i].x >= begin_x_Three_Four_Bot && vectorPassableElement[i].x <= end_x_Three_Four_Bot))
                                   )
                                {
                                    vectorFoundWay.push_back(vectorPassableElement[i]);
                                    break;
                                }
                            }
                    }
               }

              ++_i;

            if (vectorFoundWay.size() == _i)
            {
                break;
            }
        }
        for (int _i(vectorFoundWay.size()-1); _i >= 0; _i--)
        {
            n_map[vectorFoundWay[_i].x][vectorFoundWay[_i].y] = -1;
        }
    }
    else
    {
        qDebug() << "Path not found(((";
    }
}

void algorithmLI::setBadWay(int y, int x)
{
    qDebug() << "bad position";
    n_map[x][y] = 7;
}
