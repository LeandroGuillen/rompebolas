/****************************************************************************
** Meta object code from reading C++ file 'lpanel.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/lpanel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LPanel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      29,    7,    7,    7, 0x05,
      49,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      72,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LPanel[] = {
    "LPanel\0\0puntosCambiados(int)\0"
    "puntosActuales(int)\0puntosLimpiar(QString)\0"
    "nuevo(bool)\0"
};

void LPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        LPanel *_t = static_cast<LPanel *>(_o);
        switch (_id) {
        case 0: _t->puntosCambiados((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->puntosActuales((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->puntosLimpiar((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->nuevo((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData LPanel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject LPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LPanel,
      qt_meta_data_LPanel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LPanel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LPanel))
        return static_cast<void*>(const_cast< LPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int LPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void LPanel::puntosCambiados(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LPanel::puntosActuales(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LPanel::puntosLimpiar(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
