#ifndef AGHDNODEIMPLEMENT_H_
#define AGHDNODEIMPLEMENT_H_
// -------------------------------------------------------------
template<class T>
aghDnode<T>::aghDnode(){
    this -> setData(T());
    setPrev(NULL);
    setNext(NULL);
}
// -------------------------------------------------------------------------

template<class T>
aghDnode<T>::aghDnode(T const & _data, aghDnode * _next, aghDnode * _prev){
    this -> setData(_data);
    setNext(_next);
    setPrev(_prev);
}
// -------------------------------------------------------------------------

template<class T>
aghDnode<T>::~aghDnode(){

}
// -------------------------------------------------------------------------

template<class T>
aghDnode<T>* aghDnode<T>::getNext() const {
    return next;
}
// -------------------------------------------------------------------------

template<class T>
void aghDnode<T>::setNext(aghDnode<T> * node){
    next = node;
}
// -------------------------------------------------------------------------

template<class T>
aghDnode<T>* aghDnode<T>::getPrev() const {
    return prev;
}
// -------------------------------------------------------------------------

template<class T>
void aghDnode<T>::setPrev(aghDnode<T> * node){
    prev = node;
}
// -------------------------------------------------------------------------
#endif /* AGHDNODEIMPLEMENT_H_ */
