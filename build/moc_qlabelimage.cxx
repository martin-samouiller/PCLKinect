/****************************************************************************
** Meta object code from reading C++ file 'qlabelimage.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qlabelimage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlabelimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QLabelImage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      29,   12,   12,   12, 0x05,
      41,   12,   12,   12, 0x05,
      59,   12,   12,   12, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QLabelImage[] = {
    "QLabelImage\0\0Mouse_Pressed()\0Mouse_Pos()\0"
    "Mouse_ClickLeft()\0Mouse_ReleasePos()\0"
};

void QLabelImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QLabelImage *_t = static_cast<QLabelImage *>(_o);
        switch (_id) {
        case 0: _t->Mouse_Pressed(); break;
        case 1: _t->Mouse_Pos(); break;
        case 2: _t->Mouse_ClickLeft(); break;
        case 3: _t->Mouse_ReleasePos(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData QLabelImage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QLabelImage::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QLabelImage,
      qt_meta_data_QLabelImage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QLabelImage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QLabelImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QLabelImage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QLabelImage))
        return static_cast<void*>(const_cast< QLabelImage*>(this));
    return QLabel::qt_metacast(_clname);
}

int QLabelImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QLabelImage::Mouse_Pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QLabelImage::Mouse_Pos()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QLabelImage::Mouse_ClickLeft()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QLabelImage::Mouse_ReleasePos()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
