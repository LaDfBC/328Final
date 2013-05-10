/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: Matrix_Vector.h
* Purpose: Header file for the Matrix_Vector class
*/

#ifndef MATRIX_VECTOR_H
#define MATRIX_VECTOR_H

#include <cstdlib>
#include <iostream>
#include <cmath>
#include "range_err.h"
#include "size_err.h"	
#include "div_zero_err.h"
#include "size_difference_err.h"

using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::endl;

/* CLASS: Matrix_Vector
     PURPOSE: Provide an easy-to-use vector, a common structure used in linear
       algebra, as well as defining a number of function to operate on multiple
       vectors.  To avoid conflicts with the C++ vectors, these are named 
       Matrix_Vectors. 
     MEMBER VARIABLES:
       unsigned short m_size - The number of elements in the Matrix_Vector
       T* m_data[] - A pointer to the data contained in the Matrix_Vector
*/
template <class T>
class Matrix_Vector
{
  public:
    /*
      CONSTRUCTOR: Matrix_Vector()
      PRE: None
      POST: Creates an empty, 0-sized Matrix_Vector
      PURPOSE: Default constructor. Creates a Matrix_Vector of size 0.
        This means there is no data in a Matrix_Vector created by default!
        Be careful when using this constructor!
    */
    Matrix_Vector();
   
    /*
      CONSTRUCTOR: Matrix_Vector(unsigned short const vector_size)
        Input: vector_size - the number of elements in
          the newly created Matrix_Vector
      PRE: vector_size must be greater than 0. A vector with size less than
        zero is undefined!
      POST: Creates a Matrix_Vector of size vector_size, filled with 0's
      PURPOSE: Size-fed constructor. Creates a Matrix_Vector of size 
        vector_size. Every element in this vector will be a 0.  Make sure
        to fill it with data before using it or errors may be thrown!
    */
    Matrix_Vector(unsigned short const vector_size);
    
    /*
      CONSTRUCTOR: Matrix_Vector(const Matrix_Vector<T>& right_hand_side)
        Input: right_hand_side - the Matrix_Vector to which this new instance
          will be set equal.
      PRE: Note that element-by-element assignment will occur.  Only use this
        constructor on a Matrix_Vector that stores scalar element or elements
        that otherwise have an assignment operator (=) defined!
      POST: Constructs a new Matrix_Vector identical to right_hand_side. Every
        element will be the same and their sizes will be set to the same value.
      PURPOSE: Copy Constructor. Used to create an identical copy to a
        Matrix_Vector that already exists in a program.  All aspects of the 
        new Matrix_Vector will be equal to the copied version.
    */
    Matrix_Vector(const Matrix_Vector<T>& right_hand_side);

    /*
      DESTRUCTOR: ~Matrix_Vector()
      PRE: None
      POST: Deletes the pointer to the m_data array
      PURPOSE: Called when a Matrix_Vector leaves scope. Automatically
        returns memory to the freestore. A STORE WHERE THINGS ARE FREE? COOL!
    */
    ~Matrix_Vector();

    /*
      FUNCTION: void set_vector_size(short new_vector_size)
        Input: new_vector_size - the size to which this Matrix_Vector 
         is to be set.
      PRE: A backup of the current data stored in m_data, if desired. See the
        postcondition. In addition, new_vector_size must be greater than 0. A 
        vector with size less than zero is undefined!
      POST: This Matrix_Vector's size is set equal to new_vector_size.
        Note that all data stored in this Matrix_Vector is deleted when this
        function is called!  If you need the data, copy it to another 
        Matrix_Vector before making the call!
      PURPOSE: Allows this Matrix_Vector to be resized on the fly. However,
        simply call the assignment operator if you would like this instance
        to be set equl to another Matrix_Vector.
    */
    void set_vector_size(short new_vector_size);

    /*
      FUNCTION: void copy(const Matrix_Vector<T>& right_hand_side)
        Input: right_hand_side - the Matrix_Vector to which this new instance
          will be set equal.
      PRE: Note that element-by-element assignment will occur.  Only use this
        function on a Matrix_Vector that stores scalar element or elements
        that otherwise have an assignment operator (=) defined!
      POST: Constructs a new Matrix_Vector identical to right_hand_side. Every
        element will be the same and their sizes will be set to the same value.
      PURPOSE: Copier Function. Used to create an identical copy to another
        Matrix_Vector in the same program.  All aspects of the 
        new Matrix_Vector will be equal to the copied version.
    */
    void copy(const Matrix_Vector<T>& right_hand_side);

    /*
      OPERATOR: T& operator[](unsigned short const data_location)
        Input: unsigned short data_location - the integer index of 
          a specific number in the Matrix_Vector. Zero indexed.
        Output: The numeric at the position defined by data_location
      PRE: data_location between 0 and Matrix_Vector_size - 1, inclusive
      POST: Returns the data at data_location, as defined above
      PURPOSE: Indexing operator. Make the Matrix_Vector able to be referenced
        the same as a array. 
      NOTE: This version of the function is called on assignment. The
        original Matrix_Vector is changed!
    */
    T& operator[](unsigned short const data_location);

    /*
      OPERATOR: T& operator[](unsigned short const data_location) const
        Input: unsigned short data_location - the integer index of 
          a specific number in the Matrix_Vector. Zero indexed.
        Output: The numeric at the position defined by data_location
      PRE: data_location between 0 and Matrix_Vector_size - 1, inclusive
      POST: Returns the data at data_location, as defined above
      PURPOSE: Indexing operator. Make the Matrix_Vector able to be referenced
        the same as a array. 
      NOTE: This version of the function is called for reference. The
        original Matrix_Vector is NOT changed!
    */
    T& operator[](unsigned short const data_location) const;

    /*
      OPERATOR: Matrix_Vector<T>& operator+=(
                                       const Matrix_Vector<T>& right_hand_side)
        Input: const Matrix_Vector<T>& right_hand_side - the Matrix_Vector 
          to be added to the Matrix_Vector stored in this instance of the class
      PRE: Note that scalar addition among elements is used.  Therefore, 
        this function should only be used on a vector that holds either scalar
        values or objects that have their own addition operator defined.
      POST: This Matrix_Vector becomes the result of itself + right_hand_side.
        The + operation on a Matrix_Vector simply involves adding each
        individual member.
      PURPOSE: See post condition. No additional side effects. Implements
        the += operation for all Matrix_Vectors AND Matrix_Vector += (scalar)
    */
    Matrix_Vector<T>& operator+=(const Matrix_Vector<T>& right_hand_side);

     
    /*
      OPERATOR: Matrix_Vector<U>& operator+(
                                       const Matrix_Vector<U>& left_hand_side
                                       const Matrix_Vector<T>& right_hand_side)
        Input: const Matrix_Vector<T>& right_hand_side - the Matrix_Vector to be
          added to left_hand_side
               const Matrix_Vector<T>& left_hand_side - the Matrix_Vector to be
          added to right_hand_side
        Output: Matrix_Vector<T>& - the sum of left_hand_side and 
          right_hand_side.
      PRE: None
      POST: The Matrix_Vectors left_hand_side and right_hand_side are added
        together to produce the output Matrix_Vector
        The + operation on a Matrix_Vector simply involves adding each
        individual member.
      PURPOSE: See post condition. No additional side effects. Implements
        the + operation for all Matrix_Vectors.
    */ 
    friend Matrix_Vector operator+(const Matrix_Vector& left_hand_side, 
                                const Matrix_Vector& right_hand_side)
    {
      
      if (right_hand_side.m_size != left_hand_side.m_size)
      {
        throw Size_Difference_Err(right_hand_side.m_size,
                                  left_hand_side.m_size);
      }

      Matrix_Vector<T> ret_Matrix_Vector(left_hand_side);
      return ret_Matrix_Vector += right_hand_side; 
    }

    /*
      OPERATOR: Matrix_Vector<T>& operator-=(
                                       const Matrix_Vector<T>& right_hand_side)
        Input: const Matrix_Vector<T>& right_hand_side - the Matrix_Vector 
          to be subtracted from the Matrix_Vector stored in this instance 
          of the class
      PRE: Note that scalar subtraction among elements is used.  Therefore, 
        this function should only be used on a vector that holds either scalar
        values or objects that have their own subtraction operator defined.
      POST: This Matrix_Vector becomes the result of itself - right_hand_side.
        The - operation on a Matrix_Vector simply involves subtracting each
        individual member.
      PURPOSE: See post condition. No additional side effects. Implements
        the -= operation for all Matrix_Vectors AND Matrix_Vector -= (scalar)
    */
    Matrix_Vector<T>& operator-=(const Matrix_Vector<T>& right_hand_side);

    /*
      OPERATOR: Matrix_Vector<U>& operator-(
                                       const Matrix_Vector<U>& left_hand_side
                                       const Matrix_Vector<T>& right_hand_side)
        Input: const Matrix_Vector<T>& right_hand_side - the Matrix_Vector 
          to be subtracted from left_hand_side
               const Matrix_Vector<T>& left_hand_side - the 
          original Matrix_Vector
        Output: Matrix_Vector<T>& - the difference between left_hand_side and 
          right_hand_side.
      PRE: Note that scalar addition among elements is used.  Therefore, 
        this function should only be used on a vector that holds either 
        scalar values or objects that have their own addition operator defined.
      POST: The Matrix_Vectors right_hand_side is subtracted from 
        left_hand_sidebto produce the output Matrix_Vector
        The - operation on a Matrix_Vector simply involves subtracting the
        second Matrix_Vector from the first one.
      PURPOSE: See post condition. No additional side effects. Implements
        the - operation for all Matrix_Vectors.
    */
    friend Matrix_Vector operator-(const Matrix_Vector& left_hand_side, 
                                const Matrix_Vector& right_hand_side)
    {
      if (right_hand_side.m_size != left_hand_side.m_size)
      {
        throw Size_Difference_Err(right_hand_side.m_size,
                                  left_hand_side.m_size);
      }

      Matrix_Vector<T> ret_Matrix_Vector(left_hand_side);
      return ret_Matrix_Vector -= right_hand_side; 
    }

    /*
      OPERATOR: Matrix_Vector<T> operator/(const double right_hand_side)
        Input: right_hand_side - the scalar number to be divided
          by this Matrix_Vector
        Output: A (new) matrix_vector as the result of *this / right_hand_side
      PRE: right_hand_side should not be 0 or a division by zero error will
        be thrown! Note that each element will be divided by right_hand_side
        so only call this function when the Matrix_Vector holds scalar values
        or a class with an operator to handle scalar division
      POST: returns *this / right_hand_side, as defined above
      PURPOSE: Define Matrix_Vector/scalar division. 
    */
    Matrix_Vector<T> operator/(const double right_hand_side) const;

    /*
      OPERATOR: Matrix_Vector<T> operator/=(const double right_hand_side)
        Input: right_hand_side - the scalar number to be divided
          by this Matrix_Vector
        Output: This matrix_vector, modified to be the result of 
          *this / right_hand_side
      PRE: right_hand_side should not be 0 or a division by zero error will
        be thrown! Note that each element will be divided by right_hand_side
        so only call this function when the Matrix_Vector holds scalar values
        or a class with an operator to handle scalar division
      POST: returns *this = *this / right_hand_side, as defined above
      PURPOSE: Define Matrix_Vector/scalar division, for shortcut 
        division-assignment
    */
    Matrix_Vector<T>& operator/=(const double right_hand_side);

    /*
      OPERATOR: Matrix_Vector<T> operator*(double right_hand_side)
        Input: right_hand_side - the scalar number to multiply
          by this matrix_vector
        Output: A matrix_vector as the result of *this * right_hand_side
      PRE: Note that each element will be multiplied by right_hand_side,
        so only use this function with a Matrix_Vector filled with scalar
        values or classes that have a scalar multiplication defined
      POST: returns *this = *this * right_hand_side, as defined above
      PURPOSE: Define Matrix_Vector * scalar multiplication
    */
    Matrix_Vector<T> operator*(const double right_hand_side);

    /*
      OPERATOR: Matrix_Vector<T> operator*=(double right_hand_side)
        Input: right_hand_side - the scalar number to multiply
          by this matrix_vector
        Output: A matrix_vector as the result of *this * right_hand_side
      PRE: Note that each element will be multiplied by right_hand_side,
        so only use this function with a Matrix_Vector filled with scalar
        values or classes that have a scalar multiplication defined
      POST: returns *this = *this * right_hand_side, as defined above
      PURPOSE: Define Matrix_Vector * scalar multiplication, for shortcut
        multiplication-assignment
    */
    Matrix_Vector<T>& operator*=(const double right_hand_side);

    /*
      OPERATOR: Matrix_Vector<T> operator-()
        Output: Returns the negation of this Matrix_Vector
      PRE: None
      POST: The Matrix_Vector's negation is returned.  This original
        Matrix_Vector is unaffected by the operator call
      PURPOSE: This operator simply computes the negation and returns it.
        You must explicitly set the Matrix_Vector equal to the function's output
        to change the original
    */
    Matrix_Vector<T> operator-();
 
    /* 
      OPERATOR Matrix_Vector<T>& operator=(
                                       const Matrix_Vector<T>& right_hand_side)
        Input: right_hand_side - the Matrix_Vector to be set equal to
        Output: *this, after being set equal to right_hand_side
      PRE: None
      POST: This Matrix_Vector is set equal to right_hand_side
      PURPOSE: Assignment operator - makes this Matrix_Vector a replica of
        right_hand_side.
    */
    Matrix_Vector<T>& operator=(const Matrix_Vector<T>& right_hand_side);

          
    /*
      OPERATOR: bool operator==(const Matrix_Vector<T>& right_hand_side) const
        Input: const Matrix_Vector<T>& right_hand_side - the Matrix_Vector to
          compare to the Matrix_Vector stored in this class
        Output: True if the two Matrix_Vectors are replicas of each other.
          False otherwise.
      PRE: Comparisons between each individual element are executed. Do not
        call this function unless the elements in this Matrix_Vector are scalar
        or have their equal operator (==) defined!
      POST: Returns true or false as defined above. No side effects.
      PURPOSE: Equality operator - Tests if two Matrix_Vectors are the same
    */
    bool operator==(const Matrix_Vector<T>& right_hand_side) const;
      
    /*
      OPERATOR: bool operator!=(const Matrix_Vector<T>& right_hand_side) const
        Input: const Matrix_Vector<T>& right_hand_side - the Matrix_Vector to
          compare to this Matrix_Vector
        Output: True if the two Matrix_Vectors are NOT replicas of each other.
          False if they are exactly the same.
      PRE: Comparisons between each individual element are executed. Note that 
           this function invokes the == operator on individual elements, but
           does NOT invoke the != operator on individual elements.  Therefore,
           do not  call this function unless the elements in this Matrix_Vector 
           are scalar or have their equal operator (==) defined!
      POST: Returns true or false as defined above. No side effects.
      PURPOSE: Equality operator - Tests if two Matrix_Vectors are different
    */
    bool operator!=(const Matrix_Vector<T>& right_hand_side) const;

    /*
      OPERATOR: ostream& operator<<(ostream& out, 
                                const Matrix_Vector<U>& calling_matrix_vector);
        Input: ostream& out - the stream used to display information about
          the Matrix_Vector to the screen
               const Matrix_Vector<U> calling_Matrix_Vector - the Matrix_Vector
          to be displayed to the screen in proper format
        Output: Functions like a cout statement.  The Matrix_Vector is output
          to the screen in the format [e1, e2, e3 ... ek]
      PRE: Note that this function attempts to output each element in turn.
        Ensure that complex or programmer-defined objects have an output 
        operator defined!
      POST: Outputs the Matrix_Vector to the screen in the foramt defined
        above. 
      PURPOSE: Allow "cout << Matrix_Vector" to function correctly. Called
        when the Matrix_Vector must be output.
    */
    template <class U>
    friend ostream& operator<<(ostream& out, 
                               const Matrix_Vector<U>& calling_matrix_vector);
   
    /*
      OPERATOR: istream& operator>>(istream& in, 
                                const Matrix_Vector<U>& calling_Matrix_Vector);
        Input: istream& in - the input stream from which to read information
          about the Matrix_Vector
               const Matrix_Vector<U>& calling_Matrix_Vector - the 
          Matrix_Vector to be built from the input on the command line
        Output: Functions like a cin statement.  The Matrix_Vector is read in
          from numbers entered at the command line
      PRE: Note that this function attempts to input each element in turn.
        Ensure that complex or programmer-defined objects have an input
        operator defined!
      POST: Builds the Matrix_Vector from user-defined input
      PURPOSE: Allow "cin >> Matrix_Vector" to function correctly.  Called
        when a Matrix_Vector must be read in from user-defined values.
    */
    template <class U>
    friend istream& operator>>(istream& in, 
                               const Matrix_Vector<U>& calling_Matrix_Vector);

    /*
      OPERATOR: double dot_product(
                             const Matrix_Vector<T>& right_hand_side) const;
        Input: right_hand_side - the Matrix_Vector to be used with this vector
          to calculate the dot product of the two
        Output: double - the dot product of right_hand_side and 
          this matrix_vector
      PRE: Note that this function uses multiplication of each
        individual element, so only call this function on Matrix_Vectors that
        hold scalar elements or classes with a multiplication operator defined
      POST: Returns the dot product of the two vectors.  This is defined as
        the sum of the products of corresponding elements in the two vectors
      PURPOSE: Return the dot product as defined in the post condition. This
        is the version to be called by a Matrix_Vector directed toward another.
    */

    double dot_product(const Matrix_Vector<T>& right_hand_side) const;

    /*
      FUNCTION: double dot_product(const Matrix_Vector<U>& left_hand_side,
                      const Matrix_Vector<U>& right_hand_side)
        Input: right_hand_side - the Matrix_Vector to be used with 
          left_hand_side to calculate the dot product of the two
               left_hand_side - the Matrix_Vector to be used with
          right_hand_side to calculate the dot product of the two
        Output: double - the dot product of right_hand_side and 
          left_hand_side
      PRE: Note that this function uses multiplication of each
        individual element, so only call this function on Matrix_Vectors that
        hold scalar elements or classes with a multiplication operator defined
      POST: Returns the dot product of the two vectors.  This is defined as
        the sum of the products of corresponding elements in the two vectors
      PURPOSE: Return the dot product as defined in the post condition. This
        is the version to be called by an outside function on two 
        Matrix_Vectors of choice.
    */
    template <class U>
    friend double dot_product(const Matrix_Vector<U>& left_hand_side,
                      const Matrix_Vector<U>& right_hand_side);

    /*
      FUNCTION: double mag() const
        Output: The magnitude of this matrix_vector. The magnitude is defined
          as the square root of the sum of the squares of the vector's
          components.
      PRE: None
      POST: Returns the magnitude as defined above.
      PURPOSE: Return the magnitude of the matrix_vector. This is identical to
        the L2 Norm, but this function is included for ease-of-use by users
        who are not mathematically inclined or who would like to know a 
        vector's magnitude without worrying about normalization.
    */
    double mag() const;

    /* 
      FUNCTION: unsigned short size() const
        Output: Finds and returns m_size, the number of elements in this vector
      PRE: None
      POST: Returns m_size.  This value represents the size, or number of
        elements in this Maatrix_Vector
      PURPOSE: Serve as the accessor for the variabale m_size. Commonly
        used in for-loops to determine the length of the Matrix_Vector
    */
    unsigned short size() const;

  private:
    T* m_data; // A pointer to the data stored in the Matrix_Vector
    unsigned short m_size; // The number of elements in the Matrix_Vector
};

#include "matrix_vector.hpp"
#endif // MATRIX_VECTOR_H