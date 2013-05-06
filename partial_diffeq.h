/*
* Programmers: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: partial_diffeq.h
* Purpose: Header file for the functor whose purpose is to
*   define a partial differential equation
*/

#ifndef PARTIAL_DIFFEQ_H
#define PARTIAL_DIFFEQ_H

template<class T, class U, class V, double Top_Function(double), 
                                    double Left_Function(double), 
                                    double Right_Function(double), 
                                    double Bottom_Function(double)>
class Partial_DiffEQ
{
  public:
    Partial_DiffEQ(const unsigned short input_points);

    //Matt, what is this going to do in the PDE class? Also, it needs to be generic - Use T, not Matrix_Vector<T>
    T operator()();
	
    V& get_a_matrix();
    U& get_b_vector();
    void set_x_vector_index(const short input_index, const T input_data);

    ostream& output_stream(ostream& out) const;
    
  private:
    void init_vectors(const unsigned short input_points);
    void init_a_matrix(const unsigned short input_points);
    unsigned short m_num_points;
    U m_b_vector;
    U m_x_vector;
    V m_a_matrix;
};

#include "partial_diffeq.hpp"
#endif // PARTIAL_DIFFEQ_H