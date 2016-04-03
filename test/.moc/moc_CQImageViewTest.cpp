/****************************************************************************
** Meta object code from reading C++ file 'CQImageViewTest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CQImageViewTest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CQImageViewTest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CQImageViewTest_t {
    QByteArrayData data[14];
    char stringdata[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CQImageViewTest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CQImageViewTest_t qt_meta_stringdata_CQImageViewTest = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 17),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 1),
QT_MOC_LITERAL(4, 37, 1),
QT_MOC_LITERAL(5, 39, 8),
QT_MOC_LITERAL(6, 48, 8),
QT_MOC_LITERAL(7, 57, 8),
QT_MOC_LITERAL(8, 66, 9),
QT_MOC_LITERAL(9, 76, 7),
QT_MOC_LITERAL(10, 84, 9),
QT_MOC_LITERAL(11, 94, 8),
QT_MOC_LITERAL(12, 103, 8),
QT_MOC_LITERAL(13, 112, 11)
    },
    "CQImageViewTest\0imagePositionSlot\0\0x\0"
    "y\0nextSlot\0prevSlot\0graySlot\0sepiaSlot\0"
    "redSlot\0greenSlot\0blueSlot\0gridSlot\0"
    "updateState\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CQImageViewTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x08,
       5,    0,   69,    2, 0x08,
       6,    0,   70,    2, 0x08,
       7,    0,   71,    2, 0x08,
       8,    0,   72,    2, 0x08,
       9,    0,   73,    2, 0x08,
      10,    0,   74,    2, 0x08,
      11,    0,   75,    2, 0x08,
      12,    0,   76,    2, 0x08,
      13,    0,   77,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CQImageViewTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CQImageViewTest *_t = static_cast<CQImageViewTest *>(_o);
        switch (_id) {
        case 0: _t->imagePositionSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->nextSlot(); break;
        case 2: _t->prevSlot(); break;
        case 3: _t->graySlot(); break;
        case 4: _t->sepiaSlot(); break;
        case 5: _t->redSlot(); break;
        case 6: _t->greenSlot(); break;
        case 7: _t->blueSlot(); break;
        case 8: _t->gridSlot(); break;
        case 9: _t->updateState(); break;
        default: ;
        }
    }
}

const QMetaObject CQImageViewTest::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CQImageViewTest.data,
      qt_meta_data_CQImageViewTest,  qt_static_metacall, 0, 0}
};


const QMetaObject *CQImageViewTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CQImageViewTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CQImageViewTest.stringdata))
        return static_cast<void*>(const_cast< CQImageViewTest*>(this));
    return QDialog::qt_metacast(_clname);
}

int CQImageViewTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
