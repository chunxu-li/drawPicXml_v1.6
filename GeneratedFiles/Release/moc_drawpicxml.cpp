/****************************************************************************
** Meta object code from reading C++ file 'drawpicxml.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../drawpicxml.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawpicxml.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_drawPicXml_t {
    QByteArrayData data[17];
    char stringdata[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_drawPicXml_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_drawPicXml_t qt_meta_stringdata_drawPicXml = {
    {
QT_MOC_LITERAL(0, 0, 10), // "drawPicXml"
QT_MOC_LITERAL(1, 11, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(4, 60, 35), // "on_actionProcess_pictures_tri..."
QT_MOC_LITERAL(5, 96, 31), // "on_actionGenerate_XML_triggered"
QT_MOC_LITERAL(6, 128, 30), // "on_actionSourse_code_triggered"
QT_MOC_LITERAL(7, 159, 23), // "on_actionHelp_triggered"
QT_MOC_LITERAL(8, 183, 28), // "on_actionShow_Dock_triggered"
QT_MOC_LITERAL(9, 212, 28), // "on_actionOpenFiles_triggered"
QT_MOC_LITERAL(10, 241, 16), // "Slot_ItemClicked"
QT_MOC_LITERAL(11, 258, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(12, 275, 4), // "item"
QT_MOC_LITERAL(13, 280, 33), // "on_actionChangeListSize_trigg..."
QT_MOC_LITERAL(14, 314, 28), // "on_actionListModel_triggered"
QT_MOC_LITERAL(15, 343, 28), // "on_actionIconModel_triggered"
QT_MOC_LITERAL(16, 372, 27) // "on_actionOriginal_triggered"

    },
    "drawPicXml\0on_actionOpen_triggered\0\0"
    "on_actionExit_triggered\0"
    "on_actionProcess_pictures_triggered\0"
    "on_actionGenerate_XML_triggered\0"
    "on_actionSourse_code_triggered\0"
    "on_actionHelp_triggered\0"
    "on_actionShow_Dock_triggered\0"
    "on_actionOpenFiles_triggered\0"
    "Slot_ItemClicked\0QListWidgetItem*\0"
    "item\0on_actionChangeListSize_triggered\0"
    "on_actionListModel_triggered\0"
    "on_actionIconModel_triggered\0"
    "on_actionOriginal_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_drawPicXml[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    1,   87,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void drawPicXml::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        drawPicXml *_t = static_cast<drawPicXml *>(_o);
        switch (_id) {
        case 0: _t->on_actionOpen_triggered(); break;
        case 1: _t->on_actionExit_triggered(); break;
        case 2: _t->on_actionProcess_pictures_triggered(); break;
        case 3: _t->on_actionGenerate_XML_triggered(); break;
        case 4: _t->on_actionSourse_code_triggered(); break;
        case 5: _t->on_actionHelp_triggered(); break;
        case 6: _t->on_actionShow_Dock_triggered(); break;
        case 7: _t->on_actionOpenFiles_triggered(); break;
        case 8: _t->Slot_ItemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 9: _t->on_actionChangeListSize_triggered(); break;
        case 10: _t->on_actionListModel_triggered(); break;
        case 11: _t->on_actionIconModel_triggered(); break;
        case 12: _t->on_actionOriginal_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject drawPicXml::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_drawPicXml.data,
      qt_meta_data_drawPicXml,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *drawPicXml::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *drawPicXml::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_drawPicXml.stringdata))
        return static_cast<void*>(const_cast< drawPicXml*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int drawPicXml::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
