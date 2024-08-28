#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    startLable.setText("Start");
    endLable.setText("End");
    threadInLable.setText("Number of threads");
    startBtn.setText("Start");
    threadOutLable0.setText("Thread 1");
    threadOutLable1.setText("Thread 2");
    threadOutLable2.setText("Thread 3");
    threadOutLable3.setText("Thread 4");

    startLayout.addWidget(&startEdit);
    startLayout.addWidget(&startLable);
    endLayout.addWidget(&endEdit);
    endLayout.addWidget(&endLable);
    threadInLayout.addWidget(&threadEdit);
    threadInLayout.addWidget(&threadInLable);
    threadInLayout.addWidget(&startBtn);
    threadOutSubLayout0.addWidget(&threadOutLable0);
    //Add table 0
    threadOutLayout.addLayout(&threadOutSubLayout0);
    threadOutSubLayout1.addWidget(&threadOutLable1);
    //Add table 1
    threadOutLayout.addLayout(&threadOutSubLayout1);
    threadOutLayout.addWidget(&threadOutLable2);
    //Add table 2
    threadOutLayout.addLayout(&threadOutSubLayout2);
    threadOutLayout.addWidget(&threadOutLable3);
    //Add table 3
    threadOutLayout.addLayout(&threadOutSubLayout3);

    mainLayout.addLayout(&startLayout);
    mainLayout.addLayout(&endLayout);
    mainLayout.addLayout(&threadInLayout);
    mainLayout.addLayout(&threadOutLayout);

    centralWidget.setLayout(&mainLayout);
    setCentralWidget(&centralWidget);
}

MainWindow::~MainWindow() {}

void MainWindow::start() {

}
