#include "parsing.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

Parsing::Parsing() {}

bool Parsing::ParsTextFile(const QString &nameFile, int n_Map[CNT_ROWS_MAP][CNT_COLS_MAP])
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

    while (!n_StreamReadFile.atEnd()) {
        n_StreamReadFile >> n_Map[i][j];

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
    }

    n_FileForRead.flush();
    n_FileForRead.close();

    return true;
}
