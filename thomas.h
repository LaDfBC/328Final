/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: thomas.h
* Purpose: Header file for the Thomas Functor. 
*   (The purpose of this is to implement the Thomas Algorithm to solve
*    systems of equations represented by a tridiagonal matrix)
*/

#ifndef THOMAS_H
#define THOMAS_H
#include "tridiagonal_matrix.h"
#include "diagonal_dominance_err.h"
#include "diagonal_err.h"

/*
  CLASS: Thomas
  MEMBER VRIABLES: m_member_matrix - a system of equations stored in matrix 
    form - make sure it is tridiagonal!
                   m_member_b_vector - the "answers" to the system of
    equations - the numbers on the right hand side of the equal sign
  PRE: Refer to the constructor and operator preconditions for required 
    functions in the templated class that this functor uses.  Remember that
    the input matrix must be tridiagonal and diagonally dominant!
  PURPOSE: Provide a functor that will carry out the mathematical process
    called the Thomas Algorithm.  This process is carried out
    by calling the () operator.
*/
template <class T, class U>
class Thomas
{
  public:
    /*
      CONSTRUCTOR: Thomas(const T& input_matrix, const U& input_b_vector)
        Input: input_matrix - the matrix portion of the system of equations
          to be solved by the Thomas Algorithm
               input_b_vector - the vector portion of the system of equations
          to be solved by the Thomas Algorithm.  This stores the "answers" or
          right hand side of the system when viewwed on paper.
      PRE: Both the matrix and vector must have bracket operators for element
        access defined for the functor to be able to function.  Additionally,
        the matrix must have get_number_of_rows() and get_number_of_columns()
        functions defined to return the number of rows and columns in the 
        matrix, respectively.  The matrix must be tridiagonal.
      PURPOSE: Serve as the constructor for the Thomas class. Takes in a matrix
        and B-Vector and sets both member variables equal, respectively.
    */
    Thomas(const T& input_matrix, const U& input_b_vector);

    /* 
      OPERATOR: operator()()
        Output: The vector representing the solution to the system of equations
      PRE: The vector (U) must have a size() function to return the number of 
        elements currently stored in the vector.  The matrix (T) must have a 
        get_number_of_rows() function to return the number of rows currently
        in the matrix.
      POST:  Returns the solution to the system of equations in the form of a 
        vector with each element in the vector representing a number for a
        variable that would solve the system, in successive order.
      PURPOSE: Return the solution to the system of linear equations stored in
        the member matrix using the Thomas Algorithm. The matrix is unchanged 
        in the process.
    */
    U operator()() const;

  private:
    T m_member_matrix;
    U m_member_b_vector;
};

#include "thomas.hpp"
#endif // THOMAS_H