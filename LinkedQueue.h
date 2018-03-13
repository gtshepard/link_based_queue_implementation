//------------------------------------------------------------------------------------------------------------------
//  Title :         test_linked_queue.cpp
//  Author :        Garrison Shepard
//  Created :       March 9th, 2018
//
//  Description :   This is an implementation of a Linked Queue data structure
//                  Tests are run against operations to verify correctness.
//
//  Purpose :       To provide a link based queue implementation for general use 
//                  and study. Of Interest to those preparing for software engineering 
//                  interviews and studying Computer Science. Originally created for CS community 
//                  on college campus for interview preparation, now open for public use.
//
//  Usage :         ./test_linked_queue_implementation
//
//  Build with : g++ -g -std=c++11 -Wall -I.   -c test_queue.cpp -o test_queue.o
//               g++ -g -std=c++11 -Wall -o ./test_queue test_queue.o  -I.  -L/usr/lib -L/usr/local/lib -lm    
//               Or for convience use Make all command (make file included)
//
//  Modifications : no modifications since creation date.
//------------------------------------------------------------------------------------------------------------------
#ifndef LINKED_QUEUE_H_
#define LINKED_QUEUE_H_
#include<iostream>
template<class T>
class LinkedQueue {
  public:
    //@desc default constructor, initializes default 
    //      for private memebers
    //@post private members have known default values
    //      rids class of garbage values.
    LinkedQueue();
    //@desc  copy constructor, arguement queue's data 
    //       is copied to 'this' queue 
    //@pre   queue to copy must have size_ > 0, 
    //       do not copy empty queue undefined behavior
    //@param LinkedQueue<T>& queue, queue to copy 
    //@post  'this' queue has identical data entries to 
    //       argument queue 
    LinkedQueue(const LinkedQueue<T>& queue); 
    
    //@desc assginment operator, assigns argument queue
    //      to 'this' queue
    //@pre  queue to assign must have size_ > 0
    //@post arguement queue data is copied to 'this' queue
    //      'this' queue has been initialized to argument queue 
    LinkedQueue<T>& operator=(const LinkedQueue<T>& rhs);
    
    //@desc removes all data entries from queue, and destroys it
    //@post automatically called by class, onece called data is 
    //      deleted and object is destroyed for given instance of the class
    ~LinkedQueue();
    
     //---------------------------
    // non-mutable public methods
    //---------------------------
    
    //@desc    checks to see if the queue contains data 
    //@mutable method non-mutable, cannot mutate queue
    //@return  if queue contains data false, else true
    bool IsEmpty() const;
  
    //@desc     returns next availible data entry in queue 
    //@pre      size_ > 0, do not call empty queue, undefined behavior 
    //          dangerous to store result in variable upon 
    //          call Front on an empty queue
    //@mutable  method non-mutable, cannot mutate queue 
    //@return   T, next availible data entry in queue, if queue is 
    //          empty reuslt is undefined 
    T Front() const;
    
    //@desc    getter method for size_ member
    //@mutable method is non-mutable, cannot mutate queue
    //@return  size_t, number of data entries in queue 
    size_t get_size() const;
  
    //---------------------------
    // mutable public methods
    //---------------------------
    
    //@desc     adds a data entry to the back of the queue
    //@param    const T& data, where T is a template type
    //               and data holds the data to be pushed
    //               into the queue.
    //@mutable  method is mutable, can mutate queue
    //@post     queue contains the new data entry
    void Enqueue(const T& data);
   
    //@desc    removes data entry from the front of the queue 
    //@pre     method has no effect on an empty queue 
    //@mutable method is mutable, can mutate queue
    //@post    front data entry is deleted from queue. 
    //         if queue is empty, no data is removed 
    //         and function terminates normally.
    void Dequeue();

    //@desc    deletes each data entry in the queue
    //@pre     method has no effect on an empty queue 
    //@mutable mehtod is mutable, can mutate queue
    //@post    all data entries in queue have been removed
    //         if queue is empty, no data is removed.
    //         fucntion terminates normally.
    void Erase();
 
  private:
    struct Node {
      Node():next(nullptr){}
      Node(const T&d):data(d){}
      Node(const T&d, Node* n):data(d), next(n){}
      
      T data;
      Node* next;
    };
  
   LinkedQueue::Node* front_; //first data entry in queue
   LinkedQueue::Node* back_;  //last data entry in queue 
   int size_; //number of data entries in queue 
   
   //---------------------------
   // mutable private methods
   //---------------------------
  
   //@desc    deep copy on contents of queue 
   //@pre     size_ > 0, do not call on empty queue 
   //@param   LinkedQueue<T>& queue, queue to copy contents of 
   //@mutable method is mutable, can mutate queue 
   //@post    'this' queue contains the same data entries 
   //         as argument queue passed in
   void Copy(const LinkedQueue<T>& queue);
};
#include "LinkedQueue.cpp"
#endif
