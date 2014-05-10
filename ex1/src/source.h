/**
* \file source.h
* \author Artem Mensk & Kamil Chlebek
* \date 09.05.2014
* \version 1.0
* \brief Deklaracja szablonu funkcji suma oraz funkcji specjalizowanej dla typu char**
*/
// -------------------------------------------------------------------------

#ifndef SOURCE_H_
#define SOURCE_H_

#include <iostream>
#include <string.h>

using namespace std;

// -------------------------------------------------------------------------


/// \brief funkcja szablonowa sumujaca skladniki
/// \param  T- skldniki sumy
/// \param  iter - dlugosc tablicy
/// \return funkcja zwraca dlugosc sumy oraz wyswietla wyniki w formie skladnik + skladnik = wynik
template<typename T>
double suma(T tab, int iter){

  double result = tab[0];

  cout << tab[0];
  for (int i=1 ; i < iter ; i++){
    cout <<  " + " << tab[i];
    result += tab[i];
  }
  cout << " = " << result << endl;

  return result;
}
// -------------------------------------------------------------------------

/// \brief funkcja specjalizowana dla typu char** sumujaca składniki
/// \param  T- skldniki sumy
/// \param  iter - dlugosc tablicy
/// \return funkcja zwraca dlugosc sumy oraz wyswietla wyniki w formie skladnik + skladnik = wynik(dlugosc)
template<>
double suma<char**>(char** tab, int iter);
// -------------------------------------------------------------------------

#endif /* SOURCE_H_ */
