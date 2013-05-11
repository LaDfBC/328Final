/*
* Programmers: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: partial_diffeq.h
* Purpose: Header file for the functor whose purpose is to
*   define a partial differential equation
*/

#ifndef PARTIAL_DIFFEQ_H
#define PARTIAL_DIFFEQ_H

#include <iostream>

/*
  CLASS: Partial_DiffEQ
    Member Variables: m_num_points - the number of points in a row of the
      approximation mesh, minus one.
                      U m_b_vector -the right hand side of the system of
      equations - the values to be set equal to
                      U m_x_vector - the solution vector, storing the result
      of the system of equations
                      V m_a_matrix - the matrix storing the system of equations
  PURPOSE: Stores a partial differential equation and the matrix and vectors
    required to hold the data.

  TEMPLATES: T - the built-in type used in the differential equation
             U - a vector class with accessor operator
             V - a matrix class with accessor operator
             Functions - the functions at the boundaries of the mesh,
               as hinted at by the names of the templates
*/
template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
class Partial_DiffEQ
{
  public:
    /*
      CONSTRUCTOR: Partial_DiffEQ(const unsigned short input_points)
        Input: input_points - the number of points in a row in the
          mesh, minus one.
      PRE: None
      PURPOSE: Required constructor - takes in the number of poitns in a row
        in the matrix, minus one.
    */
    Partial_DiffEQ(const unsigned short input_points);

    Partial_DiffEQ(const Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                        Right_Function, Bottom_Function>& input_diffeq);

    Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                        Right_Function,Bottom_Function>&
    operator=(Partial_DiffEQ<T, U, V, Top_Function,Left_Function,
                        Right_Function,Bottom_Function>& input_diffeq);

    /*
      FUNCTION: V& get_a_matrix() const;
      PRE: None
      POST: Returns (a reference to) the matrix representing the system of 
        equations stored in this class.
      PURPOSE: Getter for the A-Matrix stored in this differential equation
    */
    V& get_a_matrix() const;

    /*
      FUNCTION: U& get_b_vector() const;
      PRE: None
      POST: Returns (a reference to) the vector representing the right hand
        side of the system of equations.
      PURPOSE: Getter for the (reference to) vector of values set equal to 
        A times the coefficients.
    */
    U get_b_vector() const;

    T get_num_points() const { return m_num_points; }

    /*
      FUNCTION: void set_x_vector_index(const short input_index, 
                                        const T input_data)
      PRE: None
      POST: Sets x_vector[input_index] equal to input_data
      PURPOSE: Setter for individual elements in the b-vector.  Used to set
        elements of the vector to desired values.
    */
    void set_x_vector_index(const short input_index, const T input_data);

    void set_x_vector(const U& input_vector) {m_x_vector = input_vector;}
   
    /*
      FUNCTION: ostream& output_stream(ostream& out) const
      PRE: None. To avoid strange behavior, pass an empty out parameter
        to the function so only the class's member variables are output.
      POST: Returns a stream that will be outputted to the screen.  The stream
        outputs the solution matrix.
      PURPOSE: Output the differential equation information and allow a call
        such as cout << DiffEQ to function properly.
    */
    ostream& output_stream(ostream& out) const;
    
  private:
    /*
      FUNCTION: void init_vectors(const unsigned short input_points);
        Input: input_points - the number of points in a single row 
          of the approximation mesh, minus one
      PRE: None
      POST: Initializes the x-vector to 0 and the B-Vector to the values
        associated with the partial differential equation approximation,
        ((1/M) * b) - (h^2 / 4) * forcing function
      PURPOSE: Initialize the vectors to their respective useful values
        so that the differential equation can subsequently be used
        properly.
    */
    void init_vectors(const unsigned short input_points);

    /*
      FUNCTION: void init_a_matrix(const unsigned short input_points);
        Input: input_points - the number of points in a single row 
          of the approximation mesh, minus one
      PRE: None
      POST: Initializes the A-Matrix according to the approximation rules
        discussed previously.  They are too lengthy to explain here, but
        noticing the patterns in the matrices should be sufficient.
      PURPOSE: Initialize the matrix to its correct values so that the
        differential equation can be used properly.
    */
    void init_a_matrix(const unsigned short input_points);
    unsigned short m_num_points;
    U m_b_vector;
    U m_x_vector;
    V m_a_matrix;
};

#include "partial_diffeq.hpp"
#endif // PARTIAL_DIFFEQ_H