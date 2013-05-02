/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: symmetric_matrix.hpp
* Purpose: Implementation file for the Symmetric_Matrix class
*/

#include "symmetric_matrix.h"
#include "symmetric_err.h"

template <class T>
Symmetric_Matrix<T>::Symmetric_Matrix(const Matrix<T>& input_matrix)
{
  //Included to make the checks easier and speedier
  data_size input_rows = input_matrix.get_number_of_rows();
  data_size input_columns = input_matrix.get_number_of_columns();

  //Check for a square matrix
  if (input_rows != input_columns)
  {
    throw Square_Matrix_Err<data_size>(input_rows, input_columns);
  }

  //Check for existing numbers in areas besides the diagonal
  for (data_size i = 0; i < input_rows; i++)
  {
    for (data_size j = 0; j < input_columns; j++)
    {
      if(input_matrix(i, j) != input_matrix(j, i))
      { 
        throw Symmetric_Err<T>(input_matrix(i, j));
      }
    }
  }

  Matrix<T>::clear();

  Matrix<T>::m_rows = input_rows;
  Matrix<T>::m_columns = input_rows;
  Matrix<T>::m_elements = new T*[Matrix<T>::m_rows];
  for (data_size i = 0; i < Matrix<T>::m_rows; i++)
  {
    Matrix<T>::m_elements[i] = new T[i + 1];
  }

  Matrix<T>::pointer_copy(input_matrix);
  for(data_size k = 0; k < Matrix<T>::m_rows; k++)
  {
    for (data_size m = 0; m <= k; m++)
    {
      (*this)(k, m) = input_matrix(k, m);
    }
  }

  Matrix<T>::m_columns = input_columns;
}

template <class T>
Symmetric_Matrix<T>::Symmetric_Matrix(data_size input_rows, data_size input_columns)
{
  //Check for a square matrix
  if (input_rows != input_columns)
  {
    throw Square_Matrix_Err<T>(input_rows, input_columns);
  }

  Matrix<T>::m_rows = input_rows;
  Matrix<T>::m_columns = Matrix<T>::m_rows;
  Matrix<T>::m_elements = new T*[Matrix<T>::m_rows];
  for (data_size i = 0; i < Matrix<T>::m_rows; i++)
  {
    Matrix<T>::m_elements[i] = new T[i + 1];
  }

  for (data_size i = 0; i < Matrix<T>::m_rows; i++)
  {
    for (data_size j = 0; j <= i; j++)
    {
      (*this)(i, j) = 0;
    }
  }
}

template <class T>
istream& Symmetric_Matrix<T>::input_stream(istream& in)
{
  for (data_size i = 0; i < Matrix<T>::m_rows; i++)
  {
    for (data_size j = 0; j <= i; j++)
    {
      in >> (*this)(i, j);
    }
  }
  return in;
}

template <class T>
T& Symmetric_Matrix<T>::operator()(const data_size input_row, 
                                   const data_size input_column)
{
  if(input_row > Matrix<T>::m_rows)
  {
    throw Range_Err(input_row);
  }
  if(input_column > Matrix<T>::m_columns)
  {
    throw Range_Err(input_column);
  }

  if(input_row >= input_column)
  {
    return Matrix<T>::m_elements[input_row][input_column];
  }
  else
  {
    return Matrix<T>::m_elements[input_column][input_row];
  }
}

template <class T>
T& Symmetric_Matrix<T>::operator()(const data_size input_row, 
                                   const data_size input_column) const
{
  if(input_row > Matrix<T>::m_rows)
  {
    throw Range_Err(input_row);
  }
  if(input_column > Matrix<T>::m_columns)
  {
    throw Range_Err(input_column);
  }

  if(input_row >= input_column)
  {
    return Matrix<T>::m_elements[input_row][input_column];
  }
  else
  {
    return Matrix<T>::m_elements[input_column][input_row];
  }
}

template <class T>
Symmetric_Matrix<T>& Symmetric_Matrix<T>::plus_equals(
                                  const Matrix<T>& right_hand_side)
{
  data_size input_row = right_hand_side.get_number_of_rows();
  data_size input_column = right_hand_side.get_number_of_columns();
  if(Matrix<T>::m_rows != input_row)
  {
    throw Size_Difference_Err(Matrix<T>::m_rows, input_row);
  }

  if(input_row != input_column)
  {
    throw Square_Matrix_Err<T>(input_row, input_column);
  }

  for (data_size i = 0; i < input_row; i++)
  {
    for (data_size j = 0; j < input_column; j++)
    {
      if (right_hand_side(i, j) != right_hand_side(j, i))
      {
        throw Symmetric_Err<T>(right_hand_side(i, j));
      }
    }
  }
 
  for (data_size i = 0; i < Matrix<T>::m_rows; i++)
  {
    for (data_size j = 0; j <= i; j++)
    {
      (*this)(i, j) += right_hand_side(i, j);
    }
  }

  return *this;
}

template <class T>
Symmetric_Matrix<T>& Symmetric_Matrix<T>::minus_equals(
                                  const Matrix<T>& right_hand_side)
{
  data_size input_rows = right_hand_side.get_number_of_rows();
  data_size input_columns = right_hand_side.get_number_of_columns();
  if(Matrix<T>::m_rows != input_rows)
  {
    throw Size_Difference_Err(Matrix<T>::m_rows, input_rows);
  }

  if(input_rows != input_columns)
  {
    throw Square_Matrix_Err<T>(input_rows, input_columns);
  }

  for (data_size i = 0; i < input_rows; i++)
  {
    for (data_size j = 0; j < input_columns; j++)
    {
      if (right_hand_side(i, j) != right_hand_side(j, i))
      {
        throw Symmetric_Err<T>(right_hand_side(i, j));
      }
    }
  }
 
  for (data_size i = 0; i < Matrix<T>::m_rows; i++)
  {
    for (data_size j = 0; j <= i; j++)
    {
      (*this)(i, j) -= right_hand_side(i, j);
    }
  }

  return *this;
}

template <class T>
Symmetric_Matrix<T>& Symmetric_Matrix<T>::operator*=(
                                          const double right_hand_side)
{
  for (data_size i = 0; i < Matrix<T>::m_rows; i++)
  {
    for (data_size j = 0; j <= i; j++)
    {
      (*this)(i, j) *= right_hand_side;
    }
  }
  return *this;
}
    
template <class T>
Symmetric_Matrix<T>& Symmetric_Matrix<T>::operator/=(
                                          const double right_hand_side)
{
  for (data_size i = 0; i < Matrix<T>::m_rows; i++)
  {
    for (data_size j = 0; j <= i; j++)
    {
      (*this)(i, j) /= right_hand_side;
    }
  }
  return *this;
}

template <class T>
ostream& Symmetric_Matrix<T>::output_stream (ostream& out) const
{
  out << "[";
  for (data_size i = 0; i < Matrix<T>::m_rows; i++)
  {
    if (i != 0)
    {
      out << " ";
    }
    out << "[";
    for (data_size j = 0; j < Matrix<T>::m_rows; j++)
    {
      //The upper (existing!) part of the matrix
      /*if (i >= j)
      {*/
        out << (*this)(i, j);
      //}
      ////All other locations
      //else
      //{
      //  out << (*this);
      //}
    
      if ((j + 1) < Matrix<T>::m_rows)
      {
         out << "\t";
      }
    }
    out << "]";
    if ((i + 1) < Matrix<T>::m_rows)
    {
      out << endl;
    }
  }
  out << "]";
  return out;
}

template <class T>
Symmetric_Matrix<T>& Symmetric_Matrix<T>::operator=(
                            const Symmetric_Matrix<T>& right_hand_side)
{
  data_size input_rows = right_hand_side.get_number_of_rows();
  data_size input_columns =  right_hand_side.get_number_of_columns();

  Matrix<T>::clear();
  Matrix<T>::m_rows = input_rows;
  Matrix<T>::m_columns = input_columns;
  Matrix<T>::m_elements = new T*[Matrix<T>::m_rows];
  for (data_size i = 0; i < Matrix<T>::m_rows; i++)
  {
    Matrix<T>::m_elements[i] = new T[i + 1];
  }

  //Check for symmetry throughout 
  for (data_size i = 0; i < input_rows; i++)
  {
    for (data_size j = 0; j < input_columns; j++)
    {
      if(right_hand_side(i, j) != right_hand_side(j, i))
      {
        throw Symmetric_Err<T>(right_hand_side(i, j));
      }
    }
  }

  Matrix<T>::pointer_copy(right_hand_side);
  for(data_size k = 0; k < Matrix<T>::m_rows; k++)
  {
    for (data_size m = 0; m <= k; m++)
    {
      (*this)(k, m) = right_hand_side(m, k);
    }
  }

  Matrix<T>::m_columns = input_columns;

  return *this;
}
