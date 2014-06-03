#ifndef AGHDLISTIMPLEMENT_H_
#define AGHDLISTIMPLEMENT_H_
// -------------------------------------------------------------
template<class T>
aghDlist<T>::aghDlist(){
   front = NULL;
   rear = NULL;
}
// -------------------------------------------------------------
template<class T>
aghDlist<T>::aghDlist(aghDlist<T> const & pattern){
    this -> aghDlist<T>::operator=(pattern);
}
// -------------------------------------------------------------

template<class T>
aghDlist<T>::aghDlist(aghContainer<T> const & pattern){
    this -> aghDlist<T>::operator=(pattern);
}
// -------------------------------------------------------------

template<class T>
aghDlist<T>::~aghDlist(){
    if(!this->isEmpty())
        this->clear();
}
// -------------------------------------------------------------

template<class T>
int aghDlist<T>::size(void) const{

    int count = 0;

    aghDnode<T>* temp = front;

    while(temp != NULL){
        count++;
        temp = temp->getNext();
    }

    return count;
}
// -------------------------------------------------------------

template<class T>
void aghDlist<T>::putFront(T const & _value){

    aghDnode<T> * node = new aghDnode<T>(_value, front);

    if(front == NULL){
        rear = node;
    }
    else {
        front->setPrev(node);
    }
    front = node;

}
// -------------------------------------------------------------

template<class T>
void aghDlist<T>::putBack(T const & _value){

    aghDnode<T> * node = new aghDnode<T>(_value, NULL, rear);

    if(rear == NULL){
        putFront(_value);
    }
    else {
        rear -> setNext(node);
    }
    rear = node;

}
// -------------------------------------------------------------

template<class T>
void aghDlist<T>::putAt(int _index, T const & _value){

    aghDnode<T> * temp = getNode(_index);
    aghDnode<T> * node = new aghDnode<T>(_value, temp, temp->getPrev());

    temp -> getPrev() -> setNext(node);
    temp -> setPrev(node);

}
// -------------------------------------------------------------

template<class T>
aghDnode<T>* aghDlist<T>::getNode(int _index) const{

    aghDnode<T>* result = NULL;

    if(size() > 0){

        if(_index < 0 || _index >= size()) throw aghException(0, "Wrong index", __FILE__, __LINE__);

        aghDnode<T>* temp = front;
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
void aghDlist<T>::popFront(){
    if(front != NULL){
        if(rear == front) {
            front = NULL;
            delete  rear;
            rear = NULL;
        }
        else {
            aghDnode<T> *temp = front->getNext();
            temp->setPrev(NULL);
            delete front;
            front = temp;
        }
    }
}
// -------------------------------------------------------------

template<class T>
void aghDlist<T>::popBack(){

    if(rear != NULL){
        if(rear == front) {
            front= NULL;
            delete rear;
            rear = NULL;
        }
        else {
            aghDnode<T>* temp = rear->getPrev();
            temp->setNext(NULL);
            delete rear;
            rear = temp;
        }
   }
}
// -------------------------------------------------------------

template<class T>
void aghDlist<T>::popAt(int _index){

   if(size() > 0){

        aghDnode<T>* temp = getNode(_index);
        temp -> getPrev() -> setNext(temp->getNext());
        temp -> getNext() -> setPrev(temp->getPrev());

        delete temp;

   }

}
// -------------------------------------------------------------
#endif /* AGHDLISTIMPLEMENT_H_ */
