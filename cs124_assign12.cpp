/***********************************************************************
* Program:
*    Assignment 12, Input and Variables
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    In the first place, Using cin function to prompt the user input and display it.
*    Using a variable to store data and display the result.
*
*    Estimated:  0.1 hrs   
*    Actual:     0.1 hrs
*      There was no difficult part at all.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Display the prompts user's income as float and display result.
 ***********************************************************************/
int main()
{
   cout.setf(ios  ::fixed);
   cout.setf(ios  ::showpoint);
   cout.precision(2);
    
   cout << "\tYour monthly income: ";
   float income;
   cin >> income;
   cout << "Your income is: " << "$" << setw(9) << income << endl;
   return 0;
}
