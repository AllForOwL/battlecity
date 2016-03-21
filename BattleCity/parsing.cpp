#include "parsing.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

Parsing::Parsing() {}

bool Parsing::ParsTextFile(const QString &nameFile, int n_Map[CNT_ROWS_MAP][CNT_COLS_MAP], bool searchGoodWay)
{
    QFile   n_FileForRead(nameFile);
    if (!n_FileForRead.exists()) {
        qDebug() << "File not create!";
    }

    int i = 0;
    int j = 0;
    int tempRows = CNT_ROWS_MAP - 1;
    int tempCols = CNT_COLS_MAP - 1;

    if (!n_FileForRead.open(QIODevice::ReadOnly)) {
        qDebug() << "Can't open file!";
        return false;
    }

    QTextStream  n_StreamReadFile(&n_FileForRead);

    int audit_rows_dec = 0;
    int audit_rows_inc = 0;

    while (!n_StreamReadFile.atEnd()) {
        n_StreamReadFile >> n_Map[i][j];

        if (searchGoodWay && audit_rows_dec > 2)
        {
            --audit_rows_dec;
            ++audit_rows_inc;
            if ( n_Map[i][j] == OBJ_TYPE_WHITE_WALL || n_Map[i][j] == OBJ_TYPE_WATER &&
                 n_Map[i][audit_rows_dec] != OBJ_TYPE_WHITE_WALL && OBJ_TYPE_WATER
               )
            {
                n_Map[i][audit_rows_dec] = OBJ_TYPE_WHITE_WALL;
            }
            else if ( n_Map[i][j] == OBJ_TYPE_WHITE_WALL || n_Map[i][j] == OBJ_TYPE_WATER &&
                      n_Map[i][audit_rows_inc] != OBJ_TYPE_WHITE_WALL && OBJ_TYPE_WATER
                    )
            {
                n_Map[i][audit_rows_inc] = OBJ_TYPE_WHITE_WALL;
            }
        }

        if ((i == (tempRows) && (j == (tempCols)))) {
            break;
        }
        else if (j == tempCols) {
            ++i;
            j = 0;
        }
        else {
            ++j;
        }

        audit_rows_dec = j;
        audit_rows_inc = j;
    }

    n_FileForRead.flush();
    n_FileForRead.close();

    return true;
}
