/* cppbuch/k15/Worker.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef WORKER_H
#define WORKER_H
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

class Worker {
public:
  Worker() = default;

  void operator()() {
    while (!beendet) {
      std::cout << "Worker bei der Arbeit!" << std::endl;
      pauseOderNicht();
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Worker macht Feierabend!" << std::endl;
  }
  void warten() {
    std::lock_guard<std::mutex> lock(mtxPause);
    pause = true;
  }
  void weiter() {
    std::lock_guard<std::mutex> lock(mtxPause);  // siehe Text
    pause = false;
    cond.notify_one();  // siehe Text
  }
  void beenden() {
    beendet = true;
    cond.notify_one();  // ... falls im Zustand pausierend
  }
  bool istBeendet() const { return beendet; }

private:
  bool pause{false};
  bool beendet{false};
  std::mutex mtxPause;
  std::condition_variable cond;

  void pauseOderNicht() {
    std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);
    while (pause && !beendet) {
      std::cout << "Worker pausiert!" << std::endl;
      cond.wait(lock);
      std::cout << "Worker macht weiter!" << std::endl;
    }
  }
};
#endif
