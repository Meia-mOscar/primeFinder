#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    startLable.setText("Start");
    endLable.setText("End");
    threadInLable.setText("Number of threads");
    startBtn.setText("Start");
    threadOutLable_0.setText("Thread 1");
    threadOutLable_1.setText("Thread 2");
    threadOutLable_2.setText("Thread 3");
    threadOutLable_3.setText("Thread 4");

    startLayout.addWidget(&startEdit);
    startLayout.addWidget(&startLable);
    endLayout.addWidget(&endEdit);
    endLayout.addWidget(&endLable);
    threadInLayout.addWidget(&threadEdit);
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
}

MainWindow::~MainWindow() {}


void MainWindow::calcRange() {
    start = startEdit.value();
    end = endEdit.value();
    threadCount = threadEdit.value();
    range = end-start;

    if(range % threadCount == 0) {
        increment = range/threadCount;
    } else {
        increment = (range/threadCount)+1;
    }
}

void MainWindow::setFinders() {
    threadCount = threadEdit.value();
    for(int i=0; i<threadCount; i++) {
        PrimeFinder *aPrimeFinder = new PrimeFinder;
        finders.push_back(aPrimeFinder);
    }
}

void MainWindow::findPrimes() {
    //std::thread thread_obj(foo, params);
    start = startEdit.value();
    for(int i=0; i<threadEdit.value(); i++) {
        int a = start+i*increment;
        int b = start+(i+1)*increment;
        threads.push_back(std::thread(&PrimeFinder::findPrimesInRange, finders.at(i), a, b));
    }

    /**
     * For each new prime found,
     * update the table widgets w new row
     *
     * QStandardItem *albumTitleItem = new QStandardItem;
     * albumTitleItem->setText(albumTitleInput->text());
     * table->setItem(rowCount,1,albumTitleItem);
     */
}

void MainWindow::refreshThreads(PrimeFinder &primes, std::vector<QStandardItem*> items) {
    /*
     * I need 4 tables
     * Each of ten rows
     * Then a function has to add
     *
    */

    int pSize = primes.getPrimes()->size();
    for(int i=items.size(); i<pSize; i++) {
        QStandardItem *itm = new QStandardItem;
        itm->setText(QString::number(i));
    }
}
