/**
* \file aghComplex.h
* \author Artem Mensk & Kamil Chlebek
* \date 19.05.2014
* \version 1.0
* \brief Declaration of aghComplex
*/
// -------------------------------------------------------------------------

#ifndef AGHCOMPLEX_H_
#define AGHCOMPLEX_H_

// -------------------------------------------------------------------------

/**
* \class aghFib.h
* \author Artem Mensk & Kamil Chlebek
* \date 19.05.2014
* \brief Class that holds complex numbers
*/
class aghComplex {

    private:

        double im;
        double re;

    public:

        /// \brief Default constructor
        aghComplex();

        /// \brief Constructor that sets complex number
        ///
        /// \param re - real part
        /// \param im - imaginary part
        aghComplex(double re, double im);

        /// \brief Overloaded + operator
        ///
        /// \param c - complex number
        /// \return added components
        aghComplex operator+(aghComplex const & c);

        /// \brief Overloaded * operator
        ///
        /// \param c - complex number
        /// \return multiplied components
        aghComplex operator*(aghComplex const & c);

         /// \brief Overloaded == operator
        ///
        /// \param c - complex number
        /// \return True if complex numbers are the same
        bool operator==(aghComplex const & c);

        /// \brief Overloaded != operator
        ///
        /// \param c - complex number
        /// \return True if complex numbers are diffrent
        bool operator!=(aghComplex const & c);

};
// -------------------------------------------------------------------------

#endif /* AGHCOMPLEX_H_ */
