#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    threads.clear();

    startLable.setText("Start");
    endLable.setText("End");
    threadInLable.setText("Number of threads");
    startBtn.setText("Start");
    threadOutLable_0.setText("Thread 1");
    threadOutLable_1.setText("Thread 2");
    threadOutLable_2.setText("Thread 3");
    threadOutLable_3.setText("Thread 4");

    startEdit.setRange(1,INT_MAX);
    startLayout.addWidget(&startEdit);
    startLayout.addWidget(&startLable);
    endEdit.setRange(1,INT_MAX);
    endLayout.addWidget(&endEdit);
    endLayout.addWidget(&endLable);
    threadEdit->setRange(1,4);
    threadInLayout.addWidget(threadEdit);
    threadInLayout.addWidget(&threadInLable);
    threadInLayout.addWidget(&startBtn);

    threadOutSubLayout_0.addWidget(&threadOutLable_0);
    tableView_0.setModel(&table_0);
    threadOutSubLayout_0.addWidget(&tableView_0);
    threadOutLayout.addLayout(&threadOutSubLayout_0);

    threadOutSubLayout_1.addWidget(&threadOutLable_1);
    tableView_1.setModel(&table_1);
    threadOutSubLayout_1.addWidget(&tableView_1);
    threadOutLayout.addLayout(&threadOutSubLayout_1);

    threadOutSubLayout_2.addWidget(&threadOutLable_2);
    tableView_2.setModel(&table_2);
    threadOutSubLayout_2.addWidget(&tableView_2);
    threadOutLayout.addLayout(&threadOutSubLayout_2);

    threadOutSubLayout_3.addWidget(&threadOutLable_3);
    tableView_3.setModel(&table_3);
    threadOutSubLayout_3.addWidget(&tableView_3);
    threadOutLayout.addLayout(&threadOutSubLayout_3);

    mainLayout.addLayout(&startLayout);
    mainLayout.addLayout(&endLayout);
    mainLayout.addLayout(&threadInLayout);
    mainLayout.addLayout(&threadOutLayout);

    centralWidget.setLayout(&mainLayout);
    setCentralWidget(&centralWidget);

    connect(&prime_0, &PrimeFinder::primeFound, this, &MainWindow::addToTable_0);
    connect(&prime_1, &PrimeFinder::primeFound, this, &MainWindow::addToTable_1);
    connect(&prime_2, &PrimeFinder::primeFound, this, &MainWindow::addToTable_2);
    connect(&prime_3, &PrimeFinder::primeFound, this, &MainWindow::addToTable_3);
    connect(&startBtn, &QPushButton::clicked, this, &MainWindow::startClicked);
}

MainWindow::~MainWindow() {
    delete threadEdit;
    for(int i=0; i<items_0.size(); i++) {
        delete items_0.at(i);
    }
    for(int i=0; i<items_1.size(); i++) {
        delete items_0.at(i);
    }
    for(int i=0; i<items_2.size(); i++) {
        delete items_0.at(i);
    }
    for(int i=0; i<items_1.size(); i++) {
        delete items_0.at(i);
    }
}


void MainWindow::setRange() {
    start = startEdit.value();
    end = endEdit.value();
    threadCount = threadEdit->value();
    range = end-start;

    if(range % threadCount == 0) {
        increment = range/threadCount;
    } else {
        increment = (range/threadCount)+1;
    }
}

void MainWindow::setThreads() {
    threadCount = threadEdit->value();
    finders.push_back(&prime_0);
    finders.push_back(&prime_1);
    finders.push_back(&prime_2);
    finders.push_back(&prime_3);
}

void MainWindow::findPrime() {
    //std::thread thread_obj(foo, params);
    threads.clear();
    start = startEdit.value();
    for(int i=0; i<threadCount; i++) {
        int a = start+i*increment;
        int b;
        if(i == threadCount-1) {
            b = end;
        } else {
            b = start+(i+1)*increment-1;
        }
        threads.push_back(std::thread(&PrimeFinder::findPrime, finders.at(i), a, b));
    }
    for(auto &t: threads) {
        t.join();
    }
}

void MainWindow::refreshTable(PrimeFinder &primeObj, QStandardItemModel &itemModel) {
    int pSize = primeObj.getPrimes()->size();
    int prime;
    for(int i=itemModel.rowCount(); i<pSize; i++) {
        QStandardItem *itm = new QStandardItem;
        prime = primeObj.getPrimes()->at(i);
        itm->setText(QString::number(prime));
        itemModel.setItem(i, 0, itm);
    }
}

void MainWindow::addToTable_0() {
    refreshTable(prime_0, table_0);
}

void MainWindow::addToTable_1() {
    refreshTable(prime_1, table_1);
}

void MainWindow::addToTable_2() {
    refreshTable(prime_2, table_2);
}

void MainWindow::addToTable_3() {
    refreshTable(prime_3, table_3);
}

void MainWindow::startClicked() {
    setRange();
    setThreads();
    findPrime();
}
