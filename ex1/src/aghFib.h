/**
* \file aghFib.h
* \author Artem Mensk & Kamil Chlebek
* \date 09.05.2014
* \version 1.0
* \brief Deklaracja klasy aghFib
*/
// -------------------------------------------------------------------------

#ifndef AGHFIB_H_
#define AGHFIB_H_

// -------------------------------------------------------------------------

/**
* \class aghFib.h
* \author Artem Mensk & Kamil Chlebek
* \date 09.05.2014
* \brief Klasa oblicza wartosc wskazanego wyrazu ciagu fibonacciego
*/
class aghFib {

/// \brief oblicza wskazany wyraz ciagu
///
/// \param index - indeks wyrazu ciagu
/// \return wartosc wskazanego wyrazu ciagu
int fibonacci(int index);

public:

  /// \brief Konstruktor klasy
  aghFib();

  /// \brief Destruktor klasy
  virtual ~aghFib();

  /// \brief przeladowanie operatora p[]
  ///
  /// \param nIndex - indeks wyrazu ciagu
  /// \return wartosc wskazanego wyrazu ciagu
  int operator[] (const int nIndex);

};
// -------------------------------------------------------------------------

#endif /* AGHFIB_H_ */
