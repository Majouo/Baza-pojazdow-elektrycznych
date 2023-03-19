#pragma once
template <typename T>
void wejscie(T& i)//sprawdzanie poprawnoœci wpisanych danych i ich przyjmowanie
{
	while (!(std::cin >> i)) { 
		std::cin.clear();
		std::cin.ignore(65536, '\n');
		std::cout << "Bledne dane, wprowadz je ponownie" << "\n";
	}
};
