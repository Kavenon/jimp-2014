/**
* \file aghTnode.h
* \author Artem Mensk & Kamil Chlebek
* \date 13.06.2014
* \version 1.0
* \brief Declaration of class aghTnode
*/
// -------------------------------------------------------------------------

#ifndef AGHTNODE_H_
#define AGHTNODE_H_

// -------------------------------------------------------------------------

/**
* \class aghTnode.h
* \author Artem Mensk & Kamil Chlebek
* \date 13.06.2014
* \brief Class represents node
*/

template<class T>
class aghTnode {

    private:

        T data; /// \brief Next node
        aghTnode<T>* parent; /// \brief Parent node
        aghTnode<T>* left; /// \brief Left node
        aghTnode<T>* right; /// \brief Right node

    public:

        /// \brief Default constructor
        aghTnode();

        /// \brief Parametric constructor
        ///
        /// \param value - value of node
        /// \param left - left node
        /// \param right - right node
        aghTnode(T const & value, aghTnode<T> * left = NULL, aghTnode<T> * right = NULL, aghTnode<T> * parent = NULL);

        /// \brief Default destructor
        ~aghTnode();

        /// \brief Setter for data
        ///
        /// \param data
        void setData(T const & data);

        /// \brief Getter for data
        ///
        /// \return ref to data
        T& getData();

        /// \brief Setter for left
        ///
        /// \param node
        void setLeft(aghTnode<T> * node);

        /// \brief Getter for left
        ///
        /// \return Pointer to node
        aghTnode<T> * getLeft() const;

        /// \brief Setter for right
        ///
        /// \param node
        void setRight(aghTnode<T> * node);

        /// \brief Getter for right
        ///
        /// \return Pointer to node
        aghTnode<T> * getRight() const;

        /// \brief Setter for parent
        ///
        /// \param node
        void setParent(aghTnode<T> * node);

        /// \brief Getter for parent
        ///
        /// \return Pointer to node
        aghTnode<T> * getParent() const;

};
#endif /* AGHTNODE_H_ */

