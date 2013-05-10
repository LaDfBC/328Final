/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: diagonal_dominance_err.h
* Purpose: Header file for the Diagonal_Dominance_Err class
*/

#ifndef DIAGONAL_DOMINANCE_ERR_H
#define DIAGONAL_DOMINANCE_ERR_H

/* 
  CLASS: Diagonal_Dominance_Err
  PURPOSE: An error class to be thrown when a Jacobi Iteration or Gauss_Seidel
    process is attempted and the matrix to be used is not diagonally dominant
  MEMBER VARIABLES: diagonal_value - the number in the diagonal of the matrix
    that was less than or equal to the sum of the other numbers in the same row
                    bad_total_value - the sum of the numbers in the row that
    are greater than the number in the diagonal
*/
template <class T>
class Diagonal_Dominance_Err
{
  public:
    /* 
      CONSTRUCTOR:Diagonal_Dominance_Err(T input_total, T input_diagonal_value)
        Input: input_total - the sum of all numbers other than the one in the 
          diagonal
               diagonal_value - the number in the diagonal of the offending 
          matrix
      PRE: None
      POST: Sets diagonal_value equal to input_diagonal_value and 
        bad_total_value equal to input_total
      PURPOSE: The constructor for this error class.  Takes the offending
                 variables and uses them to construct an instance of the class
    */
    Diagonal_Dominance_Err(T input_total, T input_diagonal_value);
    /* 
      DESTRUCTOR: ~Diagonal_Dominance_Err()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers are involved, this empty function 
                 makes the class more scalable.
    */
    ~Diagonal_Dominance_Err();

    /* 
      FUNCTION: T bad_diagonality()
      PRE: None
      POST: Passes the difference between the total value and the diagonal
        value back to the caller
      PURPOSE: Returns the difference between the total value and the diagonal
        value back to the caller. Delivers a useful error message back to the
        function that originally caused the error.
    */
    T bad_diagonality();

  private:
    T diagonal_value;
    T bad_total_value;
};
#include "diagonal_dominance_err.hpp"
#endif // DIAGONAL_DOMINANCE_ERR_H
