/* cppbuch/k32/arrayunique.cpp
   Beispiel zum Buch von U. Breymann: Der C++ Programmierer; 5. Auflage 2017
   Diese Software ist freie Software. Website: http://www.cppbuch.de/ 
*/
#include <iostream>
#include <memory>

void f() {
  // alternativ:
  std::unique_ptr<int[]> arr = std::make_unique<int[]>(10);
  // entspricht std::unique_ptr<int[]> arr(new int[10]); // int[]
  // statt int
  // Benutzung des Arrays
  for (int i = 0; i < 10; ++i) {
    arr[i] = i;
    std::cout << arr[i] << '\n';
  }
}  // kein Memory-Leak, Array wird korrekt gelöscht

void g() {
  // wie f(), nur ausgeschrieben
  std::unique_ptr<int[], std::default_delete<int[]>> arr =
      std::make_unique<int[]>(10);
  // Benutzung des Arrays
  for (int i = 0; i < 10; ++i) {
    arr[i] = i;
    std::cout << arr[i] << '\n';
  }
}  // kein Memory-Leak, Array wird korrekt gelöscht

int main() {
  f();
  g();
}
