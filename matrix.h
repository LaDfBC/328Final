/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: matrix.h
* Purpose: Header file for the Matrix class
*/

#ifndef MATRIX_H
#define MATRIX_H

#include "matrix_vector.h"
#include "matrix_base.h"

/* 
  CLASS: Matrix - An implementation of a standard Matrix, as commonly used in
    mathematics. This version is templated and parameterized.
  MEMBER VARIABLES: 
    data_size (typedef - defined above) m_rows - the number
      of rows in this matrix
    data_size (typedef - defined above) m_columns - the number
      of columns in this matrix
    T** m_elements - the two dimensional array of values stored in this matrix
  PRE: Watch the preconditions of member functions. Some will only work if
    the class or scalar has a certain attribute defined
  PURPOSE: Define a simple-to-use and powerful implementation of matrices
    commonly used in mathematics.
*/
template <class T>
class Matrix : public virtual Matrix_Base<T>
{
  public:
    /*
      CONSTRUCTOR: Matrix() 
      PRE: None
      POST: Sets m_rows and m_columns equal to 0. Therefore, there also exist
        no elements, but m_elements does hold the non-existent elements.
      PURPOSE: Default constructor.  Initializes a Matrix of size 0 with no
        elements at all.
    */
    Matrix();

    /*
      CONSTRUCTOR:  Matrix(data_size input_rows, data_size input_columns)
        Inputs: input_rows - a value defining the number of rows in the matrix
                input_columns - a value defining the number of columns in the
                  matrix
      PRE: Note that the individual elements are left uninitialized!  Only
        use this constructor before code that fills it with actual values.
      POST: Creates an input_rows x input_columns size Matrix where each value
        is of type T, but is uninitialized. Make sure to assign values!
      PURPOSE: Constructor to define a Matrix of a specific size.  Allows for
        the creation of mxn matrices of any (non-negative) m and 
        any (non-negative) n.
    */
    Matrix(data_size input_rows, data_size input_columns);

    /*
      CONSTRUCTOR: Matrix(const Matrix_Vector<T>& source_vector)
        Inputs: source_vector - the vector to be used to build a matrix of size
          m x 1, where m is the number of rows. The matrix will have 1 column.
      PRE: source_vector must have a .size() function defined that returns the
        number of elements defined within the vector, as this constructor 
        makes a call to this function.
        Additionally, this constructor makes use of each element's assignment
        operator.  Only use when storing objects that have an assignment
        operator defined!
      POST: Creates a matrix of size m x 1, where m is the number of rows.  The
        contents of the matrix will be the same as the vector, in the order in
        which they existed in the vector
      PURPOSE: Constructor to copy or translate a vector into a matrix.  This
        makes matrix-vector multiplication much easier to understand.
    */
    Matrix(const Matrix_Vector<T>& source_vector); 

    /*
      CONSTRUCTOR: Matrix(const Matrix<T>& source_matrix)
        Input: source_matrix - the matrix to be copied into this one
      PRE: This constructor makes use of each element's assignment
        operator by copying each element individually. Only use when storing 
        objects that have an assignment operator defined!
      POST: Copies source matrix into this matrix.  Each element and the size
        of the matrix will be the same.
      PURPOSE: Standard copy constructor. Refer to postcondition
        for description.
    */
    Matrix(const Matrix<T>& source_matrix);

    /*
      DESTRUCTOR: ~Matrix()
      PRE: None
      POST: Deletes each pointer in the array, and the pointer to the
        m_elements array itself. 
      PURPOSE: Called when the Matrix goes out of scope. Returns memory
        to the freestore and eliminates the possibility of dangling pointers
    */
    virtual ~Matrix();

    /*
      OPERATOR: Matrix<T>& operator=(const Matrix<T>& right_hand_side)
        Input: right_hand_side - the matrix to be copied
      PRE: This operator makes use of each element's assignment
        operator by copying each element individually. Only use when storing 
        objects that have their own assignment operator defined!
      POST: Copies right_hand_side into this matrix. Each element and the size
        of the matrix will be the same.
      PURPOSE: Standard assignment operator.  Refer to postcondition for
        description.
    */
    Matrix<T>& operator=(const Matrix<T>& right_hand_side);

    /*
      OPERATOR:T& operator()(const data_size input_row, 
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
      PURPOSE: Element Accessor.  This option is the mutator.
    */
    T& operator()(const data_size input_row, const data_size input_column);

    /*
      OPERATOR:T& operator()(const data_size input_row, 
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
      PURPOSE: Element Accessor.  This option is the accessor.
    */
    T& operator()(const data_size input_row, const data_size input_column) const;

    /*
      FUNCTION: istream& input_stream(istream& in);
        Input: in - the input stream from which to read information
          about the matrix
        Output: Functions like a cin statement.  The matrix is read in
          from numbers entered at the command line
      PRE: Note that this function attempts to input each element in turn.
        Ensure that complex or programmer-defined objects have an input
        operator defined!
      POST: Builds the matrix from user-defined input
      PURPOSE: Allow "cin >> matrix" to function correctly.  Called
        when a Matrix must be read in from user-defined values.
    */
    virtual istream& input_stream(istream& in);

    /*
      FUNCTION: ostream& output_stream(ostream& out) const;
        Input: out - the stream used to display information about
          the matrix to the screen
        Output: Functions like a cout statement.  The matrix is output
          to the screen in the format [e1, e2, e3 ... ek]
      PRE: Note that this function attempts to output each element in turn.
        Ensure that complex or programmer-defined objects have an output 
        operator defined!
      POST: Outputs the matrix to the screen in the foramt defined above. 
      PURPOSE: Allow "cout << matrix" to function correctly. Called
        when the Matrix must be output.
    */
    virtual ostream& output_stream(ostream& out) const;

    /*
      FUNCTION: Matrix_Base<T>& plus_equals(const Matrix<T>& right_hand_side)
        Input: right_hand_side - the Matrix to be added to this matrix instance
        Output: This matrix, after being added to right_hand_side
      PRE: Note that scalar addition among elements is used.  Therefore, 
        this function should only be used on a matrix that holds either scalar
        values or objects that have their own addition operator defined. Note
        that by definition, the matrices being added must have the same number
        of rows and the same number of columns!
      POST: This matrix becomes the result of itself + right_hand_side. The + 
        operation on a matrix simply involves adding each individual member.
      PURPOSE: See post condition. No additional side effects. Implements
        the += operation for all same-sized Matrices.
    */
    virtual Matrix_Base<T>& plus_equals(const Matrix<T>& right_hand_side);
    
    /*
      FUNCTION: Matrix_Base<T>& minus_equals(const Matrix<T>& right_hand_side)
        Input: right_hand_side - the Matrix to be subtracted
          from this matrix instance
        Output: This matrix, after right_hand_side is subtracted from it
      PRE: Note that scalar subtraction among elements is used.  Therefore, 
        this function should only be used on a matrix that holds either scalar
        values or objects that have their own subtraction operator defined. 
        Note that by definition, the matrices being subtracted must have the 
        same number of rows and the same number of columns!
      POST: This Matrix becomes the result of itself - right_hand_side. The - 
        operation on a Matrix simply involves adding each individual member.
      PURPOSE: See post condition. No additional side effects. Implements
        the -= operation for all same-sized Matrices.
    */
    virtual Matrix_Base<T>& minus_equals(const Matrix<T>& right_hand_side);
    
    /*
      OPERATOR: Matrix<T>& operator*=(const double right_hand_side)
        Input: right_hand_side - the scalar value to be multiplied
          by this Matrix instance
        Output: This matrix, after being multiplied 
          by the scalar right_hand_side
      PRE: Note that scalar multiplication among elements is used.  Therefore, 
        this function should only be used on a matrix that holds either scalar
        values or objects that can be multiplied by a scalar value.
      POST: Each member of this Matrix becomes the result of itself * 
        right_hand_side. The * operation on a Matrix simply involves 
        multiplying the scalar by each individual member.
      PURPOSE: See post condition. No additional side effects. Implements
        the *= operation for all Matrices on scalars.
    */
    Matrix<T>& operator*=(const double right_hand_side);

    /*
      OPERATOR: Matrix<T>& operator*=(const Matrix<T>& right_hand_side)
        Input: right_hand_side - the matrix to be multiplied by this one
        Output: This matrix after being multiplied by right_hand_side
      PRE: Note that this operator is memory inefficient as a new matrix of
        the correct size is created (multiplying matrices creates a matrix of 
        adifferent size than the originals) and this matrix simply copies it.
        ALSO, the columns of this matrix must be equal to the rows of 
        right_hand_side! An error is thrown otherwise, since this is a rule of
        mathematics.
      POST: This matrix becomes the result of itself * right_hand_side.  Note 
        that this Matrix's size will change as defined by mathematical matrix
        multiplication.  That is, an mxn matrix * an nxp matrix will output a
        mxp matrix.
      PURPOSE: Matrix multiplication operator.  Sets this matrix equal to
        itself times right_hand_side. See Pre and Post conditions for details.
    */
    Matrix<T>& operator*=(const Matrix<T>& right_hand_side);

    /*
      OPERATOR: Matrix& operator*(const Matrix& left_hand_side,
                                  const Matrix& right_hand_side)
        Input: left_hand_side - the matrix to be multiplied by right_hand_side
               right_hand_side - the matrix to be multiplied by left_hand_side
        Output: This matrix after being multiplied by right_hand_side
      PRE: ALSO, the columns of left_hand_side must be equal to the rows of 
        right_hand_side! An error is thrown otherwise, since this is a rule of
        mathematics.
      POST: Returns the solution of left_hand_side * right_hand_side.  Note 
        that the output Matrix's size will change as defined by mathematical 
        matrix multiplication.  That is, an mxn matrix * an nxp matrix will 
        output a mxp matrix.
      PURPOSE: Matrix multiplication operator.  Returns a matrix equal to
        left_hand_side times right_hand_side. See Pre and Post conditions 
        for details.
    */
    friend Matrix operator*(const Matrix& left_hand_side,
                            const Matrix& right_hand_side)
    {
      Matrix<T> ret_matrix(left_hand_side);
      return ret_matrix *= right_hand_side;
    }

    /*
      OPERATOR: Matrix operator*(const Matrix& left_hand_side,
                                 const double right_hand_side)
        Input: left_hand_side - the Matrix to be multiplied by a scalar value
               right_hand_side - the scalar value to be multiplied
                 by the Matrix left_hand_side
        Output: left_hand_side multiplied by the scalar right_hand_side
      PRE: Note that scalar multiplication among elements is used.  Therefore, 
        this function should only be used on a matrix that holds either scalar
        values or objects that can be multiplied by a scalar value.
      POST: Each member of left_hand_side becomes the result of itself * 
        right_hand_side. The * operation on a Matrix simply involves 
        multiplying the scalar by each individual member.
      PURPOSE: See post condition. No additional side effects. Implements
        the * operation for all Matrices with all basic numeric scalars
    */
    friend Matrix operator*(const Matrix& left_hand_side,
                            const double right_hand_side)
    {
      //No error checking since the *= function has this included
      Matrix<T> ret_matrix(left_hand_side);
      return ret_matrix *= right_hand_side;
    }
    
    /*
      OPERATOR: Matrix<T>& operator/=(const double right_hand_side)
        Input: right_hand_side - the scalar value to be divided
          through this Matrix instance
        Output: This matrix, after being divided by the scalar right_hand_side
      PRE: Note that scalar division among elements is used.  Therefore, 
        this function should only be used on a matrix that holds either scalar
        values or objects that can be divided by a scalar value.
      POST: Each member of this Matrix becomes the result of itself / 
        right_hand_side. The / operation on a Matrix simply involves 
        dividing the scalar by each individual member.
      PURPOSE: See post condition. No additional side effects. Implements
        the /= operation for all Matrices on scalars.
    */
    Matrix<T>& operator/=(const double right_hand_side);

    /*
      OPERATOR: Matrix operator/(const Matrix& left_hand_side,
                                 const double right_hand_side)
        Input: left_hand_side - the Matrix to be divided by a scalar value
               right_hand_side - the scalar value to be the divisor
                 for the Matrix left_hand_side
        Output: left_hand_side divided by the scalar right_hand_side
      PRE: Note that scalar division among elements is used.  Therefore, 
        this function should only be used on a matrix that holds either scalar
        values or objects that can be divided by a scalar value.
      POST: Each member of left_hand_side becomes the result of itself /
        right_hand_side. The / operation on a Matrix simply involves 
        multiplying the scalar by each individual member.
      PURPOSE: See post condition. No additional side effects. Implements
        the / operation for all Matrices with all basic numeric scalars.
    */
    friend Matrix operator/(const Matrix& left_hand_side,
                            const double right_hand_side)
    {
      //No error checking since the /= function has this included
      Matrix<T> ret_matrix(left_hand_side);
      return ret_matrix /= right_hand_side;
    }

    /*
      OPERATOR: Matrix operator-(const Matrix& left_hand_side,
                                 const Matrix& right_hand_side)
        Input: left_hand_side - the original Matrix - will have 
                 right_hand_side subtracted from it
               right_hand_side - the Matrix to be subtracted
                 from the Matrix left_hand_side
        Output: right_hand_side subtracted from left_hand_side
      PRE: Note that scalar subtraction between elements is used.  Therefore, 
        this function should only be used on two matrices that hold either 
        scalar values or objects that can be subtracted from each other.
      POST: The output matrix is the result of left_hand_side - right_hand_side
        The - operation on a Matrix simply involves subtracting each element
        in right_hand_side from its corresponding element in left_hand_side.
      PURPOSE: See post condition. No additional side effects. Implements
        the - operation between two matrices.
    */
    friend Matrix operator-(const Matrix& left_hand_side, 
                            const Matrix& right_hand_side)
    {
      //Size checking will occur in the += operator called below.
      //  Doing so here will simply slow the program down, providing no benefit
      Matrix<T> ret_matrix(left_hand_side);
      return ret_matrix -= right_hand_side;
    }

    /*
      OPERATOR: Matrix operator+(const Matrix& left_hand_side,
                                 const Matrix& right_hand_side)
        Input: left_hand_side - the original Matrix - will have 
                 right_hand_side added to it
               right_hand_side - the Matrix to be added to
                 the Matrix left_hand_side
        Output: right_hand_side added to left_hand_side
      PRE: Note that scalar addition between elements is used.  Therefore, 
        this function should only be used on two matrices that hold either 
        scalar values or objects that can be added to each other.
      POST: The output matrix is the result of left_hand_side + right_hand_side
        The + operation on a Matrix simply involves adding each element
        in right_hand_side to its corresponding element in left_hand_side.
      PURPOSE: See post condition. No additional side effects. Implements
        the + operation between two matrices.
    */
    friend Matrix operator+(const Matrix& left_hand_side, 
                            const Matrix& right_hand_side)
    {
      Matrix<T> ret_matrix(left_hand_side);
      return ret_matrix.plus_equals(right_hand_side);
    }

    /*
      FUNCTION: data_size get_number_of_rows() const
        output: data_size - the number of rows in the matrix
      PRE: None
      POST: Returns the number of rows in the matrix. No side effects.
      PURPOSE: A simple getter that does nothing more than returns the
        number of rows currently in the matrix
    */
    data_size get_number_of_rows() const;
 
    /*
      FUNCTION: data_size get_number_of_columns() const
        output: data_size - the number of columns in the matrix
      PRE: None
      POST: Returns the number of columns in the matrix. No side effects.
      PURPOSE: A simple getter that does nothing more than returns the
        number of columns currently in the matrix
    */
    data_size get_number_of_columns() const;
     
  protected:
    data_size m_rows;
    data_size m_columns;
    T** m_elements;
    static T zero_variable;

    /*
      FUNCTION: void copy(const Matrix<T>& right_hand_side)
        Input: right_hand_side - the matrix to be copied
      PRE: This operator makes use of each element's assignment
        operator by copying each element individually. Only use when storing 
        objects that have their own assignment operator defined!
      POST: Copies just the elements of right_hand_side into this matrix.
        Will not copy variables defining the number of rows or columns.
      PURPOSE: Element copier.  Used as a helper function for the
        copy constructor or assignment operator.
    */
    virtual void copy(const Matrix<T>& right_hand_side);

    /*
      FUNCTION: void copy(const Matrix<T>& right_hand_side)
        Input: right_hand_side - the matrix to be copied
      PRE: This operator makes use of each element's assignment
        operator by copying each element individually. Only use when storing 
        objects that have their own assignment operator defined!
      POST: Copies just the elements of right_hand_side into this matrix.
        Will not copy variables defining the number of rows or columns.
      PURPOSE: Element copier.  Used as a helper function for the
        copy constructor or assignment operator.
    */

    virtual void pointer_copy(const Matrix<T>& right_hand_side);
    
    /*
      FUNCTION: void clear()
      PRE: None
      POST: Deletes each pointer in the array, and the pointer to the
        m_elements array itself. 
      PURPOSE: Called when the Matrix goes out of scope. Returns memory
        to the freestore and eliminates the possibility of dangling pointers
    */
    void clear();
};

#include "matrix.hpp"
#endif //MATRIX_H