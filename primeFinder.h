#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H

#include <QObject>
#include <QDebug>

class PrimeFinder : public QObject {
    Q_OBJECT
    /* In the following, can I go without the READ & rid of getNewPrime*
     * Further, can I get rid of 'int newPrime; too!
     */
    Q_PROPERTY(int newPrime READ getNewPrime WRITE addToPrimes NOTIFY primeFound FINAL)
public:
    PrimeFinder();
    ~PrimeFinder();
    void findPrime(int start, int end);
    std::vector<int>* getPrimes();
    int getId();
private:
    void addToPrimes(int prime);
    std::vector<int> primesInRange;
    int getNewPrime();
    int newPrime;
    int start;
    int end;
    int range;
    int id;
    static int nxtId;
signals:
    void primeFound(int newestPrime);
};

#endif // PRIMEFINDER_H
