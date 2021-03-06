------------------------------------------------------------------------------------------------------------------------------
### Title 
test_linked_queue.cpp
***
### Author 
Garrison Shepard
***
### Created 
March 9th, 2018
***
### Description  
Tests This is an implementation of a Linked Queue data structure
Tests are run against operations to verify correctness.
***
### Purpose 
To provide a linked based queue implementation for general use 
and study. Of Interest to those preparing for software engineering 
interviews and studying Computer Science. Originally created for a CS community 
on a college campus for interview preparation, now open for public use.
***
### Usage
./test_linked_queue_implementation
***
### Build With 
g++ -g -std=c++11 -Wall -I -c test_linked_queue.cpp -o test_linked_queue.o
g++ -g -std=c++11 -Wall -o ./test_linked_queue_implementation test_linked_queue.o 
                                  -I.-L/usr/lib -L/usr/local/lib -lm 

Or Build with 'make all' command (for this convenience a make file has been include). 
***
### Modifications 
no modifications since creation date.
***
### Testing
test_linked_queue.cpp contains a series of test cases that verfiy the correctness
of the operations of the provided stack implementation. 

Each test produces output signaling the successful completion or failure of a test
for a specific stack operation. In addition to the signaling of a test failure an 
error message is generated and displayed. The error message is generated by the 
ERR_MSG macro 

ERR_MSG macro defined in test_linked_queue.cpp
TEST_FAIL(method_name) macro defined in test_linked_queue.cpp
TEST_SUCCESS(method_name) macro defined in test_linked_queue.cpp
LOG macro defined in test_linked_queue.cpp

ERR_MSG macro provides information on the where abouts of the error in the tester 
program to narrow down the source of the problem in the code.
TEST_FAIL(method_name) denotes failure of test
TEST_SUCCESS(method_name) denotes success of test
LOG denotes when a line is executed 

***
### Design Advantages 
There is flexibility in the implementation of queue as long as all the integrity of 
the queue's operations are perserved along with the standard runtime bounds on 
these operations.

There are two immediate choices for an underlying data structure for a queue, an array 
or a linked list. Both implementations have their advantages.

In this project a link based implementation is provided. The link based implementation 
offers the ability for the queue to grow and shrink in size because memory is dynamically 
allocated. There is no 'fixed' size limit for a link based queue because memory can be 
allocated during execution time, where an array based implementation would be limited 
to the size of the array, because the size of the array is determined at compile time 
and cannot be expanded later. An array based implementation would be fine if it was known that
the queue would never exceed N entries (where N is the number of entries), in fact it would be 
a better choice, because most of the memory allocation could be handled up front and would not 
steal resources throughout the lifetime of the program. Both implementations offer the same 
runtimes for operations. The link based implementation was chosen because of its flexibility in size. 
It is a more efficient management of memory because only memory needed is allocated. 

Further say the max size of the queue is known, N = 3000, where N is max number of entries in the queue, 
however the queue rarely exceeds 40 entries and the case of 3,000 entries is an extreme outlier that almost 
never occurs due to the nature of the program. Allocating an array up font that can hold 3,000 entries 
is wasteful in terms of memory usage. 

A link based implementation was chosen for this design because the number entries cannot be predetermined.
***
### Operation Runtimes
* IsEmpty()  - Runtime O(1)
* Enqueue()  - Runtime O(1)
* Dequeue()  - Runtime O(1) 
* Front()    - Runtime O(1)         
* Erase()    - Runtime O(n)
* Copy()     - Runtime O(n)
***
### Closing Notes
Program was compiled with g++ and tested on Fedora Linux 24. This program has not been tested on other 
systems. Any questions regarding this program can be directed to the author by email.

contact: shepard.garrisont@gmail.com 
------------------------------------------------------------------------------------------------------------------------------




