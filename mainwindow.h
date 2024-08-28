#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void start();
private:
    std::vector<std::thread> threads;
    QWidget centralWidget;
    QVBoxLayout mainLayout;
    QHBoxLayout startLayout;
    QHBoxLayout endLayout;
    QHBoxLayout threadInLayout;
    QHBoxLayout threadOutLayout;
    QVBoxLayout threadOutSubLayout0;
    QVBoxLayout threadOutSubLayout1;
    QVBoxLayout threadOutSubLayout2;
    QVBoxLayout threadOutSubLayout3;
    //Add a table w 1 row to each
    QLabel startLable;
    QLabel endLable;
    QLabel threadInLable;
    QLabel threadOutLable0;
    QLabel threadOutLable1;
    QLabel threadOutLable2;
    QLabel threadOutLable3;

    QSpinBox startEdit;
    QSpinBox endEdit;
    QSpinBox threadEdit;

    QPushButton startBtn;
};
#endif // MAINWINDOW_H
