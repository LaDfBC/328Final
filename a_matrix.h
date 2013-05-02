/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: a_matrix.h
* Purpose: Header file for the functor whose purpose is to create
*   the A-matrix used to estimate Partial Differential Equations
*/

#ifndef A_MATRIX_H
#define A_MATRIX_H

typedef unsigned short matrix_data_type;
#include "symmetric_matrix.h"

template <class T>
class A_Matrix
{
  public:
    A_Matrix(matrix_data_type input_points) : m_num_points(input_points) {};

    Symmetric_Matrix<T> operator()();

  private:
    matrix_data_type m_num_points;
};

#include "a_matrix.hpp"
#endif //A_MATRIX_H