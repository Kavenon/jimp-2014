#ifndef AGHTREEIMPLEMENT_H_
#define AGHTREEIMPLEMENT_H_
// -------------------------------------------------------------
template<class T>
aghTree<T>::aghTree(){
    root = NULL;
    treeCount = 0;
}
// -------------------------------------------------------------
template<class T>
aghTree<T>::aghTree(aghTree<T> const & pattern){
    root = NULL;
    treeCount = 0;
    this -> aghTree<T>::operator=(pattern);
}
// -------------------------------------------------------------

template<class T>
aghTree<T>::aghTree(aghContainer<T> const & pattern){
    root = NULL;
    treeCount = 0;
    this -> aghTree<T>::operator=(pattern);
}
// -------------------------------------------------------------

template<class T>
aghTree<T>::~aghTree(){
    if(!this->isEmpty())
      this->clear();
}
// -------------------------------------------------------------

template<class T>
int aghTree<T>::size(void) const{
    return treeCount;
}
// -------------------------------------------------------------
template<class T>
T& aghTree<T>::at(int _index) const {
   return getNode(_index)->getData();
}
// -------------------------------------------------------------

template<class T>
bool aghTree<T>::insert(int _index, T const& _value){

    bool result = true;

    if(_index < 0 || _index > size()) throw aghException(0, "Wrong index", __FILE__, __LINE__);

    aghTnode<T> * node = new aghTnode<T>(_value, NULL, NULL);
    aghTnode<T>* y = NULL;
    aghTnode<T>* x = root;

    while(x != NULL){
        y = x;
        if(node->getData() < x -> getData()){
            x = x-> getLeft();
        }
        else {
            x = x -> getRight();
        }
    }

    node -> setParent(y);

    if(y == NULL){
        root = node;
    }
    else {
        if(node->getData() < y->getData()){
            y -> setLeft(node);
        }
        else {
            y -> setRight(node);
        }
    }

    treeCount++;

    return result;

}
// -------------------------------------------------------------

template<class T>
aghTnode<T>* aghTree<T>::findMin(aghTnode<T> * node) const {
    aghTnode<T> * result = NULL;

    if(node != NULL){
        result = node;
        while(result -> getLeft() != NULL)
            result = result ->getLeft();
    }

    return result;

}
// -------------------------------------------------------------

template<class T>
aghTnode<T>* aghTree<T>::findSuccessor(aghTnode<T> * node) const {

    aghTnode<T> * result = NULL;

    if(node != NULL){

        if (node -> getRight() != NULL){
            result = findMin(node->getRight());
        }
        else {

             aghTnode < T > *temp;
             temp = node;
             result = temp -> getParent();
             while(result != NULL && result -> getLeft() != temp){
                temp = result;
                result = result -> getParent();
             }

        }

    }
    return result;
}
// -------------------------------------------------------------

template<class T>
bool aghTree<T>::remove(int _index){

    bool result = false;

    if(size() > 0){

        aghTnode<T>* found = inOrderWalk(root, _index);
        if(found != NULL){
            aghTnode<T>* y = NULL;
            aghTnode<T>* x = NULL;
            if(found -> getLeft() == NULL || found -> getRight() == NULL){
                y = found;
            }
            else {
                y = findSuccessor(found);
            }

            if(y -> getLeft() != NULL){
                x = y -> getLeft();
            }
            else {
                x = y -> getRight();
            }

            if(x != NULL){
                x -> setParent(y->getParent());
            }

            if(y->getParent() == NULL){
                root = x;
            }
            else {
                if(y == y->getParent()->getLeft()){
                    y->getParent()->setLeft(x);
                }
                else {
                    y->getParent()->setRight(x);
                }
            }
            if(y != found){
                found -> setData(y->getData());
            }

            delete y;
            treeCount--;

            result = true;
        }
    }
    return result;

}
// -------------------------------------------------------------

template<class T>
aghTnode<T>* aghTree<T>::inOrderWalk(aghTnode<T>* node ,int &k) const {

    if (node == NULL)
        return NULL;

    aghTnode<T> *tmp = inOrderWalk(node->getLeft(), k);

    if (tmp != NULL)
        return tmp;

    if (k-- == 0)
        return node;

    return inOrderWalk(node->getRight(), k);
}
// -------------------------------------------------------------

template<class T>
aghTnode<T>* aghTree<T>::getNode(int _index) const {

    aghTnode<T>* result = NULL;

    if(size() > 0){

        if(_index < 0 || _index > size()) throw aghException(0, "Wrong index", __FILE__, __LINE__);

        result =  inOrderWalk(root, _index);

    }

    return result;

}
// -------------------------------------------------------------
#endif /* AGHTREEIMPLEMENT_H_ */
