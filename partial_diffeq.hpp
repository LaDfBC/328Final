/*
* Programmers: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: partial_diffeq.hpp
* Purpose: Implementation file for the functor whose purpose is to
*   define a partial differential equation
*/

#include "partial_diffeq.h"

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                        Right_Function,Bottom_Function>::
Partial_DiffEQ(const unsigned short input_points)
{
  //Create the A Matrix - It will not need to be changed after this!
  init_a_matrix(input_points);

  //Now build the B Vector and X Vector - The B vector will not need to be
  //  changed and the X vector represents the solution!
  init_vectors(input_points);
}

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
V& Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                          Right_Function,Bottom_Function>::
get_a_matrix() const
{
  return const_cast<V&>(m_a_matrix);
}

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
U Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                             Right_Function,Bottom_Function>::
get_b_vector() const
{
  return m_b_vector;
}

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
void Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                             Right_Function,Bottom_Function>::
set_x_vector_index(const short input_index, const T input_data)
{
  m_x_vector[input_index] = input_data;
  return;
}



template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
ostream& Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                                 Right_Function,Bottom_Function>::
output_stream(ostream& out) const
{
  long i = m_b_vector.size() - (m_num_points - 1);
  while(i >= 0)
  {
    for(long j = i; j < i + (m_num_points - 1); j++)
    {
      out << m_x_vector[j] << "\t";
    }
    out << endl;
    i -= (m_num_points - 1);
  }
  return out;
}

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
void Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                          Right_Function,Bottom_Function>::
init_a_matrix(const unsigned short input_points)
{
  m_num_points = input_points;
  //Create the A Matrix - It will not need to be changed after this!
  unsigned short point_adjuster = input_points - 1;
  // Actually, I want to write a Quad_Matrix class that only stores 1/4
  //   of the numbers in a whole matrix.  All A-Matrices are symmetric
  //   across BOTH diagonals, so this would save even more space.
  V temp_matrix(pow(point_adjuster, 2), pow(point_adjuster, 2));

  //Iterate through all of the points. Add only those less than the 
  //  current one to make it quicker.

  for(unsigned short i = 0; i < pow(point_adjuster, 2); i++)
  {
    temp_matrix(i, i) = 1;
    
    if(i + point_adjuster < pow(point_adjuster, 2))
    {
      temp_matrix(i, i + point_adjuster) = -0.25;
    }
    
    if (((i + 1) % point_adjuster) != 0)
    {
      temp_matrix(i, i + 1) = -0.25;
    }
  }

  m_a_matrix = temp_matrix;
}

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
void Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                          Right_Function,Bottom_Function>::
init_vectors(const unsigned short input_points)
{
  unsigned short point_adjuster = input_points - 1;
  
  U temp_vector(pow(point_adjuster, 2));

  //While we have a recently constructed vector, we'll set zero it, so x can
  //  be set and it's ready to be primed with the values for B.
  for(int i = 0; i < temp_vector.size(); i++)
  {
    temp_vector[i] = 0;
  }
  
  //Set x
  m_x_vector = temp_vector;

  //Now do the calculations for the B_Vector
  double x_position;
  double y_position;
  for(unsigned short i = 0; i < pow(point_adjuster, 2); i++)
  {
    x_position = ((i% point_adjuster) + 1) / static_cast<double>(input_points);
    y_position = ((i / point_adjuster) + 1) / static_cast<double>(input_points);

    //Check left boundary
    if((i % point_adjuster) == 0)
    {
      temp_vector[i] += Left_Function(y_position);
    }

    //Check top boundary
    if((i / point_adjuster) == (input_points - 2))
    {
      temp_vector[i] += Top_Function(x_position);
    }

    //Check right boundary
    if((i % point_adjuster) == (point_adjuster - 1))
    {
      temp_vector[i] += Right_Function(y_position);
    }

    //Check bottom boundary
    if((i / point_adjuster) == 0)
    {
      temp_vector[i] += Bottom_Function(x_position);
    }
    //(1/4) * (sum of 4 surrounding) - (h^2 / 4) * forcing function
    temp_vector[i] /= 4.0;//point_adjuster;//input_points;
    temp_vector[i] -= ((pow((1 / static_cast<float>(input_points)), 2) / 
                        4.0) * y_position);
  }

  m_b_vector = temp_vector;
}
