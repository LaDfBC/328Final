/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: size_err.h
* Purpose: Header file for the Size_Err class
*/

#ifndef SIZE_ERR_H
#define SIZE_ERR_H

/* 
  CLASS: Size_Err
    PURPOSE: The error to be thrown when code attempts to define an array
      or vector of size less than 0
    MEMBER VARIABLES:
      int size: The number originally attempted to be used as the size of an
      array or vector. Thrown and returned to show what number was used.
*/
class Size_Err
{
  public:
    /* 
      CONSTRUCTOR: Size_Err(int problem_size)
        Input: int problem_siez - the value originally to be used as the size
          of an array that would not have been undefined
      PRE: None
      POST: Sets size equal to problem_size
      PURPOSE: The constructor for this error class.  Takes the offending
        variable and uses it to construct an instance of the class
    */
    Size_Err(int error_value);
    /* 
      DESTRUCTOR: ~Size_Err()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers are involved, this empty function 
        makes the class more scalable.
    */
    ~Size_Err();

    /* 
      FUNCTION: int bad_size()
      PRE: None
      POST: Passes the error-causing variable to the caller.
      RETURNS: An integer value originally attempted to be used as the size
        of an array or vector
    */
    int bad_size();

  private:
    int size; // The error-causing index variable
};

#endif // SIZE_ERR_H