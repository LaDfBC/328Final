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

/*
  This is to set up for the Barton-Nackman Trick.  The last parameter to the
  Solver inheritance includes template parameters for Solver AND Gauss Seidel!
*/
template <class T, class U, class V>
class Gauss_Seidel : public Solver<U, V, 
                                   Solver<U, V, Gauss_Seidel<T, U, V> > >
{
  public:
    Gauss_Seidel(const V& input_matrix, 
                    const U& input_b_vector, 
                    const U& input_x_vector);
    ostream& output_stream(ostream& out) const;
    U& operator()();

  private:
    V m_a_matrix;
    U m_b_vector;
    U m_x_vector;
};

#endif //GAUSS_SEIDEL_H