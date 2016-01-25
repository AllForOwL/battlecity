/****************************************************************************
** Meta object code from reading C++ file 'battlecitymap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BattleCity/battlecitymap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'battlecitymap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BattleCityMap_t {
    QByteArrayData data[46];
    char stringdata0[743];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BattleCityMap_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BattleCityMap_t qt_meta_stringdata_BattleCityMap = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BattleCityMap"
QT_MOC_LITERAL(1, 14, 22), // "signalTimeoutForOneBot"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 22), // "signalTimeoutForTwoBot"
QT_MOC_LITERAL(4, 61, 24), // "signalTimeoutForThreeBot"
QT_MOC_LITERAL(5, 86, 7), // "xPlayer"
QT_MOC_LITERAL(6, 94, 7), // "yPlayer"
QT_MOC_LITERAL(7, 102, 23), // "signalTimeoutForFourBot"
QT_MOC_LITERAL(8, 126, 16), // "signalMoveOneBot"
QT_MOC_LITERAL(9, 143, 16), // "signalMoveTwoBot"
QT_MOC_LITERAL(10, 160, 18), // "signalMoveThreeBot"
QT_MOC_LITERAL(11, 179, 17), // "signalMoveFourBot"
QT_MOC_LITERAL(12, 197, 16), // "signalUpdateBase"
QT_MOC_LITERAL(13, 214, 8), // "typeWall"
QT_MOC_LITERAL(14, 223, 14), // "signalGameOver"
QT_MOC_LITERAL(15, 238, 20), // "numberKillsOnePlayer"
QT_MOC_LITERAL(16, 259, 20), // "numberKillsTwoPlayer"
QT_MOC_LITERAL(17, 280, 12), // "slotAddBot_1"
QT_MOC_LITERAL(18, 293, 12), // "slotAddBot_2"
QT_MOC_LITERAL(19, 306, 12), // "slotAddBot_3"
QT_MOC_LITERAL(20, 319, 12), // "slotAddBot_4"
QT_MOC_LITERAL(21, 332, 13), // "slotShowBonus"
QT_MOC_LITERAL(22, 346, 15), // "slotRemoveBonus"
QT_MOC_LITERAL(23, 362, 22), // "slotShowProtectionBase"
QT_MOC_LITERAL(24, 385, 26), // "slotBuildProtectionForBase"
QT_MOC_LITERAL(25, 412, 22), // "slotRemoveBonusForBase"
QT_MOC_LITERAL(26, 435, 17), // "slotShowTimeBonus"
QT_MOC_LITERAL(27, 453, 15), // "slotStopAllBots"
QT_MOC_LITERAL(28, 469, 27), // "slotRemoveBonusForTimeBonus"
QT_MOC_LITERAL(29, 497, 22), // "slotShowExplosionBonus"
QT_MOC_LITERAL(30, 520, 24), // "slotRemoveExplosionBonus"
QT_MOC_LITERAL(31, 545, 29), // "slotRemoveExplosionBonusTimer"
QT_MOC_LITERAL(32, 575, 11), // "slotTimeout"
QT_MOC_LITERAL(33, 587, 12), // "slotMoveBots"
QT_MOC_LITERAL(34, 600, 13), // "slotRunOneBot"
QT_MOC_LITERAL(35, 614, 13), // "slotRunTwoBot"
QT_MOC_LITERAL(36, 628, 15), // "slotRunThreeBot"
QT_MOC_LITERAL(37, 644, 14), // "slotRunFourBot"
QT_MOC_LITERAL(38, 659, 12), // "slotGameOver"
QT_MOC_LITERAL(39, 672, 23), // "slotSetPosPlayerForSend"
QT_MOC_LITERAL(40, 696, 16), // "slotMoveOpponent"
QT_MOC_LITERAL(41, 713, 1), // "x"
QT_MOC_LITERAL(42, 715, 1), // "y"
QT_MOC_LITERAL(43, 717, 6), // "rotate"
QT_MOC_LITERAL(44, 724, 5), // "shot2"
QT_MOC_LITERAL(45, 730, 12) // "slotShotTank"

    },
    "BattleCityMap\0signalTimeoutForOneBot\0"
    "\0signalTimeoutForTwoBot\0"
    "signalTimeoutForThreeBot\0xPlayer\0"
    "yPlayer\0signalTimeoutForFourBot\0"
    "signalMoveOneBot\0signalMoveTwoBot\0"
    "signalMoveThreeBot\0signalMoveFourBot\0"
    "signalUpdateBase\0typeWall\0signalGameOver\0"
    "numberKillsOnePlayer\0numberKillsTwoPlayer\0"
    "slotAddBot_1\0slotAddBot_2\0slotAddBot_3\0"
    "slotAddBot_4\0slotShowBonus\0slotRemoveBonus\0"
    "slotShowProtectionBase\0"
    "slotBuildProtectionForBase\0"
    "slotRemoveBonusForBase\0slotShowTimeBonus\0"
    "slotStopAllBots\0slotRemoveBonusForTimeBonus\0"
    "slotShowExplosionBonus\0slotRemoveExplosionBonus\0"
    "slotRemoveExplosionBonusTimer\0slotTimeout\0"
    "slotMoveBots\0slotRunOneBot\0slotRunTwoBot\0"
    "slotRunThreeBot\0slotRunFourBot\0"
    "slotGameOver\0slotSetPosPlayerForSend\0"
    "slotMoveOpponent\0x\0y\0rotate\0shot2\0"
    "slotShotTank"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BattleCityMap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  189,    2, 0x06 /* Public */,
       3,    0,  190,    2, 0x06 /* Public */,
       4,    2,  191,    2, 0x06 /* Public */,
       7,    2,  196,    2, 0x06 /* Public */,
       8,    0,  201,    2, 0x06 /* Public */,
       9,    0,  202,    2, 0x06 /* Public */,
      10,    0,  203,    2, 0x06 /* Public */,
      11,    0,  204,    2, 0x06 /* Public */,
      12,    1,  205,    2, 0x06 /* Public */,
      14,    2,  208,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  213,    2, 0x0a /* Public */,
      18,    0,  214,    2, 0x0a /* Public */,
      19,    0,  215,    2, 0x0a /* Public */,
      20,    0,  216,    2, 0x0a /* Public */,
      21,    0,  217,    2, 0x0a /* Public */,
      22,    0,  218,    2, 0x0a /* Public */,
      23,    0,  219,    2, 0x0a /* Public */,
      24,    0,  220,    2, 0x0a /* Public */,
      25,    0,  221,    2, 0x0a /* Public */,
      26,    0,  222,    2, 0x0a /* Public */,
      27,    0,  223,    2, 0x0a /* Public */,
      28,    0,  224,    2, 0x0a /* Public */,
      29,    0,  225,    2, 0x0a /* Public */,
      30,    0,  226,    2, 0x0a /* Public */,
      31,    0,  227,    2, 0x0a /* Public */,
      32,    0,  228,    2, 0x0a /* Public */,
      33,    0,  229,    2, 0x0a /* Public */,
      34,    0,  230,    2, 0x0a /* Public */,
      35,    0,  231,    2, 0x0a /* Public */,
      36,    0,  232,    2, 0x0a /* Public */,
      37,    0,  233,    2, 0x0a /* Public */,
      38,    0,  234,    2, 0x0a /* Public */,
      39,    0,  235,    2, 0x0a /* Public */,
      40,    4,  236,    2, 0x0a /* Public */,
      45,    0,  245,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   16,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,   41,   42,   43,   44,
    QMetaType::Void,

       0        // eod
};

void BattleCityMap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BattleCityMap *_t = static_cast<BattleCityMap *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalTimeoutForOneBot(); break;
        case 1: _t->signalTimeoutForTwoBot(); break;
        case 2: _t->signalTimeoutForThreeBot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->signalTimeoutForFourBot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->signalMoveOneBot(); break;
        case 5: _t->signalMoveTwoBot(); break;
        case 6: _t->signalMoveThreeBot(); break;
        case 7: _t->signalMoveFourBot(); break;
        case 8: _t->signalUpdateBase((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->signalGameOver((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->slotAddBot_1(); break;
        case 11: _t->slotAddBot_2(); break;
        case 12: _t->slotAddBot_3(); break;
        case 13: _t->slotAddBot_4(); break;
        case 14: _t->slotShowBonus(); break;
        case 15: _t->slotRemoveBonus(); break;
        case 16: _t->slotShowProtectionBase(); break;
        case 17: _t->slotBuildProtectionForBase(); break;
        case 18: _t->slotRemoveBonusForBase(); break;
        case 19: _t->slotShowTimeBonus(); break;
        case 20: _t->slotStopAllBots(); break;
        case 21: _t->slotRemoveBonusForTimeBonus(); break;
        case 22: _t->slotShowExplosionBonus(); break;
        case 23: _t->slotRemoveExplosionBonus(); break;
        case 24: _t->slotRemoveExplosionBonusTimer(); break;
        case 25: _t->slotTimeout(); break;
        case 26: _t->slotMoveBots(); break;
        case 27: _t->slotRunOneBot(); break;
        case 28: _t->slotRunTwoBot(); break;
        case 29: _t->slotRunThreeBot(); break;
        case 30: _t->slotRunFourBot(); break;
        case 31: _t->slotGameOver(); break;
        case 32: _t->slotSetPosPlayerForSend(); break;
        case 33: _t->slotMoveOpponent((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 34: _t->slotShotTank(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BattleCityMap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleCityMap::signalTimeoutForOneBot)) {
                *result = 0;
            }
        }
        {
            typedef void (BattleCityMap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleCityMap::signalTimeoutForTwoBot)) {
                *result = 1;
            }
        }
        {
            typedef void (BattleCityMap::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleCityMap::signalTimeoutForThreeBot)) {
                *result = 2;
            }
        }
        {
            typedef void (BattleCityMap::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleCityMap::signalTimeoutForFourBot)) {
                *result = 3;
            }
        }
        {
            typedef void (BattleCityMap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleCityMap::signalMoveOneBot)) {
                *result = 4;
            }
        }
        {
            typedef void (BattleCityMap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleCityMap::signalMoveTwoBot)) {
                *result = 5;
            }
        }
        {
            typedef void (BattleCityMap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleCityMap::signalMoveThreeBot)) {
                *result = 6;
            }
        }
        {
            typedef void (BattleCityMap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleCityMap::signalMoveFourBot)) {
                *result = 7;
            }
        }
        {
            typedef void (BattleCityMap::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleCityMap::signalUpdateBase)) {
                *result = 8;
            }
        }
        {
            typedef void (BattleCityMap::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BattleCityMap::signalGameOver)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject BattleCityMap::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_BattleCityMap.data,
      qt_meta_data_BattleCityMap,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BattleCityMap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BattleCityMap::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BattleCityMap.stringdata0))
        return static_cast<void*>(const_cast< BattleCityMap*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int BattleCityMap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void BattleCityMap::signalTimeoutForOneBot()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void BattleCityMap::signalTimeoutForTwoBot()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void BattleCityMap::signalTimeoutForThreeBot(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BattleCityMap::signalTimeoutForFourBot(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BattleCityMap::signalMoveOneBot()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void BattleCityMap::signalMoveTwoBot()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void BattleCityMap::signalMoveThreeBot()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void BattleCityMap::signalMoveFourBot()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void BattleCityMap::signalUpdateBase(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void BattleCityMap::signalGameOver(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
