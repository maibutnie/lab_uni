#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->but0, &QPushButton::clicked, this, &MainWindow::but_0, Qt::ConnectionType::AutoConnection);
    connect(ui->but00, &QPushButton::clicked, this, &MainWindow::but_00, Qt::ConnectionType::AutoConnection);
    connect(ui->but1, &QPushButton::clicked, this, &MainWindow::but_1, Qt::ConnectionType::AutoConnection);
    connect(ui->but2, &QPushButton::clicked, this, &MainWindow::but_2, Qt::ConnectionType::AutoConnection);
    connect(ui->but3, &QPushButton::clicked, this, &MainWindow::but_3, Qt::ConnectionType::AutoConnection);
    connect(ui->but4, &QPushButton::clicked, this, &MainWindow::but_4, Qt::ConnectionType::AutoConnection);
    connect(ui->but5, &QPushButton::clicked, this, &MainWindow::but_5, Qt::ConnectionType::AutoConnection);
    connect(ui->but6, &QPushButton::clicked, this, &MainWindow::but_6, Qt::ConnectionType::AutoConnection);
    connect(ui->but7, &QPushButton::clicked, this, &MainWindow::but_7, Qt::ConnectionType::AutoConnection);
    connect(ui->but8, &QPushButton::clicked, this, &MainWindow::but_8, Qt::ConnectionType::AutoConnection);
    connect(ui->but9, &QPushButton::clicked, this, &MainWindow::but_9, Qt::ConnectionType::AutoConnection);
    connect(ui->plus, &QPushButton::clicked, this, &MainWindow::but_plus, Qt::ConnectionType::AutoConnection);
    connect(ui->minus, &QPushButton::clicked, this, &MainWindow::but_min, Qt::ConnectionType::AutoConnection);
    connect(ui->devide, &QPushButton::clicked, this, &MainWindow::but_dev, Qt::ConnectionType::AutoConnection);
    connect(ui->multiply, &QPushButton::clicked, this, &MainWindow::but_mul, Qt::ConnectionType::AutoConnection);
    connect(ui->pi, &QPushButton::clicked, this, &MainWindow::but_pi, Qt::ConnectionType::AutoConnection);
    connect(ui->econst, &QPushButton::clicked, this, &MainWindow::but_e, Qt::ConnectionType::AutoConnection);
    connect(ui->sqrt, &QPushButton::clicked, this, &MainWindow::but_sqrt, Qt::ConnectionType::AutoConnection);
    connect(ui->cos, &QPushButton::clicked, this, &MainWindow::but_cos, Qt::ConnectionType::AutoConnection);
    connect(ui->sin, &QPushButton::clicked, this, &MainWindow::but_sin, Qt::ConnectionType::AutoConnection);
    connect(ui->tg, &QPushButton::clicked, this, &MainWindow::but_tg, Qt::ConnectionType::AutoConnection);
    connect(ui->devnow, &QPushButton::clicked, this, &MainWindow::but_dex, Qt::ConnectionType::AutoConnection);
    connect(ui->log, &QPushButton::clicked, this, &MainWindow::but_log2, Qt::ConnectionType::AutoConnection);
    connect(ui->ln, &QPushButton::clicked, this, &MainWindow::but_ln, Qt::ConnectionType::AutoConnection);
    connect(ui->log10, &QPushButton::clicked, this, &MainWindow::but_log10, Qt::ConnectionType::AutoConnection);
    connect(ui->plmn, &QPushButton::clicked, this, &MainWindow::but_plmn, Qt::ConnectionType::AutoConnection);
    connect(ui->delall, &QPushButton::clicked, this, &MainWindow::but_c, Qt::ConnectionType::AutoConnection);
    connect(ui->delnow, &QPushButton::clicked, this, &MainWindow::but_del, Qt::ConnectionType::AutoConnection);
    connect(ui->mc, &QPushButton::clicked, this, &MainWindow::but_mc, Qt::ConnectionType::AutoConnection);
    connect(ui->mm, &QPushButton::clicked, this, &MainWindow::but_mm, Qt::ConnectionType::AutoConnection);
    connect(ui->mr, &QPushButton::clicked, this, &MainWindow::but_mr, Qt::ConnectionType::AutoConnection);
    connect(ui->mp, &QPushButton::clicked, this, &MainWindow::but_mp, Qt::ConnectionType::AutoConnection);
    connect(ui->equal, &QPushButton::clicked, this, &MainWindow::but_eq, Qt::ConnectionType::AutoConnection);
    connect(ui->butdot, &QPushButton::clicked, this, &MainWindow::make_dot, Qt::ConnectionType::AutoConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::make_dot()
{
    wrt += ".";
    ui->label->setText(wrt);
}

void MainWindow::but_1()
{
    wrt += "1";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_2()
{
    wrt += "2";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_3()
{
    wrt += "3";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_4()
{
    wrt += "4";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_5()
{
    wrt += "5";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_6()
{
    wrt += "6";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_7()
{
    wrt += "7";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_8()
{
    wrt += "8";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_9()
{
    wrt += "9";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_0()
{
    wrt += "0";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_00()
{
    wrt += "00";
    ui->label->setNum(wrt.toDouble());
}

void MainWindow::but_eq()
{
    if (res.count() >= 2)
    {
        res.push(QString().setNum(ui->label->text().toDouble()));
        calcul();
        res.clear();
        res.push(QString().setNum(ui->label->text().toDouble()));
    }
    else
    {
        res.push(QString().setNum(ui->label->text().toDouble()));
        wrt = "";
    }
}

void MainWindow::but_mc()
{
    mem = 0;
    ui->label->setNum(mem);
}

void MainWindow::but_mm()
{
    if (res.count() >= 2)
    {
       res.push(QString().setNum(ui->label->text().toDouble()));
       calcul();
       res.clear();
       res.push(QString().setNum(ui->label->text().toDouble()));
       mem -= res.pop().toDouble();
       wrt = "";
    }
    else
    {
       res.push(QString().setNum(ui->label->text().toDouble()));
       mem -= res.pop().toDouble();
       res.push("=");
       wrt = "";
    }
    res.clear();
}

void MainWindow::but_mp()
{
    if (res.count() >= 2)
    {
       res.push(QString().setNum(ui->label->text().toDouble()));
       calcul();
       res.clear();
       res.push(QString().setNum(ui->label->text().toDouble()));
       mem += res.pop().toDouble();
       wrt = "";
    }
    else
    {
       res.push(QString().setNum(ui->label->text().toDouble()));
       mem += res.pop().toDouble();
       res.push("=");
       wrt = "";
    }
    res.clear();
}

void MainWindow::but_mr()
{
    ui->label->setNum(mem);
}

void MainWindow::but_min()
{
    if(ui->label->text().contains("error"))
    {
        ui->label->setText("error");
        return;
    }
    ui->label1->setText("-");
    if (res.count() >= 2)
    {
        res.push(QString().setNum(ui->label->text().toDouble()));
        calcul();
        res.clear();
        res.push(QString().setNum(ui->label->text().toDouble()));
        res.push("-");
        wrt = " ";
    }
    else
    {
        res.push(QString().setNum(ui->label->text().toDouble()));
        res.push("-");
        wrt = " ";
    }
}

void MainWindow::but_plus()
{
    if(ui->label->text().contains("error"))
    {
        ui->label->setText("error");
        return;
    }
    ui->label1->setText("+");
    if (res.count() >= 2)
    {
        res.push(QString().setNum(ui->label->text().toDouble()));
        calcul();
        res.clear();
        res.push(QString().setNum(ui->label->text().toDouble()));
        res.push("+");
        wrt = "";
    }
    else
    {
        res.push(QString().setNum(ui->label->text().toDouble()));
        res.push("+");
        wrt = "";
    }
}

void MainWindow::but_dev()
{
    if(ui->label->text().contains("error"))
    {
        ui->label->setText("error");
        return;
    }
    ui->label1->setText("/");
    if (res.count() >= 2)
    {
        res.push(QString().setNum(ui->label->text().toDouble()));
        calcul();
        res.clear();
        res.push(QString().setNum(ui->label->text().toDouble()));
        res.push("/");
        wrt = " ";
    }
    else
    {
        res.push(QString().setNum(ui->label->text().toDouble()));
        res.push("/");
        wrt = " ";
    }
}

void MainWindow::but_mul()
{
    if(ui->label->text().contains("error"))
    {
        ui->label->setText("error");
        return;
    }
    ui->label1->setText("*");
    if (res.count() >= 2)
    {
        res.push(QString().setNum(ui->label->text().toDouble()));
        calcul();
        res.clear();
        res.push(QString().setNum(ui->label->text().toDouble()));
        res.push("*");
        wrt = " ";
    }
    else
    {
        res.push(QString().setNum(ui->label->text().toDouble()));
        res.push("*");
        wrt = " ";
    }
}

void MainWindow::but_del()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    int op = res.pop().toInt();
    int fRes = 0;
    fRes = op / 10;
    ui->label->setNum(fRes);
    res.clear();
    res.push(QString().setNum(ui->label->text().toDouble()));
}

void MainWindow::but_sqrt()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("sqrt");
    wrt = "";
    but_eq();
}

void MainWindow::but_sin()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("sin");
    wrt = "";
    but_eq();
}

void MainWindow::but_cos()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("cos");
    wrt = "";
    but_eq();
}

void MainWindow::but_tg()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("tg");
    wrt = "";
    but_eq();
}

void MainWindow::but_log2()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("log2");
    wrt = "";
    but_eq();
}

void MainWindow::but_ln()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("ln");
    wrt = "";
    but_eq();
}

void MainWindow::but_log10()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("log10");
    wrt = "";
    but_eq();
}

void MainWindow::but_pi()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("pi");
    wrt = "";
    but_eq();
}

void MainWindow::but_e()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("e");
    wrt = "";
    but_eq();
}

void MainWindow::but_per()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("%");
    wrt = "";
    but_eq();
}

void MainWindow::but_dex()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("1/x");
    wrt = "";
    but_eq();
}

void MainWindow::but_plmn()
{
    res.push(QString().setNum(ui->label->text().toDouble()));
    res.push("+/-");
    wrt = "";
    but_eq();
}

void MainWindow::calcul()
{
    if(ui->label->text().contains("error"))
    {
        ui->label->setText("error");
        return;
    }
    qreal op2 = res.pop().toDouble();
    QString str_op = res.pop();
    QString op_check = res.pop();
    qreal op1 = op_check.toDouble();
    qreal d_res = 0;
    if (op_check == "error")
    {
        ui->label->setText("error");
        return;
    }
    else if (str_op == "+")
    {
        d_res = op1 + op2;
    }
    else if (str_op == "-")
    {
        d_res = op1 - op2;
    }
    else if (str_op == "*")
    {
        d_res = op1 * op2;
    }
    else if (str_op == "/")
    {
        if (op2 != 0)
            d_res = op1 / op2;
        else
        {
            ui->label->setText("error");
            return;
        }
    }
    else if (str_op == "%")
    {
        d_res = op1 /100;
    }
    else if (str_op == "log2")
    {
        if (op1 > 0)
            d_res = log2(op1);
        else
        {
            ui->label->setText("error");
            return;
        }
    }
    else if (str_op == "log10")
    {
        if (op1 > 0)
            d_res = log10(op1);
        else
        {
            ui->label->setText("error");
            return;
        }
    }
    else if (str_op == "1/x")
    {
        if (op1 != 0)
            d_res = 1 / op1;
        else
        {
            ui->label->setText("error");
            return;
        }
    }
    else if (str_op == "ln")
    {
        if (op1 > 0)
            d_res = log(op1);
        else
        {
            ui->label->setText("error");
            return;
        }
    }
    else if (str_op == "sin")
    {
        d_res = sin(op1);
    }
    else if (str_op == "cos")
    {
        d_res = cos(op1);
    }
    else if (str_op == "tg")
    {
        d_res = tan(op1);
    }
    else if (str_op == "+/-")
    {
        d_res = op1 * -1;
    }
    else if (str_op == "pi")
    {
        d_res = op1 * M_PI;
    }
    else if (str_op == "e")
    {
        d_res = op1 * M_E;
    }
    else if (str_op == "sqrt")
    {
        if (op1 >= 0)
            d_res = sqrt(op1);
        else
        {
            ui->label->setText("error");
            return;
        }
    }
    ui->label->setNum(d_res);
}

void MainWindow::but_c()
{
    res.clear();
    wrt = " ";
    ui->label->setText("0");
}
