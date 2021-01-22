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
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"


using namespace QXlsx;



data static check_hit(int row, int col, QVariant var, data input)
{


    if (row == 2 && col == 16)
         input.employee_name = var.toString();
    else if (row == 3 && col == 11)
        input.pv_payment = var.toString();
    else if (row == 3 && col == 13)
        input.sv_payment = var.toString();
   else if (row == 3 && col == 15)
        input.tax = var.toString();
    else if (row == 3 && col == 17)
        input.hourly_pay = var.toString();
    else if (row == 3 && col == 19)
        input.pension = var.toString();
    else if (row == 3 && col == 21)
    input.insurance = var.toString();
   else  if (row > 5 && row < 20 && col == 3)
   {
     input.time_string = var.toString();
    input = calc_diff_hours(input);
   }
    else if (row > 5 && row < 20 && col == 5)
      {
        input.hours = input.hours + var.toFloat() + adjust_minute_fraction(var);
        input.all_hours = QString::number(input.hours);
        }
         return (input);

}

static data check_day(QVariant var, data input)
{
    QString cmp;
    QString su = "su";
    cmp = var.toString();
    if (cmp == su)
 input.sunday = 1;
    return (input);
}

data reader(QString filename, data input)
{


QString file = QFileInfo(filename).absoluteFilePath();
Document xlsxR(file);


 int col;
 int row = 1;
while (row < 21)
 {
    col = 1;
    while (col < 22)
    {
 Cell* cell = xlsxR.cellAt(row, col); // get cell pointer.
        if ( cell != NULL )
        {
            QVariant var = cell->value(); // read cell value (number(double), QDateTime, QString ...)
            if (row > 5 && row < 20 && col == 1)
             input = check_day(var, input);
            input = check_hit(row, col, var, input);
        }
         col += 1;
        }
 row += 1;
}
return (input);
}
