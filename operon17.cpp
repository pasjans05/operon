// operon17.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream plik("pesel.txt");

bool plec(unsigned long long a)
{
    int k;
    a /= 10;
    k = a % 10;
    if (k % 2 == 0) return true;
    return false;
}
bool kontrol(unsigned long long a)
{
    int k = a % 10; //cyfra kontrolna z peselu
    a /= 10; //pesel bez cyfry kontrolnej (10 cyfr)
    int s = 0; //suma, generowanie liczby kontrolnej na podstawie peselu
    for (int i = 0; i < 10; i++) //pętla dla 10 cyfrowego pesela
    {
        int b = a % 10; //aktualna cyfra z pesela licząc od końca
        int w; //waga, zdeterminowana przez poniższego switcha, do mnożenia *b, iloczyn dodajemy do s
        switch(i%4)
        {
            case 0:
                w = 3;
                break;
            case 1:
                w = 1;
                break;
            case 2:
                w = 9;
                break;
            case 3:
                w = 7;
                break;
        }
        s += (b * w) % 10; //dodajemy tylko cyfre jedności naszego mnożenia
        a /= 10;
    }
    s = 10 - (s % 10); //cyfre jedności uzyskanej w powyższym for sumy odejmujemy od 10
    if (s == k) return true; //jeżeli nasza obliczona cyfra kontrolna zgadza się z tą z pesela wszystko ok
    return false; //a jak nie to nie
}
int wiekf(unsigned long long a)
{
    a /= 10000000;
    int mies = a % 100; //miesieąc + kod dekady
    a /= 100;
    int rok = a; //ostatnie dwie cyfry roku; potem rok
    int k = mies / 10; //kod dekady - 1800-1899 -> +80; 2000-2099 -> +20; 2100-2199 -> +40; 2200-2299 -> +60
    if (k == 8 || k == 9) rok += 1800;
    else if (k == 0 || k == 1) rok += 1900;
    else if (k == 2 || k == 3) rok += 2000;
    else if (k == 4 || k == 5) rok += 2100;
    else if (k == 6 || k == 7) rok += 2200;
    return 2022 - rok;
}
int main()
{
    vector<int> wiek;
    for (int i = 0; i < 4; i++) wiek.push_back(0);
    unsigned long long pesel;
    int k = 0;
    int m = 0;
    int wiekz;
    for (int i = 0; i < 200; i++)
    {
        plik >> pesel;
        if (plec(pesel)) k++;
        else m++;
        if (kontrol(pesel) == false) cout << pesel << endl;
        wiekz = wiekf(pesel);
        if (wiekz <= 18) wiek[0]++;
        else if (wiekz <= 50) wiek[1]++;
        else if (wiekz <= 100) wiek[2]++;
        else wiek[3]++;
    }
    cout << "17.1 m: " << m << " k: " << k << endl;
    cout << "17.3" << endl << "do 18 lat:\t" << wiek[0] << "\nod 19 do 50:\t" << wiek[1] << "\nod 51 do 100:\t" << wiek[2] << "\npowyzej 100:\t" << wiek[3] << endl;
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
