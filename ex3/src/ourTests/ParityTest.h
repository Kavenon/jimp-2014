/**
* \file ParityTest.h
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \version 1.0
* \brief Declaration of ParityTest.h which has definition of class ParityTest
*/
// -------------------------------------------------------------------------

#ifndef PARITYTEST_H_
#define PARITYTEST_H_
// -------------------------------------------------------------------------

#include "Test.h"
#include "../ourGenerators/Generator.h"
#include <iostream>
// -------------------------------------------------------------------------

using namespace std;

/**
* \class Test
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \brief The definition of ParityTest class that allows make patity test
*/
class ParityTest: public Test {
public:

  /// \brief The default constructor
  ParityTest();

  /// \brief The class destructor
  virtual ~ParityTest();

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

#endif /* PARITYTEST_H_ */
