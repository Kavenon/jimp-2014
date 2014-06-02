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
    allocVector();
    this -> aghSlist<T>::operator=(pattern);
}
// -------------------------------------------------------------
template<class T>
aghSlist<T>::~aghSlist(){
    while(size() > 0)
	remove(size()-1); // bo numerujemy od 0
}
// -------------------------------------------------------------
template<class T>
int aghSlist<T>::size(void) const{
    int count = 0;
    aghSlist* temp = front;
    while(temp != NULL){
	count++;
	temp = temp->next;
    }
    return count;
}
template<class T>
T& aghSlist<T>::at(int _index) const {
    if(_index < 0 || _index >= size()){
        throw aghException(0, "Wrong index", __FILE__, __LINE__);
    }

    int count = 0;
    T* result = NULL;

    aghSlist* temp = front;
    while(temp != NULL){
	if(count == _index){
	   result = temp;
	   break;	
	} 
	count++;	
	temp = temp->next;
    }
    
    return result;

}
template<class T>
bool aghSlist<T>::insert(int _index, T const& _value){
   bool result = false;
   if(_index == 0){
	result = putFront(_value);
   }
   else if(_index == size()){
	result = putBack(_value);
   }
   else {
        result = putAt(_index, _value);
   }
   return result;

}
template<class T>
bool aghSlist<T>::putFront(T& const _value){

   // TODO: create node
   if(front == NULL){
	
        front = &node;
   }
   else {
	aghSlist* temp = front;
	front = &node;
	front -> next = temp;
   }



}
template<class T>
bool aghSlist<T>::putBack(T& const _value){
   if(front == NULL){
	putFront(_value);
   }
   else {
	// moze byc funkcja FIND LAST
	aghSlist* temp = front;
	while(temp != NULL)
		temp = temp -> next; // dodac node temp -> node -> next

	temp -> next = node;
	
   }
}

