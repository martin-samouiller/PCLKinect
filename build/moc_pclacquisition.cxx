/****************************************************************************
** Meta object code from reading C++ file 'pclacquisition.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/pclacquisition.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pclacquisition.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PCLAcquisition[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      42,   15,   15,   15, 0x08,
      69,   15,   15,   15, 0x08,
      95,   15,   15,   15, 0x08,
     124,   15,   15,   15, 0x08,
     153,   15,   15,   15, 0x08,
     186,  178,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PCLAcquisition[] = {
    "PCLAcquisition\0\0on_actionSave_triggered()\0"
    "on_actionStart_triggered()\0"
    "on_actionOpen_triggered()\0"
    "on_actionTexture_triggered()\0"
    "on_actionFiltrer_triggered()\0"
    "on_actionICP_triggered()\0cur,pre\0"
    "on_listClouds_current_change(QModelIndex,QModelIndex)\0"
};

void PCLAcquisition::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PCLAcquisition *_t = static_cast<PCLAcquisition *>(_o);
        switch (_id) {
        case 0: _t->on_actionSave_triggered(); break;
        case 1: _t->on_actionStart_triggered(); break;
        case 2: _t->on_actionOpen_triggered(); break;
        case 3: _t->on_actionTexture_triggered(); break;
        case 4: _t->on_actionFiltrer_triggered(); break;
        case 5: _t->on_actionICP_triggered(); break;
        case 6: _t->on_listClouds_current_change((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PCLAcquisition::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PCLAcquisition::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PCLAcquisition,
      qt_meta_data_PCLAcquisition, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PCLAcquisition::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PCLAcquisition::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PCLAcquisition::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PCLAcquisition))
        return static_cast<void*>(const_cast< PCLAcquisition*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PCLAcquisition::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
