#include "aghInclude.h"
// -------------------------------------------------------------

template<>
void aghMatrix<char>::setItems(int r, int c, ...){

    if(r*c < 0)  throw aghException(0, "Wrong dimesions", __FILE__, __LINE__);

    deleteContainer();
    createContainer(r,c);

    va_list arguments;
    va_start ( arguments, c );

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++) {
            container[r][c] = va_arg(arguments, int);
        }
    }

    va_end ( arguments );
}
// -------------------------------------------------------------

template<>
aghMatrix<char> aghMatrix<char>::operator+(aghMatrix<char> const &m){

    if(m.rows != rows || m.cols != cols) throw aghException(1, "Wrong dimesions, cannot add", __FILE__, __LINE__);

    aghMatrix<char> result;
    result.createContainer(rows, cols);

    for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
            result.container[r][c] = ((container[r][c] - 'a' + m.container[r][c] - 'a')%('z'-'a' + 1)) + 'a';

    return result;

}
// -------------------------------------------------------------

template<>
aghMatrix<char> aghMatrix<char>::operator*(aghMatrix<char> const &m){

    if(cols != m.rows) throw aghException(2, "Wrong dimesions, cannot multiply", __FILE__, __LINE__);

    aghMatrix<char> result;
    result.createContainer(rows,m.cols);


    for(int i = 0; i < rows; i++){
        for(int j = 0; j < m.cols; j++){
            for(int k = 0; k < cols; k++){
                result.container[i][j] +=  ((container[i][k]-'a') * (m.container[k][j]-'a'))%('z'-'a' + 1);
            }
            result.container[i][j] = (result.container[i][j]%('z'-'a' + 1)) + 'a';
        }
    }

    return result;

}
// -------------------------------------------------------------

template<>
aghMatrix<char*> aghMatrix<char*>::operator+(aghMatrix<char*> const &m){

    aghMatrix<char*> result;

    if(m.rows != rows || m.cols != cols) throw aghException(3, "Wrong dimesions, cannot add", __FILE__, __LINE__);

    result.createContainer(rows, cols);

    for(int r = 0; r<rows;r++){
        for(int c = 0; c<cols;c++){
            result.setItem(r,c, "");
            char * sum = sumStrings(container[r][c], m.container[r][c]);
            strcpy(result.container[r][c], sum);
        }
    }

    return result;

}
// -------------------------------------------------------------

template<>
aghMatrix<char*> aghMatrix<char*>::operator*(aghMatrix<char*> const &m){

    aghMatrix<char*> result;

    if(cols != m.rows) throw aghException(4, "Wrong dimesions, cannot multiply", __FILE__, __LINE__);

    result.createContainer(rows, m.cols);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < m.cols; j++){
            result.setItem(i, j, "");
            for(int k = 0; k < cols; k++){
                result.container[i][j] = sumStrings(  result.container[i][j], multiplyStrings(container[i][k], m.container[k][j]));
            }

        }
    }

    return result;

}
// -------------------------------------------------------------

template<>
void aghMatrix<char*>::setItem(int r, int c, char *value){

    if(r >= rows || c >= cols || r*c < 0)  throw aghException(5, "Wrong dimesions", __FILE__, __LINE__);

    if(container[r][c] != NULL) delete[] container[r][c];

    container[r][c] = new char[strlen(value)+1];
    strcpy(container[r][c], value);

}
// -------------------------------------------------------------

template<>
void aghMatrix<char*>::setItems(char ** values){

    for(int r = 0; r < rows;r++){
        for(int c = 0; c < cols; c++){

             if(container[r][c] != NULL) delete[] container[r][c];

             container[r][c] = new char[strlen(*values)+1];
             strcpy(container[r][c], *values);
             values++;

        }
    }

}
// -------------------------------------------------------------

template<>
void aghMatrix<char*>::setItems(int r, int c, ...){

    if(r*c < 0)  throw aghException(6, "Wrong dimesions", __FILE__, __LINE__);

    deleteContainer();
    createContainer(r,c);

    va_list arguments;
    va_start ( arguments, c );

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++) {
            setItem(r,c, va_arg(arguments, char*));
        }
    }

    va_end ( arguments );

}
// -------------------------------------------------------------
template<>
aghMatrix<char*>::~aghMatrix(){

    if(container != NULL) {
        for(int r = 0; r < rows; r++)
            for(int c = 0; c < cols;c++)
                if(container[r][c] != NULL)
                    delete [] container[r][c];

        deleteContainer();
    }

}
// -------------------------------------------------------------

template<>
bool aghMatrix<char*>::operator==(aghMatrix<char*> & m){

    if(m.rows != rows || m.cols != cols) return false;

    for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
            if(strcmp(container[r][c], m.container[r][c]) != 0) return false;

    return true;
}
// -------------------------------------------------------------

template<>
bool aghMatrix<char*>::operator!=(aghMatrix<char*> & m){

    return !operator==(m);

}
// -------------------------------------------------------------
template<>
aghMatrix<char*> & aghMatrix<char*>::operator=(aghMatrix<char*> const & m){

    if(&m != this){

        if(container != NULL) {

            for(int r=0;r<rows;r++)
                for(int c=0;c<cols;c++)
                    if(container[r][c] != NULL) delete [] container[r][c];

            deleteContainer();
        }

        createContainer(m.rows,m.cols);

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                setItem(r,c, m.container[r][c]);
            }
        }

    }

    return *this;

}
// -------------------------------------------------------------
