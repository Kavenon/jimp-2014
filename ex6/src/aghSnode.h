/**
* \file aghSnode.h
* \author Artem Mensk & Kamil Chlebek
* \date 07.06.2014
* \version 1.0
* \brief Declaration of class aghSnode
*/
// -------------------------------------------------------------------------

#ifndef AGHSNODE_H_
#define AGHSNODE_H_

// -------------------------------------------------------------------------

/**
* \class aghSnode.h
* \author Artem Mensk & Kamil Chlebek
* \date 07.06.2014
* \brief Class represents node
*/

template<class T>
class aghSnode {

    private:

        T data; /// \brief Next node
        aghSnode<T>* next; /// \brief Next node

    public:

        /// \brief Default constructor
        aghSnode();

        /// \brief Parametric constructor
        ///
        /// \param value - value of node
        /// \param next - next node
        aghSnode(T const & value, aghSnode<T> * next = NULL);

        /// \brief Default destructor
        ~aghSnode();

        /// \brief Setter for data
        ///
        /// \param data
        void setData(T const & data);

        /// \brief Getter for data
        ///
        /// \return ref to data
        T& getData();

        /// \brief Setter for next
        ///
        /// \param node
        void setNext(aghSnode<T> * node);

        /// \brief Getter for next
        ///
        /// \return Pointer to node
        aghSnode<T> * getNext() const;

};
#endif /* AGHSNODE_H_ */
