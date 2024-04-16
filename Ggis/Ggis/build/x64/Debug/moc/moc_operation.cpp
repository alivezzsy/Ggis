/****************************************************************************
** Meta object code from reading C++ file 'operation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/operation/operation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'operation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Operation_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Operation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Operation_t qt_meta_stringdata_Operation = {
    {
QT_MOC_LITERAL(0, 0, 9) // "Operation"

    },
    "Operation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Operation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void Operation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Operation::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Operation.data,
      qt_meta_data_Operation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Operation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Operation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Operation.stringdata0))
        return static_cast<void*>(const_cast< Operation*>(this));
    return QObject::qt_metacast(_clname);
}

int Operation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_OperationDelete_t {
    QByteArrayData data[4];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OperationDelete_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OperationDelete_t qt_meta_stringdata_OperationDelete = {
    {
QT_MOC_LITERAL(0, 0, 15), // "OperationDelete"
QT_MOC_LITERAL(1, 16, 17), // "sigDeleteFeatures"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10) // "softDelete"

    },
    "OperationDelete\0sigDeleteFeatures\0\0"
    "softDelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OperationDelete[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void OperationDelete::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OperationDelete *_t = static_cast<OperationDelete *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDeleteFeatures((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OperationDelete::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OperationDelete::sigDeleteFeatures)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject OperationDelete::staticMetaObject = {
    { &Operation::staticMetaObject, qt_meta_stringdata_OperationDelete.data,
      qt_meta_data_OperationDelete,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OperationDelete::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OperationDelete::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OperationDelete.stringdata0))
        return static_cast<void*>(const_cast< OperationDelete*>(this));
    return Operation::qt_metacast(_clname);
}

int OperationDelete::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Operation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void OperationDelete::sigDeleteFeatures(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_OperationRotate_t {
    QByteArrayData data[5];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OperationRotate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OperationRotate_t qt_meta_stringdata_OperationRotate = {
    {
QT_MOC_LITERAL(0, 0, 15), // "OperationRotate"
QT_MOC_LITERAL(1, 16, 19), // "sigSendFeatureToGPU"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 11), // "GeoFeature*"
QT_MOC_LITERAL(4, 49, 7) // "feature"

    },
    "OperationRotate\0sigSendFeatureToGPU\0"
    "\0GeoFeature*\0feature"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OperationRotate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void OperationRotate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OperationRotate *_t = static_cast<OperationRotate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigSendFeatureToGPU((*reinterpret_cast< GeoFeature*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (OperationRotate::*_t)(GeoFeature * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&OperationRotate::sigSendFeatureToGPU)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject OperationRotate::staticMetaObject = {
    { &Operation::staticMetaObject, qt_meta_stringdata_OperationRotate.data,
      qt_meta_data_OperationRotate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OperationRotate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OperationRotate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OperationRotate.stringdata0))
        return static_cast<void*>(const_cast< OperationRotate*>(this));
    return Operation::qt_metacast(_clname);
}

int OperationRotate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Operation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void OperationRotate::sigSendFeatureToGPU(GeoFeature * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
