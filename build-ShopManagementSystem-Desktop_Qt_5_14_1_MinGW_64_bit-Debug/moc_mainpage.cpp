/****************************************************************************
** Meta object code from reading C++ file 'mainpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../ShopManagementSystem/mainpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainpage_t {
    QByteArrayData data[13];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainpage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainpage_t qt_meta_stringdata_mainpage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mainpage"
QT_MOC_LITERAL(1, 9, 21), // "on_umaction_triggered"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "on_actionmima_triggered"
QT_MOC_LITERAL(4, 56, 25), // "on_actiondenglu_triggered"
QT_MOC_LITERAL(5, 82, 24), // "on_actionxinxi_triggered"
QT_MOC_LITERAL(6, 107, 25), // "on_actionjinhuo_triggered"
QT_MOC_LITERAL(7, 133, 10), // "ifSupplier"
QT_MOC_LITERAL(8, 144, 22), // "insertSuplier_manage_v"
QT_MOC_LITERAL(9, 167, 29), // "on_pushButton1_submit_clicked"
QT_MOC_LITERAL(10, 197, 29), // "on_pushButton2_search_clicked"
QT_MOC_LITERAL(11, 227, 29), // "on_pushButton2_modify_clicked"
QT_MOC_LITERAL(12, 257, 29) // "on_pushButton3_submit_clicked"

    },
    "mainpage\0on_umaction_triggered\0\0"
    "on_actionmima_triggered\0"
    "on_actiondenglu_triggered\0"
    "on_actionxinxi_triggered\0"
    "on_actionjinhuo_triggered\0ifSupplier\0"
    "insertSuplier_manage_v\0"
    "on_pushButton1_submit_clicked\0"
    "on_pushButton2_search_clicked\0"
    "on_pushButton2_modify_clicked\0"
    "on_pushButton3_submit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainpage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mainpage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainpage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_umaction_triggered(); break;
        case 1: _t->on_actionmima_triggered(); break;
        case 2: _t->on_actiondenglu_triggered(); break;
        case 3: _t->on_actionxinxi_triggered(); break;
        case 4: _t->on_actionjinhuo_triggered(); break;
        case 5: { bool _r = _t->ifSupplier();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->insertSuplier_manage_v(); break;
        case 7: _t->on_pushButton1_submit_clicked(); break;
        case 8: _t->on_pushButton2_search_clicked(); break;
        case 9: _t->on_pushButton2_modify_clicked(); break;
        case 10: _t->on_pushButton3_submit_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mainpage::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_mainpage.data,
    qt_meta_data_mainpage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mainpage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainpage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainpage.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int mainpage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
