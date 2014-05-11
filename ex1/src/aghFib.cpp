#include "aghFib.h"
#include "aghException.h"
// -------------------------------------------------------------

aghFib::aghFib() {
}
// -------------------------------------------------------------

aghFib::~aghFib() {
}
// -------------------------------------------------------------

int aghFib::operator[] (const int index){
  return fibonacci(index);
}
// -------------------------------------------------------------

int aghFib::fibonacci(int index){

  if(index < 0) throw aghException(0, "Index out of range", __FILE__, __LINE__);

  if (index == 0)
    return 0;
  if (index <= 2)
    return 1;

  int a = 1;
  int b = 1;
  int result = 0;

  for (int i = 3; i <= index; i++){
    result = a + b;
    a = b;
    b = result;
  }

  return result;
}
// -------------------------------------------------------------
