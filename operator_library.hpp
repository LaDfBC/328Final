/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: operator_library.hpp
* Purpose: Implementation file for the operators that are used
*   in many of the matrices and cannot be inherited, due to forcibly being
*   friend functions or taking two classes to execute
*/

#include "operator_library.h"

template <class T>
ostream& operator<<(ostream& out, const Matrix_Base<T>& input_matrix)
{
  return input_matrix.output_stream(out);
}

template <class T>
istream& operator>>(istream& in, Matrix_Base<T>& input_matrix)
{
  return input_matrix.input_stream(in);
}

template <class T>
Matrix_Base<T>& operator+=(Matrix<T>& calling_matrix,
                           const Matrix<T>& right_hand_side)
{
  return calling_matrix.plus_equals(right_hand_side);
}

template <class T>
Matrix_Base<T>& operator-=(Matrix<T>& calling_matrix,
                           const Matrix<T>& right_hand_side)
{
  return calling_matrix.minus_equals(right_hand_side);
}
