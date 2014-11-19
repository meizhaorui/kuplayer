/*********************************************
*     MadeBy : MeiZhaorui(Mason)
*     E-Mail : listener_mei@163.com
*      Phone : (0)131-5898-7498
*       Date : 2014/10/13
*       host : Ubuntu x86_64 3.13.0-37
 *********************************************/
#ifndef KUPLAYER_H
#define KUPLAYER_H


#include "common.h"
#include "shadow_widget.h"
#include "play_list_widget.h"
#include "skin_widget.h"
#include "main_menu.h"

#include <QBitArray>
#include <array>
#include <QSystemTrayIcon>
class QSettings;
class TitleWidget;
class QStackedWidget;
class MPlayerWidget;
class MPlayer;
class PyScript;
class mThread;
class LoadImage;


class kuplayer        
#ifdef CAN_RESIZE
 : public MainWidget
#else
 : public ShadowWidget
#endif
{
    Q_OBJECT
public:
    kuplayer(PyScript *pyinit,QWidget *parent = 0);
    virtual ~kuplayer();
    void setIniFile(QSettings *);
public slots:
    void on_showMin_clicked();
    void on_skin_changed(QString);
    void on_Fullscreen_changed();
    void on_play_finished(bool);
    void on_loadImage_started(int,const QStringList&);
    void on_nextPage_loaded(CLASS);
    void loadImageFinished(CLASS, QPixmap, QString, QString);
    void on_url_triggered(QString, QString);
    void url_ji_triggered(QString, QString url);
    void change_url(CLASS, int, QString);
private slots:
    void trayIcon_clicked(QSystemTrayIcon::ActivationReason);
    void show_normal_or_close();
private:
    void init_setting();
    void to_inifile();
    void init_trayicon();
    
public:    
    const QStringList name{"tv","movice","zy","music","comic"};
private:
      PlayListWidget   xuan_ji_widget;
          SkinWidget   skin_widget;
          
            PyScript   *pyinit;
         TitleWidget   *title_widget;
      QStackedWidget   *stacked_widget;
       MPlayerWidget   *player_widget;
             MPlayer   *player;
          MenuWidget   *main_menu;
     QSystemTrayIcon   *trayicon;
           conf_info   *setting;
           QSettings   *iniFile;
           
           QBitArray   can_update{5,true};
    std::array<int,5>  pages{ {2,2,2,2,2} };     
    std::array<std::tuple<QString,QString,QString>,5> locate_class_time;
};

#endif // KUPLAYER_H
