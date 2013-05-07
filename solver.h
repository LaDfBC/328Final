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

template <class U, class V, class DerivedSolver>
class Solver
{
  public:

    DerivedSolver& as_derived() 
    {
      return static_cast<DerivedSolver>(*this);
    }

    ostream& output_stream(ostream& out) const
    {
      return as_derived(output_stream(out));
    }

    int get_convergence_speed()
    {
      return as_derived(get_convergence_speed());
    }

    U& evaluate()
    {
      return as_derived(evaluate());
    }

  private:
    V m_a_matrix;
    U m_b_vector;
    U m_x_vector;
    int m_convergence_speed;
};

#endif //SOLVER_H