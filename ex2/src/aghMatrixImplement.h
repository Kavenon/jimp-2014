#ifndef AGHMATRIXIMPLEMENT_H_
#define AGHMATRIXIMPLEMENT_H_
// -------------------------------------------------------------

template<class T>
aghMatrix<T>::aghMatrix(){
    rows = 0;
    cols = 0;
    container = NULL;
}
// -------------------------------------------------------------

template<class T>
aghMatrix<T>::aghMatrix(int rows, int cols){
    createContainer(rows,cols);
}
// -------------------------------------------------------------

template<class T>
aghMatrix<T>::aghMatrix(aghMatrix<T> const & m){
    *this = m;
}
// -------------------------------------------------------------

template<class T>
aghMatrix<T>::~aghMatrix(){
    if(container != NULL) deleteContainer();
}
// -------------------------------------------------------------

template<class T>
void aghMatrix<T>::createContainer(int r, int c){

    rows = r;
    cols = c;

    container = new T*[r];
    for(int i = 0; i < r; i++){
        container[i] = new T[c];
        for(int c = 0; c < cols; c++){
            container[i][c] = T();
        }
    }

}
// -------------------------------------------------------------

template<class T>
void aghMatrix<T>::deleteContainer(){

    if(container != NULL){
        for(int i = 0; i < rows; i++){
            delete [] container[i];
        }
        delete [] container;

        container = NULL;
        rows = 0;
        cols = 0;
    }

}
// -------------------------------------------------------------

template<class T>
void aghMatrix<T>::setItem(int r, int c, T value){

    if(r < rows && c < cols && container != NULL){
        container[r][c] = value;
    }

}
// -------------------------------------------------------------

template<class T>
void aghMatrix<T>::setItems(T* values){
    for(int r = 0; r < rows;r++){
        for(int c = 0; c < cols; c++){
            container[r][c] = *(values++);
        }
    }
}
// -------------------------------------------------------------

template<class T>
void aghMatrix<T>::setItems(int r, int c, ...){

    if(r*c < 0)  throw aghException(0, "Wrong dimesions", __FILE__, __LINE__);

    deleteContainer();
    createContainer(r,c);

    va_list arguments;
    va_start ( arguments, c );

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++) {
            container[r][c] = va_arg(arguments, T);
        }
    }

    va_end ( arguments );

}
// -------------------------------------------------------------

template<class T>
aghMatrix<T>& aghMatrix<T>::operator=(aghMatrix<T> const &m){

    if(&m != this){

        if(container != NULL) deleteContainer();
        createContainer(m.rows,m.cols);

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                container[r][c] = m.container[r][c];
            }
        }

    }

    return *this;

}
// -------------------------------------------------------------

template<class T>
aghMatrix<T> aghMatrix<T>::operator+(aghMatrix<T> const &m){

    if(m.rows != rows || m.cols != cols) throw aghException(2, "Wrong dimesions, cannot add", __FILE__, __LINE__);

    aghMatrix<T> result;
    result.createContainer(rows, cols);

    for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
            result.container[r][c] = container[r][c] + m.container[r][c];

    return result;

}
// -------------------------------------------------------------

template<class T>
aghMatrix<T> aghMatrix<T>::operator*(aghMatrix<T> const &m){
    if(cols != m.rows) throw aghException(3, "Wrong dimesions, cannot multiply", __FILE__, __LINE__);

    aghMatrix<T> result;
    result.createContainer(rows,m.cols);

    for(int i = 0; i < rows; i++)
        for(int j = 0; j < m.cols; j++)
            for(int k = 0; k < cols; k++)
                result.container[i][j] =  result.container[i][j] + (container[i][k] * m.container[k][j]);

    return result;

}
// -------------------------------------------------------------

template<class T>
bool aghMatrix<T>::operator==(aghMatrix<T> &m){

    if(m.rows != rows || m.cols != cols) return false;

    for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
            if(container[r][c] != m.container[r][c]) return false;

    return true;
}
// -------------------------------------------------------------

template<class T>
bool aghMatrix<T>::operator!=(aghMatrix<T> &m){
    return !aghMatrix<T>::operator==(m);
}
// -------------------------------------------------------------

template<class T>
T aghMatrix<T>::operator()(int r, int c)  {
    if( r*c < 0 || r >= rows || c >= cols) throw aghException(4, "Wrong dimesions", __FILE__, __LINE__);
    return container[r][c];
}
// -------------------------------------------------------------

#endif /* AGHMATRIXIMPLEMENT_H_ */

