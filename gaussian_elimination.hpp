/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: gaussian_elimination.hpp
* Purpose: Implementation file for the small class built to approximate
*   differential equations using Gaussian Elimination
*/

template <class T, class U, class V>
Gaussian_Elimination<T, U, V>::Gaussian_Elimination(const V& input_diffeq)
{
  U temporary_matrix(input_diffeq.get_a_matrix().get_number_of_rows(),
                     input_diffeq.get_a_matrix().get_number_of_columns() + 1);
  
  unsigned int number_of_rows = 
    input_diffeq.get_a_matrix().get_number_of_rows();

  U a_matrix_placeholder = input_diffeq.get_a_matrix();

  //Appends the b vector to the end of the matrix
  for (data_size i = 0; i < number_of_rows; i++)
  {
    for (data_size j = 0; j < number_of_rows; j++)
    {
      temporary_matrix(i, j) = a_matrix_placeholder(i, j);
    }

    temporary_matrix(i, a_matrix_placeholder.get_number_of_columns()) = 
      input_diffeq.get_b_vector[i];
  }

  m_a_matrix = temporary_matrix;
}

template <class T, class U, class V>
Gaussian_Elimination<T, U, V>::T& operator()
{
  int number_of_columns = m_a_matrix.get_number_of_columns();
  int number_of_rows = m_a_matrix.get_number_of_rows();
  double current_pivot = 0;
  for(unsigned int i = 0; i < number_of_columns - 2; i++)
  {
    // CHECK FOR ROWS WITH LL 0's

    double current_pivot = m_a_matrix(i, i);
    for(unsigned int j = i; j < number_of_rows - 1; j++)
    {
      for(unsigned int k = j; k < number_of_columns - 1; i++)
      {
        m_a_matrix(j, k) -= m_a_matrix(i, k) * 
                           (m_a_matrix(j, i) / m_a_matrix(i , i));
      }
    }
  }

  T solution_vector(number_of_rows);
  for(int i = 0 ; i < number_of_rows; i++)
  {
    solution_vector[i] = m_a_matrix(i, number_of_columns - 1);
  }

  return solution_vector;
}


