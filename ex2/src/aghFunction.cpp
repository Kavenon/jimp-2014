#include "aghInclude.h"
// -------------------------------------------------------------------------

char * sumStrings(const char * s1, const char * s2){

    if(strlen(s1) == 0 && strlen(s2) == 0) return NULL;

    char * buffer = new char[strlen(s1)+strlen(s2)+1];
    char * result = NULL;
    int count = 0;

    for(int i = 0; i <strlen(s1);i++){
        if(strchr(buffer, s1[i]) == NULL){
            buffer[count++] = s1[i];
        }
    }
     for(int i = 0; i <strlen(s2);i++){
        if(strchr(buffer, s2[i]) == NULL){
            buffer[count++] = s2[i];
        }
    }

    buffer[count] = '\0';
    result = new char[count+1];
    strcpy(result, buffer);
    delete[] buffer;

    return result;
}
// -------------------------------------------------------------------------

char * multiplyStrings(const char * s1, const char * s2){

    if(strlen(s1) == 0 && strlen(s2) == 0) return NULL;

    char * buffer = new char[(((strlen(s1) > strlen(s2))) ? strlen(s1) : strlen(s2))+1];
    char * result = NULL;
    int count = 0;

    for( int i = 0; i < strlen(s1); i++ ){
        if(strchr(s2, s1[i]) != NULL && strchr(buffer, s1[i]) == NULL){
            buffer[count++] = s1[i];
        }
    }

    buffer[count] = '\0';
    result = new char[count + 1];
    strcpy(result, buffer);
    delete[] buffer;

    return result;

}
// -------------------------------------------------------------------------
