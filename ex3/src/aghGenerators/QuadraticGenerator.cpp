#include "../aghInclude.h"
// -------------------------------------------------------------------------

QuadraticGenerator::QuadraticGenerator() {
  setGeneratorName("\"QuadraticGenerator\"");
}
// -------------------------------------------------------------------------

QuadraticGenerator::~QuadraticGenerator() {
}
// -------------------------------------------------------------------------

int QuadraticGenerator::toGenerate() {

  setSeed(myRand());
  while((getSeed() > getMaxValue()) || (getSeed() < getMinValue()))
    setSeed(myRand());
  print(std::cout);
  return getSeed();

}
// -------------------------------------------------------------------------

int QuadraticGenerator::myRand(){
  // ax^2 + bx + c
  // where x = seed, a = variableA, b = variableB, c = variableC
  return getMinValue() + (getVariableA() * (int)pow(getSeed(),2) + getVariableB() * getSeed() + getVariableC()) % getMaxValue();
}
// -------------------------------------------------------------------------
