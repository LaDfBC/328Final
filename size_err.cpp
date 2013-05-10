/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: size_err.cpp
* Purpose: Implementation file for the Size_Err class
*/

#include "size_err.h"
#include <iostream>

Size_Err::Size_Err(int problem_size)
{
  size = problem_size;
}

Size_Err::~Size_Err()
{
  //If error classes begin to use pointers, this function will be important
}

int Size_Err::bad_size()
{
  return size;
}