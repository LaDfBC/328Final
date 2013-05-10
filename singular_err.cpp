/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: singular_err.hpp
* Purpose: Implementation file for the Singular_Err class
*/

#include "singular_err.h"
#include <iostream>

Singular_Err::Singular_Err(long input_error_row)
{
  error_row = input_error_row;
}

Singular_Err::~Singular_Err()
{
  //If error classes begin to use pointers, this function will be important
}

long Singular_Err::bad_row()
{
  return error_row;
}