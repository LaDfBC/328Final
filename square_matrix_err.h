/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: div_zer_err.h
* Purpose: Header file for the Square_Matrix_Err class
*/

#ifndef SQUARE_MATRIX_ERR_H
#define SQUARE_MATRIX_ERR_H

/* CLASS: Square_Matrix_Err
     PURPOSE: An error class to be thrown when a matrix is not square
     MEMBER VARIABLES: first_index - the "rows" or x-length of the
       offending matrix
                       second_index - the "columns" or y-length of the
       offending matrix
*/
template <class T>
class Square_Matrix_Err
{
  public:
    /* 
      CONSTRUCTOR: Square_Matrix_Err(T input_first_index, T input_second_index)
        Input: T input_first_index - the "rows" or x-length of the 
          offending matrix
               T input_second_index - the "columns" or y-length of the 
          offending matrix
      PRE: None
      POST: sets both first_index and second_index equal to their respective
        inputs
      PURPOSE: The constructor for this error class.  Takes the offending
                 variables and uses them to construct an instance of the class
    */
    Square_Matrix_Err(T input_first_index, T input_second_index);
    /* 
      DESTRUCTOR: ~Square_Matrix_Err()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers are involved, this empty function 
                 makes the class more scalable.
    */
    ~Square_Matrix_Err();

    /* 
      FUNCTION: T bad_first_index()
      PRE: None
      POST: Passes the x-position variable to the caller
      RETURNS: A numeric value originally attempted to be used as the "rows" 
        or x-length of a matrix
    */
    T bad_first_index();

    /* 
      FUNCTION: T bad_second_index()
      PRE: None
      POST: Passes the y-position variable to the caller
      RETURNS: A numeric value originally attempted to be used as the "columns" 
        or y-length of a matrix
    */
    T bad_second_index();


  private:
    T first_index; // X point
    T second_index; // Y point
};
#include "square_matrix_Err.hpp"
#endif // SQUARE_MATRIX_ERR_H
