# Operating-Systems-Memory-Allocation-and-Deallocation
This assignment was locked Jun 27, 2024 at 11:45pm.
This page last modified 19 May, 2024

Design and implement a program to simulate memory allocation/deallocation.
You shall create a program that simulates the main memory allocation in an operating system.  You will use 
this to simulate and evaluate first fit and best fit memory allocation/deallocation techniques when using 
a linked list to keep track of memory usage.

Implementation:
Assume the following:
-  Memory is 256 KB and is divided into units of 2 KB each.
-  A process may request between 3 and 10 units of memory.

Your simulation consists of three components: (1) Memory component that implements a specific 
allocation/deallocation technique; (2) a request generation component that generates allocation/deallocation
requests; and (3) a statistics reporting component that prints out the relevant statistics.

The Memory component exports the following functions:
int allocate_mem (int process_id, int num_units): allocates num_units units of memory to a process whose
id is process_id. If successful, it returns the number of nodes traversed in the linked list. Otherwise, 
it returns -1.

int deallocate_mem (int process_id): deallocates the memory allocated to the process whose id is 
process_id. It returns 1, if successful, otherwise –1.

int fragment_count( ): returns the number of holes (fragments of sizes 1 or 2 units). 

You will implement a separate Memory component for each memory allocation/deallocation technique. The 
request generation component generates allocation and deallocation requests. For allocation requests, the 
component specifies the process id of the process for which memory is requested as well as the number of 
memory units being requested. For this simulation, assume that memory is requested for each process only 
once. For deallocation requests, the component specifies the process id of the process whose memory has to 
be deallocated. For this simulation, assume that the entire memory allocated to a process is deallocated on 
a deallocation request. You may generate these requests based on some specific criteria, e.g. a random 
sequence or hard coded sequence. There are three performance parameters that your simulation should 
calculate for both techniques: average number of external fragments, average allocation time in terms of the
average number of nodes traversed in allocation, and the percentage of times an allocation request is denied.
 
Run your simulation generating 10,000 requests using the request generation component, and for each request,
invoke the appropriate function of the Memory component for each of the memory allocation/deallocation 
technique. After every request, update the three performance parameters for each of the techniques.

The statistics reporting component prints the value of the three parameters for both techniques at the end.

Your project shall include a README file using the same conventions/requirements specified in the course 
README instructions file.

Your program will be tested by compiling and executing on edoras. Your program shall be written such that it
compiles and executes cleanly when using gcc/g++. Note - you must use a Makefile. You shall create a 
sub-directory named "a3" in your home directory. In it, you shall place all of your project files, including
your Makefile. Your source files shall contain sufficient comments for making the source easy to read. Name
the executable "sim".  Also, create an archive file (tarball or zip) and upload to edoras (one student per
project) as your turn-in for assignment #3.
Create ~/a3 by hand.
Create all necessary project files. Put them into ~/a3.
The Makefile shall create an executable named "sim" in this same directory (~/a3).
The system call "system()" will NOT be allowed
You must work individually or in pairs (individually or a team of 2 students)
