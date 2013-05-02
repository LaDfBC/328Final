/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: file_stream.hpp
* Purpose: Implementation file for the File_Stream class
*/

#include "file_stream.h"
#include "file_err.h"
using std::fstream;
using std::string;

template <class T, class U>
File_Stream<T, U>::File_Stream(const string input_file_name)
{
  m_file_name = input_file_name;
  m_num_lines = -1; // Flag value. Will be changed when file is read
}

template <class T, class U>
File_Stream<T, U>::~File_Stream()
{
  // Intentionally empty.  If pointers are used in the future, this function
  //   will make the class more easily scalable.
}

template <class T, class U>
void File_Stream<T, U>::file_open()
{
  // If it's already open, just return and do nothing.
  if (m_file_instance.is_open())
  {
    return;
  }

  m_file_instance.open(m_file_name.c_str());
  
  if (!m_file_instance.is_open()) // Failed to open file! Throw Error!
  {
    throw File_Err(m_file_name);
  }
  
  return;
}

template <class T, class U>
U File_Stream<T, U>::matrix_vector_read_one(
                                    const unsigned short matrix_vector_size)
{
  //The Matrix Vector to be RETurned
  U ret_matrix_vector(matrix_vector_size);

  for (unsigned short i = 0; i < matrix_vector_size; i++)
  {
    m_file_instance >> ret_matrix_vector[i];
  }
  
  return ret_matrix_vector;
}

template <class T, class U>
void File_Stream<T, U>::file_close()
{
  //Only close if it's already open!
  if (m_file_instance.is_open())
  {
    m_file_instance.close();
  }
  return;
}

template <class T, class U>
T File_Stream<T, U>::matrix_read_one()
{
  m_file_instance >> m_num_lines;

  T matrix_from_file(m_num_lines, m_num_lines);

  for (data_size i = 0; i < m_num_lines; i++)
  {
    for (data_size j = 0; j < m_num_lines; j++)
    {
      m_file_instance >> matrix_from_file(i, j);
    }
  }

  return matrix_from_file;
}

template <class T, class U>
U File_Stream<T, U>::matrix_read_b_vector(const data_size m_rows)
{
  return matrix_vector_read_one(m_rows);
}

template <class T, class U>
U File_Stream<T, U>::matrix_vector_read_all()
{
  m_file_instance >> m_num_lines;
  //m_num_lines and matrix_vector_size will always be equal. Two variables are used
  //  for clarity and to make code more readable.
  unsigned short matrix_vector_size = m_num_lines;

  // Matrix Vector to be RETurned
  Matrix_Vector<T> matrix_vector_group(m_num_lines);
  
  for (unsigned short i = 0; i < m_num_lines; i++)
  {
    matrix_vector_group[i] = matrix_vector_read_one(matrix_vector_size);
  }

  return matrix_vector_group;
}