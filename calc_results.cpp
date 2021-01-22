#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVariant>
#include <QDebug>

#include <iostream>
using namespace std;

float calc_brutto(data input, float all_hours)
{
    float brutto;
    float hourly;



    hourly = input.hourly_pay.toFloat();
    //qDebug("\n HOURLY PAY %f\n", hourly);
   // qDebug("\n all hours %f\n", all_hours);

    brutto = all_hours * hourly + input.late_night_hours * (hourly + (hourly * 0.20))
            + input.night_hours * (hourly + (hourly * 0.15))
            + input.overtime_hours * (hourly + (hourly * 0.5)) + input.sunday_hours * hourly * 2 ;
    return (brutto);
}
