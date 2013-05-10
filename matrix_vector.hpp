/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: Matrix_Vector.hpp
* Purpose: Implementation file for the Matrix_Vector class
*/

#include "matrix_vector.h"

template <class T>
Matrix_Vector<T>::Matrix_Vector()
{
    m_data = NULL;
    m_size = 0;
}

template <class T>
Matrix_Vector<T>::Matrix_Vector(unsigned short const vector_size)
{
    // No need to throw error. The unsigned data type forces postitive values
    //   of vector_size!
    m_data = new T[vector_size];
    m_size = vector_size;
    for (unsigned short i = 0; i < m_size; i++)
    {
      m_data[i] = 0;
    }
}

template <class T>
Matrix_Vector<T>::Matrix_Vector(const Matrix_Vector<T>& right_hand_side)
{
  m_size = right_hand_side.m_size;
  m_data = new T[m_size];
  copy(right_hand_side);
}

template <class T>
void Matrix_Vector<T>::copy(const Matrix_Vector<T>& right_hand_side)
{
  T* temporary_left_hand_side = m_data + m_size;
  T* temporary_right_hand_side = right_hand_side.m_data + m_size;

  while(temporary_left_hand_side > m_data)
  {
    *--temporary_left_hand_side = *--temporary_right_hand_side;
  }
  return;
}

template <class T>
Matrix_Vector<T>::~Matrix_Vector()
{
  delete []m_data;
}

template <class T>
void Matrix_Vector<T>::set_vector_size(short new_vector_size)
{
  if (new_vector_size < 0)
  {
    throw Range_Err(new_vector_size);
  }
  else
  {
    if (m_size != new_vector_size)
    {
      delete []m_data;
      m_size = new_vector_size;
      m_data = new T[m_size];
    }
  }
  return;
}

template <class T>
Matrix_Vector<T> Matrix_Vector<T>::operator/
                                   (const double right_hand_side) const
{
  Matrix_Vector<T> new_Matrix_Vector(*this);
  for (short i = 0; i < m_size; i++)
  {
    new_Matrix_Vector.m_data[i] = new_Matrix_Vector[i] / right_hand_side;
  }

  return new_Matrix_Vector;
}

template <class T>
Matrix_Vector<T>& Matrix_Vector<T>::operator/=(const double right_hand_side)
{
  for (unsigned short i = 0; i < m_size; i++)
  {
    m_data[i] /= right_hand_side;
  }
  return *this;
}

template <class T>
Matrix_Vector<T> Matrix_Vector<T>::operator*(const double right_hand_side)
{
  Matrix_Vector<T> new_Matrix_Vector(*this);
  for (short i = 0; i < m_size; i++)
  {
    new_Matrix_Vector.m_data[i] = new_Matrix_Vector[i] * right_hand_side;
  }

  return new_Matrix_Vector;
}

template <class T>
Matrix_Vector<T>& Matrix_Vector<T>::operator*=(const double right_hand_side)
{
  for (unsigned short i = 0; i < m_size; i++)
  {
    m_data[i] *= right_hand_side;
  }
  return *this;
}

template <class T>
Matrix_Vector<T>& Matrix_Vector<T>::operator+=(const Matrix_Vector<T>& right_hand_side)
{
  if (right_hand_side.m_size != m_size)
  {
    throw Size_Difference_Err(right_hand_side.m_size, m_size);
  }  

  for (unsigned short i = 0; i < m_size; i++)
  {
    m_data[i] += right_hand_side.m_data[i];
  }
  return *this;
}

template <class T>
Matrix_Vector<T>& Matrix_Vector<T>::operator-=(const Matrix_Vector<T>& right_hand_side)
{
  if (right_hand_side.m_size != m_size)
  {
    throw Size_Difference_Err(right_hand_side.m_size, m_size);
  }

  for (short i = 0; i < m_size; i++)
  {
    m_data[i] -= right_hand_side.m_data[i];
  }
  return *this;
}

template <class T>
bool Matrix_Vector<T>::operator==(const Matrix_Vector<T>& right_hand_side) const
{
  if (m_size != right_hand_side.m_size)
  {
    return false;
  } 
  for (short i = 0; i < m_size; i++)
  { 
    if (m_data[i] != right_hand_side.m_data[i])
    {
      return false;
    }
  }
  return true;
}

template <class T>
bool Matrix_Vector<T>::operator!=(const Matrix_Vector<T>& right_hand_side) const
{
  return !(*this == right_hand_side);
}

template <class T>
ostream& operator<<(ostream &out, const Matrix_Vector<T>& calling_Matrix_Vector)
{
  out << "[";
  for (unsigned short i = 0; i < calling_Matrix_Vector.m_size; i++)
  {
    out << calling_Matrix_Vector.m_data[i];
    
    // Delivers the proper spacing for a user-friendly output of the vector
    if(i < calling_Matrix_Vector.m_size - 1)
    {
      out << " ";
    }
  }
  out << "]";
  return out;
}

template <class T>
istream& operator>>(istream& in, const Matrix_Vector<T>& calling_Matrix_Vector)
{
  for (unsigned short i = 0; i < calling_Matrix_Vector.m_size; i++)
  {
    in >> calling_Matrix_Vector.m_data[i];
  }
  return in;
}

template <class T>
Matrix_Vector<T> Matrix_Vector<T>::operator-()
{
  Matrix_Vector<T> ret_Matrix_Vector;
  for (unsigned short i = 0; i < m_size; i++)
  {
    ret_Matrix_Vector.m_data[i] = -m_data[i];
  }
  return ret_Matrix_Vector;
}

template <class T>
Matrix_Vector<T>& Matrix_Vector<T>::operator=(const Matrix_Vector<T>& right_hand_side)
{
  set_vector_size(right_hand_side.m_size);
  copy(right_hand_side);
  return *this;
}

template <class T>
T& Matrix_Vector<T>::operator[](unsigned short const data_location) const
{
    if (data_location >= m_size)
       throw Range_Err(data_location);
    
    return m_data[data_location];
}

template <class T>
T& Matrix_Vector<T>::operator[](unsigned short const data_location)
{
    if (data_location >= m_size)
       throw Range_Err(data_location);
    
    return m_data[data_location];
}

template <class T>
double Matrix_Vector<T>::dot_product(
                        const Matrix_Vector<T>& right_hand_side) const
{
  double running_total = 0;
  if (m_size == right_hand_side.m_size)
  {
    for (unsigned short i = 0; i < m_size; i++)
    {
      running_total += (m_data[i] * right_hand_side[i]);
    }
  }
  else
  {
    throw Size_Difference_Err(m_size, right_hand_side.m_size);
  }

  return running_total;
}

template <class T>
double dot_product(const Matrix_Vector<T>& left_hand_side,
                  const Matrix_Vector<T>& right_hand_side)
{
  double running_total = 0;
  if (left_hand_side.m_size == right_hand_side.m_size)
  {
    for (unsigned short i = 0; i < left_hand_side.m_size; i++)
    {
      running_total += (left_hand_side[i] * right_hand_side[i]);
    }
  }
  else
  {
    throw Size_Difference_Err(left_hand_side.m_size, right_hand_side.m_size);
  }

  return running_total;
}

template <class T>
double Matrix_Vector<T>::mag() const
{
  double running_total = 0;
  for (unsigned short i = 0; i < m_size; i++)
  {
    running_total += pow(m_data[i], 2);
  }

  return sqrt(running_total);
}

template <class T>
unsigned short Matrix_Vector<T>::size() const
{
  return m_size;
}
