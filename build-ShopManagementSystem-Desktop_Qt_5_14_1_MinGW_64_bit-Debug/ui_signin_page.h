/********************************************************************************
** Form generated from reading UI file 'signin_page.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_PAGE_H
#define UI_SIGNIN_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignIn_Page
{
public:
    QFrame *frame;
    QRadioButton *RBtn_M;
    QRadioButton *RBtn_G;
    QPushButton *PBtn_signIn;
    QFrame *frame_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *InputNumber;
    QLineEdit *InputPassWord;

    void setupUi(QWidget *SignIn_Page)
    {
        if (SignIn_Page->objectName().isEmpty())
            SignIn_Page->setObjectName(QString::fromUtf8("SignIn_Page"));
        SignIn_Page->resize(400, 300);
        frame = new QFrame(SignIn_Page);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(100, 170, 181, 101));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        RBtn_M = new QRadioButton(frame);
        RBtn_M->setObjectName(QString::fromUtf8("RBtn_M"));
        RBtn_M->setGeometry(QRect(0, 20, 115, 19));
        RBtn_G = new QRadioButton(frame);
        RBtn_G->setObjectName(QString::fromUtf8("RBtn_G"));
        RBtn_G->setGeometry(QRect(90, 20, 115, 19));
        PBtn_signIn = new QPushButton(frame);
        PBtn_signIn->setObjectName(QString::fromUtf8("PBtn_signIn"));
        PBtn_signIn->setGeometry(QRect(40, 60, 93, 28));
        PBtn_signIn->setCursor(QCursor(Qt::ArrowCursor));
        frame_2 = new QFrame(SignIn_Page);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(50, 30, 251, 111));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 81, 31));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 81, 41));
        InputNumber = new QLineEdit(frame_2);
        InputNumber->setObjectName(QString::fromUtf8("InputNumber"));
        InputNumber->setGeometry(QRect(80, 10, 151, 31));
        InputPassWord = new QLineEdit(frame_2);
        InputPassWord->setObjectName(QString::fromUtf8("InputPassWord"));
        InputPassWord->setGeometry(QRect(80, 70, 151, 31));
        InputPassWord->setInputMethodHints(Qt::ImhHiddenText);

        retranslateUi(SignIn_Page);

        QMetaObject::connectSlotsByName(SignIn_Page);
    } // setupUi

    void retranslateUi(QWidget *SignIn_Page)
    {
        SignIn_Page->setWindowTitle(QCoreApplication::translate("SignIn_Page", "Form", nullptr));
        RBtn_M->setText(QCoreApplication::translate("SignIn_Page", "\347\256\241\347\220\206\345\221\230", nullptr));
        RBtn_G->setText(QCoreApplication::translate("SignIn_Page", "\346\237\234\345\217\260", nullptr));
        PBtn_signIn->setText(QCoreApplication::translate("SignIn_Page", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("SignIn_Page", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">\350\264\246\345\217\267\357\274\232</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SignIn_Page", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:600;\">\345\257\206\347\240\201\357\274\232</span></p></body></html>", nullptr));
        InputNumber->setText(QString());
#if QT_CONFIG(whatsthis)
        InputPassWord->setWhatsThis(QCoreApplication::translate("SignIn_Page", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        InputPassWord->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignIn_Page: public Ui_SignIn_Page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_PAGE_H
