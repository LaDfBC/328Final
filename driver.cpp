/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/01/2013
* FileName: driver.cpp
* Purpose: Driver for Assignment 5, with the goal to build a parameterized
*   matrix class, capable of most typical arithmetic matrix operations, in
*   addition to Gauss-Seidel AND Jacobi iteration to solve the system of
*   linear equations stored in the Matrix.
*/

#include <iostream>
#include "file_stream.h"
#include "matrix.h"
#include "operator_library.h"
#include "solver.h"
#include "gauss_seidel.h"
#include "symmetric_matrix.h"
#include "partial_diffeq.h"
#include "domain_err.h"
#include "analyzer.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;	

int main(int argc, char* argv[])
{
  string test_file_name;
  if (argc < 2)
  {
    cout << endl;
    cout << "No file name specified. Using 'test_data.txt.' " << endl;
    cout << "If you would like to use another file, name it at the end of the"
         << " command line!" << endl << endl;;
    test_file_name = "test_data.txt";
  }
  else
  {
    test_file_name = argv[1];
  }

  Partial_DiffEQ<double, Matrix_Vector<double>, Symmetric_Matrix<double>, 
                 sqrt, sqrt, sqrt, sqrt> checker(4);
  
  cout << checker.get_b_vector() << endl;

  Gauss_Seidel<Matrix_Vector<double>, 
               Matrix<double>, 
               Partial_DiffEQ<double, Matrix_Vector<double>, Symmetric_Matrix<double>, 
                 sqrt, sqrt, sqrt, sqrt> > solver1(checker);
  cout << solver1.evaluate() << endl;

  //cout << checker.get_a_matrix() << endl;
  //
  //Matrix_Vector<double> new_vect(checker.get_a_matrix().get_number_of_rows());
  //for(int i = 0; i < checker.get_a_matrix().get_number_of_rows(); i++)
  //{
  //  new_vect[i] = i + 2;
  //}
  //
  //Matrix<double> new_mat(checker.get_a_matrix().get_number_of_rows(),
  //                   checker.get_a_matrix().get_number_of_columns() + 1);
  //
  //unsigned int quick_number_of_rows = 
  //  checker.get_a_matrix().get_number_of_rows();

  ////Appends the b vector to the end of the matrix
  //for (data_size i = 0; i < quick_number_of_rows; i++)
  //{
  //  for (data_size j = 0; j < quick_number_of_rows; j++)
  //  {
  //    new_mat(j, i) = checker.get_a_matrix()(j, i);
  //  }

  //  new_mat(i, new_mat.get_number_of_columns() - 1) = 
  //    new_vect[i];
  //}

  //cout << new_mat << endl;
  //cout << "Here" << endl;
  //cout << new_mat.get_number_of_columns() << endl;
  //cout << checker.get_a_matrix().get_number_of_rows() << endl;
  //int number_of_columns = new_mat.get_number_of_columns();
  //int number_of_rows = new_mat.get_number_of_rows();
  //double current_pivot = 0;
  //for(unsigned int i = 0; i < number_of_columns - 2; i++)
  //{
  //  // CHECK FOR ROWS WITH LL 0's

  //  for(unsigned int j = i + 1; j < number_of_columns - 1; j++)
  //  {
  //    for(unsigned int k = j; k < number_of_rows; k++)
  //    {
  //      new_mat(j, k) -= new_mat(i, k) * 
  //                         (new_mat(j, i) / new_mat(i, i));
  //    }
  //    new_mat(j, i) = 0;
  //  }
  //}
  //
  //cout << "Here2" << endl;
  //Matrix_Vector<double> solution_vector(number_of_rows);
  //for(int i = 0 ; i < number_of_rows; i++)
  //{
  //  solution_vector[i] = new_mat(i, number_of_columns - 1);
  //}

  ////Need backward substitution

    

  /*cout << new_mat << endl << endl;
  cout << solution_vector << endl;*/
  

  return 0;
}