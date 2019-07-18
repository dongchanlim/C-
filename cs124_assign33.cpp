/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*  Write a program to ask two people for their account balance. 
*  Then, based on who has the most money, all subsequent purchases 
*  will be charged to his or her account.
*
*    Estimated:  0.3 hrs   
*    Actual:     0.3 hrs
*      There was nothing complex or difficult to solve.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Prompt Dinner, Movie, and Ice Cream prices and 
 * reduce the value of pAccount by that amount.
 ***********************************************************************/
void date(float * pAccount)
{
   cout << "Cost of the date:" << endl;
   float Dinner;
   float Movie;
   float IceCream;
   cout << "\tDinner:    ";
   cin >> Dinner;
   cout << "\tMovie:     ";
   cin >> Movie;
   cout << "\tIce cream: ";
   cin >> IceCream;
   *pAccount -= (Dinner + Movie + IceCream);
   return;
}

/**********************************************************************
 * store the two account balances. Create a pointer to the account 
 * that has the largest balance. 
 * Then, for the three item costs on the date, 
 * reduce the balance of the appropriate account using the pointer.
 ***********************************************************************/
int main()
{
   cout.setf(ios :: fixed);
   cout.precision(2);
   float SamBalance;
   float SueBalance;
   float * pAccount;
   cout << "What is Sam's balance? ";
   cin >> SamBalance;
   cout << "What is Sue's balance? ";
   cin >> SueBalance; 
   if (SamBalance > SueBalance)
      pAccount = &SamBalance;
   else
      pAccount = &SueBalance;
   date(pAccount); 
   cout << "Sam's balance: $" << SamBalance << endl;
   cout << "Sue's balance: $" << SueBalance << endl;
   return 0;
}
