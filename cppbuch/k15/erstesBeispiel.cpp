/* cppbuch/k15/erstesBeispiel.cpp
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
  cout << "t3.get_id(): " << t3.get_id() << endl;
  t1.join();  // warten auf Beendigung
  cout << "t1.join() ok" << endl;
  t2.join();  // warten auf Beendigung
  cout << "t2.join() ok" << endl;
  t3.join();  // warten auf Beendigung
  cout << "t3.join() ok\n"
       << "t1.get_id(): " << t1.get_id() << "\nmain() ist beendet\n";
}
