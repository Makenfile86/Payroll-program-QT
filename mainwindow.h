#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class data
{
public:
    QString fileName;
    QString employee_name;
    QString all_hours;
    QString hourly_pay;
    float night_hours;
    float late_night_hours;
    QString time_string;
    QString overtime;
    float overtime_hours;
    float sunday_hours;
    float hours;
    QString tax;
    QString pension;
    QString insurance;
    QString sv_payment;
    QString pv_payment;
    bool sunday;
};

data reader(QString filename, data input);
float calc_brutto(data input, float all_hours);
float calc_minutes_fraction(QString time_string, bool start);
float adjust_minute_fraction(QVariant var);
data calc_diff_hours(data input);
float calc_overtime_hours(float all_hours);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_all_hours_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_lineEdit_4_textEdited(const QString &arg1);

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_lineEdit_5_textEdited(const QString &arg1);

    void on_lineEdit_6_textEdited(const QString &arg1);

    void on_brutto_textEdited(const QString &arg1);

    void on_tax_pros_textEdited(const QString &arg1);

    void on_lineEdit_9_textEdited(const QString &arg1);

    void on_lineEdit_10_textEdited(const QString &arg1);

    void on_netto_textEdited(const QString &arg1);

    void on_lineEdit_12_textEdited(const QString &arg1);

    void on_hourly_pay_textEdited(const QString &arg1);

    void on_pv_maksu_textEdited(const QString &arg1);

    void on_sv_maksu_textEdited(const QString &arg1);

    void on_actionexcell_triggered();

    void on_night_pa_textEdited(const QString &arg1);

    void on_late_night_pa_textEdited(const QString &arg1);

    void on_sunday_pa_textEdited(const QString &arg1);

    void on_sunday_pa_pros_textEdited(const QString &arg1);

    void on_late_night_pa_pros_textEdited(const QString &arg1);

    void on_night_pa_pros_textEdited(const QString &arg1);

    void on_pv_pros_textEdited(const QString &arg1);

    void on_sv_pros_textEdited(const QString &arg1);

    void on_tax_amount_textEdited(const QString &arg1);

    void on_pension_pros_textEdited(const QString &arg1);

    void on_insurance_pros_textEdited(const QString &arg1);

    void on_overtime_pros_textEdited(const QString &arg1);

    void on_overtime_pa_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
