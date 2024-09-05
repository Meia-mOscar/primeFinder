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
    void refreshTable(PrimeFinder &primeObj, QStandardItemModel &itemModel);
    void startClicked();
private:
    void findPrime();
    void setRange();
    void addToTable_0();
    void addToTable_1();
    void addToTable_2();
    void addToTable_3();
    int start;
    int end;
    int threadCount;
    int range;
    int increment;
    std::vector<std::thread> threads;
    std::vector<PrimeFinder*> finders;
    PrimeFinder prime_0;
    PrimeFinder prime_1;
    PrimeFinder prime_2;
    PrimeFinder prime_3;
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
    QLabel startLable;
    QLabel endLable;
    QLabel threadInLable;
    QLabel threadOutLable_0;
    QLabel threadOutLable_1;
    QLabel threadOutLable_2;
    QLabel threadOutLable_3;
    QSpinBox startEdit;
    QSpinBox endEdit;
    QSpinBox *threadEdit = new QSpinBox(this);
    QPushButton startBtn;
    QTableView tableView_0;
    QTableView tableView_1;
    QTableView tableView_2;
    QTableView tableView_3;
    QStandardItemModel table_0;
    QStandardItemModel table_1;
    QStandardItemModel table_2;
    QStandardItemModel table_3;
    std::vector<QStandardItem*> items_0;
    std::vector<QStandardItem*> items_1;
    std::vector<QStandardItem*> items_2;
    std::vector<QStandardItem*> items_3;
};
#endif // MAINWINDOW_H
