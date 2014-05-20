/**
* \file Generator.h
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \version 1.0
* \brief Declaration of Generator.h which has definition of abstract class Generator
*/
// -------------------------------------------------------------------------

#ifndef GENERATOR_H_
#define GENERATOR_H_
// -------------------------------------------------------------------------

#include <iostream>
#include <limits>
// -------------------------------------------------------------------------

using namespace std;

/**
* \class Generator
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \brief The definition of Generator class that allows as interface for other generators classes
*/
class Generator {

  static const int DEFAULT_MIN_VALUE;   ///< Stores a default minimum random value = 1
  static const int DEFAULT_VARIABLE_A;  ///< Stores a default algorithm variable a = 16807
  static const int DEFAULT_VARIABLE_B;  ///< Stores a default algorithm variable b = 21
  static const int DEFAULT_VARIABLE_C;  ///< Stores a default algorithm variable c = 888

  int seed;                               ///< Stores a algorithm seed (by default value from time(NULL); )
  int minValue;                           ///< Stores a minimum random value (by default 1)
  int maxValue;                           ///< Stores a maximum random value (by default maximum integer from system)
  int variableA;                          ///< Stores a algorithm variable a
  int variableB;                          ///< Stores a algorithm variable b
  int variableC;                          ///< Stores a algorithm variable c
  std::string generatorName;               ///< Stores a generator's name

public:

  /// \brief The default constructor
  Generator(){};

  /// \brief The class destructor
  virtual ~Generator(){};

  /// \brief Pure virtual function that generate and return value
  ///
  /// \return random integer number
  virtual int toGenerate() = 0;
  
  /// \brief Function that print result of generation on any stream
  ///
  /// \param out - a stream for output
  /// \return no values return
  void print(std::ostream& out);

  /// \brief Setter for setting a default algorithm seed
  ///
  /// \return no values return
  void setSeed();

  /// \brief Setter for setting the default algorithm minimum and maximum values
  ///
  /// \return no values return
  void setRange();

  /// \brief Setter for setting the default algorithm variables (a, b, c values)
  ///
  /// \return no values return
  void setVariables();

  /// \brief Setter for setting a algorithm seed
  ///
  /// \param _seed - algorithm seed
  /// \return no values return
  void setSeed(int _seed);

  /// \brief Setter for setting a range values for generate
  ///
  /// \param _minValue - minimum value for generate
  /// \param _maxValue - maximum value for generate
  /// \return no values return
  void setRange(int _minValue, int _maxValue);

  /// \brief Setter for setting the algorithm variables (a, b, c values)
  ///
  /// \param _variableA - algorithm variable a
  /// \param _variableB - algorithm variable b
  /// \param _variableC - algorithm variable c
  /// \return no values return
  void setVariables(int _variableA, int _variableB, int _variableC);

  /// \brief Setter for setting a generator name
  ///
  /// \param _generatorName - generator name
  /// \return no values return
  void setGeneratorName(std::string _generatorName);

  /// \brief Getter for getting seed from algorithm
  ///
  /// \return seed from algorithm
  int getSeed();

  /// \brief Getter for getting minimum value for generate
  ///
  /// \return minimum value for generate
  int getMinValue();

  /// \brief Getter for getting maximum value for generate
  ///
  /// \return maximum value for generate
  int getMaxValue();

  /// \brief Getter for getting algorithm variable a
  ///
  /// \return algorithm variable a
  int getVariableA();

  /// \brief Getter for getting algorithm variable b
  ///
  /// \return algorithm variable b
  int getVariableB();

  /// \brief Getter for getting algorithm variable c
  ///
  /// \return algorithm variable c
  int getVariableC();

  /// \brief Getter for getting generator name
  ///
  /// \return generator name
  std::string& getGeneratorName();

};
// -------------------------------------------------------------------------

#endif /* GENERATOR_H_ */
