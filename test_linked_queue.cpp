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
//               g++ -g -std=c++11 -Wall -o ./test_linled_queue_implementation test_linked_queue.o  
//                                        -I. -L/usr/lib -L/usr/local/lib -lm    
//               Or for convience use Make all command (make file included)
//
//  Modifications : no modifications since creation date.
//------------------------------------------------------------------------------------------------------------------
#include<iostream>
#include "LinkedQueue.h"
#define ERR_MSG std::cerr << "ERORR ->>> File:" << __FILE__ << ", Line--" << __LINE__ << ", "<< __TIMESTAMP__<< std::endl;
#define TEST_FAIL(method_name) std::cerr << method_name << " Test Failed" << std::endl;
#define TEST_SUCCESS(method_name) std::cerr << method_name << " Test Successful" << std::endl;
#define LOG std::cerr << "Line "<< __LINE__  << " was executed"<< std::endl;
//@desc format print in stanard output (terminal)
//@post line printed to standard output
void Format(){
  std::cout << "---------------------------------------" << std:: endl;
}
//@desc   compares to queues to see if they are equal. 
//        used to test assignment and copy operator
//@pre    reponsible for saving queues data before call to IsEqual
//@param  LinkedQueue<T>& queue_one, a queue to compare
//@param  LinkedQueue<T>& queue_two, a queue to compare
//@return false if not equal. else true
//@post   the data in each queue has been completely deleted 
template<class T>
bool IsEqual(LinkedQueue<T>& queue_one, LinkedQueue<T>& queue_two){
 
  bool flag = false; //equality error 
  if(queue_one.get_size() != queue_two.get_size()) //queues are not equal
    return false;   
 
  if(queue_one.IsEmpty() && queue_two.IsEmpty()) {//queues are equal 
    return true;
  }
  
  while(!queue_one.IsEmpty() && !queue_two.IsEmpty()){
    if(queue_one.Front() == queue_two.Front()){ //data entries are equal 
      queue_one.Dequeue(); //advance to next item 
      queue_two.Dequeue(); //advance to next item 
    } else {
      flag = false;  //detected error
      return flag;  //not equal
    } //end if
  }//end while
  
  queue_one.Erase(); //completely delete queue one 
  queue_two.Erase(); //completely delete queue two 
  return true; //equal 
} //end IsEqual

//@desc tests essential operations of LinkedQueue class
//@post each operation passes or fails a test 
void TestQueue(){
  Format(); //format standard output (Terminal)
  
  std::cout << "Linked Queue Test" << std::endl;// print to standard output (terminal)
  
  Format(); //format standard output (Terminal)
  LinkedQueue<int> queue_a; //test default constructor 
  
  if(!queue_a.IsEmpty()){
    ERR_MSG; //print error message to standard output (terminal)
    TEST_FAIL("IsEmpty()"); //print test result to standard output (terminal) 
  } else {
    TEST_SUCCESS("IsEmpty()");  //print test result to standard output (terminal) 
  }  
  Format(); //format standard output (Terminal)
  
  queue_a.Enqueue(78);  //test Enqueue
  queue_a.Enqueue(999); //test Enqueue
  queue_a.Enqueue(234); //test Enqueue
  queue_a.Enqueue(123); //test Enqueue

  if(queue_a.get_size() != 4){ //queue not correct size
    ERR_MSG; //print error message to standard output (terminal)
    TEST_FAIL("Enqueue()"); //print test result to standard output
  } else {
    TEST_SUCCESS("Enqueue()");  //print test result to standard output
  }
  Format(); //format standard output (Terminal)
  
  while(!queue_a.IsEmpty()){ queue_a.Dequeue();} //test Dequeue
  
  if(!queue_a.IsEmpty()){
    ERR_MSG;  //print error message to standard output (terminal)
    TEST_FAIL("Dequeue()"); //print test result to standard output (terminal) 
  }else {
    TEST_SUCCESS("Dequeue()");  //print test result to standard output (terminal) 
  }//end if 
  Format(); //format standard output (Terminal)
  
  queue_a.Enqueue(78);  //fill queue
  queue_a.Enqueue(999); //fill queue 
  queue_a.Enqueue(234); //fill queue 
  queue_a.Enqueue(123); //fill queue
  
  if(queue_a.Front() != 78){  //test Front
    ERR_MSG;  //print error message to standard output (terminal)
    TEST_FAIL("Front()"); //print test result to standard output (terminal)
  } else {
    TEST_SUCCESS("Front()");  //print test result to standard output (terminal) 
  } 
  Format(); //format standard output (Terminal)
  
  
  queue_a.Erase();
  if(!queue_a.IsEmpty()){
    ERR_MSG;  //print error message to standard output (terminal)
    TEST_FAIL("Erase()"); //print test result to standard output (terminal) 
  }else {
    TEST_SUCCESS("Erase()");  //print test result to standard output (terminal) 
  }
  Format(); //format standard output (Terminal)
  
  queue_a.Enqueue(78);  //fill queue
  queue_a.Enqueue(999); //fill queue 
  queue_a.Enqueue(234); //fill queue 
  queue_a.Enqueue(123); //fill queue
  
  LinkedQueue<int> queue_b(queue_a);  //test copy constructor, do not copy empty queue
  
  if(!IsEqual(queue_a, queue_b)){ 
    ERR_MSG;  //print error message to standard output (terminal)
    TEST_FAIL("Copy Constructor");  //print test result to standard output (terminal) 
  } else {
    TEST_SUCCESS("Copy Constructor"); //print test result to standard output (terminal) 
  }
  Format(); //format standard output (Terminal)
  
  queue_b.Enqueue(666); //mutate queue
  LinkedQueue<int> queue_c = queue_b; //test assignment operator 
 
  if(!IsEqual(queue_b, queue_c)){ 
    ERR_MSG; //print error message to standard output (terminal)
    TEST_FAIL("Assignment Operator");  //print test result to standard output (terminal) 
  } else {
    TEST_SUCCESS("Assignment Operator"); //print test result to standard output (terminal) 
  }
  Format(); //format standard output (Terminal)
}//end TestQueue
int main(){

  TestQueue();  //tests queue implementation
  return 0;
}//end main
