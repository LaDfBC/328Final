/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: Gauss_Seidel.hpp
* Purpose: Implementation file for the small class built to approximate
*   differential equations using Gauss-Seidel
*/

template <class T, class U, class V>
Gauss_Seidel<T, U, V>::Gauss_Seidel(const V& input_diffeq)
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
      input_diffeq.get_b_vector()[i];
  }

  m_a_matrix = temporary_matrix;
}

template <class T, class U, class V>
T Gauss_Seidel<T, U, V>::evaluate()
{
  // ERROR CHECKING - for diagonal dominance

  T current_guess_vector(m_a_matrix.get_number_of_rows());
  for ( long i = 0; i < m_a_matrix.get_number_of_rows(); i++)
  {
    current_guess_vector[i] = 0;
  }
  T next_guess_vector(current_guess_vector);

  double current_difference = 0;
  double running_total = 0;

  do
  {
    //We're going to overwrite the next guess, so make them equal.
    current_guess_vector = next_guess_vector;

    for (long i = 0; i < current_guess_vector.size(); i++)
    {
      running_total = 0;
      for (long j = 0; j < current_guess_vector.size() + 1; j++)
      {
        if(j != i)
        {
          if(j == current_guess_vector.size())
          {
            running_total += m_a_matrix(i, j);
          }
          else
          {
            /*
            *   Adding a negative, except for the last value in the matrix.
            *  The last value is the one from the b-vector.  ALSO, this line
            *  is the only difference between Jacobi and G_S! Instead of using
            *  the old vector, this one picks new values, if they exist, from
            *  the constantly-updated next vector.
            */
            running_total += 
                          -(m_a_matrix(i, j) * next_guess_vector[j]);
          }
        }
      }
      //After the inner loops end, we'll divide by this variable's coefficient
      //  and store it into the next iteration's spot.
      next_guess_vector[i] = running_total / m_a_matrix(i, i);
    }
    
    L_Two_Norm<T> current_norm_value(next_guess_vector);
    L_Two_Norm<T> last_norm_value(current_guess_vector);

    current_difference = (current_norm_value()) - (last_norm_value());

  } while(fabs(current_difference) >= proximity_threshold);
  
  return next_guess_vector;
}

