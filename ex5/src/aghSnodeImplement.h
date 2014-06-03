#ifndef AGHSNODEIMPLEMENT_H_
#define AGHSNODEIMPLEMENT_H_
// -------------------------------------------------------------
template<class T>
aghSnode<T>::aghSnode(){
    setData(T());
    setNext(NULL);
}
// -------------------------------------------------------------

template<class T>
aghSnode<T>::aghSnode(T const & _data, aghSnode * _next){
    setData(_data);
    setNext(_next);
}
// -------------------------------------------------------------

template<class T>
aghSnode<T>::~aghSnode(){

}
// -------------------------------------------------------------

template<class T>
aghSnode<T>* aghSnode<T>::getNext() const {
    return next;
}
// -------------------------------------------------------------

template<class T>
void aghSnode<T>::setNext(aghSnode<T> * node){
    next = node;
}
// -------------------------------------------------------------

template<class T>
T& aghSnode<T>::getData() {
    return data;
}
// -------------------------------------------------------------

template<class T>
void aghSnode<T>::setData(T const & value){
    data = value;
}
// -------------------------------------------------------------
#endif /* AGHSNODEIMPLEMENT_H_ */
