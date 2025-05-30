// Course: CS 480
// Professor Guy Leonard
// Year: 2024
// Programming Assignment #3 
// Group members:
// Name: Steven Al-Sheikh
// RedID: 826493311
// Edoras account: 
// Name: Moe Jawadi
// RedID: 130102437
// Edoras account: cssc4444

#include <iostream>
#include "sim.h"
#include <cstdlib>
#include <ctime>
using namespace std;


// This main method is making 2 method calls to the running()
// one call for first fit memory allocation and the other for best fit memory allocation
int main() {

    cout << "End of First Fit Allocation" << endl;
    running(mem_allocate_for_first_fit);

    // reset stats so best fit stats are accurate
    totalNumOfFragments = 0.0;
    totalNumOfDeclinations = 0;
    totalNumOfRequests = 0;

    cout << endl;
    cout << "End of Best Fit Allocation" << endl;
    running(mem_allocate_for_best_fit);
    return 0;
}






