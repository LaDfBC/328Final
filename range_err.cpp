/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: range_err.cpp
* Purpose: Implementation file for the Range_Err class
*/

#include "range_err.h"
#include <iostream>

Range_Err::Range_Err(int problem_value)
{
  subscr = problem_value;
}

Range_Err::~Range_Err()
{
  //If error classes begin to use pointers, this function will be important
}

int Range_Err::bad_subscr()
{
  return subscr;
}