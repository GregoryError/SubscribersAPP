#ifndef BACKEND_H
#define BACKEND_H


#include <QtWidgets>
#include "myclient.h"


#include <QMainWindow>
#include <QObject>
#include <QString>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QMessageBox>
#include <QApplication>
#include <QGeoPositionInfoSource>
#include <QDesktopServices>
#include <QWindow>


class location
{
public:
    float longitude, latitude;
    QString address;
    float t_long, t_lat;

    location() = default;
    location(const float &lon, const float &lat):longitude(lon), latitude(lat){}
    location(const float &lon, const float &lat, const QString &addr, const float &t_long, const float &t_lat):
        longitude(lon), latitude(lat), address(addr), t_long(t_long), t_lat(t_lat) {}

    float ShowDiff(location &first, location &second)
    {
         return std::abs(pow(pow((second.latitude - first.latitude), 2) + pow((second.longitude - first.longitude), 2), 0.5));
    }

    bool operator <(location &obj)
    {
        location temp(longitude, latitude);
        location own(t_long, t_lat);
        return ShowDiff(own, temp) < ShowDiff(own, obj);
    }

    bool operator >(location &obj)
    {
        location temp(longitude, latitude);
        location own(t_long, t_lat);
        return ShowDiff(own, temp) > ShowDiff(own, obj);
    }
};


class BackEnd : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)
    //Q_PROPERTY(QString text MEMBER m_text NOTIFY textChanged)

public:
    QQmlContext *cont;
    QQmlApplicationEngine engine;


    location owner;
    QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
    QRect displaySize;



    BackEnd(QObject *parent = nullptr);

public slots:
    void payList();
    void trustedPay();
 QString showATM();
    void callUs();
    void goUrl();
    void social();

};
























#endif // BACKEND_H
