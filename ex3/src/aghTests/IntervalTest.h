/**
* \file IntervalTest.h
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \version 1.0
* \brief Declaration of IntervalTest.h which has definition of class IntervalTest
*/
// -------------------------------------------------------------------------

#ifndef INTERVALTEST_H_
#define INTERVALTEST_H_

// -------------------------------------------------------------------------

using namespace std;

/**
* \class IntervalTest
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \brief The definition of IntervalTest class that allows make interval test
*/
class IntervalTest: public Test {
public:

  /// \brief The default constructor
  IntervalTest();

  /// \brief The class destructor
  virtual ~IntervalTest();

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

#endif /* INTERVALTEST_H_ */
