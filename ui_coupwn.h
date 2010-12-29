/********************************************************************************
** Form generated from reading UI file 'coupwn.ui'
**
** Created: Mon Sep 6 04:49:37 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUPWN_H
#define UI_COUPWN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Coupwn
{
public:
    QAction *action_about;
    QAction *action_location;
    QAction *action_mode;
    QAction *action_settings;
    QWidget *centralWidget;
    QPushButton *pushButton_get;
    QPushButton *pushButton_submit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_quota;
    QLabel *label_city;
    QLabel *label_mode;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *messageBox_status;
    QWidget *widget;
    QMenuBar *menu;
    QMenu *menuWhatever;

    void setupUi(QMainWindow *Coupwn)
    {
        if (Coupwn->objectName().isEmpty())
            Coupwn->setObjectName(QString::fromUtf8("Coupwn"));
        Coupwn->resize(800, 400);
        action_about = new QAction(Coupwn);
        action_about->setObjectName(QString::fromUtf8("action_about"));
        action_location = new QAction(Coupwn);
        action_location->setObjectName(QString::fromUtf8("action_location"));
        action_location->setCheckable(false);
        action_mode = new QAction(Coupwn);
        action_mode->setObjectName(QString::fromUtf8("action_mode"));
        action_settings = new QAction(Coupwn);
        action_settings->setObjectName(QString::fromUtf8("action_settings"));
        action_settings->setMenuRole(QAction::PreferencesRole);
        centralWidget = new QWidget(Coupwn);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton_get = new QPushButton(centralWidget);
        pushButton_get->setObjectName(QString::fromUtf8("pushButton_get"));
        pushButton_get->setGeometry(QRect(40, 200, 250, 70));
        pushButton_submit = new QPushButton(centralWidget);
        pushButton_submit->setObjectName(QString::fromUtf8("pushButton_submit"));
        pushButton_submit->setGeometry(QRect(40, 280, 250, 70));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 40, 241, 81));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 0, 0, 0);
        label_quota = new QLabel(gridLayoutWidget);
        label_quota->setObjectName(QString::fromUtf8("label_quota"));

        gridLayout_2->addWidget(label_quota, 4, 0, 1, 1);

        label_city = new QLabel(gridLayoutWidget);
        label_city->setObjectName(QString::fromUtf8("label_city"));

        gridLayout_2->addWidget(label_city, 2, 0, 1, 1);

        label_mode = new QLabel(gridLayoutWidget);
        label_mode->setObjectName(QString::fromUtf8("label_mode"));

        gridLayout_2->addWidget(label_mode, 3, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(319, 39, 441, 321));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        messageBox_status = new QLabel(gridLayoutWidget_2);
        messageBox_status->setObjectName(QString::fromUtf8("messageBox_status"));
        messageBox_status->setAutoFillBackground(false);
        messageBox_status->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_3->addWidget(messageBox_status, 0, 0, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(200, 40, 120, 300));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 300));
        Coupwn->setCentralWidget(centralWidget);
        menu = new QMenuBar(Coupwn);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(0, 0, 800, 25));
        menu->setDefaultUp(false);
        menuWhatever = new QMenu(menu);
        menuWhatever->setObjectName(QString::fromUtf8("menuWhatever"));
        Coupwn->setMenuBar(menu);

        menu->addAction(menuWhatever->menuAction());
        menuWhatever->addAction(action_about);
        menuWhatever->addAction(action_location);
        menuWhatever->addAction(action_mode);
        menuWhatever->addAction(action_settings);

        retranslateUi(Coupwn);

        QMetaObject::connectSlotsByName(Coupwn);
    } // setupUi

    void retranslateUi(QMainWindow *Coupwn)
    {
        Coupwn->setWindowTitle(QApplication::translate("Coupwn", "Coupwn", 0, QApplication::UnicodeUTF8));
        action_about->setText(QApplication::translate("Coupwn", "About", 0, QApplication::UnicodeUTF8));
        action_location->setText(QApplication::translate("Coupwn", "Location", 0, QApplication::UnicodeUTF8));
        action_mode->setText(QApplication::translate("Coupwn", "Mode", 0, QApplication::UnicodeUTF8));
        action_settings->setText(QApplication::translate("Coupwn", "Settings", 0, QApplication::UnicodeUTF8));
        pushButton_get->setText(QApplication::translate("Coupwn", "Get ticket", 0, QApplication::UnicodeUTF8));
        pushButton_submit->setText(QApplication::translate("Coupwn", "Submit ticket", 0, QApplication::UnicodeUTF8));
        label_quota->setText(QApplication::translate("Coupwn", "Current Quota: 7", 0, QApplication::UnicodeUTF8));
        label_city->setText(QApplication::translate("Coupwn", "City: Vienna", 0, QApplication::UnicodeUTF8));
        label_mode->setText(QApplication::translate("Coupwn", "Mode: Auto", 0, QApplication::UnicodeUTF8));
        messageBox_status->setText(QString());
        menuWhatever->setTitle(QApplication::translate("Coupwn", "Coupwn_", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Coupwn: public Ui_Coupwn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUPWN_H
