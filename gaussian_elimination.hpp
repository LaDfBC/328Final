/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: gaussian_elimination.hpp
* Purpose: Implementation file for the class built to approximate
*   differential equations using Gaussian Elimination
*/

template <class T, class U, class V>
Gaussian_Elimination<T, U, V>::Gaussian_Elimination(const V& input_diffeq)
{
  //Set a temporary matrix and 
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
      input_diffeq.get_b_vector()[i];
  }

  //Set the class's matrix equal to the temporary one
  m_a_matrix = temporary_matrix;
}

template <class T, class U, class V>
T Gaussian_Elimination<T, U, V>::evaluate()
{
  unsigned int number_of_columns = m_a_matrix.get_number_of_columns();
  unsigned int number_of_rows = m_a_matrix.get_number_of_rows();

  //Check for rows of all zeroes, which mean that the matrix is not singular
  for(unsigned int i = 0; i < number_of_rows - 1; i++)
  {
    for(unsigned int j = 0; j < number_of_columns; j++)
    {
      if(m_a_matrix(i, j) != 0)
      {
        break;
      }
      if(j == number_of_columns - 1)
      {
        //throw //Some Err!
      }
    }
  }

  for(unsigned int i = 0; i < number_of_columns; i++)
  {
    // CHECK FOR ROWS WITH ALL 0's
    for(unsigned int j = i + 1; j < number_of_rows; j++)
    {
      double div_value = (m_a_matrix(j, i) / m_a_matrix(i, i));
      for(unsigned int k = i + 1; k < number_of_columns; k++)
      {
        m_a_matrix(j, k) -= m_a_matrix(i, k) * div_value;
      }
      m_a_matrix(j, i) = 0;
    }
  }
  //Backwards Substitution
  T solution_vector(number_of_rows);

  solution_vector[number_of_rows - 1] = 
    (m_a_matrix(number_of_rows - 1, number_of_columns - 1) / 
     m_a_matrix(number_of_rows - 1, number_of_rows - 1));
  
  for (long j = number_of_rows - 2; j >= 0; j--)
  {
    solution_vector[j] = m_a_matrix(j, number_of_columns - 1);
    for(long i = number_of_columns -2; i > j; i--)
    {
      solution_vector[j] -= (m_a_matrix(j, i) * solution_vector[i]);
    }
    solution_vector[j] /= m_a_matrix(j, j);
  }

  return solution_vector;
}


