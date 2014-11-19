/*********************************************
*     MadeBy : MeiZhaorui(Mason)
*     E-Mail : listener_mei@163.com
*      Phone : (0)131-5898-7498
*       Date : 2014/10/13
*       host : Ubuntu x86_64 3.13.0-37
 *********************************************/
#ifndef COMMON_H
#define COMMON_H

#include <algorithm>
#include <functional>
#include <memory>
using std::for_each;
using std::find_if;
using std::find_if_not;
using std::bind;
using std::function;

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QPainter>
#include <QApplication>

#define SHADOW_WIDTH  5
#define SHADOW_HEIGHT 5

#if defined(__GNUC__) && !defined(__clang__) 
    #if (__GNUC__ < 4) || (__GNUC__ == 4 && __GNUC_MINOR__ < 6)
        #error Please use gcc4.6.0 or higher to support some new feature.
//    #else
//        #pragma message "gcc is using"
    #endif
#elif defined(__clang__)
    #if (__clang_major__ < 3) || (__clang_major__ == 3 && __clang_minor__ < 5)
        #error Please use clang3.5.0 or higher to support some new feature.
//    #else
//        #pragma message "clang is using "
    #endif
#endif

typedef unsigned int CLASS;
const CLASS TV = 0,MOVIE = 1,ZONGYI = 2,MUSIC = 3,COMIC = 4,PLAYER = 5,NONE = 6;

template<typename T>
inline void set_no_margin(T *layout){
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
}
template<typename T>
inline void delete_list(T* store){
    while (store->size()){
        delete store->at(0);
        store->removeAt(0);
    }
    delete store;
}

inline QString msg_font_style(const QString& text)
{
    QString tmp;
    tmp.insert(0,"<span style=\"font-family:'SimSun'; color:#ff0000;\"><h2>");
    tmp.insert(tmp.size(),text);
    tmp.insert(tmp.size(),"</h2></span>");
    return std::move(tmp);
}

#endif
