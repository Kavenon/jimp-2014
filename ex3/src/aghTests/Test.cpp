#include "../aghInclude.h"
// -------------------------------------------------------------------------

const int Test::DEFAULT_SAMPLING = 100;
const int Test::DEFAULT_INTERVAL_NUMBER = 10;

// -------------------------------------------------------------------------

Test::Test() {
}
// -------------------------------------------------------------------------

Test::~Test() {
}
// -------------------------------------------------------------------------

void Test::setGenerator(Generator* _generator) {
  if(_generator == NULL) throw aghException(0, "Generator does not exist", __FILE__, __LINE__);
  generator = _generator;
}
// -------------------------------------------------------------------------

void Test::setResultText(string _result) {
  result = _result;
}
// -------------------------------------------------------------------------

void Test::setSampling(int _sampling) {
  if(_sampling <= 0) throw aghException(0, "Wrong values", __FILE__, __LINE__);
  sampling = _sampling;
}
// -------------------------------------------------------------------------

void Test::setSampling() {
  sampling = DEFAULT_SAMPLING;
}
// -------------------------------------------------------------------------

void Test::setIntervalNumber(int _intervalNumber) {
  intervalNumber = _intervalNumber;
}
// -------------------------------------------------------------------------

void Test::setIntervalNumber() {
  intervalNumber = DEFAULT_INTERVAL_NUMBER;
}
// -------------------------------------------------------------------------

int Test::getSampling() {
  return sampling;
}
// -------------------------------------------------------------------------

int Test::getIntervalNumber() {
  return intervalNumber;
}
// -------------------------------------------------------------------------

string Test::getResult() {
  return result;
}
// -------------------------------------------------------------------------

void Test::addInResultText(string _result) {
  result += _result;
}
// -------------------------------------------------------------------------

Generator* Test::getGenerator() {
  return generator;
}
// -------------------------------------------------------------------------
