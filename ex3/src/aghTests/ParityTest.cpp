#include "../aghInclude.h"
// --------------------------------------------------------------

ParityTest::ParityTest() {
}
// --------------------------------------------------------------

ParityTest::~ParityTest() {
}
// --------------------------------------------------------------

void ParityTest::runTest() {

  int sampling = getSampling();
  int evenCount = 0;
  int oddCount = 0;
  int array[sampling];
  ostringstream ss;

  for(int i = 0 ; i < getSampling() ; i++){
    array[i] = getGenerator()->toGenerate();
    if ((array[i] % 2) == 0)
      evenCount++;
    else
      oddCount++;
  }

  ss << "Generator " << getGenerator()->getGeneratorName() << " gave me numbers:\n";
  for (int i = 0 ; i < sampling ; i++ ){
    ss << array[i] << "   ";
    if ((i+1) % 5 == 0)
      ss << endl;
  }
  ss << "Numbers have:\n";
  ss << evenCount << " even numbers\n";
  ss << "and\n";
  ss << oddCount <<" odd numbers\n";
  ss << "Proportion even/odd is: \n";
  ss << (double) oddCount / (double) evenCount << endl;

  addInResultText(ss.str());

}
// --------------------------------------------------------------

void ParityTest::printResult(ostream& out) {

  out << endl << "//----------------------------------//" << endl;
  out << "Hello, I'm ParityTest." << endl;
  out << getResult();
  out << "//----------------------------------//" << endl;

}
// --------------------------------------------------------------
