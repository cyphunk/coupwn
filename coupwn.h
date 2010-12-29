#ifndef COUPWN_H
#define COUPWN_H

#include <QMainWindow>
#include <QtGui>
#include <QObject>
#include <QDebug>

// send sms:
#include "tpsession.h"
#include "tpsessionaccount.h"
// sql db parsing:
#include "sqlite3.h"
#include "time.h"  // localtime, strftime
#include "stdio.h" // atoi
#include <QRegExp>
// get guid from phone num in inejctdb
#include <string.h>

namespace Ui {
    class Coupwn;
}




class Coupwn : public QMainWindow
{
    Q_OBJECT

public:
    explicit Coupwn(QWidget *parent = 0);
    ~Coupwn();

private:
    Ui::Coupwn *ui;
 //   QAction action;
//    QAction action2;
    //TpSession* tps;
    //void _importsms();


private slots:
    void on_action_settings_triggered();
    void on_action_location_triggered();
    void on_action_mode_triggered();
    void on_action_about_triggered();
    void on_pushButton_get_released();
    void on_pushButton_get_pressed();
    void on_pushButton_submit_clicked();
 //   void on_pushButton_get_clicked();

};

#endif // COUPWN_H
