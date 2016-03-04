/****************************************************************************
** Meta object code from reading C++ file 'tank.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BattleCity/tank.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tank.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tank_t {
    QByteArrayData data[19];
    char stringdata[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tank_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tank_t qt_meta_stringdata_Tank = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Tank"
QT_MOC_LITERAL(1, 5, 10), // "signalShot"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 10), // "typeObject"
QT_MOC_LITERAL(4, 28, 18), // "signalTankTookStar"
QT_MOC_LITERAL(5, 47, 28), // "signalBuildProtectionForBase"
QT_MOC_LITERAL(6, 76, 17), // "signalStopAllBots"
QT_MOC_LITERAL(7, 94, 22), // "signalExplosionAllBots"
QT_MOC_LITERAL(8, 117, 15), // "signalGameOver2"
QT_MOC_LITERAL(9, 133, 18), // "signalSearchNewWay"
QT_MOC_LITERAL(10, 152, 9), // "useRotate"
QT_MOC_LITERAL(11, 162, 30), // "signalSearchNewWayFor_3_4_Bots"
QT_MOC_LITERAL(12, 193, 1), // "x"
QT_MOC_LITERAL(13, 195, 1), // "y"
QT_MOC_LITERAL(14, 197, 12), // "slotMoveTank"
QT_MOC_LITERAL(15, 210, 12), // "slotTankShot"
QT_MOC_LITERAL(16, 223, 13), // "slotAllowShot"
QT_MOC_LITERAL(17, 237, 12), // "slotGameOver"
QT_MOC_LITERAL(18, 250, 11) // "slotKillBot"

    },
    "Tank\0signalShot\0\0typeObject\0"
    "signalTankTookStar\0signalBuildProtectionForBase\0"
    "signalStopAllBots\0signalExplosionAllBots\0"
    "signalGameOver2\0signalSearchNewWay\0"
    "useRotate\0signalSearchNewWayFor_3_4_Bots\0"
    "x\0y\0slotMoveTank\0slotTankShot\0"
    "slotAllowShot\0slotGameOver\0slotKillBot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tank[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    0,   82,    2, 0x06 /* Public */,
       5,    0,   83,    2, 0x06 /* Public */,
       6,    0,   84,    2, 0x06 /* Public */,
       7,    0,   85,    2, 0x06 /* Public */,
       8,    0,   86,    2, 0x06 /* Public */,
       9,    1,   87,    2, 0x06 /* Public */,
      11,    2,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   95,    2, 0x0a /* Public */,
      15,    1,   96,    2, 0x0a /* Public */,
      16,    0,   99,    2, 0x0a /* Public */,
      17,    0,  100,    2, 0x0a /* Public */,
      18,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tank::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tank *_t = static_cast<Tank *>(_o);
        switch (_id) {
        case 0: _t->signalShot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->signalTankTookStar(); break;
        case 2: _t->signalBuildProtectionForBase(); break;
        case 3: _t->signalStopAllBots(); break;
        case 4: _t->signalExplosionAllBots(); break;
        case 5: _t->signalGameOver2(); break;
        case 6: _t->signalSearchNewWay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->signalSearchNewWayFor_3_4_Bots((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->slotMoveTank(); break;
        case 9: _t->slotTankShot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->slotAllowShot(); break;
        case 11: _t->slotGameOver(); break;
        case 12: _t->slotKillBot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tank::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tank::signalShot)) {
                *result = 0;
            }
        }
        {
            typedef void (Tank::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tank::signalTankTookStar)) {
                *result = 1;
            }
        }
        {
            typedef void (Tank::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tank::signalBuildProtectionForBase)) {
                *result = 2;
            }
        }
        {
            typedef void (Tank::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tank::signalStopAllBots)) {
                *result = 3;
            }
        }
        {
            typedef void (Tank::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tank::signalExplosionAllBots)) {
                *result = 4;
            }
        }
        {
            typedef void (Tank::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tank::signalGameOver2)) {
                *result = 5;
            }
        }
        {
            typedef void (Tank::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tank::signalSearchNewWay)) {
                *result = 6;
            }
        }
        {
            typedef void (Tank::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tank::signalSearchNewWayFor_3_4_Bots)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject Tank::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tank.data,
      qt_meta_data_Tank,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Tank::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tank::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Tank.stringdata))
        return static_cast<void*>(const_cast< Tank*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< Tank*>(this));
    return QObject::qt_metacast(_clname);
}

int Tank::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Tank::signalShot(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tank::signalTankTookStar()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Tank::signalBuildProtectionForBase()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Tank::signalStopAllBots()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Tank::signalExplosionAllBots()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Tank::signalGameOver2()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Tank::signalSearchNewWay(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Tank::signalSearchNewWayFor_3_4_Bots(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
