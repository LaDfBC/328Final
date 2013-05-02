/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: gaussian_elimination.h
* Purpose: Implementation file for the small class built to approximate
*   differential equations using Gaussian Elimination
*/

#ifndef GAUSSIAN_ELIMINATION_H
#define GAUSSIAN_ELIMINATION_H

#include "solver.h"

template <class T, class U, class V>
class Gaussian_Elimination : public Solver<T, U, V>
{
  public:
    Gaussian_Elimination(const V& input_matrix, 
                         const U& input_b_vector, 
                         const U& input_x_vector);
    ostream& output_stream(ostream& out) const = 0;
    U& operator()();

  private:
    V m_a_matrix;
    U m_b_vector;
    U m_x_vector;
};

#endif //GAUSSIAN_ELIMINATION_H