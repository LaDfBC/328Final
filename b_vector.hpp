template<class T, class U, double Top_Function(double), 
                           double Left_Function(double), 
                           double Right_Function(double), 
                           double Bottom_Function(double)>
B_Vector::B_Vector(const unsigned short input_points)
{
}

template<class T, class U, double Top_Function(double), 
                           double Left_Function(double), 
                           double Right_Function(double), 
                           double Bottom_Function(double)>
U<T> B_Vector::operator()()
{
  // this stops compiler err
  U<T> return_this;
  return return_this;
}