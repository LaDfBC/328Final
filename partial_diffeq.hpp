/*
* Programmers: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: partial_diffeq.hpp
* Purpose: Implementation file for the functor whose purpose is to
*   define a partial differential equation
*/

template<class T, class U, class V, double Top_Function(double), 
                  double Left_Function(double), 
                  double Right_Function(double), 
                  double Bottom_Function(double)>
Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                        Right_Function,Bottom_Function>::
Partial_DiffEQ(const unsigned short input_points)
{
  m_num_points = input_points;

  //Create the A Matrix - It will not need to be changed after this!
  unsigned short point_adjuster = m_num_points - 1;
  // Actually, I want to write a Quad_Matrix class that only stores 1/4
  //   of the numbers in a whole matrix.  All A-Matrices are symmetric
  //   across BOTH diagonals, so this would save even more space.
  V ret_matrix(pow(point_adjuster, 2), pow(point_adjuster, 2));

  //Iterate through all of the points. Add only those less than the 
  //  current one to make it quicker.

  for(unsigned short i = 0; i < pow(point_adjuster, 2); i++)
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

  m_a_matrix = ret_matrix;
}

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
T Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                          Right_Function,Bottom_Function>::
operator()()
{
  // this stops compiler err
  Matrix_Vector<T> return_this;
  return return_this;
}

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
V& Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                          Right_Function,Bottom_Function>::
get_a_matrix()
{
  return m_a_matrix;
}

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
void Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                             Right_Function,Bottom_Function>::
set_b_vector_index(const short input_index, const T input_data)
{
  return;
}

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
void Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                             Right_Function,Bottom_Function>::
set_x_vector_index(const short input_index, const T input_data)
{
  return;
}