/**
* \file aghSList.h
* \author Artem Mensk & Kamil Chlebek
* \date 07.06.2014
* \version 1.0
* \brief Declaration of class aghSList
*/
// -------------------------------------------------------------------------

#ifndef AGHSLIST_H_
#define AGHSLIST_H_

// -------------------------------------------------------------------------

/**
* \class aghSList.h
* \author Artem Mensk & Kamil Chlebek
* \date 07.06.2014
* \brief Class represents list
*/
template<class T> class aghSnode;
// -------------------------------------------------------------------------
template<class T>
class aghSlist : public aghContainer<T> {

   private:

        aghSnode<T> * front; /// \brief holds front of list

        /// \brief Put item at front
        ///
        /// \param value - value to add
        virtual void putFront(T const & _value);

        /// \brief Put item at end
        ///
        /// \param _value - value to add
        virtual void putBack(T const & _value);

        /// \brief Put item at index
        ///
        /// \param _index - where to add
        /// \param _value - value to add
        virtual void putAt(int _index, T const & _value);

        /// \brief Delete item from front
        virtual void popFront();

        /// \brief Delete item from back
        virtual void popBack();

        /// \brief Delete item from _index
        ///
        /// \param _index - what remove
        virtual void popAt(int _index);

        /// \brief Get node
        ///
        /// \param _index - position of node
        /// \return Pointer to node
        virtual aghSnode<T>* getNode(int _index) const;

   public:

        /// \brief Default constructor
        aghSlist();

        /// \brief Copy constructor
        ///
        /// \param pattern - pattern to copy
        aghSlist(aghSlist<T> const & pattern);


        /// \brief Copy constructor
        ///
        /// \param pattern - pattern to copy
        aghSlist(aghContainer<T> const &pattern);

        /// \brief Destructor
        virtual ~aghSlist();

        /// \brief Inserts value
        ///
        /// \param _index - where to add
        /// \param _value - value to add
        /// \return true if selected index is valid and exists
        bool insert(int _index, T const& _value);

        /// \brief Get value
        ///
        /// \param _index - index to select
        /// \return value at given key
        T& at(int _index) const;

        /// \brief Get size
        ///
        /// \return int size
        int size(void)  const;

        /// \brief Remove selected key
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

#endif /* AGHSLIST_H_ */
