#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string>
#include "../../includes/heap/heap.h"
#include "../../includes/heap/pqueue.h"
using namespace std;

const string line = "\n"+string(50,'-')+"\n";
const string dashes = "\n"+string(50,'.')+"\n";

bool heap_test(bool debug = false)
{
  Heap<int> heap;
  heap.insert(50);
  cout << heap << endl;
  heap.insert(25);
  cout << heap << endl;
  heap.insert(30);
  cout << heap << endl;
  heap.insert(12);
  cout << heap << endl;
  heap.insert(35);
  cout << heap << endl;
  heap.insert(20);
  cout << heap << endl;
  cout << "pop: " << endl;
  cout << heap.remove() << endl << endl;
  cout << heap;
  cout << "pop: " << endl;
  cout << heap.remove() << endl << endl;
  cout << heap;
  cout << "pop: " << endl;
  cout << heap.remove() << endl << endl;
  cout << heap;
  cout << "pop: " << endl;
  cout << heap.remove() << endl << endl;
  cout << heap;
  cout << endl;
  return true;
}

bool pq_test(bool debug = false){
    PQueue<string> pq;
    cout << line 
         << "Priority Queue Test: " <<endl<< line<<line << endl;

    pq.push("Joe Mama", 100);
    pq.push("Joe Biden", 999);
    pq.push("I. Yankit", 5);
    pq.push("Jack Goff", 4);
    pq.push("Phil A. Mignon", 6);
    pq.push("Barb Dwyer", 8);
    pq.push("Hugh Mungus", 2);
    pq.push("Yuri Tarded", 0);
    pq.push("Joe Rogan", 2);
    pq.push("Hugh Jass", 6);
    pq.push("Justin Case", 8);
    pq.push("I. P. Freely", 5);
    pq.push("Jacques Strap", 0);
    pq.push("Jim Shu", 2);
    if(debug)
        cout<<pq<<line<<endl;
    while (!pq.is_empty()){
        cout<<"POPPED: "<<pq.Pop_debug()<<endl;
        if(debug)
            cout<<dashes<<pq<<endl<<line<<endl;
    }

    return true;
}

TEST(TEST_HEAP, TestHeap) {
  bool success = heap_test(true);
  EXPECT_EQ(success, true);
}
TEST(TEST_PQ, TestPQ) {
  bool success = pq_test(false);
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running testB.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

