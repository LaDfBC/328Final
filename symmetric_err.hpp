/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: div_zero_err.hpp
* Purpose: Implementation file for the Div_Zero_Err class
*/

#include "symmetric_err.h"
#include <iostream>

template <class T>
Symmetric_Err<T>::Symmetric_Err(T error_value)
{
  non_symmetric_index = error_value;
}

template <class T>
Symmetric_Err<T>::~Symmetric_Err()
{
  //If error classes begin to use pointers, this function will be important
}

template <class T>
T Symmetric_Err<T>::bad_symmetry()
{
  return non_symmetric_index;
}