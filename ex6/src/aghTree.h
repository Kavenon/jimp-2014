/**
* \file aghTree.h
* \author Artem Mensk & Kamil Chlebek
* \date 13.06.2014
* \version 1.0
* \brief Declaration of class aghTree
*/
// -------------------------------------------------------------------------

#ifndef AGHTREE_H_
#define AGHTREE_H_

// -------------------------------------------------------------------------

/**
* \class aghTree.h
* \author Artem Mensk & Kamil Chlebek
* \date 13.06.2014
* \brief Class represents tree
*/
template<class T> class aghTnode;
// -------------------------------------------------------------------------
template<class T>
class aghTree : public aghContainer<T> {

   private:

        aghTnode<T> * root; /// \brief holds root of tree
        int treeCount; /// \brief tree size

        /// \brief Get node
        ///
        /// \param _index - position of node
        /// \return Pointer to node
        virtual aghTnode<T>* getNode(int _index) const;

        /// \brief Do inorderWalk
        ///
        /// \param _index - position of node
        /// \param node - current node
        /// \return Pointer to node
        aghTnode<T>* inOrderWalk(aghTnode<T>* node, int & _index) const;

        /// \brief Find successor
        ///
        /// \param node - current node
        /// \return Pointer to node
        aghTnode<T>* findSuccessor(aghTnode<T> * node) const;

        /// \brief Find min value node
        ///
        /// \param node - current node
        /// \return Pointer to node
        aghTnode<T>* findMin(aghTnode<T> * node) const;

   public:

        /// \brief Default constructor
        aghTree();

        /// \brief Copy constructor
        ///
        /// \param pattern - pattern to copy
        aghTree(aghTree<T> const & pattern);


        /// \brief Copy constructor
        ///
        /// \param pattern - pattern to copy
        aghTree(aghContainer<T> const &pattern);

        /// \brief Destructor
        virtual ~aghTree();

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

#endif /* aghTree_H_ */
