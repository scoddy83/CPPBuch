/* cppbuch/k15/ThreadGroup.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef THREADGROUP_H
#define THREADGROUP_H
#include <cstddef>
#include <functional>  // ref()
#include <thread>
#include <vector>

class ThreadGroup {
public:
  ThreadGroup() = default;
  ThreadGroup(const ThreadGroup&) = delete;
  ThreadGroup& operator=(const ThreadGroup&) = delete;

  template <typename F> 
  void add_thread(F& f) {
    threads.emplace_back(std::ref(f));      // Thread speichern und starten
  }

  void join_all() {                         // Auf Beendigung aller Threads warten
    for (auto& t : threads) {
      t.join();
    }
  }

  std::size_t size() const { return threads.size(); }
  // mögliche weitere Methoden weggelassen
private:
  std::vector<std::thread> threads;
};
#endif
