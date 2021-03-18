#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define _USE_MATH_DEFINES
#include <cmath>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QLabel;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void make_dot();
    void calcul();
    void but_min();
    void but_plus();
    void but_mul();
    void but_dev();
    void but_per();
    void but_ln();
    void but_log2();
    void but_log10();
    void but_pi();
    void but_e();
    void but_plmn();
    void but_dex();
    void but_cos();
    void but_sin();
    void but_tg();
    void but_c();
    void but_sqrt();
    void but_eq();
    void but_del();
    void but_mm();
    void but_mp();
    void but_mc();
    void but_mr();
    void but_1();
    void but_2();
    void but_3();
    void but_4();
    void but_5();
    void but_6();
    void but_7();
    void but_8();
    void but_9();
    void but_0();
    void but_00();

private:
    Ui::MainWindow *ui;
    QStack<QString> res;
    QString wrt;
    qreal mem;
    QString str;
};
#endif // MAINWINDOW_H
