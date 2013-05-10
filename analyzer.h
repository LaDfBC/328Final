/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: analyzer.h
* Purpose: Header file for the analyzer class
*/

#ifndef ANALYZER_H
#define ANALYZER_H

#include <ctime>
/* 
  CLASS: Analyzer -an implementation of a timing class used to measure runtime
  MEMBER VARIABLES:
    start_time - used to know when the timing started
    runtime - the length of time between calls of start and stop, in seconds
  PRE: Make an analyzer object, and call start when you want to start timing
    and call stop when you want to stop timing.
  PURPOSE: Define a simple-to-use timer class.
*/
class Analyzer
{
  public:
    /*
      CONSTRUCTOR: Analyzer() 
      PRE: None
      POST: Sets runtime to 0.
      PURPOSE: Default constructor.  Initializes the timer to start at 0.
    */
    Analyzer();
    /*
      DESTRUCTOR: ~Analyzer() 
      PRE: None
      POST: Deletes the Analyzer object.
      PURPOSE: Destroy.
    */
    ~Analyzer();
    /*
      FUNCTION: start() 
      PRE: None
      POST: Sets the start time to the current time.
      PURPOSE: Begin timing.
    */
    void start();
    /*
      FUNCTION: stop() 
      PRE: start has been called prior to this call.
      POST: Returns the time from the last start call to this call.
      PURPOSE: Stop timing and return the runtime.
    */
    unsigned short stop();
    
  private:
    clock_t start_time;
    unsigned short runtime;
};

#include "analyzer.hpp"
#endif