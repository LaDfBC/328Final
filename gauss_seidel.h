/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: gauss_seidel.h
* Purpose: Header file for the small class built to approximate
*   differential equations using Gauss-Seidel
*/

#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

#include "solver.h"
#include "l_two_norm.h"

double proximity_threshold = 0.000001;
/*
  This is to set up for the Barton-Nackman Trick.  The last parameter to the
  Solver inheritance includes template parameters for Solver AND Gauss Seidel!
*/
template <class T, class U, class V>
class Gauss_Seidel : public Solver<T, U, Gauss_Seidel<T, U, V> >
{
  public:
    Gauss_Seidel(const V& input_diffeq);
    T evaluate();

  private:
    U m_a_matrix;
};

#include "gauss_seidel.hpp"
#endif //GAUSS_SEIDEL_H