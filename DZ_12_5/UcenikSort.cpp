#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Ucenik
{
    char imePrezime[50];
    float prosjek;
};

bool cmp(Ucenik &a, Ucenik &b) 
{
    return a.prosjek > b.prosjek;
}

int main()
{
    struct Ucenik ucenici[100];
    int brUcenika = 0;
    fstream datotekica("podatci.bin", ios::binary | ios::in);
    while (datotekica.read((char*)&ucenici[brUcenika], sizeof(Ucenik)))
    {
        cout << ucenici[brUcenika].imePrezime << " " << ucenici[brUcenika].prosjek << endl;
        brUcenika++;
    }
    datotekica.close();
    int n;
    cin >> n;
    for (int i = 0; i < 0; i++)
    {
        cin.getline(ucenici[brUcenika + i].imePrezime, 50);
        cin >> ucenici[brUcenika + i].prosjek;
    }
    sort(ucenici,ucenici + brUcenika + n,cmp);
    datotekica.open("podatci.bin",ios::binary | ios::out | ios::trunc);
    datotekica.write((char*)ucenici,sizeof(Ucenik)*(brUcenika + n));
    datotekica.close();
    return 0;
}
//comit