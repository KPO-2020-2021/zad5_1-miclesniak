#ifndef SCENA_HH
#define SCENA_HH

#include "dron.hh"
/**
 * @file Scena.hh
 * @brief Plik zawierający definicję klasy Scena
 * 
 */

/**
 * @brief Klasa modeluje pojęcie Sceny
 * 
 */
class Scena
{
    /**
     * @brief Dwuwymiarowa tablica zawierająca obiekty typu Dron
     * 
     */
    Dron _TabDronow[2];
    /**
     * @brief Obiekt typu LaczeDoGNUPlota
     * 
     */
    PzG::LaczeDoGNUPlota _Lacze;
    /**
     * @brief Zmienna statyczna służąca do wybrania aktywnego drona
     * 
     */
    static int _AktDron;


    /**
     * @brief Metoda pozwalająca na użycie aktywnego drona
     * 
     * @return Dron& - Aktywny dron
     */
    Dron &UzyjAktywnegoDrona()
    {
        return _TabDronow[_AktDron];
    }

    /**
     * @brief Metoda wyświetlająca aktualne położenie dronóœ
     * 
     */
    void WyswietlPolozenie();

    
public:
    /**
     * @brief Konstruktor Sceny
     * 
     * @param Polozenie1 - Położenie pierwszego drona
     * @param KatObrotu1 - kąt obrotu pierwszego drona
     * @param Polozenie2 - Położenie drugiego drona
     * @param KatObrotu2 - kąt obrotu drugiego drona
     */
    Scena(const Wektor3D &Polozenie1,
          const double KatObrotu1,
          const Wektor3D &Polozenie2,
          const double KatObrotu2);

    /**
     * @brief Metoda pozwalająca na wybranie aktywnego drona
     * 
     */
    void WybierzDrona();

    /**
     * @brief Metoda pozwalająca na wyświetlenie położenia aktywnego drona
     * 
     */
    void WyswietlAktPolozenie();

    /**
     * @brief Metoda inicjalizująca scenę
     * 
     * Metoda ma na celu zapisanie współrzędnych początkowych dronów do układu globalnego
     * 
     * @return true - Jeżeli operacja się powiedzie
     * @return false - Jeżeli nastąpi problem z otwarciem plików
     */
    bool InicjalizujScene();

    /**
     * @brief Metoda inicjalizująca łącze
     * 
     * Metoda ma na celu skonfigurowanie łącza oraz narysowanie początkowej pozycji dronóœ
     * 
     */
    void InicjalizujLacze();

    /**
     * @brief Metoda pozwalająca na lot drona
     * 
     * Metoda ma na celu wykonanie operacji związanych z lotem drona, tj. pobranie
     * odpowiednich parametrów, narysowanie ścieżki, a następnie lot pionowy,
     * obrót, lot poziomy, oraz opadanie.
     * @param Kat - Kat obrotu drona 
     * @param Dl - Dlugosc lotu drona
     * @param DlXY - Wektor przesuniecia drona
     * @param sciezka - sciezka lotu drona 
     * @return true - Jeżeli operacja się powiedzie
     * @return false - Jeżeli nastąpi problem z otwarciem plików
     */
    bool LotDrona(double &Kat,double &Dl,Wektor3D &DlXY, vector<Wektor3D>&sciezka);
};


#endif