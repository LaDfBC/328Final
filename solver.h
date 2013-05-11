/*
* Programmer: George Mausshardt and Matt Lindsay
* Date: 05/12/2013
* FileName: solver.h
* Purpose: Header file for the base class representing any number of
* differential equation approximaters
*/

#ifndef SOLVER_H
#define SOLVER_H

#include "operator_library.h"

/*
  CLASS: Solver
  PURPOSE: "Base" Class for the Gaussian Elimination and Gauss-Seidel 
    System-of-Equations solver algorithms. Employs the Barton and Nackmann
    trick to serve as a base class and improve speed at runtime.
  TEMPLATES: U - Vector Class
             V - Matrix Class
             DerivedSolver - Name of the derived solver to use
*/
template <class U, class V, class DerivedSolver>
class Solver
{
  public:
    /*
      FUNCTION: DerivedSolver& as_derived()
        Output: DerivedSolver& - the child class solver that needs to
          reference its parent's methods.
      PRE: None
      POST: Returns a reference to the calling child class.  No side effects
      PURPOSE: Work as virtual base classes would, by referencing the child
        when a parent's function is needed.
    */
    DerivedSolver& as_derived() 
    {
      return static_cast<DerivedSolver>(*this);
    }

    /*
      FUNCTION: ostream& output_stream(ostream& out) const
        Input: ostream& - the stream to write to the screen. Dervied solver
          classes will typically output the Matrix, B-Vector, and solution
          vector using this function.
        Output: ostream& - see above; out in this case is simply the parameter
          to hold data changed in the function and intended to be output by the
          user.
      PRE: None. To avoid weird things, pass an empty "out" parameter.
      POST: Returns the solver in an easy-to-read format, as defiend above.
      PURPOSE: Write to the screen as an operator would.  Note that due to the
        implementation, a simple cout << DerivedSolver will work as expected!
    */
    ostream& output_stream(ostream& out) const
    {
      return as_derived(output_stream(out));
    }

    /*
      FUNCTION: int get_convergence_speed()
        Output: int - the number of iterations, moves, or other measurements
          taken by the solver in order to complete its algorithm and solve
          the equations.
      PRE: Call evaluate() first!  The convergence speed variable is set during
        this process and uninitialized beforehand!
      POST: Returns the convergence speed, as defined in the Output section
        above
      PURPOSE: Getter for the convergence speed, as defined in the
        Output section above.
    */
    int get_convergence_speed()
    {
      return as_derived(get_convergence_speed());
    }

    /*
      FUNCTION: U& evaluate()
        Output: U& - A vector containing the solution to the system of linear
          equations passed into the solver class.
      PRE: None
      POST: Calculates and returns the solution vector containing the values
        used to solve the system.  Note that some derived solver evaluate()
        functions may be destructive (modify member variables)!
      PURPOSE: Evaluate and solve the system of equations using the method
        of the Dervied Solver class.
    */
    U& evaluate()
    {
      return as_derived(evaluate());
    }
};

#endif //SOLVER_H