/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: div_zero_err.h
* Purpose: Header file for the Div_Zero_Err class
*/

#ifndef DIV_ZERO_ERR_H
#define DIV_ZERO_ERR_H

/* CLASS: Div_Zero_Err
     PURPOSE: An error class to be thrown when division by zero is attempted
     MEMBER VARIABLES: divisor - the numerator of the fraction that caused
       division by zero
*/
template <class T>
class Div_Zero_Err
{
  public:
    /* 
      CONSTRUCTOR: Div_Zero_Err(T error_value)
        Input: int error_value - the value used in an attempt to divide by zero
      PRE: None
      POST: Sets divisor equal to error_value
      PURPOSE: The constructor for this error class.  Takes the offending
                 variable and uses it to construct an instance of the class
    */
    Div_Zero_Err(T error_value);
    /* 
      DESTRUCTOR: ~Div_Zero_Err()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers are involved, this empty function 
                 makes the class more scalable.
    */
    ~Div_Zero_Err();

    /* 
      FUNCTION: T bad_divisor()
      PRE: None
      POST: Passes the error-causing variable to the caller.
      RETURNS: A numeric value originally attempted to be used as the divisor
                 in an equation that included division by zero.
    */
    T bad_divisor();

  private:
    T divisor; // The numerator (divisor) in an equation that divided by zero
};
#include "div_zero_err.hpp"
#endif // DIV_ZERO_ERR_H
