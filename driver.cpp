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
#include "symmetric_matrix.h"
#include "a_matrix.h"

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

  A_Matrix<float> checker(4);
  cout << checker() << endl;

  return 0;
}