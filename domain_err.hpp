/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: domain_err.hpp
* Purpose: Implementation file for the Domain_Err class
*/

#include <iostream>
#include "domain_err.h"

template <class T>
Domain_Err<T>::Domain_Err(T a_matrix_size, T b_vector_size)
{
  matrix_size = a_matrix_size;
  vector_size = b_vector_size;
}

template <class T>
Domain_Err<T>::~Domain_Err()
{
}

template <class T>
T Domain_Err<T>::bad_matrix_size()
{
  return matrix_size;
}

template <class T>
T Domain_Err<T>::bad_vector_size()
{
  return vector_size;
}