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
template<class T>
class aghSlist : public aghContainer<T> {
	
   private:
      
	aghSNode* front;

	bool putFront(T& const _value);
	bool putBack(T& const _value);
	bool putAt(int _index, T& const _value);

   public:

	/// \brief Default constructor
        aghSNode();

        /// \brief Copy constructor
        ///
        /// \param pattern - pattern to copy
        aghSNode(aghSNode<T> const & pattern);


        /// \brief Copy constructor
        ///
        /// \param pattern - pattern to copy
        aghSNode(aghContainer<T> const &pattern);

        /// \brief Destructor
        ~aghSNode();

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

#endif
