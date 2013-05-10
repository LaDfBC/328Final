/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: singular_err.h
* Purpose: Header file for the Singular_Err class
*/

#ifndef SINGULAR_ERR_H
#define SINGULAR_ERR_H

/* CLASS: Singular_Err
     PURPOSE: An error class to be thrown when a matrix representation of
       a system of linear equations contains a row of all zeroes, meaning
       that the system does not have a certain solution
     MEMBER VARIABLES: error_row - the row in the matrix that contains
       only zeroes
*/

class Singular_Err
{
  public:
    /* 
      CONSTRUCTOR: Singular_Err(long input_error_row)
        Input: int error_value - the value used in an attempt to divide by zero
      PRE: None
      POST: Sets divisor equal to error_value
      PURPOSE: The constructor for this error class.  Takes the offending
                 variable and uses it to construct an instance of the class
    */
    Singular_Err(long error_value);
    /* 
      DESTRUCTOR: ~Singular_Err()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers are involved, this empty function 
                 makes the class more scalable.
    */
    ~Singular_Err();

    /* 
      FUNCTION: long bad_row()
      PRE: None
      POST: Passes the error-causing row to the caller.
      RETURNS: A numeric value originally attempted to be used as row index
                 in a matrix holding a system of linear equations with no
                 single solution
    */
    long bad_row();

  private:
    long error_row;
};
#endif // SINGULAR_ERR_H
