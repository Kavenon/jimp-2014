#include "DefaultGenerator.h"
// -------------------------------------------------------------------------

DefaultGenerator::DefaultGenerator() {
  setGeneratorName("\"DefaultGenerator\"");
}
// -------------------------------------------------------------------------

DefaultGenerator::~DefaultGenerator() {

}
// -------------------------------------------------------------------------

int DefaultGenerator::toGenerate() {

  srand(getSeed());
  setSeed(getMinValue() + rand() % getMaxValue());
  while((getSeed() > getMaxValue()) || (getSeed() < getMinValue()))
    setSeed(getMinValue() + rand() % getMaxValue());
  print(cout);
  return getSeed();

}
// -------------------------------------------------------------------------
