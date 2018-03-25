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
//  Build with : g++ -g -std=c++11 -Wall -I.   -c test_linked_queue.cpp -o test_linked_queue.o
//               g++ -g -std=c++11 -Wall -o ./test_linled_queue_implementation test_linked_queue.o  -I.  -L/usr/lib -L/usr/local/lib -lm    
//               Or for convience use Make all command (make file included)
//
//  Modifications : no modifications since creation date.
//------------------------------------------------------------------------------------------------------------------
#include "LinkedQueue.h"
#include<iostream>
template<class T>
LinkedQueue<T>::LinkedQueue():front_(nullptr), back_(nullptr), size_(0){}

template<class T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& queue){
  front_ = nullptr; //initialize default value
  back_ = nullptr; //initialize default value
  size_ = 0;  //initialize default value
  Erase();  //remove any data entries
  Copy(queue); //copy argument queue to 'this' queue 
}

template<class T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rhs){
  
  if(this != &rhs){
    size_ = 0;  //initialize default value
    front_ = nullptr; //initialize default value
    back_ = nullptr;  //initialize default value
    Erase();  //remove any data entries
    Copy(rhs);  //copy argument queue to 'this' queue 
  }
  return *this; //returns this queue 
} 

template<class T>
LinkedQueue<T>::~LinkedQueue(){Erase();} //removes all data entries from queue 

//---------------------------
// non-mutable public methods
//---------------------------
 
template<class T>
bool LinkedQueue<T>::IsEmpty() const {
  if(size_ != 0) //if queue has data 
    return false;

  return true; // if queue has no data 
} //end IsEmpty

template<class T>
T LinkedQueue<T>::Front()const{return front_->data;} //end Front

template<class T>
size_t LinkedQueue<T>::get_size()const {return size_;} //end get_size

template<class T>
void LinkedQueue<T>::Enqueue(const T& data){
  if(IsEmpty()){ //create first node
    front_ = new Node(data, nullptr); //creates head of queue 
    back_ = front_; //sets end node
  } else{
    Node* append = new Node(data, nullptr); //create additional node
    back_->next = append; //append to back of list
    back_ = back_->next; //set end node 
  }
  size_++; //adjust number of data entries
}//end Enqueue

template<class T>
void LinkedQueue<T>::Dequeue(){
   Node* remove = front_; //retrieve first entry 
   front_ = front_->next; //adjust first entry of queue
   delete remove; //remove retrieved entry 
   size_--; //adjust number of data entries
} //end Dequeue

template<class T>
void LinkedQueue<T>::Erase(){
  while(!IsEmpty()) //if data in queue 
    Dequeue(); //remove data entry 
} //end Erase

//---------------------------
// mutable private methods
//---------------------------

template<class T>
void LinkedQueue<T>::Copy(const LinkedQueue<T>& queue){

  if(queue.IsEmpty()) // no data entries in queue
    return;
    
   Node* traverse = queue.front_; //next availible item in argument queue 
   while(traverse != nullptr){
       Enqueue(traverse->data); //copy data entry into 'this' queue 
       traverse = traverse->next; //advance to next entry
   }  //end while
} //end Copy 
