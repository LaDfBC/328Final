/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: square_matrix_err.hpp
* Purpose: Implementation file for the Square_Matrix_Err class
*/

#include "square_matrix_err.h"
#include <iostream>

template <class T>
Square_Matrix_Err<T>::Square_Matrix_Err(T input_first_index,
                                        T input_second_index)
{
  first_index = input_first_index;
  second_index = input_second_index;
}

template <class T>
Square_Matrix_Err<T>::~Square_Matrix_Err()
{
  //If error classes begin to use pointers, this function will be important
}

template <class T>
T Square_Matrix_Err<T>::bad_first_index()
{
  return first_index;
}

template <class T>
T Square_Matrix_Err<T>::bad_second_index()
{
  return second_index;
}