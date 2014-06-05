#ifndef AGHCONTAINERIMPLEMENT_H_
#define AGHCONTAINERIMPLEMENT_H_
// -------------------------------------------------------------

template<class T>
aghContainer<T>::aghContainer(){

}
// -------------------------------------------------------------

template<class T>
aghContainer<T>::~aghContainer(){

}
// -------------------------------------------------------------

template<class T>
bool aghContainer<T>::replace(int _index, T const& _value){

    if(_index < 0 || _index >= size()){
        return false;
    }

    bool removeF = remove(_index);
    bool insertF = false;

    if(removeF) insertF = insert(_index,_value);

    return (removeF && insertF);

}
// -------------------------------------------------------------

template<class T>
void aghContainer<T>::clear(void){

    int sizeHold = size();
    for(int i = sizeHold-1; i >= 0;i--)
        remove(i);

}
// -------------------------------------------------------------

template<class T>
bool aghContainer<T>::isEmpty(void) const {
    return (size() <= 0);
}
// -------------------------------------------------------------

template<class T>
void aghContainer<T>::append(T const& value){

    if(!insert(size(), value)){
        throw aghException(0, "Append failed", __FILE__, __LINE__);
    }

}
// -------------------------------------------------------------
template<class T>
int aghContainer<T>::indexOf(T const& _value, int _from ) const {

    int result = -1;
    for(int i = _from; i < size(); i++){
        if(at(i) == _value){
            result = i;
            break;
        }
    }
    return result;

}
// -------------------------------------------------------------

template<class T>
bool aghContainer<T>::contains(T const& _value, int _from ) const {

    bool result = false;

    if(size() > 0){
        for(int i = _from; i < size(); i++){
             if(at(i) == _value){
                result = true;
                break;
             }
        }
    }

    return result;

}
// -------------------------------------------------------------

template<class T>
bool aghContainer<T>::operator==(aghContainer<T> const& right){

    if(size() != right.size()) return false;

    for(int i = 0; i < size(); i++){
        if(at(i) != right.at(i)){
            return false;
        }
    }

    return true;

}
// -------------------------------------------------------------
template<class T>
bool aghContainer<T>::operator!=(aghContainer<T> const& right){
    return !operator==(right);
}
// -------------------------------------------------------------

template<class T>
T& aghContainer<T>::operator[](int n) const {
    return at(n);
}
// -------------------------------------------------------------

template<class T>
aghContainer<T>& aghContainer<T>::operator+=(aghContainer<T> const& right){

    for(int i = 0; i<right.size();i++)
        append(right.at(i));

    return *this;

}
// -------------------------------------------------------------

template<class T>
aghContainer<T>& aghContainer<T>::operator+=(T const& element){

    append(element);
    return *this;

}
// -------------------------------------------------------------

template<class T>
aghContainer<T>& aghContainer<T>::operator<<(T const& element){

    append(element);
    return *this;

}
// -------------------------------------------------------------

template<class T>
aghContainer<T>& aghContainer<T>::operator<<(aghContainer<T> const& right){

    *this+=right;
    return *this;

}
// -------------------------------------------------------------

template<class T>
aghContainer<T>& aghContainer<T>::operator=(aghContainer const &pattern){

    if(this != &pattern){
        if(!isEmpty()) clear();
        *this += pattern;
    }

    return *this;

}
// -------------------------------------------------------------

template<class T>
std::ostream& operator<<(std::ostream& output, aghContainer<T> const& right){

    if(!right.isEmpty()){
        for(int i = 0; i < right.size(); i++){
            output << right.at(i);
            output << endl;
        }
    }

    return output;

}
// -------------------------------------------------------------

#endif /* AGHCONTAINERIMPLEMENT_H_ */
