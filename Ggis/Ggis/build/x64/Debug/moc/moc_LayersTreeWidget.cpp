/****************************************************************************
** Meta object code from reading C++ file 'LayersTreeWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/Widget/LayersTreeWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LayersTreeWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LayersTreeWidget_t {
    QByteArrayData data[27];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LayersTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LayersTreeWidget_t qt_meta_stringdata_LayersTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "LayersTreeWidget"
QT_MOC_LITERAL(1, 17, 15), // "sigUpdateOpengl"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 15), // "sigSendMapToGPU"
QT_MOC_LITERAL(4, 50, 7), // "bUpdate"
QT_MOC_LITERAL(5, 58, 12), // "sigZoomToMap"
QT_MOC_LITERAL(6, 71, 14), // "sigZoomToLayer"
QT_MOC_LITERAL(7, 86, 9), // "GeoLayer*"
QT_MOC_LITERAL(8, 96, 5), // "layer"
QT_MOC_LITERAL(9, 102, 15), // "sigStartEditing"
QT_MOC_LITERAL(10, 118, 2), // "on"
QT_MOC_LITERAL(11, 121, 18), // "onUpdateLayersTree"
QT_MOC_LITERAL(12, 140, 13), // "onAddNewLayer"
QT_MOC_LITERAL(13, 154, 8), // "newLayer"
QT_MOC_LITERAL(14, 163, 13), // "onItemChanged"
QT_MOC_LITERAL(15, 177, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(16, 194, 4), // "item"
QT_MOC_LITERAL(17, 199, 6), // "column"
QT_MOC_LITERAL(18, 206, 13), // "onRemoveLayer"
QT_MOC_LITERAL(19, 220, 12), // "onRenameItem"
QT_MOC_LITERAL(20, 233, 20), // "onOpenAttributeTable"
QT_MOC_LITERAL(21, 254, 17), // "onShowStyleDialog"
QT_MOC_LITERAL(22, 272, 14), // "onStartEditing"
QT_MOC_LITERAL(23, 287, 11), // "onSaveEdits"
QT_MOC_LITERAL(24, 299, 13), // "onStopEditing"
QT_MOC_LITERAL(25, 313, 11), // "onZoomToMap"
QT_MOC_LITERAL(26, 325, 13) // "onZoomToLayer"

    },
    "LayersTreeWidget\0sigUpdateOpengl\0\0"
    "sigSendMapToGPU\0bUpdate\0sigZoomToMap\0"
    "sigZoomToLayer\0GeoLayer*\0layer\0"
    "sigStartEditing\0on\0onUpdateLayersTree\0"
    "onAddNewLayer\0newLayer\0onItemChanged\0"
    "QTreeWidgetItem*\0item\0column\0onRemoveLayer\0"
    "onRenameItem\0onOpenAttributeTable\0"
    "onShowStyleDialog\0onStartEditing\0"
    "onSaveEdits\0onStopEditing\0onZoomToMap\0"
    "onZoomToLayer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LayersTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    1,  100,    2, 0x06 /* Public */,
       5,    0,  103,    2, 0x06 /* Public */,
       6,    1,  104,    2, 0x06 /* Public */,
       9,    1,  107,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,  110,    2, 0x0a /* Public */,
      12,    1,  111,    2, 0x0a /* Public */,
      14,    2,  114,    2, 0x0a /* Public */,
      18,    0,  119,    2, 0x0a /* Public */,
      19,    0,  120,    2, 0x0a /* Public */,
      20,    0,  121,    2, 0x0a /* Public */,
      21,    0,  122,    2, 0x0a /* Public */,
      22,    0,  123,    2, 0x0a /* Public */,
      23,    0,  124,    2, 0x0a /* Public */,
      24,    0,  125,    2, 0x0a /* Public */,
      25,    0,  126,    2, 0x0a /* Public */,
      26,    0,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Bool,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   13,
    QMetaType::Void, 0x80000000 | 15, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LayersTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LayersTreeWidget *_t = static_cast<LayersTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateOpengl(); break;
        case 1: _t->sigSendMapToGPU((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->sigZoomToMap(); break;
        case 3: _t->sigZoomToLayer((*reinterpret_cast< GeoLayer*(*)>(_a[1]))); break;
        case 4: _t->sigStartEditing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onUpdateLayersTree(); break;
        case 6: _t->onAddNewLayer((*reinterpret_cast< GeoLayer*(*)>(_a[1]))); break;
        case 7: _t->onItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->onRemoveLayer(); break;
        case 9: _t->onRenameItem(); break;
        case 10: _t->onOpenAttributeTable(); break;
        case 11: _t->onShowStyleDialog(); break;
        case 12: _t->onStartEditing(); break;
        case 13: _t->onSaveEdits(); break;
        case 14: _t->onStopEditing(); break;
        case 15: _t->onZoomToMap(); break;
        case 16: _t->onZoomToLayer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LayersTreeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayersTreeWidget::sigUpdateOpengl)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LayersTreeWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayersTreeWidget::sigSendMapToGPU)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (LayersTreeWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayersTreeWidget::sigZoomToMap)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (LayersTreeWidget::*_t)(GeoLayer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayersTreeWidget::sigZoomToLayer)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (LayersTreeWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayersTreeWidget::sigStartEditing)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject LayersTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_LayersTreeWidget.data,
      qt_meta_data_LayersTreeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LayersTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LayersTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LayersTreeWidget.stringdata0))
        return static_cast<void*>(const_cast< LayersTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int LayersTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void LayersTreeWidget::sigUpdateOpengl()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void LayersTreeWidget::sigSendMapToGPU(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LayersTreeWidget::sigZoomToMap()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void LayersTreeWidget::sigZoomToLayer(GeoLayer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LayersTreeWidget::sigStartEditing(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
