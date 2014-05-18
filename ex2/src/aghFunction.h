/**
* \file aghFunction.h
* \author Artem Mensk & Kamil Chlebek
* \date 19.05.2014
* \version 1.0
* \brief Functions to sum and multiply strings by exercise rules
*/

// -------------------------------------------------------------------------

#ifndef AGHFUNCTION_H_
#define AGHFUNCTION_H_

// -------------------------------------------------------------------------


/// \brief Sum characters from given strings
/// \param  s1 - string
/// \param  s2 - string
/// \return String that contains chars that are in at least string
char * sumStrings(const char * s1, const char * s2);

/// \brief Multiply characters from given strings
/// \param  s1 - string
/// \param  s2 - string
/// \return String that contains chars that are in each string
char * multiplyStrings(const char * s1, const char * s2);


// -------------------------------------------------------------------------

#endif /* AGHFUNCTION_H_ */
