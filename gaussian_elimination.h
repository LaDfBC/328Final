/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: gaussian_elimination.h
* Purpose: Implementation file for the class built to approximate
*   differential equations using Gaussian Elimination
*/

#ifndef GAUSSIAN_ELIMINATION_H
#define GAUSSIAN_ELIMINATION_H

#include "solver.h"

template <class T, class U, class V>
class Gaussian_Elimination : public Solver<T, U, 
                                              Gaussian_Elimination<T, U, V> >
{
  public:
    Gaussian_Elimination(const V& input_diffeq);
    T evaluate();

  private:
    U m_a_matrix;
    T m_b_vector;
};

#include "gaussian_elimination.hpp"
#endif //GAUSSIAN_ELIMINATION_H