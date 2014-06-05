#ifndef AGHSLISTIMPLEMENT_H_
#define AGHSLISTIMPLEMENT_H_
// -------------------------------------------------------------
template<class T>
aghSlist<T>::aghSlist(){
    front = NULL;
}
// -------------------------------------------------------------
template<class T>
aghSlist<T>::aghSlist(aghSlist<T> const & pattern){
    this -> aghSlist<T>::operator=(pattern);
}
// -------------------------------------------------------------

template<class T>
aghSlist<T>::aghSlist(aghContainer<T> const & pattern){
    this -> aghSlist<T>::operator=(pattern);
}
// -------------------------------------------------------------

template<class T>
aghSlist<T>::~aghSlist(){
    if(!this->isEmpty())
      this->clear();
}
// -------------------------------------------------------------

template<class T>
int aghSlist<T>::size(void) const{

    int count = 0;
    aghSnode<T>* temp = front;
    while(temp != NULL){
        count++;
        temp = temp->getNext();
    }

    return count;
}
// -------------------------------------------------------------

template<class T>
T& aghSlist<T>::at(int _index) const {
    return getNode(_index)->getData();
}
// -------------------------------------------------------------

template<class T>
bool aghSlist<T>::insert(int _index, T const& _value){

   bool result = false;
   if(_index == 0){
        putFront(_value);
        result = true;
   }
   else if(_index == size()){
        putBack(_value);
        result = true;
   }
   else {
       if(_index >= 1 && _index < size()){
           putAt(_index, _value);
           result = true;
       }
   }

   return result;
}
// -------------------------------------------------------------

template<class T>
void aghSlist<T>::putFront(T const & _value){

    aghSnode<T> * node = new aghSnode<T>(_value, front);

    front = node;

}
// -------------------------------------------------------------

template<class T>
void aghSlist<T>::putBack(T const & _value){
    aghSnode<T> * node = new aghSnode<T>(_value);

    if(front == NULL){
        putFront(_value);
    }
    else {
        getNode(size()-1)-> setNext(node);
    }
}
// -------------------------------------------------------------

template<class T>
void aghSlist<T>::putAt(int _index, T const & _value){

    aghSnode<T> * node = new aghSnode<T>(_value);
    aghSnode<T> * temp = getNode(_index -1);

    node -> setNext(temp->getNext());
    temp -> setNext(node);

}
// -------------------------------------------------------------

template<class T>
bool aghSlist<T>::remove(int _index){

    bool result = false;

    if(_index == 0){
        popFront();
        result = true;
    }
    else if(_index == size()-1){
        popBack();
        result = true;
    }
    else {
        if(_index >= 1 && _index < size()){
            popAt(_index);
            result = true;
        }
   }

   return result;

}
// -------------------------------------------------------------

template<class T>
aghSnode<T>* aghSlist<T>::getNode(int _index) const{

    aghSnode<T>* result = NULL;

    if(front != NULL){

        if(_index < 0 || _index > size()) throw aghException(0, "Wrong index", __FILE__, __LINE__);

        aghSnode<T>* temp = front;
        int counter = 0;

        while(temp != NULL && counter < _index){
            counter++;
            temp = temp -> getNext();
        }
        result = temp;
    }
    return result;
}
// -------------------------------------------------------------

template<class T>
void aghSlist<T>::popFront(){

    if(front != NULL){
        aghSnode<T>* temp = front->getNext();
        delete front;
        front = temp;
    }

}
// -------------------------------------------------------------

template<class T>
void aghSlist<T>::popBack(){

   if(size() > 0){
        aghSnode<T>* temp = getNode(size() - 2);

        delete temp -> getNext();
        temp -> setNext(NULL);
   }

}
// -------------------------------------------------------------

template<class T>
void aghSlist<T>::popAt(int _index){

   if(size() > 0){

        aghSnode<T>* temp = getNode(_index);
        getNode(_index-1) -> setNext(temp->getNext());
        delete temp;

   }

}
// -------------------------------------------------------------
#endif /* AGHSLISTIMPLEMENT_H_ */
