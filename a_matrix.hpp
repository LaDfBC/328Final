/*
* Programmer: Matt Lindsay and George Mausshardt
* Date: 05/12/2013
* FileName: a_matrix.hpp
* Purpose: Implementation file for the functor whose purpose is to create
*   the A-matrix used to estimate Partial Differential Equations
*/

template <class T>
Symmetric_Matrix<T> A_Matrix<T>::operator()()
{
  matrix_data_type point_adjuster = m_num_points - 1;
  // Matrix to be RETurned
  // Actually, I want to write a Quad_Matrix class that only stores 1/4
  //   of the numbers in a whole matrix.  All A-Matrices are symmetric
  //   across BOTH diagonals, so this would save even more space.
  Symmetric_Matrix<T> ret_matrix(pow(point_adjuster, 2), pow(point_adjuster, 2));

  //Iterate through all of the points. Add only those less than the 
  //  current one to make it quicker.

  for(matrix_data_type i = 0; i < pow(point_adjuster, 2); i++)
  {
    ret_matrix(i, i) = 1;
    
    if(i + point_adjuster < pow(point_adjuster, 2))
    {
      ret_matrix(i, i + point_adjuster) = -0.25;
    }
    
    if (((i + 1) % point_adjuster) != 0)
    {
      ret_matrix(i, i + 1) = -0.25;
    }
  }
  return ret_matrix;
}