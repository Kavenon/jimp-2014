/**
* \file Test.h
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \version 1.0
* \brief Declaration of Test.h which has definition of abstract class Test
*/
// -------------------------------------------------------------------------

#ifndef TEST_H_
#define TEST_H_
// -------------------------------------------------------------------------

#include "../ourGenerators/Generator.h"
#include <string>
#include <iostream>
#include <sstream>
// -------------------------------------------------------------------------

using namespace std;

/**
* \class Test
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \brief The definition of Test class that allows as interface for other test classes
*/
class Test {

  static const int DEFAULT_SAMPLING;        ///< Stores a default sampling number
  static const int DEFAULT_INTERVAL_NUMBER; ///< Stores a default interval number
  string result;                              ///< Stores a result of test
  Generator* generator;                       ///< Stores a present generator
  int sampling;                               ///< Stores a sampling number
  int intervalNumber;                         ///< Stores a interval number

public:

  /// \brief The default constructor
  Test();

  /// \brief The class destructor
  virtual ~Test();

  /// \brief Pure virtual function that running test
  ///
  /// \return no values return
  virtual void runTest() = 0;

  /// \brief Pure virtual function that print all result in output stream
  ///
  /// \param out - a stream for output
  /// \return no values return
  virtual void printResult(ostream& out) = 0;

  /// \brief Setter for setting a current generator
  ///
  /// \param _generator - a current generator
  /// \return no values return
  void setGenerator(Generator* _generator);

  /// \brief Setter for setting test result
  ///
  /// \param _result - test result
  /// \return no values return
  void setResultText(string _result);

  /// \brief Setter for setting sampling variables for test
  ///
  /// \param _sampling - sampling variables for test
  /// \return no values return
  void setSampling(int _sampling);

  /// \brief Default setter for setting sampling variables for test, set DELAULT_SAMPLING
  ///
  /// \return no values return
  void setSampling();

  /// \brief Setter for setting interval number for test
  ///
  /// \param _intervalNumber - interval number for test
  /// \return no values return
  void setIntervalNumber(int _intervalNumber);

  /// \brief Default setter for setting interval number for test, set DEFAULT_INTERVAL_NUMBER
  ///
  /// \return no values return
  void setIntervalNumber();

  /// \brief Function add string to string result
  ///
  /// \param _result - string
  /// \return no values return
  void addInResultText(string _result);

  /// \brief Getter for getting current generator
  ///
  /// \return current generator
  Generator* getGenerator();

  /// \brief Getter for getting string with all test result
  ///
  /// \return string with all test result
  string getResult();

  /// \brief Getter for getting sampling variables for test
  ///
  /// \return sampling variables for test
  int getSampling();

  /// \brief Getter for getting interval number for test
  ///
  /// \return interval number for test
  int getIntervalNumber();

};
// -------------------------------------------------------------------------

#endif /* TEST_H_ */
