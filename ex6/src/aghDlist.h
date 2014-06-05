/**
* \file aghDList.h
* \author Artem Mensk & Kamil Chlebek
* \date 07.06.2014
* \version 1.0
* \brief Declaration of class aghDList
*/
// -------------------------------------------------------------------------

#ifndef AGHDLIST_H_
#define AGHDLIST_H_

// -------------------------------------------------------------------------

/**
* \class aghDList.h
* \author Artem Mensk & Kamil Chlebek
* \date 07.06.2014
* \brief Class represents list
*/
// -------------------------------------------------------------------------
template<class T> class aghDnode;
// -------------------------------------------------------------------------
template<class T>
class aghDlist : public aghSlist<T> {

   private:

        aghDnode<T> * front; /// \brief holds front of list
        aghDnode<T> * rear;  /// \brief holds front of list

        /// \brief Put item at front
        ///
        /// \param value - value to add
        void putFront(T const & _value);

        /// \brief Put item at end
        ///
        /// \param _value - value to add
        void putBack(T const & _value);

        /// \brief Put item at index
        ///
        /// \param _index - where to add
        /// \param _value - value to add
        void putAt(int _index, T const & _value);

        /// \brief Delete item from front
        void popFront();

        /// \brief Delete item from back
        void popBack();

        /// \brief Delete item from _index
        ///
        /// \param _index - what remove
        void popAt(int _index);

        /// \brief Get node
        ///
        /// \param _index - position of node
        /// \return Pointer to node
        aghDnode<T>* getNode(int _index) const;

   public:

        /// \brief Default constructor
        aghDlist();

        /// \brief Copy constructor
        ///
        /// \param pattern - pattern to copy
        aghDlist(aghDlist<T> const & pattern);


        /// \brief Copy constructor
        ///
        /// \param pattern - pattern to copy
        aghDlist(aghContainer<T> const &pattern);

        /// \brief Destructor
        virtual ~aghDlist();

        /// \brief Get size
        ///
        /// \return int size
        int size(void)  const;

        /// \brief Overloaded operator= from aghContainer
        ///
        /// \param pattern - pattern to copy
        /// \return aghVector
        using aghContainer<T>::operator=;

};

#endif /* AGHDLIST_H_ */
