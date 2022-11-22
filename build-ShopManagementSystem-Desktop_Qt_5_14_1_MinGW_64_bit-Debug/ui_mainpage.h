/********************************************************************************
** Form generated from reading UI file 'mainpage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINPAGE_H
#define UI_MAINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainpage
{
public:
    QAction *umaction;
    QAction *actionmima;
    QAction *actiondenglu;
    QAction *actionxinxi;
    QAction *actionkucun;
    QAction *actionjinhuo;
    QAction *actionjiezhang;
    QAction *actiontongji;
    QAction *actionxinxi_2;
    QAction *actionchaxun;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QLabel *label;
    QLineEdit *lineEdit1_account;
    QLineEdit *lineEdit1_first;
    QLineEdit *lineEdit1_name;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton1_submit;
    QLabel *label_5;
    QLineEdit *lineEdit1_next;
    QWidget *page_3;
    QLabel *label_6;
    QLineEdit *lineEdit2_Gname;
    QLineEdit *lineEdit2_ID;
    QPushButton *pushButton2_search;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit2_Gprice;
    QPushButton *pushButton2_modify;
    QWidget *page_4;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *lineEdit3_suplierID;
    QLineEdit *lineEdit3_suplierName;
    QLineEdit *lineEdit3_suplierDesc;
    QLineEdit *lineEdit3_goodsID;
    QLineEdit *lineEdit3_goodsName;
    QLineEdit *lineEdit3_goodsNum;
    QLineEdit *lineEdit3_marketPrice;
    QLineEdit *lineEdit3_shopPrice;
    QLineEdit *lineEdit3_goodsDesc;
    QPushButton *pushButton3_submit;
    QTableView *shopTable;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainpage)
    {
        if (mainpage->objectName().isEmpty())
            mainpage->setObjectName(QString::fromUtf8("mainpage"));
        mainpage->resize(800, 600);
        umaction = new QAction(mainpage);
        umaction->setObjectName(QString::fromUtf8("umaction"));
        actionmima = new QAction(mainpage);
        actionmima->setObjectName(QString::fromUtf8("actionmima"));
        actiondenglu = new QAction(mainpage);
        actiondenglu->setObjectName(QString::fromUtf8("actiondenglu"));
        actionxinxi = new QAction(mainpage);
        actionxinxi->setObjectName(QString::fromUtf8("actionxinxi"));
        actionkucun = new QAction(mainpage);
        actionkucun->setObjectName(QString::fromUtf8("actionkucun"));
        actionjinhuo = new QAction(mainpage);
        actionjinhuo->setObjectName(QString::fromUtf8("actionjinhuo"));
        actionjiezhang = new QAction(mainpage);
        actionjiezhang->setObjectName(QString::fromUtf8("actionjiezhang"));
        actiontongji = new QAction(mainpage);
        actiontongji->setObjectName(QString::fromUtf8("actiontongji"));
        actionxinxi_2 = new QAction(mainpage);
        actionxinxi_2->setObjectName(QString::fromUtf8("actionxinxi_2"));
        actionchaxun = new QAction(mainpage);
        actionchaxun->setObjectName(QString::fromUtf8("actionchaxun"));
        centralwidget = new QWidget(mainpage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 410, 801, 161));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 151, 16));
        lineEdit1_account = new QLineEdit(page_2);
        lineEdit1_account->setObjectName(QString::fromUtf8("lineEdit1_account"));
        lineEdit1_account->setGeometry(QRect(130, 40, 113, 21));
        lineEdit1_first = new QLineEdit(page_2);
        lineEdit1_first->setObjectName(QString::fromUtf8("lineEdit1_first"));
        lineEdit1_first->setGeometry(QRect(130, 80, 113, 21));
        lineEdit1_name = new QLineEdit(page_2);
        lineEdit1_name->setObjectName(QString::fromUtf8("lineEdit1_name"));
        lineEdit1_name->setGeometry(QRect(350, 40, 113, 21));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 40, 41, 16));
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 80, 71, 16));
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 40, 41, 16));
        pushButton1_submit = new QPushButton(page_2);
        pushButton1_submit->setObjectName(QString::fromUtf8("pushButton1_submit"));
        pushButton1_submit->setGeometry(QRect(630, 60, 93, 28));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(270, 90, 68, 15));
        lineEdit1_next = new QLineEdit(page_2);
        lineEdit1_next->setObjectName(QString::fromUtf8("lineEdit1_next"));
        lineEdit1_next->setGeometry(QRect(350, 80, 113, 21));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 101, 16));
        lineEdit2_Gname = new QLineEdit(page_3);
        lineEdit2_Gname->setObjectName(QString::fromUtf8("lineEdit2_Gname"));
        lineEdit2_Gname->setGeometry(QRect(320, 40, 113, 21));
        lineEdit2_ID = new QLineEdit(page_3);
        lineEdit2_ID->setObjectName(QString::fromUtf8("lineEdit2_ID"));
        lineEdit2_ID->setGeometry(QRect(130, 40, 113, 21));
        pushButton2_search = new QPushButton(page_3);
        pushButton2_search->setObjectName(QString::fromUtf8("pushButton2_search"));
        pushButton2_search->setGeometry(QRect(340, 90, 93, 28));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(260, 40, 68, 16));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 40, 68, 15));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(460, 40, 68, 15));
        lineEdit2_Gprice = new QLineEdit(page_3);
        lineEdit2_Gprice->setObjectName(QString::fromUtf8("lineEdit2_Gprice"));
        lineEdit2_Gprice->setGeometry(QRect(500, 40, 113, 21));
        pushButton2_modify = new QPushButton(page_3);
        pushButton2_modify->setObjectName(QString::fromUtf8("pushButton2_modify"));
        pushButton2_modify->setGeometry(QRect(520, 90, 93, 28));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        label_10 = new QLabel(page_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 10, 91, 16));
        label_11 = new QLabel(page_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 40, 68, 15));
        label_12 = new QLabel(page_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 70, 81, 16));
        label_13 = new QLabel(page_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 100, 91, 16));
        label_14 = new QLabel(page_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(240, 40, 68, 15));
        label_15 = new QLabel(page_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(240, 70, 68, 15));
        label_16 = new QLabel(page_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(240, 100, 68, 15));
        label_17 = new QLabel(page_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(480, 70, 41, 16));
        label_18 = new QLabel(page_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(480, 40, 51, 16));
        label_19 = new QLabel(page_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(480, 100, 68, 15));
        lineEdit3_suplierID = new QLineEdit(page_4);
        lineEdit3_suplierID->setObjectName(QString::fromUtf8("lineEdit3_suplierID"));
        lineEdit3_suplierID->setGeometry(QRect(100, 40, 113, 21));
        lineEdit3_suplierName = new QLineEdit(page_4);
        lineEdit3_suplierName->setObjectName(QString::fromUtf8("lineEdit3_suplierName"));
        lineEdit3_suplierName->setGeometry(QRect(100, 70, 113, 21));
        lineEdit3_suplierDesc = new QLineEdit(page_4);
        lineEdit3_suplierDesc->setObjectName(QString::fromUtf8("lineEdit3_suplierDesc"));
        lineEdit3_suplierDesc->setGeometry(QRect(100, 100, 113, 21));
        lineEdit3_goodsID = new QLineEdit(page_4);
        lineEdit3_goodsID->setObjectName(QString::fromUtf8("lineEdit3_goodsID"));
        lineEdit3_goodsID->setGeometry(QRect(320, 40, 113, 21));
        lineEdit3_goodsName = new QLineEdit(page_4);
        lineEdit3_goodsName->setObjectName(QString::fromUtf8("lineEdit3_goodsName"));
        lineEdit3_goodsName->setGeometry(QRect(320, 70, 113, 21));
        lineEdit3_goodsNum = new QLineEdit(page_4);
        lineEdit3_goodsNum->setObjectName(QString::fromUtf8("lineEdit3_goodsNum"));
        lineEdit3_goodsNum->setGeometry(QRect(320, 100, 113, 21));
        lineEdit3_marketPrice = new QLineEdit(page_4);
        lineEdit3_marketPrice->setObjectName(QString::fromUtf8("lineEdit3_marketPrice"));
        lineEdit3_marketPrice->setGeometry(QRect(550, 40, 113, 21));
        lineEdit3_shopPrice = new QLineEdit(page_4);
        lineEdit3_shopPrice->setObjectName(QString::fromUtf8("lineEdit3_shopPrice"));
        lineEdit3_shopPrice->setGeometry(QRect(550, 70, 113, 21));
        lineEdit3_goodsDesc = new QLineEdit(page_4);
        lineEdit3_goodsDesc->setObjectName(QString::fromUtf8("lineEdit3_goodsDesc"));
        lineEdit3_goodsDesc->setGeometry(QRect(550, 100, 113, 21));
        pushButton3_submit = new QPushButton(page_4);
        pushButton3_submit->setObjectName(QString::fromUtf8("pushButton3_submit"));
        pushButton3_submit->setGeometry(QRect(690, 90, 93, 28));
        stackedWidget->addWidget(page_4);
        shopTable = new QTableView(centralwidget);
        shopTable->setObjectName(QString::fromUtf8("shopTable"));
        shopTable->setGeometry(QRect(0, 0, 801, 411));
        mainpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainpage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        mainpage->setMenuBar(menubar);
        statusbar = new QStatusBar(mainpage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainpage->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(umaction);
        menu->addAction(actionmima);
        menu->addAction(actiondenglu);
        menu_2->addAction(actionxinxi);
        menu_2->addAction(actionkucun);
        menu_2->addAction(actionjinhuo);
        menu_3->addAction(actionjiezhang);
        menu_3->addAction(actiontongji);
        menu_4->addAction(actionxinxi_2);
        menu_4->addAction(actionchaxun);

        retranslateUi(mainpage);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(mainpage);
    } // setupUi

    void retranslateUi(QMainWindow *mainpage)
    {
        mainpage->setWindowTitle(QCoreApplication::translate("mainpage", "MainWindow", nullptr));
        umaction->setText(QCoreApplication::translate("mainpage", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        actionmima->setText(QCoreApplication::translate("mainpage", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        actiondenglu->setText(QCoreApplication::translate("mainpage", "\351\207\215\346\226\260\347\231\273\345\275\225", nullptr));
        actionxinxi->setText(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        actionkucun->setText(QCoreApplication::translate("mainpage", "\345\272\223\345\255\230\347\256\241\347\220\206", nullptr));
        actionjinhuo->setText(QCoreApplication::translate("mainpage", "\350\277\233\350\264\247\347\256\241\347\220\206", nullptr));
        actionjiezhang->setText(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201\347\273\223\350\264\246", nullptr));
        actiontongji->setText(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201\351\224\200\345\224\256\347\273\237\350\256\241", nullptr));
        actionxinxi_2->setText(QCoreApplication::translate("mainpage", "\344\274\232\345\221\230\344\277\241\346\201\257\347\273\264\346\212\244", nullptr));
        actionchaxun->setText(QCoreApplication::translate("mainpage", "\346\237\245\350\257\242\344\274\232\345\221\230\344\277\241\346\201\257", nullptr));
        label->setText(QCoreApplication::translate("mainpage", "1 - \344\277\256\346\224\271\345\257\206\347\240\201\347\225\214\351\235\242", nullptr));
        label_2->setText(QCoreApplication::translate("mainpage", "\350\264\246\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("mainpage", "\345\216\237\345\247\213\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("mainpage", "\345\247\223\345\220\215", nullptr));
        pushButton1_submit->setText(QCoreApplication::translate("mainpage", "\344\277\256\346\224\271", nullptr));
        label_5->setText(QCoreApplication::translate("mainpage", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label_6->setText(QCoreApplication::translate("mainpage", "2-\345\225\206\345\223\201\347\256\241\347\220\206", nullptr));
        pushButton2_search->setText(QCoreApplication::translate("mainpage", "\346\237\245\350\257\242", nullptr));
        label_7->setText(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201\345\220\215", nullptr));
        label_8->setText(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201ID", nullptr));
        label_9->setText(QCoreApplication::translate("mainpage", "\345\224\256\344\273\267", nullptr));
        pushButton2_modify->setText(QCoreApplication::translate("mainpage", "\344\277\256\346\224\271\345\224\256\344\273\267", nullptr));
        label_10->setText(QCoreApplication::translate("mainpage", "3-\350\277\233\350\264\247\347\256\241\347\220\206", nullptr));
        label_11->setText(QCoreApplication::translate("mainpage", "\344\276\233\345\272\224\345\225\206ID", nullptr));
        label_12->setText(QCoreApplication::translate("mainpage", "\344\276\233\345\272\224\345\225\206\345\220\215\347\247\260", nullptr));
        label_13->setText(QCoreApplication::translate("mainpage", "\344\276\233\345\272\224\345\225\206\346\217\217\350\277\260", nullptr));
        label_14->setText(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201ID", nullptr));
        label_15->setText(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201\345\220\215\347\247\260", nullptr));
        label_16->setText(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201\346\225\260\351\207\217", nullptr));
        label_17->setText(QCoreApplication::translate("mainpage", "\345\224\256\344\273\267", nullptr));
        label_18->setText(QCoreApplication::translate("mainpage", "\350\277\233\350\264\247\344\273\267", nullptr));
        label_19->setText(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201\346\217\217\350\277\260", nullptr));
        pushButton3_submit->setText(QCoreApplication::translate("mainpage", "\346\217\220\344\272\244", nullptr));
        menu->setTitle(QCoreApplication::translate("mainpage", "\347\224\250\346\210\267\347\256\241\347\220\206", nullptr));
        menu_2->setTitle(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201\347\256\241\347\220\206", nullptr));
        menu_3->setTitle(QCoreApplication::translate("mainpage", "\345\225\206\345\223\201\351\224\200\345\224\256", nullptr));
        menu_4->setTitle(QCoreApplication::translate("mainpage", "\344\274\232\345\221\230\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainpage: public Ui_mainpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINPAGE_H
