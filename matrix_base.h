/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: matrix_base.h
* Purpose: Definition file for the Matrix_Base class - a base class
*   for many different types of matrices
*/

#ifndef MATRIX_BASE_H
#define MATRIX_BASE_H

/*
  TYPEDEF: data_size - defines the amount of space needed to hold the elements
    of a matrix. Using a "short" conserves memory, while a "long" allows larger
    matrices.
  NOTE: Keep this typedef unsigned.  There will never be a reason to define
  data_size as anything other than an unsigned integer value! 
*/
typedef unsigned short data_size;

template <class T>
class Matrix_Base
{
  public:
    /*
      BASE OPERATOR: Matrix_Base<T>& operator*=(const double right_hand_side)
        Input: right_hand_side - the second part of a multiplication operator
          for any derived class
        Output: This base class, so that any derived class may use the result
      PRE: All elements must be initialized!  Check derived preconditions for
        specific information.
      POST: Returns the result of a multiplication by a scalar and sets this
        matrix equal to the result.
      PURPOSE: Define a multiplication-equals base function for all classes
        derived from this one.
    */
    virtual Matrix_Base<T>& operator*=(const double right_hand_side) = 0;
   
    /*
      BASE OPERATOR: Matrix_Base<T>& operator/=(const double right_hand_side)
        Input: right_hand_side - the second part of a division operator
          for any derived class
        Output: This base class, so that any derived class may use the result
      PRE: All elements must be initialized! Check derived preconditions for
        specific information.
      POST: Returns the result of division by a scalar and sets this matrix
        equal to the result.
      PURPOSE: Define a division-equals base function for all classes
        derived from this one.
    */
    virtual Matrix_Base<T>& operator/=(const double right_hand_side) = 0;

    /*
      BASE OPERATOR:T& operator()(const data_size input_row, 
                                  const data_size input_column);
        Input: input_row - the row of the element in the array that is to be
          found and returned. 
               input_column - input_row - the column of the element in the 
          array that is to be found and returned.
        Output: The index at position [index_row][index_column].
      PRE: input_row and input_column must be greater than 0 and be less than
        the number of rows and columns in the array.  That element must also
        obviously be initialized.
      POST: Returns the element at [input_row][input_column], if it exists.
        This operator is one of the most important due to the varied 
        types of matrices.  Check derived definitions for updates and info.
      PURPOSE: Element Accessor.  This option is the mutator.
    */
    virtual T& operator()(const data_size input_row, const data_size input_column) = 0;

    /*
      BASE OPERATOR:T& operator()(const data_size input_row, 
                                  const data_size input_column);
        Input: input_row - the row of the element in the array that is to be
          found and returned. 
               input_column - input_row - the column of the element in the 
          array that is to be found and returned.
        Output: The index at position [index_row][index_column].
      PRE: input_row and input_column must be greater than 0 and be less than
        the number of rows and columns in the array.  That element must also
        obviously be initialized.
      POST: Returns the element at [input_row][input_column], if it exists.
        This operator is one of the most important due to the varied 
        types of matrices.  Check derived definitions for updates and info.
      PURPOSE: Element Accessor.  This option is the accessor.
    */
    virtual T& operator()(const data_size input_row, const data_size input_column) const  = 0;

    /*
      BASE FUNCTION: data_size get_number_of_rows() const
        output: data_size - the number of rows in the matrix
      PRE: None
      POST: Returns the number of rows in the matrix. No side effects.
      PURPOSE: A simple getter that does nothing more than returns the
        number of rows currently in the matrix.  Not often redefined.
    */
    virtual data_size get_number_of_rows() const = 0;

    /*
      BASE FUNCTION: data_size get_number_of_columns() const
        output: data_size - the number of columns in the matrix
      PRE: None
      POST: Returns the number of columns in the matrix. No side effects.
      PURPOSE: A simple getter that does nothing more than returns the
        number of rows currently in the matrix.  Not often redefined.
    */
    virtual data_size get_number_of_columns() const = 0;

    /*
      BASE FUNCTION: ostream& output_stream(ostream& out) const;
        Input: out - the stream used to display information about
          the matrix to the screen
        Output: Functions like a cout statement.  The matrix is output
          to the screen in the format [e1, e2, e3 ... ek]
      PRE: This function commonly refers to, and outputs, each element in turn
        so most matrix implementations will need to hold scalar types or
        classes with an output operator defined.
      POST: Outputs the matrix to the screen in the foramt defined by the
        derived class.
      PURPOSE: Allow "cout << matrix" to function correctly. Called
        when the matrix must be output.
    */
    virtual ostream& output_stream (ostream& out) const = 0;

    /*
      BASE FUNCTION: istream& input_stream(istream& in);
        Input: in - the input stream from which to read information
          about the matrix
        Output: Functions like a cin statement.  The matrix is read in
          from numbers entered at the command line
      PRE: This function commonly refers to, and inputs, each element in turn
        so most matrix implementations will need to hold scalar types or
        classes with an input operator defined.
      POST: Builds the matrix from user-defined input
      PURPOSE: Allow "cin >> matrix" to function correctly.  Called
        when a Matrix must be read in from user-defined values.
    */
    virtual istream& input_stream (istream& in) = 0;
 
  private:
    /*
      BASE FUNCTION: void clear()
      PRE: None
      POST: Deletes each pointer in a matrix, and the pointer to the
        m_elements array itself. 
      PURPOSE: Called when a matrix goes out of scope. Returns memory
        to the freestore and eliminates the possibility of dangling pointers
    */
    virtual void clear() = 0;
};

#endif //MATRIX_BASE_H