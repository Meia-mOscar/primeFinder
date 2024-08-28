#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H

#include <QObject>
#include <thread>

class PrimeFinder : public QObject {
public:
    void find(std::vector<std::thread> t);
    void split(int bgn, int end, int cout);
    void get();
private:
    PrimeFinder();
    ~PrimeFinder();
    std::vector<std::thread> myThreads;
    //Each thread's values must be stored
    int range;
    std::vector<int> intervals;
};

#endif // PRIMEFINDER_H
