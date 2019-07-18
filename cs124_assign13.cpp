/***********************************************************************
* Program:
*    Assignment 13, Expressions
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Write a program to convert Fahrenheit to Celsius. 
*    The function will prompt the user for the Fahrenheit number and 
*    convert it to Celsius.
*
*    Estimated:  0.1 hrs   
*    Actual:     0.1 hrs
*      There was nothing complex or diffult to solve.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * The program will prompt the user for the temperature, 
 * compute the Celsius value, and display the results.
 ***********************************************************************/
int main()
{  
   cout.setf(ios :: fixed);
   cout.precision(0);
   
   float F;
   cout << "Please enter Fahrenheit degrees: ";
   cin >> F;
   float C = 5.0 / 9.0 * (F - 32);
   cout << "Celsius: " << C << endl;
   return 0;
}
