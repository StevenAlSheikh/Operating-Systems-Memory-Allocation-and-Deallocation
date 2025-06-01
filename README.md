# Memory Allocation Simulator

## Project Overview

This project simulates main memory allocation in an operating system using linked lists to track memory usage. It evaluates two memory allocation/deallocation techniques:

- **First Fit**
- **Best Fit**

Memory is simulated as 256 KB divided into units of 2 KB each (128 units total). Each simulated process requests between 3 and 10 units of memory.

The simulation involves three main components:

1. **Memory Component:** Implements allocation and deallocation techniques with functions to allocate, deallocate, and count fragments.
2. **Request Generation Component:** Generates allocation and deallocation requests for processes.
3. **Statistics Reporting Component:** Calculates and prints performance metrics after running the simulation.

The system runs 10,000 requests and tracks three key performance parameters for both allocation methods:

- Average number of external fragments (holes of size 1 or 2 units)
- Average allocation time (measured by the average number of nodes traversed during allocation)
- Percentage of allocation requests denied

---

## Memory Component API

- `int allocate_mem(int process_id, int num_units)`: Allocates `num_units` to `process_id`. Returns the number of nodes traversed if successful, or -1 if failed.
- `int deallocate_mem(int process_id)`: Deallocates memory for `process_id`. Returns 1 if successful, or -1 if the process is not found.
- `int fragment_count()`: Returns the count of external fragments (holes of size 1 or 2 units).

---

