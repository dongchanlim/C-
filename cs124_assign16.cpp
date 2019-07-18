/***********************************************************************
* Program:
*    Assignment 16, If Statements
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Use if statement 
*    Estimated:  0.1 hrs   
*    Actual:     0.1 hrs
*      There was nothing complicated or difficult to solve.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* write the function to determine which tax bracket a user is in 
* according to income input
************************************************************************/
int computeTax(int income)
{
   int bracket;
   if (income < 15100)
      bracket = 10;
   else if (income < 61300)
      bracket = 15;
   else if (income < 123700)
      bracket = 25;
   else if (income < 188450)
      bracket = 28;
   else if (income < 336550)
      bracket = 33;
   else
      bracket = 35;
   return bracket;
}

/**********************************************************************
 * prompts the user for his or her income and accepts the result 
 * from the computeTax() function and displays the result to the screen 
 * with a "%" after the number.
 ***********************************************************************/
int main()
{  
   int income;
   cout << "Income: ";
   cin >> income;
   int bracket = computeTax(income);
   cout << "Your tax bracket is " << bracket << "%" << endl;
   return 0;
}
