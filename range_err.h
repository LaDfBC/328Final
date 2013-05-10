/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: range_err.h
* Purpose: Header file for the Range_Err class
*/

#ifndef RANGE_ERR_H
#define RANGE_ERR_H

/* 
  CLASS: Range_Err
    PURPOSE: The error to be thrown when code indexes a part of an array
      or vector that does not exist. i.e. "Walking off the end"
    MEMBER VARIABLES:
      int subscr: The number (index) originally used to try to reference 
        an index. Thrown and returned to show what number was used.
*/
class Range_Err
{
  public:
    /* 
      CONSTRUCTOR: Range_Err(int error_value)
        Input: int error_value - the value (index!) of an array that would
          not have correctly indexed that array due to size
      PRE: None
      POST: Sets subscr equal to error_value
      PURPOSE: The constructor for this error class.  Takes the offending
        variable and uses it to construct an instance of the class
    */
    Range_Err(int error_value);
    /* 
      DESTRUCTOR: ~Range_Err()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers are involved, this empty function 
        makes the class more scalable.
    */
    ~Range_Err();

    /* 
      FUNCTION: int bad_subscr()
      PRE: None
      POST: Passes the error-causing variable to the caller.
      RETURNS: An integer value originally attempted to be used as an index
        for a position in an array.
    */
    int bad_subscr();

  private:
    int subscr; // The error-causing index variable
};

#endif