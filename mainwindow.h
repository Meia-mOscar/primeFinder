#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "primeFinder.h"
#include <QMainWindow>
#include <thread>
#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QStandardItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void findPrimes();
    void refreshThreads(PrimeFinder &primes, std::vector<QStandardItem*> itemModel);
private:
    void setFinders();
    void calcRange();
    int start;
    int end;
    int threadCount;
    int range;
    int increment;
    std::vector<std::thread> threads;
    std::vector<PrimeFinder*> finders;
    QWidget centralWidget;
    QVBoxLayout mainLayout;
    QHBoxLayout startLayout;
    QHBoxLayout endLayout;
    QHBoxLayout threadInLayout;
    QHBoxLayout threadOutLayout;
    QVBoxLayout threadOutSubLayout_0;
    QVBoxLayout threadOutSubLayout_1;
    QVBoxLayout threadOutSubLayout_2;
    QVBoxLayout threadOutSubLayout_3;
    //Add a table w 1 row to each
    QLabel startLable;
    QLabel endLable;
    QLabel threadInLable;
    QLabel threadOutLable_0;
    QLabel threadOutLable_1;
    QLabel threadOutLable_2;
    QLabel threadOutLable_3;
    QSpinBox startEdit;
    QSpinBox endEdit;
    QSpinBox threadEdit;
    QPushButton startBtn;

    QTableView tableView_0;
    QTableView tableView_1;
    QTableView tableView_2;
    QTableView tableView_3;
    QStandardItemModel table_0;
    QStandardItemModel table_1;
    QStandardItemModel table_2;
    QStandardItemModel table_3;
    std::vector<QStandardItemModel*> items_0;
    std::vector<QStandardItemModel*> items_1;
    std::vector<QStandardItemModel*> items_2;
    std::vector<QStandardItemModel*> items_3;
};
#endif // MAINWINDOW_H
