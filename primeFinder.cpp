#include "primeFinder.h"

PrimeFinder::PrimeFinder() {
    range = 0;
}

PrimeFinder::~PrimeFinder() {

}

void PrimeFinder::find() {
    /*
     * Prime is divisible by 1 & itself.
     * x/x and all numbers up to sqrt(x)
     * What if x == 2?
     *
     */
    int count = 0;

    for(int i = 2; i< sqrt(x); i++) {
        if(x%i == 0) {
            count++;
        }
    }
}

void PrimeFinder::split(int bgn, int end, int count) {
    /*
     * Div the number set into threads
     * end-bgn=range
     * range/count
     *
     */
    range = end-bgn;

}
