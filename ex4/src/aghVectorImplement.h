#ifndef AGHVECTORIMPLEMENT_H_
#define AGHVECTORIMPLEMENT_H_
// -------------------------------------------------------------

template<class T>
aghVector<T>::aghVector(){
    allocVector();
}
// -------------------------------------------------------------
template<class T>
aghVector<T>::aghVector(aghVector<T> const & pattern){
    allocVector();
    this -> aghContainer<T>::operator=(pattern);
}
// -------------------------------------------------------------

template<class T>
aghVector<T>::aghVector(aghContainer<T> const & pattern){
    allocVector();
    this -> aghContainer<T>::operator=(pattern);
}
// -------------------------------------------------------------

template<class T>
aghVector<T>::~aghVector(){
    deallocVector();
}
// -------------------------------------------------------------

template<class T>
void aghVector<T>::allocVector(){
    vector = NULL;
    vectorSize = 0;
}
// -------------------------------------------------------------

template<class T>
void aghVector<T>::reallocVector(int size){

    if(size <= 0) throw aghException(0, "Wrong size", __FILE__, __LINE__);

    T* temp = new T[size];

    for(int i = 0; i < this->size(); i++) {
        temp[i] = vector[i];
    }

    if(this->size() < size){
        for(int i = this->size(); i < size; i++){
            temp[i] = T();
        }
    }

    deallocVector();

    vector = temp;
    vectorSize = size;

}
// -------------------------------------------------------------

template<class T>
void aghVector<T>::deallocVector(){
    if(vector != NULL){
        delete [] vector;
        allocVector();
    }
}
// -------------------------------------------------------------

template<class T>
int aghVector<T>::size(void) const{
    return vectorSize;
}
// -------------------------------------------------------------

template<class T>
bool aghVector<T>::insert(int _index, T const& _value){

    reallocVector(size()+1);

    if(_index >= size() || _index < 0) return false;

    for(int i = size()-1; i > _index;i--){
        vector[i] = vector[i-1];
    }

    vector[_index] = _value;

    return true;

}
// -------------------------------------------------------------

template<class T>
T& aghVector<T>::at(int _index) const {
    if(_index < 0 || _index >= size()){
        throw aghException(0, "Wrong index", __FILE__, __LINE__);
    }

    return vector[_index];
}
// -------------------------------------------------------------

template<class T>
bool aghVector<T>::remove(int _index){
    bool result = false;

    if(_index >= 0 || _index < size()){

        if(!this->isEmpty()){
            for(int i = _index; i < size()-1; i ++){
                vector[i] = vector[i+1];
            }

            vector[size()-1].~T();
            vectorSize--;
            result = true;

        }

    }

    return result;

}
// -------------------------------------------------------------

#endif /* AGHVECTORIMPLEMENT_H_ */
