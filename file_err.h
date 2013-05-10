/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: file_err.h
* Purpose: Header file for the File_Err class
*/

#ifndef FILE_ERR_H
#define FILE_ERR_H

#include <string>
using std::string;

class File_Err
{
  public:
    /* 
      CONSTRUCTOR: File_Err(T error_file_name)
        Input: int error_file_name - the name of the file causing an error
      PRE: None
      POST: Sets file_name equal to error_file_name
      PURPOSE: The constructor for this error class.  Takes the offending
                 variable and uses it to construct an instance of the class
    */
    File_Err(string error_file_name);
    /* 
      DESTRUCTOR: ~File_Err()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers are involved, this empty function 
                 makes the class more scalable.
    */
    ~File_Err();

    /* 
      FUNCTION: T bad_file_name()
      PRE: None
      POST: Passes the error-causing variable to the caller.
      RETURNS: A string value representing the name of the error-causing file
    */
    string bad_file_name();

  private:
    string file_name; // The naame of the file causing an error
};

#endif // FILE_ERR_H
