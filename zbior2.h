#pragma once

#include <vector>

class Zbior {
    size_t m_liczbaElementow = 0;
    double* m_elementy = nullptr;
    double m_dolnaGranica = 0;
    double m_gornaGranica = 0;

    void alokuj(size_t n);
    void zwolnij();

public:
    Zbior(size_t liczElem, double dGran, double gGran);
    Zbior(const Zbior& inny);             // Konstruktor kopiujący
    Zbior(Zbior&& inny) noexcept;        // Konstruktor przenoszący
    Zbior& operator=(const Zbior& inny); // Operator przypisania kopiującego
    Zbior& operator=(Zbior&& inny) noexcept; // Operator przypisania przenoszącego
    ~Zbior();

    size_t liczbaElementow() const;
    const double* elementy() const;
};

class KompozytZbiorow {
    std::vector<Zbior> zbiory;

public:
    void dodajZbior(Zbior zbior);
    void usunZbior(size_t indeks);
    size_t liczbaZbiorow() const;
    const Zbior& pobierzZbior(size_t indeks) const;

    auto begin() const { return zbiory.begin(); }
    auto end() const { return zbiory.end(); }
};

class CzyZasobPoprawny {
public:
    bool operator()(const Zbior& zbior) const;
};

