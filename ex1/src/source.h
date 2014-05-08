#ifndef SOURCE_H_
#define SOURCE_H_

#include <iostream>
#include <string.h>

using namespace std;

template<typename T>
double suma(T tab, int iter){

  double result = tab[0];

  cout << tab[0];
  for (int i=1 ; i < iter ; i++){
    cout <<  " + " << tab[i];
    result += tab[i];
  }
  cout << " = " << result << endl;

  return result;
}

template<>
double suma<char**>(char** tab, int iter);



#endif /* SOURCE_H_ */
