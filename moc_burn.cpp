/****************************************************************************
** Meta object code from reading C++ file 'burn.h'
**
** Created: Mon Oct 20 05:17:32 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "burn.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'burn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_burn[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_burn[] = {
    "burn\0\0burndevam()\0"
};

const QMetaObject burn::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_burn,
      qt_meta_data_burn, 0 }
};

const QMetaObject *burn::metaObject() const
{
    return &staticMetaObject;
}

void *burn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_burn))
        return static_cast<void*>(const_cast< burn*>(this));
    return QDialog::qt_metacast(_clname);
}

int burn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: burndevam(); break;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
