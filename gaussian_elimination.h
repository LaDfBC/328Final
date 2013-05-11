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
#include "singular_err.h"

/*
  CLASS: Gaussian_Elimination
  PURPOSE: Implement the Gaussian Elimination Algorithm, the purpose of which
    is to solve a system of equations.  Gaussian Elimination is a pivot method 
    commonly used for this purpose.
  MEMBER VARIABLES: U m_a_matrix - the matrix storing the data for the system
    of equations.  
                    T m_b_vector - The vector storing the right side values of
    the system of equations.
  PRE: This sets up for the Barton-Nackman Trick.  The last parameter to 
    the Solver inheritance includes template parameters for Solver and
    Gauss Seidel!

  TEMPLATES: T - A vector class.
             U - A matrix class.
             V - A partial differential equation class
*/
template <class T, class U, class V>
class Gaussian_Elimination : public Solver<T, U, 
                                              Gaussian_Elimination<T, U, V> >
{
  public:
    /*
      CONSTRUCTOR: Gaussian_Elimination(const V& input_diffeq)
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
    Gaussian_Elimination(const V& input_diffeq);

    /*
      FUNCTION: T evaluate()
        Output: T - the vector storing the solution to the differential eq.
      PRE: None.  Errors handled within the function or constructor. 
      POST: Returns the solution to the differential equation in the form of
        a vector.  Note that this function is destructive - the matrix 
        will be modified when this function is called!
      PURPOSE: Solve a system of linear equations using Gaussian Elimination.
        Again, note that this function is destructive and does modify the 
        matrix stored in the class.
    */
    T evaluate();

  private:
    U m_a_matrix;
    T m_b_vector;
};

#include "gaussian_elimination.hpp"
#endif //GAUSSIAN_ELIMINATION_H