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
#include "gaussian_elimination.h"
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
                 Poisson_Top, Poisson_Left, 
                 Poisson_Right, Poisson_Bottom> checker(3);
  
  cout << checker.get_b_vector() << endl;
  cout << checker.get_a_matrix() << endl;

  Gaussian_Elimination<Matrix_Vector<double>, 
                       Matrix<double>, 
                       Partial_DiffEQ<double, Matrix_Vector<double>, 
                         Symmetric_Matrix<double>, 
                         Poisson_Top, Poisson_Left, 
                         Poisson_Right, Poisson_Bottom> > solver1(checker);
  cout << solver1.evaluate() << endl;

  Gauss_Seidel<Matrix_Vector<double>, 
               Matrix<double>, 
               Partial_DiffEQ<double, Matrix_Vector<double>, 
                 Symmetric_Matrix<double>, 
                 Poisson_Top, Poisson_Left, 
                 Poisson_Right, Poisson_Bottom> > solver2(checker);
  cout << solver2.evaluate() << endl;

  return 0;
}