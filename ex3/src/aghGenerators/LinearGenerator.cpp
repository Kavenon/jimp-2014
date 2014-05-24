#include "../aghInclude.h"
// -------------------------------------------------------------------------

LinearGenerator::LinearGenerator() {
  setGeneratorName("\"LinearGenerator\"");
}
// -------------------------------------------------------------------------

LinearGenerator::~LinearGenerator() {
}
// -------------------------------------------------------------------------

int LinearGenerator::toGenerate() {

  setSeed(myRand());
  while((getSeed() > getMaxValue()) || (getSeed() < getMinValue()))
    setSeed(myRand());
  print(std::cout);
  return getSeed();
}
// -------------------------------------------------------------------------

int LinearGenerator::myRand(){
  // ax + b
  // where x = seed, a = variableA, b = variableB
  return getMinValue() + (getVariableA() * getSeed() + getVariableB()) % getMaxValue();
}
// -------------------------------------------------------------------------
