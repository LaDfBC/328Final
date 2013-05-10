/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: gauss_seidel.h
* Purpose: Header file for the class built to approximate
*   differential equations using the Gauss-Seidel method
*/

#ifndef GAUSS_SEIDEL_H
#define GAUSS_SEIDEL_H

#include "solver.h"
#include "l_two_norm.h"
#include "diagonal_dominance_err.h"

/*  The minimum allowed between the two L2 Norm vlues for the algorithm to be
 *  considered complete.  Any number less than .001 is very small and may take
 *  a large number of iterations to complete.
*/
double proximity_threshold = 0.000001;
/*
  CLASS: Gauss_Seidel
  PURPOSE: Implement the Gauss-Seidel Algorithm, the purpose of which is to 
    solve a system of equations.  Gauss-Seidel is an iterative method and an
    improvement on Jacobi Iteration.
  MEMBER VARIABLES: U m_a_matrix - the matrix, with an extra column on the far
    right, representing the B-Vector.  This vector is appended to the matrix
    during construction of the class.
  PRE: This sets up for the Barton-Nackman Trick.  The last parameter to 
    the Solver inheritance includes template parameters for Solver and
    Gauss Seidel!

  TEMPLATES: T - A vector class.
             U - A matrix class.
             V - A partial differential equation class
*/
template <class T, class U, class V>
class Gauss_Seidel : public Solver<T, U, Gauss_Seidel<T, U, V> >
{
  public:
    /*
      CONSTRUCTOR: Gauss_Seidel(const V& input_diffeq)
        Inputs: input_diffeq: the differential equation to be solved.  
      PRE: The differential equation class must store an A-Matrix and 
        a B-Vector set up ready to solve a system of linear equations.  
        Additionally, the matrix stored in the input equation must have element
        accessors defined using the operator() with two parameters, as well as
        functions get_number_of_columns and get_number_of_rows to do the 
        obvious.  The vector must have its accessor defined using operator[].
      PURPOSE: The only Constructor - Must take a fully constructed Partial
        Differential Equation to function correctly.
    */
    Gauss_Seidel(const V& input_diffeq);

    /*
      FUNCTION: T evaluate()
        Output: T - the vector storing the solution to the differential eq.
      PRE: None.  Errors handled within the function or constructor.  To avoid
        common errors, note that Gauss-Seidel must be done on a diagonally
        dominant matrix.
      POST: Returns the solution to the differential equation in the form of
        a vector.  Note that this function is destructive - the matrix 
        will be modified when this function is called!
      PURPOSE: Solve a system of linear equations using the Gauss-Seidel
        iterative method.  Again, note that this function is destructive 
        and does modify the matrix stored in the class
    */
    T evaluate();

  private:
    U m_a_matrix;
};

#include "gauss_seidel.hpp"
#endif //GAUSS_SEIDEL_H