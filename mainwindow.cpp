#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <QFileDialog>
#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVariant>
#include <QDebug>
#include <iomanip>

#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_all_hours_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_4_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_3_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_5_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_6_textEdited(const QString &arg1)
{

}

void MainWindow::on_brutto_textEdited(const QString &arg1)
{

}

void MainWindow::on_tax_pros_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_9_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_10_textEdited(const QString &arg1)
{

}

void MainWindow::on_netto_textEdited(const QString &arg1)
{

}

void MainWindow::on_lineEdit_12_textEdited(const QString &arg1)
{

}

void MainWindow::on_hourly_pay_textEdited(const QString &arg1)
{

}

void MainWindow::on_pv_maksu_textEdited(const QString &arg1)
{

}

void MainWindow::on_sv_maksu_textEdited(const QString &arg1)
{

}

void MainWindow::on_night_pa_textEdited(const QString &arg1)
{

}

void MainWindow::on_night_pa_pros_textEdited(const QString &arg1)
{

}

void MainWindow::on_late_night_pa_textEdited(const QString &arg1)
{

}
void MainWindow::on_late_night_pa_pros_textEdited(const QString &arg1)
{

}


void MainWindow::on_sunday_pa_textEdited(const QString &arg1)
{

}

void MainWindow::on_sunday_pa_pros_textEdited(const QString &arg1)
{

}


void MainWindow::on_pv_pros_textEdited(const QString &arg1)
{

}

void MainWindow::on_sv_pros_textEdited(const QString &arg1)
{

}

void MainWindow::on_tax_amount_textEdited(const QString &arg1)
{

}

void MainWindow::on_pension_pros_textEdited(const QString &arg1)
{

}

void MainWindow::on_insurance_pros_textEdited(const QString &arg1)
{

}


void MainWindow::on_overtime_pros_textEdited(const QString &arg1)
{

}

void MainWindow::on_overtime_pa_textEdited(const QString &arg1)
{

}

void MainWindow::on_actionexcell_triggered()
{

        QString fileName;
           class data input;
           float all_hours;
           float normal_hours;






           input.hours = 0;
           input.all_hours = "";
           input.sunday = 0;
           input.sunday_hours = 0;
           input.late_night_hours = 0;
           input.overtime_hours = 0;
           input.night_hours = 0;

           //Avaa uusi_excel
           printf("%s", "moi");
           fileName = QFileDialog::getOpenFileName(this,
               tr("Open File"), "Users/markuskivipuro", tr("excel Files (*.xls *.xlsx)"));


           input = reader(fileName, input);
           all_hours = input.all_hours.toFloat();
           normal_hours = all_hours - input.night_hours - input.late_night_hours - input.sunday_hours - input.overtime_hours;
           input.overtime_hours = calc_overtime_hours(all_hours);
          ui->lineEdit_12->setPlaceholderText(QString::number(input.overtime_hours));
           ui->lineEdit_6->setPlaceholderText(input.employee_name);
           ui->hourly_pay->setPlaceholderText(input.hourly_pay);
           ui->tax_pros->setPlaceholderText(input.tax);
           ui->all_hours->setPlaceholderText(input.all_hours);
           ui->lineEdit_5->setPlaceholderText(QString::number(input.sunday_hours));
           ui->lineEdit_4->setPlaceholderText(QString::number(input.late_night_hours));
            ui->lineEdit_3->setPlaceholderText(QString::number(input.night_hours));

     // qDebug("\n INSURANCE %f\n", input.insurance.toFloat());

 ui->overtime_pros->setPlaceholderText(QString::number(50));
    ui->sunday_pa_pros->setPlaceholderText(QString::number(100));
    ui->overtime_pa->setPlaceholderText(QString::number((roundf(100 * input.overtime_hours * (input.hourly_pay.toFloat() * 1.50))) / 100));
    ui->sunday_pa->setPlaceholderText(QString::number((roundf(100 * input.sunday_hours * (input.hourly_pay.toFloat() * 1.50)) / 100)));
   ui->late_night_pa->setPlaceholderText(QString::number((roundf(100 * input.late_night_hours * (input.hourly_pay.toFloat() * 1.20))) / 100));
   ui->night_pa->setPlaceholderText(QString::number((roundf(100 * input.night_hours * (input.hourly_pay.toFloat() * 1.15)) / 100)));
    ui->night_pa_pros->setPlaceholderText(QString::number(15));
    ui->late_night_pa_pros->setPlaceholderText(QString::number(20));
            ui->lineEdit_2->setPlaceholderText(QString::number(all_hours - input.night_hours - input.late_night_hours - input.sunday_hours - input.overtime_hours));
       ui->brutto->setPlaceholderText(QString::number(roundf(100 * calc_brutto(input, normal_hours)) / 100));
      ui->tax_amount->setPlaceholderText(QString::number(roundf((100 * calc_brutto(input, normal_hours)) / 100) * input.tax.toFloat() / 100));
       ui->lineEdit_9->setPlaceholderText(QString::number(roundf(100 * calc_brutto(input, all_hours) * ((input.pension.toFloat() / 100))) / 100));
       ui->lineEdit_10->setPlaceholderText(QString::number(roundf(100 * calc_brutto(input, all_hours) * ((input.insurance.toFloat() / 100))) / 100));
       ui->pv_maksu->setPlaceholderText(QString::number(roundf(100 * calc_brutto(input, all_hours) * ((input.pv_payment.toFloat() / 100))) / 100));
       ui->sv_maksu->setPlaceholderText(QString::number(roundf(100 * calc_brutto(input, all_hours) * ((input.sv_payment.toFloat() / 100))) / 100));
        ui->pv_pros->setPlaceholderText(input.pv_payment);
         ui->sv_pros->setPlaceholderText(input.sv_payment);
         ui->pension_pros->setPlaceholderText(input.pension);
         ui->insurance_pros->setPlaceholderText(input.insurance);
       ui->netto->setPlaceholderText(QString::number(roundf(100 * calc_brutto(input, all_hours) * (1 - (input.tax.toFloat() / 100)) * (1 - input.pension.toFloat() / 100)
                                                           * (1 - input.insurance.toFloat() / 100) * (1 - input.sv_payment.toFloat() / 100) * (1 - input.pv_payment.toFloat() / 100)) / 100));

}






















