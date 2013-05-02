/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: size_difference_err.hpp
* Purpose: Implementation file for the Size_Difference_Err class
*/

#include "size_difference_err.h"
#include <iostream>

Size_Difference_Err::Size_Difference_Err(unsigned short const input_first_size, 
                                        unsigned short const input_second_size)
{
  first_size = input_first_size;
  second_size = input_second_size;
}

Size_Difference_Err::~Size_Difference_Err()
{
  //If error classes begin to use pointers, this function will be important
}

unsigned short Size_Difference_Err::bad_first_size()
{
  return first_size;
}

unsigned short Size_Difference_Err::bad_second_size()
{
  return second_size;
}