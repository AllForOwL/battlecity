/****************************************************************************
** Meta object code from reading C++ file 'mainmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../BattleCity/mainmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mainMenu_t {
    QByteArrayData data[11];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainMenu_t qt_meta_stringdata_mainMenu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mainMenu"
QT_MOC_LITERAL(1, 9, 16), // "slotCreateServer"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 16), // "slotCreateClient"
QT_MOC_LITERAL(4, 44, 13), // "slotRunServer"
QT_MOC_LITERAL(5, 58, 19), // "slotConnectToServer"
QT_MOC_LITERAL(6, 78, 30), // "slotSendMessageConnectToServer"
QT_MOC_LITERAL(7, 109, 18), // "slotReadNameServer"
QT_MOC_LITERAL(8, 128, 10), // "nameServer"
QT_MOC_LITERAL(9, 139, 19), // "slotStartGameServer"
QT_MOC_LITERAL(10, 159, 19) // "slotStartGameClient"

    },
    "mainMenu\0slotCreateServer\0\0slotCreateClient\0"
    "slotRunServer\0slotConnectToServer\0"
    "slotSendMessageConnectToServer\0"
    "slotReadNameServer\0nameServer\0"
    "slotStartGameServer\0slotStartGameClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    1,   59,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x0a /* Public */,
      10,    0,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainMenu *_t = static_cast<mainMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotCreateServer(); break;
        case 1: _t->slotCreateClient(); break;
        case 2: _t->slotRunServer(); break;
        case 3: _t->slotConnectToServer(); break;
        case 4: _t->slotSendMessageConnectToServer(); break;
        case 5: _t->slotReadNameServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->slotStartGameServer(); break;
        case 7: _t->slotStartGameClient(); break;
        default: ;
        }
    }
}

const QMetaObject mainMenu::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_mainMenu.data,
      qt_meta_data_mainMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mainMenu.stringdata0))
        return static_cast<void*>(const_cast< mainMenu*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int mainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
