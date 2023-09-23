// operon_16.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream plik("liczby16.txt");

bool wzglP(int a, int b)
{
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0 && b % i == 0) return false;
    }
    return true;
}

int dz(int a)
{
    int licz = 0;
    for (int i = 1; i < a; i++) if (a % i == 0) licz++;
    return licz+1;
}

bool dosk(int a)
{
    int sum = 0;
    for (int i = 1; i < a; i++) if (a % i == 0) sum += i;
    if (sum == a) return true;
    return false;
}

int main()
{
    int liczba;
    vector<int> P;
    for (int i = 0; i < 500; i++)
    {
        plik >> liczba;
        P.push_back(liczba);
    }
    plik.close();
    plik.open("liczby16.txt");
    int liczWP = 0;
    vector<int> dziew;
    vector<int> dos;
    for (int i = 0; i < 500; i++)
    {
        plik >> liczba;
        for (int j = 0; j < 500; j++) if (wzglP(liczba, P[j])) liczWP++;
        if (dz(liczba) == 9) dziew.push_back(liczba);
        if (dosk(liczba)) dos.push_back(liczba);
    }
    cout << "16.1 " << liczWP/2 << endl;
    cout << "16.2 " << endl;
    for (int i = 0; i < dziew.size(); i++) cout << dziew[i] << endl;
    cout << "16.3 " << endl;
    for (int i = 0; i < dos.size(); i++) cout << dos[i] << endl;
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
