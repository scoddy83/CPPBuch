//CPPBuch/K2/Übung 2.1
#include <iostream>
using namespace std;

double power(double, int);

int main() {
  double x {0};
  int y {0};
  cout << "Bite geben sie eine Zahl x ein: ";
  cin >> x;
  cout << "Bitte geben sie eine Potenz y ein: ";
  cin >> y;

  cout << "Das Resultat von x^y ergibt: " << power(x, y);

  return 0;
}


double power(double x, int y) {
 double output = x;

 if(y == 0) {
   return 1;
 } else if (y == 1) {
   return x;
 }
 else if (y < 0) {
   while(y<-1) {
     output = output * x;
     y++;
   }
   return 1 / output;
 } else {
   while(y>1) {
     output = output * x;
     y--;
   }
   return output;
 }
}
