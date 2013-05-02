template<class T, double Top_Function(double), 
                  double Left_Function(double), 
                  double Right_Function(double), 
                  double Bottom_Function(double)>
B_Vector<T,Top_Function,Left_Function,Right_Function,Bottom_Function>::
B_Vector(const unsigned short input_points)
{
}

template<class T, double Top_Function(double), 
                  double Left_Function(double), 
                  double Right_Function(double), 
                  double Bottom_Function(double)>
Matrix_Vector<T> 
B_Vector<T,Top_Function,Left_Function,Right_Function,Bottom_Function>::
operator()()
{
  // this stops compiler err
  Matrix_Vector<T> return_this;
  return return_this;
}