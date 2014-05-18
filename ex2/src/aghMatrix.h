/**
* \file aghMatrix.h
* \author Artem Mensk & Kamil Chlebek
* \date 19.05.2014
* \version 1.0
* \brief Declaration of class aghMatrix
*/
// -------------------------------------------------------------------------

#ifndef AGHMATRIX_H_
#define AGHMATRIX_H_

// -------------------------------------------------------------------------

/**
* \class aghMatrix.h
* \author Artem Mensk & Kamil Chlebek
* \date 19.05.2014
* \brief Class represents matrix
*/
template <class T>
class aghMatrix {

    private:

        int rows,cols;
        T** container;

    public:

        /// \brief Default constructor
        aghMatrix();

        /// \brief Parametric constructor
        ///
        /// \param rows - number of rows
        /// \param cols - number of cols
        aghMatrix(int rows, int cols);

        /// \brief Copy constructor
        ///
        /// \param m - matrix
        aghMatrix(aghMatrix<T> const & m);

        /// \brief Default destructor
        virtual ~aghMatrix();

        /// \brief Allocates memory for items container
        ///
        /// \param rows - number of rows
        /// \param cols - number of cols
        void createContainer(int rows, int cols);

        /// \brief Deallocates memory for container
        void deleteContainer();

        /// \brief Sets matrix item
        ///
        /// \param rows - number of rows
        /// \param cols - number of cols
        /// \param value - parametric value to be set
        void setItem(int r, int c, T value);

        /// \brief Sets matrix item
        ///
        /// \param values - parametric array of values to be set
        void setItems(T * values);

        /// \brief Sets matrix item
        ///
        /// \param r - number of rows
        /// \param c - number of cols
        /// \param ... - values to be set
        void setItems(int r, int c, ...);

        /// \brief Overloaded = operator
        ///
        /// \param m - matrix
        /// \return reference aghMatrix
        aghMatrix& operator=(aghMatrix<T> const &m);

        /// \brief Overloaded + operator, adds matrix
        ///
        /// \param m - matrix
        /// \return aghMatrix
        aghMatrix operator+(aghMatrix<T> const &m);

        /// \brief Overloaded * operator, multilpies matrix
        ///
        /// \param m - matrix
        /// \return aghMatrix
        aghMatrix operator*(aghMatrix<T> const &m);

        /// \brief Overloaded () operator
        ///
        /// \param r - row
        /// \param c - col
        /// \return content from container on (row,col)
        T operator()(int r, int c) ;

        /// \brief Overloaded == operator
        ///
        /// \param m - matrix
        /// \return True if matrix are the same
        bool operator==(aghMatrix<T> & m);

        /// \brief Overloaded != operator
        ///
        /// \param m - matrix
        /// \return True if matrix are diffrent
        bool operator!=(aghMatrix<T> & m);

};

// -------------------------------------------------------------------------

/// \brief Specialized function setItems for <char>
///
/// \param r - row
/// \param c - col
/// \param ... - values
template<>
void aghMatrix<char>::setItems(int r, int c, ...);

/// \brief Specialized operator+ for <char>
///
/// \param m - matrix
/// \return added matrix
template<>
aghMatrix<char> aghMatrix<char>::operator+(aghMatrix<char> const &m);

/// \brief Specialized operator*for <char>
///
/// \param m - matrix
/// \return multipied matrix
template<>
aghMatrix<char> aghMatrix<char>::operator*(aghMatrix<char> const &m);

// -------------------------------------------------------------------------

/// \brief Specialized operator= for <char*>
///
/// \param m - matrix
/// \return aghMatrix
template<>
aghMatrix<char*> & aghMatrix<char*>::operator=(aghMatrix<char*> const & m);

/// \brief Specialized operator+ for <char*>
///
/// \param m - matrix
/// \return added matrix
template<>
aghMatrix<char*> aghMatrix<char*>::operator+(aghMatrix<char*> const &m);

/// \brief Specialized operator*for <char*>
///
/// \param m - matrix
/// \return multipied matrix
template<>
aghMatrix<char*> aghMatrix<char*>::operator*(aghMatrix<char*> const &m);

/// \brief Specialized function setItems for <char*>
///
/// \param r - row
/// \param c - col
/// \param value - value to be set
template<>
void aghMatrix<char*>::setItem(int r, int c, char* value);

/// \brief Specialized function setItems for <char*>
///
/// \param values - array of strings to be set
template<>
void aghMatrix<char*>::setItems(char ** values);

/// \brief Specialized function setItems for <char*>
///
/// \param r - row
/// \param c - col
/// \param ... - values
template<>
void aghMatrix<char*>::setItems(int r, int c, ...);

/// \brief Specialized operator == for <char*>
///
/// \param m - matrix
/// \return True if matrix are the same
template<>
bool aghMatrix<char*>::operator==(aghMatrix<char*>& m);

/// \brief Specialized operator != for <char*>
///
/// \param m - matrix
/// \return True if matrix are diffrent
template<>
bool aghMatrix<char*>::operator!=(aghMatrix<char*>& m);

/// \brief Specialized destructor for <char*>
template<>
aghMatrix<char*>::~aghMatrix();

// -------------------------------------------------------------------------

#endif /* AGHMATRIX_H_ */

