/**
* \file SeriesTest.h
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \version 1.0
* \brief Declaration of SeriesTest.h which has definition of class SeriesTest
*/
// -------------------------------------------------------------------------

#ifndef SERIESTEST_H_
#define SERIESTEST_H_
// -------------------------------------------------------------------------

#include "Test.h"
#include "../ourGenerators/Generator.h"
#include <iostream>
// -------------------------------------------------------------------------

using namespace std;

/**
* \class SeriesTest
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \brief The definition of SeriesTest class that allows make series test
*/
class SeriesTest: public Test {
public:

  /// \brief The default constructor
  SeriesTest();

  /// \brief The class destructor
  virtual ~SeriesTest();

  /// \brief Function that implements pure virtual function from abstract class Test, that running test
  ///
  /// \return no values return
  void runTest();

  /// \brief Function that print all result in output stream
  ///
  /// \param out - a stream for output
  /// \return no values return
  void printResult(ostream& out);

};
// -------------------------------------------------------------------------

#endif /* SERIESTEST_H_ */
