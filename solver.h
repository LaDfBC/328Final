/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: solver.h
* Purpose: Header file for the base class representing any number of
* differential equation approximaters
*/

#ifndef SOLVER_H
#define SOLVER_H

#include "operator_library.h"

template <class T, class U, class V>
class Solver
{
  public:
    ostream& output_stream(ostream& out) const = 0;
    int get_convergence_speed() = 0;
    U& operator()() = 0;

  private:
    V m_a_matrix;
    U m_b_vector;
    U m_x_vector;
    int m_convergence_speed;
};

#endif //SOLVER_H