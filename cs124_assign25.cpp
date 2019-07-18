/***********************************************************************
* Program:
*    Assignment 25, Loop Design
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    display a calendar on the screen by using two parameters
*    numDays, offset. This program must work with loops
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
* display a calendar on the screen based off numDays, offset
***********************************************************************/
void displayTable(int& numDays,int& Offset)
{
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
   cout << setw(4 + (Offset + 1) % 7 * 4);
   for (int i = 1; i <= numDays; i++)
   {
      cout << i << setw(4); 
      for (int j = 7 - ((Offset + 1) % 7); j < numDays; j += 7)
      {
         if (i == j)
            cout << endl << setw(4);
      }
      if (i == numDays)
         cout << endl;     
   }
   return;
}

/**********************************************************************
* prompts the user for the number of days in the month and the offset
***********************************************************************/
int main()
{
   int numDays;
   int Offset;
   cout << "Number of days: ";
   cin >> numDays;
   cout << "Offset: ";
   cin >> Offset;
   displayTable(numDays, Offset);
   return 0;
}
