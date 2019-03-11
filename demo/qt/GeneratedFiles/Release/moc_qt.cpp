/****************************************************************************
** Meta object code from reading C++ file 'qt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qt_t {
    QByteArrayData data[12];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qt_t qt_meta_stringdata_qt = {
    {
QT_MOC_LITERAL(0, 0, 2), // "qt"
QT_MOC_LITERAL(1, 3, 8), // "initView"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 8), // "initMenu"
QT_MOC_LITERAL(4, 22, 9), // "cleanMenu"
QT_MOC_LITERAL(5, 32, 10), // "initLayout"
QT_MOC_LITERAL(6, 43, 11), // "cleanLayout"
QT_MOC_LITERAL(7, 55, 13), // "openVideoSlot"
QT_MOC_LITERAL(8, 69, 15), // "openPictureSlot"
QT_MOC_LITERAL(9, 85, 10), // "paintEvent"
QT_MOC_LITERAL(10, 96, 12), // "QPaintEvent*"
QT_MOC_LITERAL(11, 109, 1) // "e"

    },
    "qt\0initView\0\0initMenu\0cleanMenu\0"
    "initLayout\0cleanLayout\0openVideoSlot\0"
    "openPictureSlot\0paintEvent\0QPaintEvent*\0"
    "e"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qt[] = {

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
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    1,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void qt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        qt *_t = static_cast<qt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initView(); break;
        case 1: _t->initMenu(); break;
        case 2: _t->cleanMenu(); break;
        case 3: _t->initLayout(); break;
        case 4: _t->cleanLayout(); break;
        case 5: _t->openVideoSlot(); break;
        case 6: _t->openPictureSlot(); break;
        case 7: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject qt::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_qt.data,
      qt_meta_data_qt,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *qt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qt.stringdata0))
        return static_cast<void*>(const_cast< qt*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int qt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
