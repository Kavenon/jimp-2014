/**
* \file main.cpp
* \author Artem Mensk & Kamil Chlebek
* \date 20.05.2014
* \version 1.0
* \brief Definition of main.cpp. Main run program
*/
// -------------------------------------------------------------------------

#include "aghInclude.h"

// -------------------------------------------------------------------------
int main(){

  ofstream fout("results.txt");

  vector<Generator*> generators;
  generators.push_back(new DefaultGenerator());
  generators.push_back(new LinearGenerator());
  generators.push_back(new QuadraticGenerator());

  vector<Test*> tests;
  tests.push_back(new ParityTest());
  tests.push_back(new IntervalTest());
  tests.push_back(new SeriesTest());

  for(unsigned int j = 0 ; j < generators.size() ; j++ )
    for(unsigned int i = 0 ; i < tests.size() ; i++ ){

      generators.at(j)->setSeed();                   // if brackets are empty seed has default value ( time(NULL); )
      generators.at(j)->setRange();                  // if brackets are empty range has default value [ 0 ; max integer in system ]
      generators.at(j)->setVariables();              // if brackets are empty variables have default value
      tests.at(i)->setGenerator(generators.at(j));   // a = 16807, b = 21, c = 888
      tests.at(i)->setSampling();                    // if brackets are empty sampling have default value = 100
      tests.at(i)->setIntervalNumber();              // if brackets are empty interval number have default value = 10
      tests.at(i)->runTest();
      cout << endl;
      tests.at(i)->printResult(cout);
      tests.at(i)->printResult(fout);

    }

  fout.close();
  cout << "end." << endl;
  return 0;
}
// -------------------------------------------------------------------------
