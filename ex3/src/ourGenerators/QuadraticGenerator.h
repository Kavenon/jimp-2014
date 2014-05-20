/**
* \file QuadraticGenerator.h
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \version 1.0
* \brief Declaration of QuadraticGenerator.h which has definition of class QuadraticGenerator
*/
// -------------------------------------------------------------------------

#ifndef QUADRATICGENERATOR_H_
#define QUADRATICGENERATOR_H_
// -------------------------------------------------------------------------

#include "Generator.h"
#include <math.h>
// -------------------------------------------------------------------------

/**
* \class QuadraticGenerator
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \brief The definition of QuadraticGenerator class that allows make generate ranrom number
*/
class QuadraticGenerator: public Generator {
public:

  /// \brief The default constructor
  QuadraticGenerator();

  /// \brief The class destructor
  virtual ~QuadraticGenerator();

  /// \brief Function that implements pure virtual function from abstract class Generator, that generate random number and print him on stream
  ///
  /// \return random integer number
  int toGenerate();

  /// \brief Function help that generate random number (use quadratic equation)
  ///
  /// \return random integer number
  int myRand();

};
// -------------------------------------------------------------------------

#endif /* QUADRATICGENERATOR_H_ */
