/**
* \file aghVector.h
* \author Artem Mensk & Kamil Chlebek
* \date 01.06.2014
* \version 1.0
* \brief Declaration of class aghVector
*/
// -------------------------------------------------------------------------

#ifndef AGHVECTOR_H_
#define AGHVECTOR_H_

// -------------------------------------------------------------------------

/**
* \class aghVector.h
* \author Artem Mensk & Kamil Chlebek
* \date 01.06.2014
* \brief Class represents vector
*/
template<class T>
class aghVector : public aghContainer<T> {

    private:

        /// \brief vector container
        T* vector;

        /// \brief number of elements
        unsigned int vectorSize;


        /// \brief Creates default vector
        void allocVector();

        /// \brief Reallocates memory
        ///
        /// \param size - size of new vector
        void reallocVector(int size);


        /// \brief Deallocate memory
        void deallocVector();

    public:

        /// \brief Default constructor
        aghVector();

        /// \brief Copy constructor
        ///
        /// \param pattern - pattern to copy
        aghVector(aghVector<T> const & pattern);


        /// \brief Copy constructor
        ///
        /// \param pattern - pattern to copy
        aghVector(aghContainer<T> const &pattern);

        /// \brief Destructor
        ~aghVector();

        /// \brief Inserts value to vector
        ///
        /// \param _index - where to add
        /// \param _value - value to add
        /// \return true if selected index is valid and exists
        bool insert(int _index, T const& _value);

        /// \brief Get value from vector
        ///
        /// \param _index - index to select
        /// \return value from vector at given key
        T& at(int _index) const;

        /// \brief Get size of vector
        ///
        /// \return int size of the vector
        int size(void)  const;

        /// \brief Remove selected key from vector
        ///
        /// \param _index - index to delete
        /// \return true if selected index is valid and exists
        bool remove(int _index);

        /// \brief Overloaded operator= from aghContainer
        ///
        /// \param pattern - pattern to copy
        /// \return aghVector
        using aghContainer<T>::operator=;

};

// -------------------------------------------------------------------------

#endif /* AGHVECTOR_H_ */
