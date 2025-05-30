// Course: CS 480
// Professor Guy Leonard
// Year: 2024
// Programming Assignment #3 
// Group members:
// Name: Steven Al-Sheikh
// RedID: 826493311
// Edoras account: cssc4457 
// Name: Moe Jawadi
// RedID: 130102437
// Edoras account: cssc4444
#include <iostream>
#include "sim.h"
#include <cstdlib>
#include <ctime>
using namespace std;


// these are the global variables with the numeric ones initiialized to 0
Node* headNode;
double totalNumOfFragments = 0.0;
int totalNumOfDeclinations = 0;
int totalNumOfRequests = 0;

// the implementations of our methods are here
// we used a linkedlist implementation to allocate the memory by first fit allocation
int mem_allocate_for_first_fit(int process_id, int num_units) {
    

    // here we first declare a node named nodeCurrent and we set it to the head node
    // then declare an int variable called nodesTraversedCounter and initialize it to 0
    Node* nodeCurrent = headNode;
    int nodesTraversedCounter = 0;

    // we use a while loop here to loop through thr linkedlost until the memory has been allocated
    while (nodeCurrent) {
        nodesTraversedCounter++;
        if (nodeCurrent->nodeID == -1 && nodeCurrent->nodeSize > num_units) {

            //  we created a new instance of our node called newNode
            Node* newNode = new Node(nodeCurrent->nodeSize - num_units, nodeCurrent->nextNode, -1);

            nodeCurrent->nodeSize = num_units;
            nodeCurrent->nextNode = newNode;
            nodeCurrent->nodeID = process_id;
            return nodesTraversedCounter;
        }

        // at the end of each iteration of the loop, we set nodeCurrent to the nodeCurrent's nextNode
        nodeCurrent = nodeCurrent->nextNode;
    }
    totalNumOfDeclinations++;

    // we return a -1 to show that an allocation for memory by first fit was not successful
    return -1; 
}

// we use a linkedlist implementation to allocate the memory by best fit allocation 
int mem_allocate_for_best_fit(int process_id, int num_units) {

    // here we have declared two nodes
    // one of them is for the current node while the other is for the best fit node
    Node* nodeCurrent = headNode;
    Node* bestFitNode = NULL;

    int nodesTraversedCounter = 0;

    // we use a while loop to loop through the linkedlist until the memory is allocated
    while (nodeCurrent) {
        nodesTraversedCounter++;

        // we made this if statement to check to see if the conditoons have been met
        // if they are met, then the bestFitNode will be set to the current node
        if (nodeCurrent->nodeID == -1 && nodeCurrent->nodeSize > num_units &&
            (!bestFitNode || nodeCurrent->nodeSize < bestFitNode->nodeSize)) {
            bestFitNode = nodeCurrent;
        }

        nodeCurrent = nodeCurrent->nextNode;
    }

    // this if statement is the same thing as the if statement from mem_allocate_for_first_fit, except we are checking
    // the properties of bestFitNode
    if (bestFitNode) {
        Node* newNode = new Node(bestFitNode->nodeSize - num_units, bestFitNode->nextNode, -1);
        bestFitNode->nodeSize = num_units;
        bestFitNode->nextNode = newNode;
        bestFitNode->nodeID = process_id;
        return nodesTraversedCounter;
    }
    totalNumOfDeclinations++;

    return -1; 
}

// another linkedlist implementation to deallocate memory allocated to the process whose id is process_id
int mem_deallocate(int process_id) {
    Node* nodeCurrent = headNode;

    // we use a while loop to loop through the linkedlist until memory has been deallocated
    while (nodeCurrent) {
        if (nodeCurrent->nodeID == process_id) {
            nodeCurrent->nodeID = -1;
            return 1;
        }
        nodeCurrent = nodeCurrent->nextNode;
    }

    return -1; 
}

// this method uses a linkedlist implementation to return the number of fragments of sizes 1 or 2 units
int count_fragment() {
    int fragmentCounter = 0;

    // here we declare a temp node and set it to the head node
    Node* tempNode = headNode;

    // loop through the linkedlist and check to see if the temp node's id is -1 and it's size is either 1 or 2
    // if the conditions are met, then we will increment fragmentCounter
    while (tempNode != NULL) {
        if (tempNode->nodeID == -1 && (tempNode->nodeSize == 1 || tempNode->nodeSize == 2)) {
            fragmentCounter++;
        }
        tempNode = tempNode->nextNode;
    }


    return fragmentCounter;
}


// this method will display the stats of the memory allocation
// the parameter is a function pointer pointing to the function(s) that are of allocator type
void running(int (*allocator)(int, int)) {

    // this is a random number generator
    srand(time(0));

    // this head node starts with 256KB / 2KB units of memory, which is why 128 is passed in
    headNode = new Node(128);

    // we created a double called averageTraversedNodes and initialize it to 0
    double avgTraversedNodes = 0;

    int successAllocations = 0;

    // int variable to hold the 10000 allocation and deallocation requests or all allocation requests
    int allallocationRequests = 10000;

    // we use a for loop to loop through the requests and determine whether to allocate or deallocate
    for (int i = 0; i < allallocationRequests; i++) { 
        int id = i + 1;

        // this if statement will allocate
        // 2 in 5 chance to allocate the memory
        if ((rand() % 5) < 2) { 

            // process may request a random size between 3 and 10 units
            int size = (rand() % 8) + 3; 

            // declare an int variable and set it to the result of the call to the allocator function
            int traversedNodes = allocator(id, size);


            if (traversedNodes != -1) {
                avgTraversedNodes += traversedNodes;
                successAllocations++;
            }

            // at the end of the if statement, calculate the totalNumOfFragments by doing an addition assignment with a call to fragment_count()
            totalNumOfFragments += count_fragment();
        }

        // This else is to deallocate
        else { 

            // declare an int variable and set it to the random process to deallocate
            // make a call to mem_deallocate()
            int dealloc_id = (rand() % id) + 1; 
            mem_deallocate(dealloc_id);
        }
        totalNumOfRequests++;
    }

    // important calculations for the allocation stats
    avgTraversedNodes /= successAllocations;
    double avgExternalFragments = totalNumOfFragments / totalNumOfRequests;
    double percentageOfDeclinations = (totalNumOfDeclinations / (double)totalNumOfRequests) * 100.0;

    cout << "Average External Fragments Each Request: " << avgExternalFragments << endl;
    cout << "Average Nodes Traversed Each Allocation: " << avgTraversedNodes << endl;
    cout << "Percentage Allocation Requests Denied Overall: "
        << percentageOfDeclinations << "%" << endl;
}










   