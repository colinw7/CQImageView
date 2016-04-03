/****************************************************************************
** Meta object code from reading C++ file 'CQImageView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/CQImageView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CQImageView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CQImageView_t {
    QByteArrayData data[8];
    char stringdata[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CQImageView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CQImageView_t qt_meta_stringdata_CQImageView = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 15),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 1),
QT_MOC_LITERAL(4, 31, 1),
QT_MOC_LITERAL(5, 33, 14),
QT_MOC_LITERAL(6, 48, 14),
QT_MOC_LITERAL(7, 63, 17)
    },
    "CQImageView\0imageMousePress\0\0x\0y\0"
    "imageMouseDrag\0imageMouseMove\0"
    "imageMouseRelease\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CQImageView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06,
       5,    2,   39,    2, 0x06,
       6,    2,   44,    2, 0x06,
       7,    2,   49,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

       0        // eod
};

void CQImageView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CQImageView *_t = static_cast<CQImageView *>(_o);
        switch (_id) {
        case 0: _t->imageMousePress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->imageMouseDrag((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->imageMouseMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->imageMouseRelease((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CQImageView::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQImageView::imageMousePress)) {
                *result = 0;
            }
        }
        {
            typedef void (CQImageView::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQImageView::imageMouseDrag)) {
                *result = 1;
            }
        }
        {
            typedef void (CQImageView::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQImageView::imageMouseMove)) {
                *result = 2;
            }
        }
        {
            typedef void (CQImageView::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CQImageView::imageMouseRelease)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject CQImageView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CQImageView.data,
      qt_meta_data_CQImageView,  qt_static_metacall, 0, 0}
};


const QMetaObject *CQImageView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CQImageView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CQImageView.stringdata))
        return static_cast<void*>(const_cast< CQImageView*>(this));
    return QWidget::qt_metacast(_clname);
}

int CQImageView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CQImageView::imageMousePress(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CQImageView::imageMouseDrag(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CQImageView::imageMouseMove(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CQImageView::imageMouseRelease(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
