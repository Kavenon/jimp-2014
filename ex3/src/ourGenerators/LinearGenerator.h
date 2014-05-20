/**
* \file LinearGenerator.h
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \version 1.0
* \brief Declaration of LinearGenerator.h which has definition of class LinearGenerator
*/
// -------------------------------------------------------------------------


#ifndef LINEARGENERATOR_H_
#define LINEARGENERATOR_H_
// -------------------------------------------------------------------------

#include "Generator.h"
#include <iostream>
#include <stdlib.h>
// -------------------------------------------------------------------------

/**
* \class LinearGenerator
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \brief The definition of LinearGenerator class that allows make generate ranrom number
*/
class LinearGenerator: public Generator {
public:

  /// \brief The default constructor
  LinearGenerator();

  /// \brief The class destructor
  virtual ~LinearGenerator();

  /// \brief Function that implements pure virtual function from abstract class Generator, that generate random number and print him on stream
  ///
  /// \return random integer number
  int toGenerate();

  /// \brief Function help that generate random number (use linear equation)
  ///
  /// \return random integer number
  int myRand();

};
// -------------------------------------------------------------------------

#endif /* LINEARGENERATOR_H_ */
