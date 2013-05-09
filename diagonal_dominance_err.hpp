/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: diagonal_dominance_err.hpp
* Purpose: Implementation file for the Diagonal_Dominance_Err class
*/

#include "diagonal_dominance_err.h"

template <class T>
Diagonal_Dominance_Err<T>::Diagonal_Dominance_Err(
  T input_total, T input_diagonal_value)
{
  diagonal_value = input_diagonal_value;
  bad_total_value = input_total;
}

template <class T>
Diagonal_Dominance_Err<T>::~Diagonal_Dominance_Err()
{
  //If error classes begin to use pointers, this function will be important
}

template <class T>
T Diagonal_Dominance_Err<T>::bad_diagonality()
{
  return (diagonal_value - bad_total_value);
}