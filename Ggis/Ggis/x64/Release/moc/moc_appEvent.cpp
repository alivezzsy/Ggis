/****************************************************************************
** Meta object code from reading C++ file 'appEvent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/utilities/appEvent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'appEvent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppEvent_t {
    QByteArrayData data[43];
    char stringdata0[596];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppEvent_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppEvent_t qt_meta_stringdata_AppEvent = {
    {
QT_MOC_LITERAL(0, 0, 8), // "AppEvent"
QT_MOC_LITERAL(1, 9, 15), // "sigUpdateOpengl"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 26), // "sigAddNewLayerToLayersTree"
QT_MOC_LITERAL(4, 53, 9), // "GeoLayer*"
QT_MOC_LITERAL(5, 63, 5), // "layer"
QT_MOC_LITERAL(6, 69, 15), // "sigSendMapToGPU"
QT_MOC_LITERAL(7, 85, 7), // "bUpdate"
QT_MOC_LITERAL(8, 93, 17), // "sigSendLayerToGPU"
QT_MOC_LITERAL(9, 111, 19), // "sigSendFeatureToGPU"
QT_MOC_LITERAL(10, 131, 11), // "GeoFeature*"
QT_MOC_LITERAL(11, 143, 7), // "feature"
QT_MOC_LITERAL(12, 151, 12), // "sigZoomToMap"
QT_MOC_LITERAL(13, 164, 14), // "sigZoomToLayer"
QT_MOC_LITERAL(14, 179, 14), // "sigUpdateCoord"
QT_MOC_LITERAL(15, 194, 4), // "geoX"
QT_MOC_LITERAL(16, 199, 4), // "geoY"
QT_MOC_LITERAL(17, 204, 15), // "sigStartEditing"
QT_MOC_LITERAL(18, 220, 2), // "on"
QT_MOC_LITERAL(19, 223, 19), // "sigUpdateCursorType"
QT_MOC_LITERAL(20, 243, 17), // "sigDeleteFeatures"
QT_MOC_LITERAL(21, 261, 10), // "softDelete"
QT_MOC_LITERAL(22, 272, 13), // "sigAddShpData"
QT_MOC_LITERAL(23, 286, 14), // "sigAddJsonData"
QT_MOC_LITERAL(24, 301, 14), // "sigStarAddData"
QT_MOC_LITERAL(25, 316, 13), // "sigEndAddData"
QT_MOC_LITERAL(26, 330, 14), // "sigZoomChanged"
QT_MOC_LITERAL(27, 345, 14), // "onUpdateOpengl"
QT_MOC_LITERAL(28, 360, 25), // "onAddNewLayerToLayersTree"
QT_MOC_LITERAL(29, 386, 14), // "onSendMapToGPU"
QT_MOC_LITERAL(30, 401, 16), // "onSendLayerToGPU"
QT_MOC_LITERAL(31, 418, 18), // "onSendFeatureToGPU"
QT_MOC_LITERAL(32, 437, 11), // "onZoomToMap"
QT_MOC_LITERAL(33, 449, 13), // "onZoomToLayer"
QT_MOC_LITERAL(34, 463, 13), // "onUpdateCoord"
QT_MOC_LITERAL(35, 477, 14), // "onStartEditing"
QT_MOC_LITERAL(36, 492, 18), // "onUpdateCursorType"
QT_MOC_LITERAL(37, 511, 16), // "onDeleteFeatures"
QT_MOC_LITERAL(38, 528, 12), // "onAddShpData"
QT_MOC_LITERAL(39, 541, 13), // "onAddJsonData"
QT_MOC_LITERAL(40, 555, 13), // "onStarAddData"
QT_MOC_LITERAL(41, 569, 12), // "onEndAddData"
QT_MOC_LITERAL(42, 582, 13) // "onZoomChanged"

    },
    "AppEvent\0sigUpdateOpengl\0\0"
    "sigAddNewLayerToLayersTree\0GeoLayer*\0"
    "layer\0sigSendMapToGPU\0bUpdate\0"
    "sigSendLayerToGPU\0sigSendFeatureToGPU\0"
    "GeoFeature*\0feature\0sigZoomToMap\0"
    "sigZoomToLayer\0sigUpdateCoord\0geoX\0"
    "geoY\0sigStartEditing\0on\0sigUpdateCursorType\0"
    "sigDeleteFeatures\0softDelete\0sigAddShpData\0"
    "sigAddJsonData\0sigStarAddData\0"
    "sigEndAddData\0sigZoomChanged\0"
    "onUpdateOpengl\0onAddNewLayerToLayersTree\0"
    "onSendMapToGPU\0onSendLayerToGPU\0"
    "onSendFeatureToGPU\0onZoomToMap\0"
    "onZoomToLayer\0onUpdateCoord\0onStartEditing\0"
    "onUpdateCursorType\0onDeleteFeatures\0"
    "onAddShpData\0onAddJsonData\0onStarAddData\0"
    "onEndAddData\0onZoomChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppEvent[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      18,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  194,    2, 0x06 /* Public */,
       3,    1,  195,    2, 0x06 /* Public */,
       6,    1,  198,    2, 0x06 /* Public */,
       6,    0,  201,    2, 0x26 /* Public | MethodCloned */,
       8,    2,  202,    2, 0x06 /* Public */,
       8,    1,  207,    2, 0x26 /* Public | MethodCloned */,
       9,    1,  210,    2, 0x06 /* Public */,
      12,    0,  213,    2, 0x06 /* Public */,
      13,    1,  214,    2, 0x06 /* Public */,
      14,    2,  217,    2, 0x06 /* Public */,
      17,    1,  222,    2, 0x06 /* Public */,
      19,    0,  225,    2, 0x06 /* Public */,
      20,    1,  226,    2, 0x06 /* Public */,
      22,    0,  229,    2, 0x06 /* Public */,
      23,    0,  230,    2, 0x06 /* Public */,
      24,    0,  231,    2, 0x06 /* Public */,
      25,    0,  232,    2, 0x06 /* Public */,
      26,    0,  233,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      27,    0,  234,    2, 0x0a /* Public */,
      28,    1,  235,    2, 0x0a /* Public */,
      29,    1,  238,    2, 0x0a /* Public */,
      29,    0,  241,    2, 0x2a /* Public | MethodCloned */,
      30,    2,  242,    2, 0x0a /* Public */,
      30,    1,  247,    2, 0x2a /* Public | MethodCloned */,
      31,    1,  250,    2, 0x0a /* Public */,
      32,    0,  253,    2, 0x0a /* Public */,
      33,    1,  254,    2, 0x0a /* Public */,
      34,    2,  257,    2, 0x0a /* Public */,
      35,    1,  262,    2, 0x0a /* Public */,
      36,    0,  265,    2, 0x0a /* Public */,
      37,    1,  266,    2, 0x0a /* Public */,
      38,    0,  269,    2, 0x0a /* Public */,
      39,    0,  270,    2, 0x0a /* Public */,
      40,    0,  271,    2, 0x0a /* Public */,
      41,    0,  272,    2, 0x0a /* Public */,
      42,    0,  273,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    5,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   15,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    5,    7,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   15,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AppEvent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppEvent *_t = static_cast<AppEvent *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateOpengl(); break;
        case 1: _t->sigAddNewLayerToLayersTree((*reinterpret_cast< GeoLayer*(*)>(_a[1]))); break;
        case 2: _t->sigSendMapToGPU((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->sigSendMapToGPU(); break;
        case 4: _t->sigSendLayerToGPU((*reinterpret_cast< GeoLayer*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->sigSendLayerToGPU((*reinterpret_cast< GeoLayer*(*)>(_a[1]))); break;
        case 6: _t->sigSendFeatureToGPU((*reinterpret_cast< GeoFeature*(*)>(_a[1]))); break;
        case 7: _t->sigZoomToMap(); break;
        case 8: _t->sigZoomToLayer((*reinterpret_cast< GeoLayer*(*)>(_a[1]))); break;
        case 9: _t->sigUpdateCoord((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 10: _t->sigStartEditing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->sigUpdateCursorType(); break;
        case 12: _t->sigDeleteFeatures((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->sigAddShpData(); break;
        case 14: _t->sigAddJsonData(); break;
        case 15: _t->sigStarAddData(); break;
        case 16: _t->sigEndAddData(); break;
        case 17: _t->sigZoomChanged(); break;
        case 18: _t->onUpdateOpengl(); break;
        case 19: _t->onAddNewLayerToLayersTree((*reinterpret_cast< GeoLayer*(*)>(_a[1]))); break;
        case 20: _t->onSendMapToGPU((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->onSendMapToGPU(); break;
        case 22: _t->onSendLayerToGPU((*reinterpret_cast< GeoLayer*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 23: _t->onSendLayerToGPU((*reinterpret_cast< GeoLayer*(*)>(_a[1]))); break;
        case 24: _t->onSendFeatureToGPU((*reinterpret_cast< GeoFeature*(*)>(_a[1]))); break;
        case 25: _t->onZoomToMap(); break;
        case 26: _t->onZoomToLayer((*reinterpret_cast< GeoLayer*(*)>(_a[1]))); break;
        case 27: _t->onUpdateCoord((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 28: _t->onStartEditing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->onUpdateCursorType(); break;
        case 30: _t->onDeleteFeatures((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->onAddShpData(); break;
        case 32: _t->onAddJsonData(); break;
        case 33: _t->onStarAddData(); break;
        case 34: _t->onEndAddData(); break;
        case 35: _t->onZoomChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AppEvent::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigUpdateOpengl)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)(GeoLayer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigAddNewLayerToLayersTree)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigSendMapToGPU)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)(GeoLayer * , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigSendLayerToGPU)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)(GeoFeature * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigSendFeatureToGPU)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigZoomToMap)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)(GeoLayer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigZoomToLayer)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigUpdateCoord)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigStartEditing)) {
                *result = 10;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigUpdateCursorType)) {
                *result = 11;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigDeleteFeatures)) {
                *result = 12;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigAddShpData)) {
                *result = 13;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigAddJsonData)) {
                *result = 14;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigStarAddData)) {
                *result = 15;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigEndAddData)) {
                *result = 16;
                return;
            }
        }
        {
            typedef void (AppEvent::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppEvent::sigZoomChanged)) {
                *result = 17;
                return;
            }
        }
    }
}

const QMetaObject AppEvent::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AppEvent.data,
      qt_meta_data_AppEvent,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AppEvent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppEvent::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AppEvent.stringdata0))
        return static_cast<void*>(const_cast< AppEvent*>(this));
    return QObject::qt_metacast(_clname);
}

int AppEvent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 36;
    }
    return _id;
}

// SIGNAL 0
void AppEvent::sigUpdateOpengl()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AppEvent::sigAddNewLayerToLayersTree(GeoLayer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AppEvent::sigSendMapToGPU(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 4
void AppEvent::sigSendLayerToGPU(GeoLayer * _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 6
void AppEvent::sigSendFeatureToGPU(GeoFeature * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void AppEvent::sigZoomToMap()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void AppEvent::sigZoomToLayer(GeoLayer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void AppEvent::sigUpdateCoord(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void AppEvent::sigStartEditing(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void AppEvent::sigUpdateCursorType()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void AppEvent::sigDeleteFeatures(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void AppEvent::sigAddShpData()
{
    QMetaObject::activate(this, &staticMetaObject, 13, Q_NULLPTR);
}

// SIGNAL 14
void AppEvent::sigAddJsonData()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}

// SIGNAL 15
void AppEvent::sigStarAddData()
{
    QMetaObject::activate(this, &staticMetaObject, 15, Q_NULLPTR);
}

// SIGNAL 16
void AppEvent::sigEndAddData()
{
    QMetaObject::activate(this, &staticMetaObject, 16, Q_NULLPTR);
}

// SIGNAL 17
void AppEvent::sigZoomChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
