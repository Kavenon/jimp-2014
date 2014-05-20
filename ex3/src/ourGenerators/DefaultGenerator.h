/**
* \file DefaultGenerator.h
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \version 1.0
* \brief Declaration of DefaultGenerator.h which has definition of class DefaultGenerator
*/
// -------------------------------------------------------------------------


#ifndef DEFAULTGENERATOR_H_
#define DEFAULTGENERATOR_H_
// -------------------------------------------------------------------------

#include "Generator.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
// -------------------------------------------------------------------------

using namespace std;

/**
* \class DefaultGenerator
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \brief The definition of DefaultGenerator class that allows make generate ranrom number
*/
class DefaultGenerator: public Generator {
public:

  /// \brief The default constructor
  DefaultGenerator();

  /// \brief The class destructor
  virtual ~DefaultGenerator();

  /// \brief Function that implements pure virtual function from abstract class Generator, that generate random number and print him on stream
  ///
  /// \return random integer number
  int toGenerate();

};
// -------------------------------------------------------------------------

#endif /* DEFAULTGENERATOR_H_ */
