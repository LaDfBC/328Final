/*
* Programmer: George Mausshardt
* Date: 04/22/2013
* FileName: file_stream.h
* Purpose: Header file for the File_Stream class
*/
#ifndef FILE_STREAM_H
#define FILE_STREAM_H

#include <vector>
#include <fstream>
#include <string>
#include "matrix_vector.h"
#include "matrix.h"

using std::string;
using std::fstream;

/*
  CLASS: File_Stream
    PURPOSE: Define a group of functions to make File I/O simpler
    MEMBER VARIABLES:
      string m_file_name: The name of the file with which this instance of the 
        class is working.
      short m_num_lines: If the file has a number representing the total number 
        of lines in the file, it is stored here. Value is -1 otherwise
      fstream m_file_instance: The stream ("cursor") used to work with the file.
    NOTE: This class has little functionality, but can easily be scaled to work
      with other types of files simply by adding one function associated with
      each new type of file!
*/
template <class T, class U>
class File_Stream
{
  public:
    /*
      CONSTRUCTOR: File_Stream(string input_file_name)
        Input: string input_file_name - the name of the file to be used
         and handled in this class
      PRE: None
      POST: Sets file_name equal to input_file_name
      PURPOSE: Create this instance of a file stream.  Names the file but
        does no other function.  The file is NOT OPENED with this constructor!
    */
    File_Stream(const string input_file_name);
    /* 
      DESTRUCTOR: ~File_Stream()
      PRE: None
      POST: None
      PURPOSE: None currently. If pointers are involved, this empty function 
        makes the class more scalable.
    */
    ~File_Stream();

    /*
      FUNCTION: U matrix_vector_read_all()
      PRE: The file to be read is stored in the proper format. This format
        includes a number at the top dictating the number of elements in each 
        vector, with the vectors space-deliminted below.
      POST: Reads the vectors from the file and returns them. The cursor in the
        file is now at the end of the file.
      PURPOSE: Read many vectors from a file in a designated format.
    */
    U matrix_vector_read_all();

    /*
      FUNCTION: T matrix_read_all()
      PRE: The file to be read is stored in the proper format. This format
        includes a number at the top dictating number of rows and columns, 
        with the rest of the matrix space-delimited below.
      POST: Reads the matrix from the file and returns it. The cursor in the
        file is now at the end of the matrix part of the file. Many times,
        a B-Vector as a solution to a system of linear equations is stored
        below the matrix.
      PURPOSE: Read entire matrices from a file in a designated format.
    */
    T matrix_read_one();

    /*
      FUNCTION: U matrix_read_b_vector(const data_size m_rows)
      PRE: The file to be read is stored in the proper format and the
        cursor in the file is set to the right spot.  This function
        will read a single vector with m_rows number of elements in a 
        space-deliminted format.
      POST: Reads and returns a vector representing the end numbers in a
        system of linear equations.
      PURPOSE: Read a B-Vector from a file.  See precondition for when it
        is appropriate to use this function.
    */
    U matrix_read_b_vector(const data_size m_rows);

    /*
      FUNCTION: void file_open()
      PRE: None
      POST: Opens the file defined by m_file_name if not already open.
        (Does nothing [no error!] if the file is already open)
      PURPOSE: Open the file defined by m_file_name so that other 
        functions may use it.
    */
    void file_open();
    /*
      FUNCTION: void file_close()
      PRE: None
      POST: Closes the file defined by m_file_name if open.
        (Does nothing [no error!] if the file is not open)
      PURPOSE: Closes the file defined by m_file_name.
    */
    void file_close();

  private:
    string m_file_name; // Name of the file 
    short m_num_lines; // Number of lines of data in the file. -1 if not used
    fstream m_file_instance; // The file stream

    /*
      FUNCTION: U matrix_vector_read_one
        (const unsigned short matrix_vector_size)
      PRE: Reads one vector from a file in the proper format.  See the
        precondition for matrix_vector_read_all for the full description of
        proper file formats and important factors to watch out for.
      POST: Returns one vector to the calling function. The cursor in the file
        is advanced one line.
      PURPOSE: Helper function for matrix_vector_read_all.  Called multiple
        times in a loop to read vectors one by one.
    */
    U matrix_vector_read_one(const unsigned short matrix_vector_size);

    /*
      FUNCTION: T matrix_read_column()
      PRE: Reads one columns from a file in the proper format.  See the
        precondition for matrix_read_all for the full description of
        proper file formats and things to watch out for.
      POST: Returns one line of a matrix to the calling function.  The cursor
        in the file is advanced one line.
      PURPOSE: Helper function for matrix_read_all.  Called multiple times to 
        iteratively build a matrix.
    */
    T matrix_read_column();
};

#include "file_stream.hpp"

#endif // FILE_STREAM_H