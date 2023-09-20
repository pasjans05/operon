// operon15.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

ifstream plik("liczby15.txt");

bool pierwsza(int n)
{
	if (n == 1) return false;
	else
	{
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0) return false;
		}
	}
	return true;
}

int sumCyfr(int n, int i)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % i;
		n /= i;
	}
	return sum;
}

int main()
{
	int n; //liczba
	int liczP = 0;
	vector<int> Bsp;
	vector<int> P;
	for (int i = 0; i < 2000; i++)
	{
		plik >> n;
		if (pierwsza(n))
		{
			liczP++;
			P.push_back(n);
			if (pierwsza(sumCyfr(n, 2)) && pierwsza(sumCyfr(n, 10))) Bsp.push_back(n);
		}
	}
	cout << endl << "15.1 " << liczP << endl;
	cout << "15.2 " << endl;
	sort(Bsp.begin(), Bsp.end());
	for (int i = 0; i < Bsp.size(); i++)
	{
		cout << Bsp[i] << endl;
	}
	cout << "15.3 " << endl;
	for (int i = 0; i < P.size(); i++)
	{
		for (int j = 0; j < P.size(); j++) if (P[i] - P[j] == 2) cout << P[i] << "\t" << P[j] << endl;
	}
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
