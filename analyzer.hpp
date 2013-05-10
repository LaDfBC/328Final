/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: analyzer.hpp
* Purpose: Function definition file for Analyzer.
*/

Analyzer::Analyzer()
{
  runtime = 0;
}

Analyzer::~Analyzer()
{
}

void Analyzer::start()
{
  start_time = clock();
}

unsigned short Analyzer::stop()
{
  return runtime = (clock() - start_time) / CLOCKS_PER_SEC;
}