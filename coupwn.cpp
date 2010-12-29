#include "coupwn.h"
#include "ui_coupwn.h"
/* UGLY AND JUST TEST CODE ATM */

int maxsmsage = 20*60; // minutes
const char *smsmatchre = {"Singleticket \\S{5} \\S{5} \\S{5} \\S{5} \\S{5} \\S{5}"}; // regular expression
const char *smsfile = {"/home/user/.rtcom-eventlogger/el-v1.db"};
// The grou_uid should = the phone number minus the areacode for the 
// service provider, or you can just enter a random number
const char *smsquery = {"SELECT id, start_time, remote_uid, free_text, group_uid FROM Events WHERE group_uid = '6606000';"};
//defaults for new ticket injection, could also take from server:
char *servicephone = {"+436646606000"};

sqlite3 *db;


Coupwn::Coupwn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Coupwn)
{
    ui->setupUi(this);
}

Coupwn::~Coupwn()
{
    delete ui;
}



static int _smsfilter(void *NotUsed, int argc, char **argv, char **azColName)
{
  // time check vars
  char buffer[80];
  time_t currenttime;
  time_t smstime;
  struct tm * timeinfo;

  // DATABASE DATA INCOMING
  char * id         = argv[0];
  char * start_time = argv[1];
  char * remote_uid = argv[2];
  char * free_text  = argv[3];
  char * group_uid  = argv[4];

  // CHECK TIME
  // this will get rechecked by the server, so not so important
  //localtime:
  time( &currenttime );
  timeinfo = localtime( &currenttime );
  strftime(buffer, 80, "\nNow it's %B %d %H:%M\n", timeinfo);
  printf(buffer);
  //smstime:
  smstime = atoi( start_time );
  timeinfo = localtime( &smstime );
  strftime(buffer, 80, "SMS from %B %d %H:%M\n", timeinfo);
  printf(buffer);

  if( difftime(currenttime, smstime) < (maxsmsage*60) ) {
      printf("SMS under threshold (%i hours %02i minutes)\n", (maxsmsage/60), (maxsmsage%60));
  } else { return 0; }

  // CHECK TEXT
  QRegExp rx(smsmatchre);
  if( rx.indexIn(free_text) >= 0) {
      printf("SMS containts ticket match string (%s)\n", smsmatchre);
  } else { return 0; }

  // INFO
  printf("id = %s\nstart_time = %s\nremote_uid = %s\ngroup_id = %s\n", id, start_time, remote_uid, group_uid);
  printf("free_text = %s\n\n", free_text);
  return 0;

  // SUBMIT TICKET TO SERVER
  //
  // ...
  //
}

int _submitticket()
{
    char *zErrMsg = 0;
    printf("submitticket()\n");

    // EXECUTE DATABASE FILTER
    printf("open db: %s\n", smsfile);
    if( sqlite3_open(smsfile, &db) ){
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    if ( sqlite3_exec(db, smsquery, _smsfilter, 0, &zErrMsg) != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
    return 0;

}
void _injectsms(unsigned int time, char *servicephonenum, char *message)
{
    char *zErrMsg = 0;
    char smsinject[256];
    char *groupnum;
    // dirty cut to grab last 7 chars
    groupnum = servicephonenum + (strlen(servicephonenum) - 7);
    printf("groupnumcut: %s\n", groupnum);


    printf("open db: %s\n", smsfile);
    if( sqlite3_open(smsfile, &db) ){
        printf("Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }
    sprintf(smsinject, "INSERT INTO Events VALUES (NULL, 3, 7, %i, %i, %i, 1, 0, 0, 0, 'ring/tel/ring', '<SelfHandle>', '%s', NULL, '%s', '%s', 0, 0);", time, time, time, servicephonenum, message, groupnum);
    printf("Executing smsinject:\n%s\n",smsinject);
    if ( sqlite3_exec(db, smsinject, NULL, 0, &zErrMsg) != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    sqlite3_close(db);
}
void _sendrequest(char *response)
{
    // network code
    //
    // ...
	
	// This should be changed to random
    sprintf(response, "Singleticket 123jt zd4mn 0ons2 chi49 as2ju fhgu2\n");
    //sprintf(response, "Over quota\n");
    //sprintf(response, "No valid tickets\n");
    //sprintf(response, "Service experiancing technical dificulties\n");
}

int _getticket(char *response)
{
    time_t currenttime;
    _sendrequest(response);
    QRegExp rx(smsmatchre);
    if( rx.indexIn(response) >= 0) {
        printf("Server returned ticket:\n%s\n", response);
        time( &currenttime );
        printf("curtime %ui\n", (unsigned int)currenttime);
        _injectsms((unsigned int)currenttime, servicephone, response);
        return 0;
    }
    rx.setPattern("Over quota");
    if( rx.indexIn(response) >= 0) {
        printf("1: %s\n", response);
        return 1;
    }
    rx.setPattern("No valid tickets");
    if( rx.indexIn(response) >= 0) {
        printf("2: %s\n", response);
        return 2;
    }

    printf("3: %s\n", response);
    return 3;
}

void Coupwn::on_pushButton_submit_clicked()
{
    QMessageBox::about(this, "Submit ticket", "Please select new ticket to submit to server");
    /*
    message = sign(localvalidticket)
    send(message)
    alert("your comrads thank you!")
    */
    _submitticket();
}

void Coupwn::on_pushButton_get_pressed()
{
    ui->messageBox_status->setText("requesting new ticket from server...");
    sleep(1);
}

void Coupwn::on_pushButton_get_released()
{
    int ret;
    char response[256];
    sleep(1);
    ret = _getticket(response);

    if (ret == 0)
        ui->messageBox_status->setText("Got ticket");
    else if (ret == 1)
        ui->messageBox_status->setText("Over quota");
    else if (ret == 2)
        ui->messageBox_status->setText("No tickets left");
    else
        ui->messageBox_status->setText("Technical deficulties");
}

void Coupwn::on_action_about_triggered()
{
    QMessageBox::about(this, "About Coupwn","...");
}

void Coupwn::on_action_mode_triggered()
{
    QMessageBox msgBox("Set Mode", "Turn on to receive tickets dayly.", QMessageBox::NoIcon, 0, 0 , 0,  this);
    QCheckBox dontPrompt(QObject::tr("Auto mode On     "), &msgBox);
    dontPrompt.blockSignals(true);
    msgBox.addButton(&dontPrompt, QMessageBox::ActionRole);
    QAbstractButton* pYES = (QAbstractButton*)msgBox.addButton(QMessageBox::Yes);
    QAbstractButton* pNO  = (QAbstractButton*)msgBox.addButton(QMessageBox::No);
    msgBox.exec();
    if ( dontPrompt.checkState() == Qt::Checked )
    {
        //some code
    }

   // QMessageBox::information(this, "Set mode","Change Mode");
   // QCheckBox *checkbox = new QCheckBox("Check me", this);
}

void Coupwn::on_action_location_triggered()
{
    printf("localtion\n");
    QMessageBox localeBox("Set Location", "....", QMessageBox::NoIcon, 0, 0 , 0,  this);
    QListWidget localeList(&localeBox);
    localeList.addItem("Vienna");
    localeList.addItem("Berlin");
    localeBox.exec();
}

void Coupwn::on_action_settings_triggered()
{
    printf("settings\n");
}
