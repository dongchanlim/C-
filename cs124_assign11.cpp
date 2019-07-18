/***********************************************************************
* Program:
*    Assignment 11, Monthly Budget
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Showing a output of monthly budget 
*    using special Characters, which are new-line, 
*    Tab, backlash, and double quotes
*    Estimated:  0.1 hrs   
*    Actual:     0.1 hrs
*      It was straightforward and easy.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Write a program to output your monthly budget
 ***********************************************************************/
int main()
{
   cout.setf(ios  ::fixed);
   cout.setf(ios  ::showpoint);
   cout.precision(2);
  
   // display first row
   cout << "\tItem" << setw(13 + 2 + 10 - 4 - 1) << "Projected" << endl;
   // display each row
   cout << "\t" << string(13,'=') 
       << string(2,' ') << string(10,'=') << endl;
   cout << "\tIncome"
       << setw(13 + 2 - 6 + 1) << "$"
       << setw(9) << 1000.0 << endl;
   cout << "\tTaxes" 
       << setw(13 + 2 - 5 + 1) << "$" 
       << setw(9) << 100.0 << endl;
   cout << "\tTithing" 
       << setw(13 + 2 - 7 + 1) << "$" 
       << setw(9) << 100.0 << endl;
   cout << "\tLiving" 
       << setw(13 + 2 - 6 + 1) << "$" 
       << setw(9) << 650.0 << endl;
   cout << "\tOther" 
       << setw(13 + 2 - 5 + 1) << "$" 
       << setw(9) << 90.0 << endl;
   cout << "\t" 
       << string(13,'=') << string(2,' ') 
       << string(10,'=') << endl;
   cout << "\tDelta" 
       << setw(13 + 2 - 5 + 1) << "$"
       << setw(9) << 60.0 << endl;
   return 0;
}
