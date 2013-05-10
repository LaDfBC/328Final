/* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: domain_err.hpp
* Purpose: Header file for the Domain_Err class
*/

#ifndef DOMAIN_ERR_H
#define DOMAIN_ERR_H


/* CLASS: Header_Err
     PURPOSE: An error class to be thrown inputs to a differential equation
       are incorrect or poorly formatted
     MEMBER VARIABLES: matrix_size - the size of the offending A-Matrix
       vector_size - the size of the offending B-Vector
*/
template<class T>
class Domain_Err
{
  public:
    /* 
      CONSTRUCTOR: Domain_Err(T a_matrix_size, T b_vector_size)
        Input: T a_matrix_size - the (incorrect) size of the input matrix
               T b_vector_size - the (incorrect) size of the input vector
      PRE: None
      POST: Sets matrix_size and vector_size equal to their corresponding
        input parameters
      PURPOSE: The constructor for this error class.  Takes the offending
                 variables and uses them to construct an instance of the class
    */
    Domain_Err(T a_matrix_size, T b_vector_size);

    /* 
      DESTRUCTOR: ~Domain_Err()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers are involved, this empty function 
                 makes the class more scalable.
    */
    ~Domain_Err();

    /* 
      FUNCTION: T bad_matrix_size()
      PRE: None
      POST: Passes the incorrect matrix size back to the caller
      RETURNS: A numeric value originally used as the size of a matrix
                 that could not be correctly used in a differential equation
    */
    T bad_matrix_size();

    /* 
      FUNCTION: T bad_vector_size()
      PRE: None
      POST: Passes the incorrect vector size back to the caller
      RETURNS: A numeric value originally used as the size of a vector
                 that could not be correctly used in a differential equation
    */
    T bad_vector_size();

  private:
    T matrix_size;
    T vector_size;
};

#include "domain_err.hpp"
#endif // DOMAIN_ERR_H