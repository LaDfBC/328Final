/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: matrix.hpp
* Purpose: Implementation file for the Matrix class
*/

#include "matrix.h"

template <class T>
T Matrix<T>::zero_variable = 0;

template <class T>
Matrix<T>::Matrix()
{
  m_rows = 1;
  m_columns = 1;
  m_elements = new T*[m_rows];
  
  for (data_size i = 0; i < m_rows; i++)
  {
    m_elements[i] = new T[m_columns];
  }
 
  for(data_size i = 0; i < m_rows; i++)
  {
    for(data_size j = 0; j < m_columns; j++)
    {
      m_elements[i][j] = 0;
    }
  }
}

template <class T>
Matrix<T>::Matrix(data_size input_m_rows, data_size input_m_columns)
{
  /* No need to throw errors due to unsigned tag on the data_size typedef
    which controls m_rows and m_columns. Attempting to put error handling
    here makes the g++ compiler throw warnings, but let it be known that
    I did attempt to do so and left this space open for handlers in the 
    future if need be.
  */
 
  m_rows = input_m_rows;
  m_columns = input_m_columns;
  m_elements = new T*[m_rows];
  for (data_size i = 0; i < m_rows; i++)
  {
    m_elements[i] = new T[m_columns];
  }
 
  for(data_size i = 0; i < m_rows; i++)
  {
    for(data_size j = 0; j < m_columns; j++)
    {
      m_elements[i][j] = 0;
    }
  }
}

template <class T>
Matrix<T>::~Matrix()
{
  clear();
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& source_matrix)
{
  m_rows = source_matrix.m_rows;
  m_columns = source_matrix.m_columns;
  m_elements = new T*[m_rows];
  for(data_size i = 0; i < m_rows; i++)
  {
    m_elements[i] = new T[m_columns];
  }

  for(data_size i = 0; i < m_rows; i++)
  {
    for(data_size j = 0; j < m_columns; j++)
    {
      m_elements[i][j] = 0;
    }
  }

  copy(source_matrix);
}

template <class T>
Matrix<T>::Matrix(const Matrix_Vector<T>& source_vector)
{
  m_rows = source_vector.size();
  m_columns = 1;
  m_elements = new T*[m_rows];
  for(data_size i = 0; i < m_rows; i++)
  {
    m_elements[i] = new T[m_columns];
  }

  for(data_size i = 0; i < m_rows; i++)
  {
    m_elements[i][0] = source_vector[i];
  }
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& right_hand_side)
{
  clear();
  
  m_rows = right_hand_side.m_rows;
  m_columns = right_hand_side.m_columns;
  m_elements = new T*[m_rows];
  for(data_size i = 0; i < m_rows; i++)
  {
    m_elements[i] = new T[m_columns];
  }
  
  copy(right_hand_side);
  return *this;
}

template <class T>
istream& Matrix<T>::input_stream(istream& in)
{
  for (data_size i = 0; i < m_rows; i++)
  {
    for (data_size j = 0; j < m_columns; j++)
    {
      in >> m_elements[i][j];
    }
  }
  return in;
}

template <class T>
ostream& Matrix<T>::output_stream(ostream& out) const
{
  out << "[";
  for (data_size i = 0; i < m_rows; i++)
  {
    if (i != 0)
    {
      out << " ";
    }
    out << "[";
    for (data_size j = 0; j < m_columns; j++)
    {
      out << (*this)(i, j);
      if ((j + 1) < m_columns)
      {
         out << "\t";
      }
    }
    out << "]";
    if ((i + 1) < m_rows)
    {
      out << endl;
    }
  }
  out << "]";
  return out;
}

template <class T>
T& Matrix<T>::operator()(const data_size input_row, 
                         const data_size input_column)
{
  T* temp_column = m_elements[input_row];
  return temp_column[input_column];
}

template <class T>
T& Matrix<T>::operator()(const data_size input_row, 
                         const data_size input_column) const
{
  T* temp_column = m_elements[input_row];
  return temp_column[input_column];
}

template <class T>
Matrix_Base<T>& Matrix<T>::plus_equals(const Matrix<T>& right_hand_side)
{
  if(m_rows != right_hand_side.m_rows)
  {
    throw Size_Difference_Err(m_rows, right_hand_side.m_rows);
  }

  if(m_columns != right_hand_side.m_columns)
  {
    throw Size_Difference_Err(m_columns, right_hand_side.m_columns);
  }
  
  for (data_size i = 0; i < m_rows; i++)
  {
    for (data_size j = 0; j < m_columns; j++)
    {
       m_elements[i][j] += right_hand_side(i, j);
    }
  }

  return *this;
}

template <class T>
Matrix_Base<T>& Matrix<T>::minus_equals(const Matrix<T>& right_hand_side)
{
  if(m_rows != right_hand_side.m_rows)
  {
    throw Size_Difference_Err(m_rows, right_hand_side.m_rows);
  }

  if(m_columns != right_hand_side.m_columns)
  {
    throw Size_Difference_Err(m_columns, right_hand_side.m_columns);
  }
  
  for (data_size i = 0; i < m_rows; i++)
  {
    for (data_size j = 0; j < m_columns; j++)
    {
       m_elements[i][j] -= right_hand_side(i, j);
    }
  }

  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& right_hand_side)
{
  if (m_columns != right_hand_side.m_rows)
  {
    throw Size_Difference_Err(m_rows, right_hand_side.m_columns);
  }

  //We're going to create a new matrix and set (this) equal to it
  //  This will be far easier and take less time than resizing the
  //  the current matrix and subsequently modifying and filling numbers
  double new_element_value = 0;
  Matrix<T> ret_matrix(m_rows, right_hand_side.m_columns);

  for (data_size i = 0; i < right_hand_side.m_columns; i++)
  {
    for (data_size j = 0; j < m_rows; j++)
    {
      new_element_value = 0;
      for (data_size k = 0; k < m_columns; k++)
      {
        new_element_value += (m_elements[j][k] * right_hand_side(k, i));
      }
      ret_matrix(j, i) = new_element_value;
    }
  }

  *this = ret_matrix;
  return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator*=(const double right_hand_side)
{
  for (data_size i = 0; i < m_rows; i++)
  {
    for (data_size j = 0; j < m_columns; j++)
    {
       m_elements[i][j] *= right_hand_side;
    }
  }
  return *this;
}
    
template <class T>
Matrix<T>& Matrix<T>::operator/=(const double right_hand_side)
{
  if(right_hand_side == 0)
  {
    throw Div_Zero_Err<T>(right_hand_side);
  }

  for (data_size i = 0; i < m_rows; i++)
  {
    for (data_size j = 0; j < m_columns; j++)
    {
       m_elements[i][j] /= right_hand_side;
    }
  }
  return *this;
}

template <class T>
void Matrix<T>::copy(const Matrix<T>& right_hand_side)
{
  **(m_elements) = **(right_hand_side.m_elements);
  for(data_size i = 0; i < m_rows; i++)
  {
    *(m_elements[i]) = *(right_hand_side.m_elements[i]);
  }

  for(data_size i = 0; i < m_rows; i++)
  {
    for(data_size j = 0; j < m_columns; j++)
    {
      m_elements[i][j] = right_hand_side(i, j);
    }
  }

  return;
}

template <class T>
void Matrix<T>::pointer_copy(const Matrix<T>& right_hand_side)
{
  **(m_elements) = **(right_hand_side.m_elements);
  for(data_size i = 0; i < m_rows; i++)
  {
    *(m_elements[i]) = *(right_hand_side.m_elements[i]);
  }
 
  return;
}


template <class T>
void Matrix<T>::clear()
{
  for(data_size i = 0; i < m_rows; i++)
  {
    delete [] m_elements[i];
  }

  delete [] m_elements;
 
  return;
}

template <class T>
data_size Matrix<T>::get_number_of_columns() const
{
  return m_columns;
}

template <class T>
data_size Matrix<T>::get_number_of_rows() const
{
  return m_rows;
}