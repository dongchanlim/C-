/*********************************************************
* Program:     
*    Test 1, Converting to Euro
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Write a program to prompt the user for the amount in 
*    American dollars and display the equivalent amount in 
*    Euros.
***************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

/*********************************************************
* display the equivalent amount of euros according to
* the user's input.
***************************************************************/
void display(float &dollar)
{
   float euro = dollar / 1.41;
   if (dollar >= 0)
      cout << "\tEuros : $" << euro << endl;
   else
      cout << "\tEuros : $(" << euro << ")" << endl;
   return;
}

/*********************************************************
* prompt the user for the amount of dollars and convert it
* into the Euros.
***************************************************************/
int main()
{
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   float dollar;
   cout << "Please enter the amount in US Dollars: $";
   cin >> dollar;
   display(dollar);

   return 0;
}