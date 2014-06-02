/**
* \file aghContainer.h
* \author Artem Mensk & Kamil Chlebek
* \date 01.06.2014
* \version 1.0
* \brief Declaration of class aghContainer
*/
// -------------------------------------------------------------------------

#ifndef AGHCONTAINER_H_
#define AGHCONTAINER_H_

// -------------------------------------------------------------------------

/**
* \class aghContainer.h
* \author Artem Mensk & Kamil Chlebek
* \date 01.06.2014
* \brief Abstract class container
*/
template<class T>
class aghContainer {

    public:
        /// \brief Default constructor
        aghContainer();

        /// \brief Destructor
        virtual ~aghContainer();

        /// \brief Appent element to container
        ///
        /// \param value - value to add
        void append(T const& value);

        /// \brief Virtual method insert element to container
        ///
        /// \param _index - where to add
        /// \param _value - value to add
        /// \return true if selected index is valid and exists
        virtual bool insert(int, T const&) = 0;

        /// \brief Replace element in container
        ///
        /// \param _index - where replace
        /// \param _value - value to replace
        /// \return true if selected index is valid and exists
        bool replace(int, T const&);

        /// \brief Virtual method get element from container
        ///
        /// \param _index - index to get
        /// \return value from container at given key
        virtual T& at(int) const = 0;


        /// \brief Virtual method get size of vector
        ///
        /// \return int size of the vector
        virtual int size(void) const  = 0;

        /// \brief Virtual method remove selected key from vector
        ///
        /// \param _index - index to delete
        /// \return true if selected index is valid and exists
        virtual bool remove(int) = 0;

        /// \brief Delete all items from container
        void clear(void);

        /// \brief Check if container is empty
        ///
        /// \return true if container is empty
        bool isEmpty(void) const;

        /// \brief Search for value in container
        ///
        /// \param _value - what to look for
        /// \param _from - where start searching
        /// \return -1 if not found, or position if found
        int indexOf(T const& _value, int _from = 0) const;

        /// \brief Search for value in container
        ///
        /// \param _value - what to look for
        /// \param _from - where start searching
        /// \return true if found
        bool contains(T const& _value, int _from = 0) const;


        /// \brief Overloaded operator=
        ///
        /// \param pattern - what copy
        /// \return ref to aghContainer
        aghContainer& operator=(aghContainer<T> const &pattern);

        /// \brief Overloaded operator==
        ///
        /// \param right - param to comparsion
        /// \return true if containers are the same
        bool operator==(aghContainer<T> const& right);


        /// \brief Overloaded operator!=
        ///
        /// \param right - param to comparsion
        /// \return true if containers are diffrent
        bool operator!=(aghContainer<T> const& right);

        /// \brief Get element from container
        ///
        /// \param n - index to get
        /// \return value from container at given key
        T& operator[](int n) const;

        /// \brief Adds all elements from right
        ///
        /// \param right - container with values that will be added
        /// \return *this ref
        aghContainer<T>& operator+=(aghContainer<T> const& right);

        /// \brief Adds element
        ///
        /// \param element - element to be added
        /// \return *this ref
        aghContainer<T>& operator+=(T const& element);

        /// \brief Adds element
        ///
        /// \param element - element to be added
        /// \return *this ref
        aghContainer<T>& operator<<(T const& element);

        /// \brief Adds all elements from right
        ///
        /// \param right - container with values that will be added
        /// \return *this ref
        aghContainer<T>& operator<<(aghContainer<T> const& right);

};
// -------------------------------------------------------------------------

/// \brief Overloaded operator <<, prints container to output
///
/// \param output - output stream
/// \param right - container to display
/// \return Output stream
template<class T>
std::ostream& operator<<(std::ostream&, aghContainer<T> const& right);

#endif /* AGHCONTAINER_H_ */
