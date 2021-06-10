#include "Scena.hh"

int Scena::_AktDron = 0;

Scena::Scena(const Wektor3D &Polozenie1,
             const double KatObrotu1,
             const Wektor3D &Polozenie2,
             const double KatObrotu2)
    : _TabDronow{{Dron(Polozenie1, KatObrotu1)},
                 {Dron(Polozenie2, KatObrotu2)}}{}

void Scena::WyswietlPolozenie()
{
    for (int i = 0; i < 2; ++i)
    {
        _TabDronow[i].WyswietlPol();
        if (_AktDron == i)
            _TabDronow[i].WyswietlAkt();
        std::cout << std::endl;
    }
}

void Scena::WyswietlAktPolozenie()
{
    std::cout << "Polozenie Drona aktywnego (x,y): ";
    _TabDronow[_AktDron].WyswietlWsp();
    std::cout << std::endl;
}


bool Scena::InicjalizujScene()
{
    for (int i = 0; i < 2; ++i)
        if (!_TabDronow[i].Oblicz_i_Zapisz_WspGlbDrona())
            return false;
    return true;
}

void Scena::InicjalizujLacze()
{
    _Lacze.ZmienTrybRys(PzG::TR_3D);
    _Lacze.Inicjalizuj(); // Tutaj startuje gnuplot.
    _Lacze.UstawZakresX(0, 200);
    _Lacze.UstawZakresY(0, 200);
    _Lacze.UstawZakresZ(0, 120);
    _Lacze.UstawRotacjeXZ(64, 65); // Tutaj ustawiany jest widok
    _Lacze.DodajNazwePliku("PlikFinalny_Dron1_Korpus.dat");
    _Lacze.DodajNazwePliku("PlikFinalny_Dron1_Rotor1.dat");
    _Lacze.DodajNazwePliku("PlikFinalny_Dron1_Rotor2.dat");
    _Lacze.DodajNazwePliku("PlikFinalny_Dron1_Rotor3.dat");
    _Lacze.DodajNazwePliku("PlikFinalny_Dron1_Rotor4.dat");
    _Lacze.DodajNazwePliku("PlikFinalny_Dron2_Korpus.dat");
    _Lacze.DodajNazwePliku("PlikFinalny_Dron2_Rotor1.dat");
    _Lacze.DodajNazwePliku("PlikFinalny_Dron2_Rotor2.dat");
    _Lacze.DodajNazwePliku("PlikFinalny_Dron2_Rotor3.dat");
    _Lacze.DodajNazwePliku("PlikFinalny_Dron2_Rotor4.dat");
    _Lacze.DodajNazwePliku(PLIK_PLASZCZYZNY);
    _Lacze.Rysuj();
}

bool Scena::LotDrona(double &Kat,double &Dl,Wektor3D &DlXY, vector<Wektor3D>&sciezka)
{
    if (!UzyjAktywnegoDrona().NarysujSciezke(Kat,Dl,DlXY, sciezka,_Lacze))
        return false;
    if (!UzyjAktywnegoDrona().WykonajPionowyLot(LOT_PIONOWY, _Lacze))
        return false;
    if (!UzyjAktywnegoDrona().WykonajObrot(Kat,_Lacze))
        return false;
    if (!UzyjAktywnegoDrona().WykonajPoziomyLot(Dl,DlXY, _Lacze))
        return false;
    if (!UzyjAktywnegoDrona().WykonajPionowyLot(-LOT_PIONOWY, _Lacze))
        return false;
    std::cout << "\nDron wyladowal ...\n";
    UzyjAktywnegoDrona().UsunSciezke(sciezka, _Lacze);
    return true;
}

void Scena::WybierzDrona()
{
    int idx;
    std::cout << "Wybor aktywnego drona\n\n";
    WyswietlPolozenie();
    std::cout << "\nWprowadz numer aktywnego drona> ";
    std::cin >> idx;
    while (!(idx == 1 || idx == 2) || cin.fail())
    {
        std::cerr << "\nWprowadzono niepoprawny numer!\n";
        std::cout << "\nWprowadz numer aktywnego drona> ";
        cin.clear();
        cin.ignore(9999, '\n');
        std::cin >> idx;
    }
    _AktDron = idx - 1;
    WyswietlAktPolozenie();
    Wektor3D::WyswietlIlosc();
}
