#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H

#include <QObject>
#include <QDebug>

class PrimeFinder : public QObject {
public:
    PrimeFinder();
    ~PrimeFinder();
    void findPrimesInRange(int start, int end);
private:
    //Each thread's values must be stored
    //Rows = myThreads
    //Cols = primes found in each thread
    std::vector<int> primesInRange;
    int start;
    int end;
    int range;
};

#endif // PRIMEFINDER_H
