/****************************************************************************
** Meta object code from reading C++ file 'acquisitionwindows.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/acquisitionwindows.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'acquisitionwindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AcquisitionWindows[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   19,   20,   19, 0x0a,
      39,   19,   19,   19, 0x0a,
      54,   19,   19,   19, 0x0a,
      70,   19,   19,   19, 0x08,
      97,   19,   19,   19, 0x08,
     125,   19,   19,   19, 0x08,
     141,   19,   19,   19, 0x08,
     158,   19,   19,   19, 0x08,
     178,   19,   19,   19, 0x08,
     193,   19,   19,   19, 0x08,
     220,   19,   19,   19, 0x08,
     253,   19,   19,   19, 0x08,
     282,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AcquisitionWindows[] = {
    "AcquisitionWindows\0\0int\0DemarerAcqui()\0"
    "StopperAcqui()\0ConnectDevice()\0"
    "Mouse_current_pos_stream()\0"
    "Mouse_current_pos_capture()\0Mouse_pressed()\0"
    "MouseClickLeft()\0Mouse_release_pos()\0"
    "displayFrame()\0on_rdnBtn_jetLUT_clicked()\0"
    "on_rdnBtn_grayscaleLUT_clicked()\0"
    "on_rndBtn_oceanLUT_clicked()\0"
    "on_pushButton_SaveCloud_clicked()\0"
};

void AcquisitionWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AcquisitionWindows *_t = static_cast<AcquisitionWindows *>(_o);
        switch (_id) {
        case 0: { int _r = _t->DemarerAcqui();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: _t->StopperAcqui(); break;
        case 2: _t->ConnectDevice(); break;
        case 3: _t->Mouse_current_pos_stream(); break;
        case 4: _t->Mouse_current_pos_capture(); break;
        case 5: _t->Mouse_pressed(); break;
        case 6: _t->MouseClickLeft(); break;
        case 7: _t->Mouse_release_pos(); break;
        case 8: _t->displayFrame(); break;
        case 9: _t->on_rdnBtn_jetLUT_clicked(); break;
        case 10: _t->on_rdnBtn_grayscaleLUT_clicked(); break;
        case 11: _t->on_rndBtn_oceanLUT_clicked(); break;
        case 12: _t->on_pushButton_SaveCloud_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AcquisitionWindows::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AcquisitionWindows::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AcquisitionWindows,
      qt_meta_data_AcquisitionWindows, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AcquisitionWindows::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AcquisitionWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AcquisitionWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AcquisitionWindows))
        return static_cast<void*>(const_cast< AcquisitionWindows*>(this));
    return QDialog::qt_metacast(_clname);
}

int AcquisitionWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
