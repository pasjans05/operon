// operon13.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream plik("liczby13.txt");

bool binar(int i)
{
	int zero = 0;
	int jeden = 0;
	while (i > 0)
	{
		if (i % 2 == 1) jeden++;
		else zero++;
		i /= 2;
	}
	if (zero == jeden) return true;
	else return false;
}

int systeM(int i, int n) //i - podstawa; n - liczba
{
	int ile = 0;
	while (n > 0)
	{
		if (n % i == i - 1) ile++;
		n /= i;
	}
	return ile;
}

bool symetr(int n)
{
	bool spr = true;
	string heks;
	while (n > 0)
	{
		heks += char(n % 16 + 48);
		n /= 16;
	}
	//cout << heks << endl;
	for (int i = 0; i < heks.length(); i++)
	{
		if (heks[i] != heks[heks.length() - (i + 1)]) spr = false;
	}
	return spr;
}

int main()
{
	unsigned int n; //liczba
	int ile = 0; //ile liczb spełniających warunki zad 13 1
	vector<int> piec;
	vector<int> siedem;
	vector<int> trzynasce;
	vector<int> symetrycz;
	int pMax = 0;
	int sMax = 0;
	int tMax = 0;
	int p, s, t;
	for (int i = 0; i < 2000; i++)
	{
		plik >> n;
		if (binar(n)) ile++;
		p = systeM(5, n);
		s = systeM(7, n);
		t = systeM(13, n);
		if (p == pMax) piec.push_back(n);
		if (p > pMax)
		{
			piec.clear();
			piec.push_back(n);
			pMax = p;
		}
		if (s == sMax) siedem.push_back(n);
		if (s > sMax)
		{
			siedem.clear();
			siedem.push_back(n);
			sMax = s;
		}
		if (t == tMax) trzynasce.push_back(n);
		if (t > tMax)
		{
			trzynasce.clear();
			trzynasce.push_back(n);
			tMax = t;
		}
		if (symetr(n)) symetrycz.push_back(n);
	}
	plik.close();
	cout << "13.1 " << ile << endl;
	cout << "13.2 " << endl;
	for (int i = 0; i < piec.size(); i++)
	{
		cout << piec[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < siedem.size(); i++)
	{
		cout << siedem[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < trzynasce.size(); i++)
	{
		cout << trzynasce[i] << endl;
	}
	cout << endl;
	cout << "13.3 " << endl;
	for (int i = 0; i < symetrycz.size(); i++)
	{
		cout << symetrycz[i] << endl;
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
