#ifndef ANALYZER_H
#define ANALYZER_H

class Analyzer
{
  public:
    Analyzer();
    ~Analyzer();
    void start();
    void stop();
    
  private:
    unsigned short runtime;
};

#include "analyzer.hpp"
#endif