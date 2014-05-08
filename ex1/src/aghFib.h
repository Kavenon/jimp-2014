#ifndef AGHFIB_H_
#define AGHFIB_H_

class aghFib {
  int fibonacci(int index);

public:
  aghFib();
  virtual ~aghFib();

  int operator[] (const int nIndex);

};

#endif /* AGHFIB_H_ */
