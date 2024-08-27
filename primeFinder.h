#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H

#include <QObject>
#include <thread>

class PrimeFinder : public QObject {
private:
    void foo();
public:
    std::vector<std::thread> myThreads;
};

#endif // PRIMEFINDER_H
