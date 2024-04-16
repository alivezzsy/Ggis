/****************************************************************************
** Meta object code from reading C++ file 'openglwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/Widget/openglwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'openglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_openglwidget_t {
    QByteArrayData data[18];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_openglwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_openglwidget_t qt_meta_stringdata_openglwidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "openglwidget"
QT_MOC_LITERAL(1, 13, 14), // "sigUpdateCoord"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "geoX"
QT_MOC_LITERAL(4, 34, 4), // "geoY"
QT_MOC_LITERAL(5, 39, 14), // "onSendMapToGPU"
QT_MOC_LITERAL(6, 54, 7), // "bUpdate"
QT_MOC_LITERAL(7, 62, 16), // "onSendLayerToGPU"
QT_MOC_LITERAL(8, 79, 9), // "GeoLayer*"
QT_MOC_LITERAL(9, 89, 5), // "layer"
QT_MOC_LITERAL(10, 95, 18), // "onSendFeatureToGPU"
QT_MOC_LITERAL(11, 114, 11), // "GeoFeature*"
QT_MOC_LITERAL(12, 126, 7), // "feature"
QT_MOC_LITERAL(13, 134, 23), // "onSendFeatureLayerToGPU"
QT_MOC_LITERAL(14, 158, 16), // "GeoFeatureLayer*"
QT_MOC_LITERAL(15, 175, 12), // "featureLayer"
QT_MOC_LITERAL(16, 188, 13), // "onZoomToLayer"
QT_MOC_LITERAL(17, 202, 11) // "onZoomToMap"

    },
    "openglwidget\0sigUpdateCoord\0\0geoX\0"
    "geoY\0onSendMapToGPU\0bUpdate\0"
    "onSendLayerToGPU\0GeoLayer*\0layer\0"
    "onSendFeatureToGPU\0GeoFeature*\0feature\0"
    "onSendFeatureLayerToGPU\0GeoFeatureLayer*\0"
    "featureLayer\0onZoomToLayer\0onZoomToMap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_openglwidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   69,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x2a /* Public | MethodCloned */,
       7,    2,   73,    2, 0x0a /* Public */,
       7,    1,   78,    2, 0x2a /* Public | MethodCloned */,
      10,    1,   81,    2, 0x0a /* Public */,
      13,    2,   84,    2, 0x0a /* Public */,
      13,    1,   89,    2, 0x2a /* Public | MethodCloned */,
      16,    1,   92,    2, 0x0a /* Public */,
      17,    0,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Bool,    9,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Bool,   15,    6,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

       0        // eod
};

void openglwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        openglwidget *_t = static_cast<openglwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateCoord((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->onSendMapToGPU((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onSendMapToGPU(); break;
        case 3: _t->onSendLayerToGPU((*reinterpret_cast< GeoLayer*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->onSendLayerToGPU((*reinterpret_cast< GeoLayer*(*)>(_a[1]))); break;
        case 5: _t->onSendFeatureToGPU((*reinterpret_cast< GeoFeature*(*)>(_a[1]))); break;
        case 6: _t->onSendFeatureLayerToGPU((*reinterpret_cast< GeoFeatureLayer*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->onSendFeatureLayerToGPU((*reinterpret_cast< GeoFeatureLayer*(*)>(_a[1]))); break;
        case 8: _t->onZoomToLayer((*reinterpret_cast< GeoLayer*(*)>(_a[1]))); break;
        case 9: _t->onZoomToMap(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (openglwidget::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&openglwidget::sigUpdateCoord)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject openglwidget::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_openglwidget.data,
      qt_meta_data_openglwidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *openglwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *openglwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_openglwidget.stringdata0))
        return static_cast<void*>(const_cast< openglwidget*>(this));
    return QOpenGLWidget::qt_metacast(_clname);
}

int openglwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void openglwidget::sigUpdateCoord(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
