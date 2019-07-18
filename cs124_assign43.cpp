/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Write a program to convert feet to meters getting input from
*    command line.
*
*    Estimated:  0.3 hrs   
*    Actual:     0.3 hrs
*      There is nothing hard or difficult to solve.
************************************************************************/

#include <cstdlib>
#include <iostream>
using namespace std;

/**********************************************************************
 * convert feet to meters getting input from command line.
 ***********************************************************************/
int main(int argc, char **argv)
{
   cout.setf(ios  ::fixed);
   cout.precision(1);
   float meters[argc - 1];
   for (int count = 1; count < argc; count++)
   {
      meters[count] = atof(argv[count]);
      cout << meters[count] << " feet is " <<  0.3048 * meters[count] 
         << " meters" << endl;
   }
   return 0;
}



























