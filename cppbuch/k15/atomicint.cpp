/* cppbuch/k15/atomicint.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include "ThreadGroup.h"
#include <iostream>
#include <atomic>

int nonAtomicCounter {0};
std::atomic<int> atomicCounter {0};

void testeAtomizitaet() {  
  for (int i = 0; i < 1000; ++i) {
    ++nonAtomicCounter;
    ++atomicCounter;
  }
}

int main() {
  ThreadGroup threadgroup;
  for (int i = 0; i < 100; ++i) {
    threadgroup.add_thread(testeAtomizitaet);
  }
  threadgroup.join_all();
  std::cout << "nicht-atomarer Zähler = " << nonAtomicCounter << '\n';
  std::cout << "atomarer Zähler       = " << atomicCounter << '\n';
}
