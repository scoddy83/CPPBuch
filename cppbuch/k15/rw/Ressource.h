/* cppbuch/k15/rw/Ressource.h
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#ifndef RESSOURCE_H
#define RESSOURCE_H
#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>

inline std::mutex ausgabeMutex;

class Ressource {
public:
  std::string read(const std::string& id) {
    std::shared_lock<std::shared_mutex> lock(rwMutex);  // Lock für geteilten Zugriff
    ++nreader;
    println(id + "  liest " + inhalt + rwprotokoll());
    --nreader;
    return inhalt;
  }

  void write(const std::string& neu, const std::string& id) {
    std::lock_guard<std::shared_mutex> lock(rwMutex);  // Lock für exklusiven Zugriff
    ++nwriter;
    println(id + " schreibt " + neu + rwprotokoll());
    --nwriter;
    inhalt = neu;
  }

  static void println(const std::string& was) {
    std::lock_guard<std::mutex> lock(ausgabeMutex);
    std::cout << was << std::endl;
  }

private:
  std::string rwprotokoll() {
    std::string msg(" Anzahl Aktiver:  R=");
    msg +=
      std::to_string(nreader)  // Umwandlung der Zahl in einen \tt{string}
      + "  W=" + std::to_string(nwriter);
    return msg;
  }
  std::string inhalt{"nichts"};
  std::shared_mutex rwMutex;

  int nreader = 0;
  int nwriter = 0;
};

#endif
