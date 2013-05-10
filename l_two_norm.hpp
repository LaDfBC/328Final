/*
* Programmer: George Mausshardt
* Date: 04/05/2013
* FileName: matrix.hpp
* Purpose: Implementation file for the L_One_Norm Function
*   (This functor returns the L-1 Norm of a vector.)
*/

#include "l_two_norm.h"

template <class T>
L_Two_Norm<T>::L_Two_Norm(const T& input_vector)
{
  m_target_vector = input_vector;
}

template <class T>
double L_Two_Norm<T>::operator()() const
{
  double running_total = 0.0;
  for (unsigned short i = 0; i < m_target_vector.size(); i++)
  {
    running_total += pow(m_target_vector[i], 2);
  }

  return sqrt(running_total);
}