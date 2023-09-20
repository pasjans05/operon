// operon14.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream plik("liczby14.txt");

vector<int> jeden;
vector<int> dwa;
vector<int> trzy;
vector<int> pierwsz;

bool fibb(unsigned int a)
{
	unsigned int j = 0;
	unsigned int k = 0;
	unsigned int n = 0;
	for (int i = 0; n < a; i++)
	{
		if (i == 0) n = 0;
		else if (i == 1) n = 1;
		else if (i > 1)
		{
			n = k + j;
		}
		k = j;
		j = n;
		if (a == n) return true;
	}
	return false;
}

bool pierw(unsigned int a)
{
	if (a == 1) return false;
	for (int i = 2; i <= sqrt(a); i++)
	{
		if (a % i == 0) return false;
	}
	return true;
}

int main()
{
	int liczba;
	int ileFib = 0;
	for (int i = 0; i < 4000; i++)
	{
		plik >> liczba;
		if (fibb(liczba))
		{
			ileFib++;
			if (pierw(liczba)) pierwsz.push_back(liczba);
		}
		else
		{
			if (fibb(liczba - 1) || fibb(liczba + 1)) jeden.push_back(liczba);
			if (fibb(liczba - 2) || fibb(liczba + 2)) dwa.push_back(liczba);
			if (fibb(liczba - 3) || fibb(liczba + 3)) trzy.push_back(liczba);
		}
	}
	cout << "14.1 " << ileFib << endl << "14.2 +- 1: " << endl;
	sort(jeden.begin(), jeden.end());
	for (int i = 0; i < jeden.size(); i++) cout << jeden[i] << endl;
	cout << endl << "+- 2: " << endl;
	sort(dwa.begin(), dwa.end());
	for (int i = 0; i < dwa.size(); i++) cout << dwa[i] << endl;
	cout << endl << "+- 3: " << endl;
	sort(trzy.begin(), trzy.end());
	for (int i = 0; i < trzy.size(); i++) cout << trzy[i] << endl;
	cout << endl << "14.3 " << endl;
	sort(pierwsz.begin(), pierwsz.end());
	for (int i = 0; i < pierwsz.size(); i++) cout << pierwsz[i] << endl;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
