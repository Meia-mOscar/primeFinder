#include "primeFinder.h"

PrimeFinder::PrimeFinder() {
}

PrimeFinder::~PrimeFinder() {

}

void PrimeFinder::findPrimesInRange(int start, int end) {
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
            primesInRange.push_back(currentNum);
        }

    }
}
