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



#ifndef SIM_H_
#define SIM_H_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// We first start off by creating a Node struct, and this is where the attributes will be used in the implementation of our functions
struct Node {
    int nodeID;
    int nodeSize;
    Node* nextNode;

    // This is a constructor for the node with default values for the next node and node id 
    // there is also an initialization list for the node
    Node(int nodeSize, Node* nextNode = NULL, int nodeID = -1) : nodeID(nodeID), nodeSize(nodeSize), nextNode(nextNode) {}
};


// these are the declarations of external global variables
extern Node* headNode;
extern double totalNumOfFragments;
extern int totalNumOfDeclinations;
extern int totalNumOfRequests;

// methods that will be implemented in the sim.cpp file
int mem_allocate_for_first_fit(int process_id, int num_units);
int mem_allocate_for_best_fit(int process_id, int num_units);
int mem_deallocate(int process_id); 
int count_fragment(); 
void running(int (*allocator)(int, int));
#endif 



