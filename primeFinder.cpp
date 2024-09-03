#include "primeFinder.h"

PrimeFinder::PrimeFinder() {
    primesInRange.clear();
    newPrime = 0;
}

PrimeFinder::~PrimeFinder() {

}

void PrimeFinder::findPrime(int start, int end) {
    qDebug() << "PrimeFinder::findPrime()";
    /*
     * Prime is divisible by 1 & itself.
     * Up to sqrt(x). Thereafter divisor pairs.
     * Assume prime & evaluate for composite number.
     * This evaulates only one number, not a range.
     */

    for(int currentNum=start; currentNum<end; currentNum++) {
        bool isPrime = true;
        for(int i = 2; i< std::sqrt(currentNum); i++) {
            if(currentNum%i == 0) {
                isPrime = false;
            }
            break;
        }
        if(isPrime) {
            qDebug() << "currentNum(): " + currentNum;
            addToPrimes(currentNum);
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
