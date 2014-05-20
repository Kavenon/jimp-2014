#include "SeriesTest.h"
// -------------------------------------------------------------------------

SeriesTest::SeriesTest() {
}
// -------------------------------------------------------------------------

SeriesTest::~SeriesTest() {
}
// -------------------------------------------------------------------------

void SeriesTest::runTest() {

  int sampling = getSampling();
  int array[sampling];
  int increaseCount = 0;
  int decreaseCount = 0;
  int maxIncreaseSerie = 0;
  int maxDecreaseSerie = 0;
  int nonStopIncreaseCount = 0;
  int nonStopDecreaseCount = 0;

  ostringstream ss;
  array[0] = getGenerator()->toGenerate();
  for(int i = 0 ; i < getSampling() - 1 ; i++){
    array[i+1] = getGenerator()->toGenerate();
    if (array[i] < array[i+1]){
      nonStopDecreaseCount = 0;
      increaseCount++;
      nonStopIncreaseCount++;
    }
    else {
      nonStopIncreaseCount = 0;
      decreaseCount++;
      nonStopDecreaseCount++;
    }
    if (nonStopIncreaseCount > maxIncreaseSerie)
      maxIncreaseSerie = nonStopIncreaseCount;
    if (nonStopDecreaseCount > maxDecreaseSerie)
      maxDecreaseSerie = nonStopDecreaseCount;
  }

  ss << "Generator " << getGenerator()->getGeneratorName() << " gave me numbers:\n";
  for (int i = 0 ; i < sampling ; i++ ){
    ss << array[i] << "   ";
    if ((i+1) % 5 == 0)
      ss << endl;
  }
  ss << "All increase cases: " << increaseCount << endl;
  ss << "All decrease cases: " << decreaseCount << endl;
  ss << "Max series:\n";
  ss << "inc: " << maxIncreaseSerie << endl;
  ss << "dec: " << maxDecreaseSerie << endl;
  addInResultText(ss.str());

}
// -------------------------------------------------------------------------

void SeriesTest::printResult(ostream& out) {

  out << endl <<"//----------------------------------//" << endl;
  out << "Hello, I'm SeriesTest." << endl;
  out << getResult();
  out << "//----------------------------------//" << endl;

}
// -------------------------------------------------------------------------
