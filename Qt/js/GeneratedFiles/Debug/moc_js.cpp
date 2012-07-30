/****************************************************************************
** Meta object code from reading C++ file 'js.h'
**
** Created: Tue Jul 24 13:29:50 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../js.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'js.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_js[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       4,    3,    3,    3, 0x08,
      24,    3,    3,    3, 0x08,
      49,    3,    3,    3, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_js[] = {
    "js\0\0OnCubeClickedSlot()\0"
    "OnfactorialClickedSlot()\0OnpiClickedSlot()\0"
};

const QMetaObject js::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_js,
      qt_meta_data_js, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &js::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *js::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *js::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_js))
        return static_cast<void*>(const_cast< js*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int js::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: OnCubeClickedSlot(); break;
        case 1: OnfactorialClickedSlot(); break;
        case 2: OnpiClickedSlot(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
