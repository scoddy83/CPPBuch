// cppbuch/k4/uebung-9
// Kommandozeilenparameter anzeigen
#include <iostream>
#include <fstream>

int main (int argc, char* argv[]) {

    int i {1};
    do {
        std::ifstream quelle(argv[i], std::ios::binary);
        if(!quelle) {
            std::cerr << "Datei " << argv[i] << " nicht gefunden!" << '\n';
        } else {
            std::cout << argv[i] << "\n";
        }
    } while(argv[++i]);
}