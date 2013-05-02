/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: size_difference_err.h
* Purpose: Header file for the Size_Difference_Err class
*/

#ifndef SIZE_DIFFERENCE_ERR_H
#define SIZE_DIFFERENCE_ERR_H

/* CLASS: Size_Difference_Err
     PURPOSE: An error class to be thrown when mathematical operations are
       attempted between two vectors of different sizes
     MEMBER VARIABLES: first_size - the size of the first vector in the failed
       operation
                       second_size - the size of the second vector in the
       failed operation
*/
class Size_Difference_Err
{
  public:
    /* 
      CONSTRUCTOR: Size_Difference_Err(unsigned short const input_first_size,
                                       unsigned short const input_second_size);
        Input: unsigned short const input_first_size - the length of the first
          vector involved in the failed mathematical operation
               unsigned short const input_second_size - the length of the 
          second vector involved in the failed mathematical operation
      PRE: The two sizes should be greater than or equal to 0. No error is
        thrown if they are not, since constructors should make this check
        instead! Be careful when implementing classes with a size variable!
      POST: sets first_size equal to input_first_size and second_size equal
        to input_second_size
      PURPOSE: The constructor for this error class.  Takes the offending
                 variables and uses them to construct an instance of the class
    */
    Size_Difference_Err(unsigned short const input_first_size, 
                        unsigned short const input_second_size);
    /* 
      DESTRUCTOR: ~Size_Difference_Err()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers become involved, this empty function
                 makes the class more easily scalable.
    */
    ~Size_Difference_Err();

    /* 
      FUNCTION: unsigned short bad_first_size()
      PRE: None
      POST: Passes the first error-causing size variable to the caller.
      RETURNS: A numeric value originally representing the number of elements
                 in a vector used in an equation with another vector of a
                 different number of elements.
    */
    unsigned short bad_first_size();

    /* 
      FUNCTION: unsigned short bad_second_size()
      PRE: None
      POST: Passes the second error-causing size variable to the caller.
      RETURNS: A numeric value originally representing the number of elements
                 in a vector used in an equation with another vector of a
                 different number of elements.
    */
    unsigned short bad_second_size();

  private:
    unsigned short first_size;
    unsigned short second_size;
};

#endif // SIZE_DIFFERENCE_ERR_H
