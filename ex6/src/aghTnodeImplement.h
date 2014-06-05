#ifndef AGHTNODEIMPLEMENT_H_
#define AGHTNODEIMPLEMENT_H_
// -------------------------------------------------------------
template<class T>
aghTnode<T>::aghTnode(){
    setData(T());
    setLeft(NULL);
    setParent(NULL);
    setRight(NULL);
}
// -------------------------------------------------------------

template<class T>
aghTnode<T>::aghTnode(T const & _data, aghTnode * _left, aghTnode * _right,  aghTnode * _parent ){
    setData(_data);
    setLeft(_left);
    setRight(_right);
    setParent(_parent);
}
// -------------------------------------------------------------

template<class T>
aghTnode<T>::~aghTnode(){
    setParent(NULL);
    setLeft(NULL);
    setRight(NULL);
    this->data.~T();
}
// -------------------------------------------------------------

template<class T>
aghTnode<T>* aghTnode<T>::getLeft() const {
    return left;
}
// -------------------------------------------------------------

template<class T>
void aghTnode<T>::setLeft(aghTnode<T> * node){
    left = node;
}
// -------------------------------------------------------------
template<class T>
aghTnode<T>* aghTnode<T>::getRight() const {
    return right;
}
// -------------------------------------------------------------

template<class T>
void aghTnode<T>::setRight(aghTnode<T> * node){
    right = node;
}
// -------------------------------------------------------------

template<class T>
aghTnode<T>* aghTnode<T>::getParent() const {
    return parent;
}
// -------------------------------------------------------------

template<class T>
void aghTnode<T>::setParent(aghTnode<T> * node){
    parent = node;
}
// -------------------------------------------------------------

template<class T>
T& aghTnode<T>::getData() {
    return data;
}
// -------------------------------------------------------------

template<class T>
void aghTnode<T>::setData(T const & value){
    data = value;
}
// -------------------------------------------------------------
#endif /* aghTnodeIMPLEMENT_H_ */
