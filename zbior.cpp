#include "zbior.h"
#include <new>
#include <random>
#include <cassert>

void Zbior::alokuj(int n)
{
	assert(n > 0);
	m_elementy = new(std::nothrow) double[n]{};
	m_liczbaElementow = n;

}

void Zbior::zwolnij()
{
	delete[] m_elementy;
}

Zbior::Zbior(size_t liczElem, double dGran, double gGran)
{
	alokuj(liczElem);
	std::uniform_real_distribution<double> zakres(dGran, gGran);
	std::random_device generator;
	for (int elem = 0; elem < liczElem; elem++)
		m_elementy[elem] = zakres(generator);
}

Zbior::Zbior(Zbior& inny)
{
	alokuj(inny.m_liczbaElementow);
	std::uniform_real_distribution<double> zakres(inny.m_dolnaGranica, inny.m_gornaGranica);
	std::random_device generator;
	for (int elem = 0; elem < inny.m_liczbaElementow; elem++)
		inny.m_elementy[elem] = zakres(generator);
}

void Zbior::operator=(const Zbior&& inny) noexcept
{

}
