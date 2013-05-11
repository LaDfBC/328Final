/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: operator_library.h
* Purpose: Implementation file for the operators that are used
*   in many of the matrices and cannot be inherited, due to forcibly being
*   friend functions or taking two classes to execute
*/

#ifndef OPERATOR_LIBRARY_H
#define OPERATOR_LIBRARY_H

#include <iostream>
#include "solver.h"

using std::ostream;
using std::istream;

/*
  NOTE: THIS IS NOT A CLASS DEFINITION FILE!  This file exists to provide
    the same functions to derived classes that "normal" classes would enjoy.
    All of these functions have some kind of issues being directly related
    to the derived classes, so they are implemented here instead.
*/

/*
  OPERATOR: ostream& operator<<(ostream& out, 
                                  const Matrix_Base<T>& input_matrix)
    Input: out - the stream used to display information about
      the matrix to the screen
           input_matrix - the Matrix to be output to the screen.
    Output: Functions like a cout statement.  The matrix is output
      to the screen in the format [e1, e2, e3 ... ek]
  PRE: Note that this function attempts to output each element in turn.
    Ensure that complex or programmer-defined objects have an output 
    operator defined!
  POST: Outputs the matrix to the screen in the foramt defined above.
    This operator calls whatever output_stream function is defined in the 
    given matrix class.
  PURPOSE: Allow "cout << matrix" to function correctly. Called
    when the matrix must be output.
*/
template <class T>
ostream& operator<<(ostream& out, const Matrix_Base<T>& input_matrix);

/*
  OPERATOR: ostream& operator<<(ostream& out,
                              const Solver<U, V, DerivedSolver>& input_solver)
    Input: out - the stream used to display information about
      the matrix to the screen
           Solver<U, V, DerivedSolver>& input_solver - the solver to be
      displayed
    Output: Functions like a cout statement.  The system-of-equations solver
      is output  to the screen, showing the A-Matrix, B-Vector, and solution
      vector
  PRE: Note that this function attempts to output each element of matrices and
    vectors in turn. Ensure that complex or programmer-defined objects have 
    an output operator defined!
  POST: Outputs the solver to the screen in the foramt defined above.
    This operator calls whatever output_stream function is defined in the 
    given solver class.
  PURPOSE: Allow "cout << Solver" to function correctly. Called
    when a linear-systems-of-equations solver must be displayed.
*/
template <class T, class U, class V, class DerivedSolver>
ostream& operator<<(ostream& out, 
                      const Solver<U, V, DerivedSolver>& input_solver);


/*
  OPERTOR: ostream& operator<<(ostream& out, const Partial_DiffEQ<T, U, V, 
                                                       Top_Function, 
                                                       Left_Function, 
                                                       Right_Function, 
                                                       Bottom_Function>& input_diffeq);
    Input: out - the stream used to display information about
      the differential equation to the screen
           Partial_DiffEQ<T, U, V, 
                          Top_Function, 
                          Left_Function, 
                          Right_Function, 
                          Bottom_Function>& input_diffeq - the differential
             equation to be displayed to the screen
    Output: Functions like a cout statement.  The system-of-equations solver
      is output  to the screen, showing the solution vector in a useful format
  PRE: Note that this function attempts to output each element of 
    vectors in turn. Ensure that complex or programmer-defined objects stored
    in the vectors have an output operator defined!
  POST: Outputs the equation to the screen in the foramt defined above.
    This operator calls whatever output_stream function is defined in the 
    given differetial equation class.
  PURPOSE: Allow "cout << DiffEQ" to function correctly. Called
    when a differential equation must be displayed
*/

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
ostream& operator<<(ostream& out, const Partial_DiffEQ<T, U, V, 
                                                       Top_Function, 
                                                       Left_Function, 
                                                       Right_Function, 
                                                       Bottom_Function>& input_diffeq);
/*
  FUNCTION: Poisson_Top(double x)
    Input: x - the x position in the outside of a mesh estimating
      a partial differentiql equation
    Output: double - the output of Poisson's equation on the Top
      edge of the estimation matrix defined above.
  PRE: None.
  POST: Returns x-cubed, in this case.  Represents the top of the
    estimation mesh for Poisson's Equation's DiffEQ.
  PURPOSE: Outer mesh estimation function. Simply x-cubed currently.
*/
double Poisson_Top(double x);

/*
  FUNCTION: Poisson_Bottom(double x)
    Input: x - the x position in the outside of a mesh estimating
      a partial differentiql equation
    Output: double - the output of Poisson's equation on the Bottom
      edge of the estimation matrix defined above.
  PRE: None.
  POST: Returns x-cubed, in this case.  Represents the bottom of the
    estimation mesh for Poisson's Equation's DiffEQ.
  PURPOSE: Outer mesh estimation function. Simply x-cubed currently.
*/
double Poisson_Bottom(double x);

/*
  FUNCTION: Poisson_Left(double x)
    Input: dummy value to make function pointers work.
    Output: double - the output of Poisson's equation on the Left
      edge of the estimation matrix defined above.
  PRE: None.
  POST: Returns 0, currently.  Represents the left of the
    estimation mesh for Poisson's Equation's DiffEQ.
  PURPOSE: Outer mesh estimation function. Simply 0, currently.
*/
double Poisson_Left(double);

/*
  FUNCTION: Poisson_Right(double x)
    Input: dummy value to make function pointers work
    Output: double - the output of Poisson's equation on the Right
      edge of the estimation matrix defined above.
  PRE: None.
  POST: Returns 1, in this case.  Represents the top of the
    estimation mesh for Poisson's Equation's DiffEQ.
  PURPOSE: Outer mesh estimation function. Simply 1, currently.
*/
double Poisson_Right(double);

/*
  OPERATOR: istream& input_stream(istream& in);
    Input: in - the input stream from which to read information
      about the matrix
    Output: Functions like a cin statement.  The matrix is read in
      from numbers entered at the command line
  PRE: Note that this function attempts to input each element in turn.
    Ensure that complex or programmer-defined objects have an input
    operator defined!
  POST: Builds the matrix from user-defined input - calls whatever
    input_stream function is defined in the given matrix class.
  PURPOSE: Allow "cin >> matrix" to function correctly.  Called
    when a Matrix must be read in from user-defined values.
 */
template <class T>
istream& operator>>(istream& in, Matrix_Base<T>& input_matrix);

/*
  OPERATOR: Matrix_Base<T>& plus_equals(Matrix<T>& calling_matrix
              const Matrix<T>& right_hand_side)
    Input: calling_matrix - the matrix to store the result of itself plus 
             right_hand_side
           right_hand_side - the Matrix to be added to this matrix instance
    Output: This matrix, after being added to right_hand_side
  PRE: Note that scalar addition among elements is used.  Therefore, 
    this function should only be used on a matrix that holds either scalar
    values or objects that have their own addition operator defined. Note
    that by definition, the matrices being added must have the same number
    of rows and the same number of columns! This calls whatever function
    plus_equals is defined in the given matrix implementation.
  POST: This matrix becomes the result of itself + right_hand_side. The + 
    operation on a matrix simply involves adding each individual member.
  PURPOSE: See post condition. No additional side effects. Implements
    the += operation for all same-sized Matrices.
*/
template <class T>
Matrix_Base<T>& operator+=(Matrix<T>& calling_matrix,
                           const Matrix<T>& right_hand_side);

/*
  OPERATOR: Matrix_Base<T>& minus_equals(Matrix<T>& calling_matrix
              const Matrix<T>& right_hand_side)
    Input: calling_matrix - the matrix to store the result of itself plus 
             right_hand_side
           right_hand_side - the Matrix to be 
             subtracted from this matrix instance
    Output: This matrix, after right_hand_side is subtracted from it
  PRE: Note that scalar subtraction among elements is used.  Therefore, 
    this function should only be used on a matrix that holds either scalar
    values or objects that have their own subtraction operator defined. 
    Note that by definition, the matrices being subtracted must have the 
    same number of rows and the same number of columns!  This calls whatever
    function minus_equals is defined in the given matrix implementation.
  POST: This Matrix becomes the result of itself - right_hand_side. The - 
    operation on a Matrix simply involves adding each individual member.
  PURPOSE: See post condition. No additional side effects. Implements
    the -= operation for all same-sized Matrices.
*/
template <class T>
Matrix_Base<T>& operator-=(Matrix<T>& calling_matrix,
                           const Matrix<T>& right_hand_side);

#include "operator_library.hpp"
#endif //OPERATOR_LIBRARY_H