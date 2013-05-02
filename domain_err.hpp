#include <iostream>

Domain_Err::Domain_Err(short a_matrix_size, short b_vector_size)
{
  matrix_size = a_matrix_size;
  vector_size = b_vector_size
}

Domain_Err::~Domain_err()
{
}

short Domain_Err::bad_matrix_size()
{
  return matrix_size;
}

short Domain_Err::bad_vector_size()
{
  return vector_size;
}