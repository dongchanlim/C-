/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*     1. add all the multiples of 7 that are less than 100
*     2. add all the multiples of 3 that are less than 100
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * get user's input and get sum of the multiples of numbers 
 * and display it
 ***********************************************************************/
void Less100Sum()
{
   int multiple;
   cout << "What multiples are we adding? ";
   cin >> multiple;
   int sum = 0;
   for (int i = multiple; i < 100; i += multiple)
   {
      sum += i;
   }
   cout << "The sum of multiples of " << multiple
      << " less than 100 are: "
      << sum << endl;
}


/**********************************************************************
 * write a program to get user's inputs and add 
 * all the multiples of input number that are less than 100
 ***********************************************************************/
int main()
{
   Less100Sum();
   return 0;
}
