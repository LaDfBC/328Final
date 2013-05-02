#include <iostream>

template <class T>
Domain_Err<T>::Domain_Err(short a_matrix_size, short b_vector_size)
{
  matrix_size = a_matrix_size;
  vector_size = b_vector_size;
}

template <class T>
Domain_Err<T>::~Domain_Err()
{
}

template <class T>
short Domain_Err<T>::bad_matrix_size()
{
  return matrix_size;
}

template <class T>
short Domain_Err<T>::bad_vector_size()
{
  return vector_size;
}