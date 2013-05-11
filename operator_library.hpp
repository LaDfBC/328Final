/*
* Programmer: George Mausshardt and Matt Lindsay
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

template <class T, class U, class V, class DerivedSolver>
ostream& operator<<(ostream& out, 
                      const Solver<U, V, DerivedSolver>& input_solver)
{
  return input_solver.output_stream(out);
}

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
ostream& operator<<(ostream& out, const Partial_DiffEQ<T, U, V, 
                                                       Top_Function, 
                                                       Left_Function, 
                                                       Right_Function, 
                                                       Bottom_Function>& input_diffeq)
{
  return input_diffeq.output_stream(out);
}

double Poisson_Top(double x)
{
  return x * x * x;
}

double Poisson_Bottom(double x)
{
  return x * x * x;
}

double Poisson_Left(double)
{
  return 0;
}

double Poisson_Right(double)
{
  return 1;
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

