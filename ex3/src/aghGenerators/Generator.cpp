#include "../aghInclude.h"
// -------------------------------------------------------------------------

const int Generator::DEFAULT_MIN_VALUE = 1;
const int Generator::DEFAULT_VARIABLE_A = 16807;
const int Generator::DEFAULT_VARIABLE_B = 21;
const int Generator::DEFAULT_VARIABLE_C = 888;
// -------------------------------------------------------------------------

int Generator::getSeed() {
  return seed;
}
// -------------------------------------------------------------------------

int Generator::getMinValue() {
  return minValue;
}
// -------------------------------------------------------------------------

int Generator::getMaxValue() {
  return maxValue;
}
// -------------------------------------------------------------------------

int Generator::getVariableA() {
  return variableA;
}
// -------------------------------------------------------------------------

int Generator::getVariableB() {
  return variableB;
}
// -------------------------------------------------------------------------

int Generator::getVariableC() {
  return variableC;
}
// -------------------------------------------------------------------------

void Generator::setSeed() {
  seed = time(NULL);
}
// -------------------------------------------------------------------------

void Generator::setRange() {
  minValue = DEFAULT_MIN_VALUE;
  maxValue = std::numeric_limits<int>::max();

  if(maxValue > minValue) throw aghException(0, "Wrong values", __FILE__, __LINE__);
}
// -------------------------------------------------------------------------

void Generator::setVariables() {
  variableA = DEFAULT_VARIABLE_A;
  variableB = DEFAULT_VARIABLE_B;
  variableC = DEFAULT_VARIABLE_C;
}
// -------------------------------------------------------------------------

void Generator::setSeed(int _seed) {
  seed = _seed;
}
// -------------------------------------------------------------------------

void Generator::setRange(int _minValue, int _maxValue) {
  minValue = _minValue;
  maxValue = _maxValue;
}
// -------------------------------------------------------------------------

void Generator::setVariables(int _variableA, int _variableB, int _variableC) {
  variableA = _variableA;
  variableB = _variableB;
  variableC = _variableC;
}
// -------------------------------------------------------------------------

std::string& Generator::getGeneratorName() {
  return generatorName;
}
// -------------------------------------------------------------------------

void Generator::setGeneratorName(std::string _generatorName) {
  generatorName = _generatorName;
}
// -------------------------------------------------------------------------

void Generator::print(std::ostream& out){
  out << getSeed() << "   ";
}
// -------------------------------------------------------------------------
