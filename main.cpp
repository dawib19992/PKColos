#include "zbior.h"
#include <iostream>
#include <cassert>
#include <algorithm>

void test1() {
    Zbior oryginal(5, 1.0, 10.0);
    Zbior kopia(oryginal);

    assert(oryginal.elementy() != nullptr);
    assert(kopia.elementy() != nullptr);
    assert(oryginal.elementy() != kopia.elementy()); // Rozdzielone zasoby
    std::cout << "Test1 (konstruktor kopiujacy): OK\n";
}

void test2() {
    Zbior dawca(5, 1.0, 10.0);
    Zbior biorca = std::move(dawca);

    assert(dawca.elementy() == nullptr); // Dawca powinien być wyzerowany
    assert(biorca.elementy() != nullptr); // Biorca przejął zasób
    std::cout << "Test2 (operator przenoszacy): OK\n";
}

void test3() {
    KompozytZbiorow kompozyt;
    kompozyt.dodajZbior(Zbior(5, 1.0, 10.0));
  //  kompozyt.dodajZbior(Zbior(0, 0.0, 0.0)); // Niepoprawny
    kompozyt.dodajZbior(Zbior(10, -5.0, 5.0));

    CzyZasobPoprawny predykat;
    size_t liczbaPoprawnych = std::count_if(kompozyt.begin(), kompozyt.end(), predykat);

    assert(liczbaPoprawnych == 2); // Tylko dwa zbiory są poprawne
    std::cout << "Test3 (kompozyt i funktor): OK\n";
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}
