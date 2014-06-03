/**
* \file aghDnode.h
* \author Artem Mensk & Kamil Chlebek
* \date 07.06.2014
* \version 1.0
* \brief Declaration of class aghDnode
*/
// -------------------------------------------------------------------------

#ifndef AGHDNODE_H_
#define AGHDNODE_H_

// -------------------------------------------------------------------------

/**
* \class aghDnode.h
* \author Artem Mensk & Kamil Chlebek
* \date 07.06.2014
* \brief Class represents node
*/

template<class T>
class aghDnode : public aghSnode<T> {

    private:

        aghDnode<T>* prev; /// \brief Previous node
        aghDnode<T>* next; /// \brief Next node

    public:

        /// \brief Default constructor
        aghDnode();

        /// \brief Parametric constructor
        ///
        /// \param value - value of node
        /// \param next - next node
        /// \param prev - previous node
        aghDnode(T const & value, aghDnode<T> * next = NULL, aghDnode<T> * prev = NULL);

        /// \brief Default destructor
        ~aghDnode();

        /// \brief Setter for prev
        ///
        /// \param node
        void setPrev(aghDnode<T> * node);

        /// \brief Getter for prev
        ///
        /// \return Pointer to node
        aghDnode<T> * getPrev() const;

        /// \brief Setter for next
        ///
        /// \param node
        void setNext(aghDnode<T> * node);

        /// \brief Getter for next
        ///
        /// \return Pointer to node
        aghDnode<T> * getNext() const;


};
#endif /* AGHDNODE_H_ */
