#ifndef B_VECTOR_H
#define B_VECTOR_H

template<class T, double Top_Function(double), 
                  double Left_Function(double), 
                  double Right_Function(double), 
                  double Bottom_Function(double)>
class B_Vector
{
  public:
    B_Vector(const unsigned short input_points);
    Matrix_Vector<T> operator()();
  private:
    unsigned short m_num_points;
};

#include "b_vector.hpp"
#endif