/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: file_err.cpp
* Purpose: Implementation file for the File_Err class
*/

#include "file_err.h"
using std::string;

File_Err::File_Err(string error_file_name)
{
  file_name = error_file_name;
}

File_Err::~File_Err()
{
  //Intentionally Empty - Will be useful if pointers are added
}

string File_Err::bad_file_name()
{
  return file_name;
}
