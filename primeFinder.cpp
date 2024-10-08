#include "primeFinder.h"

PrimeFinder::PrimeFinder() {
    primesInRange.clear();
    newPrime = 0;
    id = nxtId;
    nxtId++;
}

PrimeFinder::~PrimeFinder() {

}

void PrimeFinder::findPrime(int start, int end) {
    /*
     * Prime is divisible by 1 & itself.
     * Up to sqrt(x). Thereafter divisor pairs.
     * Assume prime & evaluate for composite number.
     * This evaulates only one number, not a range.
     */
    primesInRange.clear();

    for(int currentNum=start; currentNum<=end; currentNum++) {
        bool isPrime = true;
        for(int i = 2; i<=std::sqrt(currentNum); i++) {
            if(currentNum%i == 0) {
                isPrime = false;
            }
        }
        if(isPrime) {
            //qDebug() << "Prime::findP() Obj_id(" + QString::number(getId()) + ") strt(" + QString::number(start) + ") - end(" + QString::number(end) + ") isPrime("+QString::number(currentNum)+")";
            addToPrimes(currentNum);
        } else {

            //qDebug() << "Prime::findP() Obj_id(" + QString::number(getId()) + ") strt(" + QString::number(start) + ") - end(" + QString::number(end) + ") isNot("+QString::number(currentNum)+")";
        }

    }
}

void PrimeFinder::addToPrimes(int prime) {
    primesInRange.push_back(prime);
    emit primeFound(prime);
}

std::vector<int>* PrimeFinder::getPrimes() {
    return &primesInRange;
}

int PrimeFinder::getNewPrime() {
    return newPrime;
}

int PrimeFinder::getId() {
    return id;
}

int PrimeFinder::nxtId = 0;
