/*
* Programmer: George Mausshardt
* Date: 04/05/2013
* FileName: matrix.hpp
* Purpose: Implementation file for the L_Two_Norm Functor
*   (This functor returns the L-2 Norm of a vector.)
*/

#ifndef L_TWO_NORM_H
#define L_TWO_NORM_H

#include <cmath>
/* CLASS: L_One_Norm
   MEMBER VARIABLES: m_target_vector - the vector whose L2 Norm will be 
     found and returned
   PRE: m_target_vector must have an element-finding bracket operator
     defined
   PURPOSE: Be able to take in a vector and thereafter be able to be
     passed to different parts of the code, delivering the L2 Norm of the
     member vector wherever it is required. 
*/  
template <class T>
class L_Two_Norm
{
  public:
     /*
      CONSTRUCTOR: L_Two_Norm(const T& input_vector)
        Input: input_vector - the vector, stored as m_target_vector to be
          used in the calculation of the L2 Norm by the () operator in this
          class.
      PRE: The input_vector (stored as T) used in this functor needs to
        have a bracket operator for retrievl of elements for the functor 
        to work correctly.
      PURPOSE: Serve as a constructor for the L_Two_Norm class. The vector
        passed to this constructor is the one whose L2 Norm is returned in
        the () operator.
    */
    L_Two_Norm(const T& input_vector);

    /*
      OPERATOR: operator()()
      PRE: m_target_vector must have a bracket operator defined to access
        elements and throw errors if no element exists at an index.
      POST: Outputs the L2 Norm of m_target_vector.  This norm is defined as
        the root of the sum of the squares
      PURPOSE: Return the L2 Norm of the m_target_vector. This is the bread
        and butter of the functor
    */
    //REQUIRES THAT T HAS A .size() FUNCTION IMPLEMENTED, TO DO THE OBVIOUS
    //  (As well as bracket operators)
    double operator()() const;

  private:
    T m_target_vector;
};

#include "l_two_norm.hpp"
#endif // L_TWO_NORM_H