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



float calc_minutes_fraction(QString time_string, bool start)
{
    int i;
   int len;

   len = time_string.length();
    i = 0;
    if (start == 1)
     {
        while (time_string[i] != ':' && time_string[i] != '\0')
            i++;
         if (time_string[i+1] == '1')
             return (0.25);
         else if (time_string[i+1] == '3')
             return (0.50);
         else if (time_string[i+1] == '4')
             return (0.75);
         else
             return (0);
    }
    else
    {
        while (time_string[len] != ':' && len > 0)
        len--;
        if (time_string[len+1] == '1')
            return (0.25);
        else if (time_string[len+1] == '3')
            return (0.50);
        else if (time_string[len+1] == '4')
            return (0.75);
        else
            return (0);
    }
}

float adjust_minute_fraction(QVariant var)
{
    int i;
    i = 0;
    QString s = var.toString();
    while (s[i] != '.' && s[i] != '\0')
        i += 1;
    if (s[i+1] == '1')
        return (0.10);
    else if (s[i+1] == '3')
        return (0.20);
    else if (s[i+i] == '4')
        return (0.30);
    else
        return (0);

}
