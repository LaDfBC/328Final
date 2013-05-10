/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: div_zero_err.hpp
* Purpose: Implementation file for the Div_Zero_Err class
*/

#include "div_zero_err.h"
#include <iostream>

template <class T>
Div_Zero_Err<T>::Div_Zero_Err(T error_value)
{
  divisor = error_value;
}

template <class T>
Div_Zero_Err<T>::~Div_Zero_Err()
{
  //If error classes begin to use pointers, this function will be important
}

template <class T>
T Div_Zero_Err<T>::bad_divisor()
{
  return divisor;
}