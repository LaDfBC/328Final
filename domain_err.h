#ifndef DOMAIN_ERR_H
#define DOMAIN_ERR_H

template<class T>
class Domain_Err
{
  public:
    Domain_Err(short a_matrix_size, short b_vector_size);
    ~Domain_Err();
    short bad_matrix_size();
    short bad_vector_size();

  private:
    short matrix_size;
    short vector_size;
};

#include "domain_err.hpp"
#endif