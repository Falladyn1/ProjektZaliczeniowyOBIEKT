#include "System.h"

int main() {
    try {
        System aplikacja;
        aplikacja.uruchom();
    }
    catch (const std::exception& e) {
        std::cerr << "KRYTYCZNY BLAD SYSTEMU: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}