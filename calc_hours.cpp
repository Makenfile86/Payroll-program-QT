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

float static calc_shift_len(float shift_starts, float shift_ends)
{
    float length;

    if (shift_ends < shift_starts)
        shift_ends += 24;
    length = shift_ends - shift_starts;
return (length);
}

float static calc_night_hours(float shift_starts, float shift_ends)
{
    float length;
    float hours;
    hours = 0;

    length = calc_shift_len(shift_starts, shift_ends);
    while (length > 0)
    {
        if (shift_starts < 22 && shift_starts >= 18)
            hours += 0.25;
        shift_starts += 0.25;
        length -= 0.25;
    }
    return (hours);
}

float static calc_latenight_hours(float shift_starts, float shift_ends)
{
    float length;
    float hours;

    hours = 0;
    length = calc_shift_len(shift_starts, shift_ends);

    //qDebug("shift_starts: %f\n", shift_starts);
    //qDebug("shift_ends: %f\n", shift_ends);
  // qDebug("length: YOYOOYOYOY %f\n", length);

    while (length > 0)
    {
        if (shift_starts == 24)
            shift_starts = 0;
        if (shift_starts < 6 && shift_starts >= 0)
            hours += 0.25;
        if (shift_starts >= 22 && shift_starts < 24)
            hours += 0.25;
        shift_starts += 0.25;
        length -= 0.25;
    }


    return (hours);
}

float calc_shifts_time(QString time_string, float shift, bool start)
{

    int len;
    QString tmp_time;
    float minutes;

    if (start == 1)
    {
       tmp_time[0] = time_string[0];
       if (time_string[1] != ':')
       tmp_time[1] = time_string[1];
    }
    else
    {
        len = time_string.length();
        while (time_string[len] != ':' && len != 0)
            len = len - 1;
        if (len >= 2)
        {
        tmp_time[1] = time_string[len-1];
        tmp_time[0] = time_string[len-2];
        }
      }
    minutes = calc_minutes_fraction(time_string, start);
    shift = tmp_time.toFloat();
    shift += minutes;
    return (shift);
}

data static calc_sunday_hours(data input, float shift_starts, float shift_ends)
{
    input.sunday_hours += calc_shift_len(shift_starts, shift_ends);
      // qDebug("sunday hours %f\n", input.sunday_hours);
       return (input);
}

data calc_diff_hours(data input)
{
   float shift_starts;
   float shift_ends;

   shift_ends = 0;
   shift_starts = 0;

  shift_starts = calc_shifts_time(input.time_string, shift_starts, 1);
  shift_ends = calc_shifts_time(input.time_string, shift_ends, 0);
//qDebug("\n shift QQ starts %f\n", shift_starts);
//qDebug("\n shift QQ ends %f\n", shift_ends);
  if (input.sunday == 1)
  input = calc_sunday_hours(input, shift_starts, shift_ends);
   input.late_night_hours += calc_latenight_hours(shift_starts, shift_ends);
    input.night_hours += calc_night_hours(shift_starts, shift_ends);
input.sunday = 0;
return (input);
}

float calc_overtime_hours(float all_hours)
{
    if (all_hours - 80.0 > 0)
        return (all_hours - 80);
    else
        return (0);
}
