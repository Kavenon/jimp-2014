#include "IntervalTest.h"
// -------------------------------------------------------------------------

IntervalTest::IntervalTest() {
}
// -------------------------------------------------------------------------

IntervalTest::~IntervalTest() {
}
// -------------------------------------------------------------------------

void IntervalTest::runTest() {

  int sampling = getSampling();
  int intervalNumber = getIntervalNumber();
  int array[sampling];
  int intervals[intervalNumber];
  int minValue = getGenerator()->getMinValue();
  int maxValue = getGenerator()->getMaxValue();
  ostringstream ss;

  for(int j = 0 ; j < intervalNumber ; j++ )
    intervals[j] = 0;

  int range = getGenerator()->getMaxValue() - getGenerator()->getMinValue();
  int step = range / intervalNumber;

  for(int i = 0 ; i < getSampling() ; i++){
    array[i] = getGenerator()->toGenerate();
      for(int j = 0 ; j < intervalNumber ; j++ )
        if ((array[i] > j * step + minValue ) && (array[i] < (j+1) * step + minValue))
          intervals[j]++;
  }

  ss << "Generator " << getGenerator()->getGeneratorName() << " gave me numbers:\n";
  for (int i = 0 ; i < sampling ; i++ ){
    ss << array[i] << "   ";
    if ((i+1) % 5 == 0)
      ss << endl;
  }
  ss << "I have " << intervalNumber << " intervals:\n";
  for(int j = 0 ; j < intervalNumber ; j++ )
    ss << "[" << j * step + minValue << " - " << (j+1) * step + minValue << "]"<< " have " << intervals[j] << " numbers.\n";
  addInResultText(ss.str());

}
// -------------------------------------------------------------------------

void IntervalTest::printResult(ostream& out) {

  out << endl <<"//----------------------------------//" << endl;
  out << "Hello, I'm IntervalTest." << endl;
  out << getResult();
  out << "//----------------------------------//" << endl;

}
// -------------------------------------------------------------------------
