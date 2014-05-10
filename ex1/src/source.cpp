#include "source.h"
// -------------------------------------------------------------

template<>
double suma<char**>(char** tab, int iter){

  char buffer[100];
  strcpy(buffer,tab[0]);
  cout << tab[0];
  for (int i=1 ; i < iter ; i++){
    cout <<  " + " << tab[i];
    strcat(buffer,tab[i]);
  }

  double result = strlen(buffer);
  cout << " = " << buffer << "(" << result << ")" << endl;

  return result;
}
// -------------------------------------------------------------
