#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <unistd.h>
#include "lacze_do_gnuplota.hh"
#include "Scena.hh"

using namespace std;





int main()
{
  vector<Wektor3D>sciezka; 
  double Kat,Dl;
  Wektor3D DlXY;
  char wyb;
  Wektor3D Wek1{POZYCJA_STARTOWA_1};
  Wektor3D Wek2{POZYCJA_STARTOWA_2};
  Scena Sc(Wek1, 0, Wek2, 90);

  Sc.InicjalizujScene();
  Sc.InicjalizujLacze();

  Sc.WyswietlAktPolozenie();
  cout << endl
       << "a - wybierz aktywnego drona\n";
  cout << "p - zadaj parametry przelotu\n";
  cout << "m - wyswietl menu\n";
  cout << "\nk - koniec dzialania programu\n";

  while (wyb != 'k')
  {
    cout<<"\nTwoj wybor: ";
    cin >> wyb;

    switch (wyb)
    {
    case 'a':
      Sc.WybierzDrona();
      break;

    case 'p':
      if (!Sc.LotDrona(Kat,Dl,DlXY,sciezka))
        cerr << "Blad, Lot nie zostal wykonany!\n";
      Sc.WyswietlAktPolozenie();
      cout << endl;
      Wektor3D::WyswietlIlosc();
      break;

    case 'm':
      Sc.WyswietlAktPolozenie();
      cout << endl
           << "a - wybierz aktywnego drona\n";
      cout << "p - zadaj parametry przelotu\n";
      cout << "m - wyswietl menu\n";
      cout << "\nk - koniec dzialania programu\n";
      break;

    case 'k':
      cout << "\nKoniec dzialania programu Dragonfly\n";
      break;

    default:
      cout << "\nBlad, podano niepoprawna opcje, sprobuj ponownie\n";
      break;
    }
  }
  return 0;
}