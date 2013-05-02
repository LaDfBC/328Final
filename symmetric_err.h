/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: div_zer_err.h
* Purpose: Header file for the Div_Zero_Err class
*/

#ifndef SYMMETRIC_ERR_H
#define SYMMETRIC_ERR_H

/* CLASS: Symmetric_Err
     PURPOSE: An error class to be thrown when a symmetric matrix does not have
       matching (symmetric) values across the diagonal axis
     MEMBER VARIABLES: non_symmetric_index - the value that caused a matrix to
       be non-symmetric. The upper value is thrown.
*/
template <class T>
class Symmetric_Err
{
  public:
    /* 
      CONSTRUCTOR: Symmetric_Err(T error_value)
        Input: int error_value - the index of a non-symmetric element in a
          matrix.
      PRE: None
      POST: Sets non_symmetric_index equal to error_value
      PURPOSE: The constructor for this error class.  Takes the offending
                 variable and uses it to construct an instance of the class
    */
    Symmetric_Err(T error_value);
    /* 
      DESTRUCTOR: ~Symmetric_Err()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers are involved, this empty function 
                 makes the class more scalable.
    */
    ~Symmetric_Err();

    /* 
      FUNCTION: T bad_symmetry()
      PRE: None
      POST: Passes the error-causing variable to the caller.
      RETURNS: A numeric value originally attempted to be used as the index
                 in a matrix that was not symmetric
    */
    T bad_symmetry();

  private:
    T non_symmetric_index; // The offending index in a non-symmetric matrix
};
#include "symmetric_err.hpp"
#endif // SYMMETRIC_ERR_H
