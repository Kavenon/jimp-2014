#include "Test.h"
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
  generator = _generator;
}
// -------------------------------------------------------------------------

void Test::setResultText(string _result) {
  result = _result;
}
// -------------------------------------------------------------------------

void Test::setSampling(int _sampling) {
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
