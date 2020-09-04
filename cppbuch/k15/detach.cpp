/* cppbuch/k15/detach.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <chrono>
#include <iostream>
#include <thread>
using namespace std;

void f(int t) {
  this_thread::sleep_for(chrono::seconds(t));
  cout << "Thread " << this_thread::get_id()
       << " : Funktion beendet! Laufzeit = " << t << " s\n";
}

int main() {
  thread t1(f, 4);
  thread t2(f, 6);
  thread t3(f, 2);
  cout << "t1.get_id(): " << t1.get_id() << '\n';
  cout << "t2.get_id(): " << t2.get_id() << '\n';
  cout << "t3.get_id(): " << t3.get_id() << '\n';
  t1.detach();
  cout << "t1.detach(): " << t1.get_id() << '\n';
  t3.detach();
  cout << "t3.detach(): " << t3.get_id() << '\n';
  t2.join();  // warten auf Beendigung des langlebigsten Threads
  cout << "main() ist beendet\n";
}
