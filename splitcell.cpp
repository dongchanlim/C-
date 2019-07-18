/***********************************************************************
* Program:
*    Practice - Cells 
*    Sister Hansen, CS124
* Author:
*    Your Name
* Summary: 
*   Run a simulation to determine the number of cells over time.
*   Write a program that asks the user to enter the number of bacteria cells
*   (whole number) and the number of minutes to run a simulation. The bacteria 
*   cells will split causing them to double in number every minute. For example,
*   if you started with 5 cells, they would become 10 cells after one minute, 
*   20 cells after two minutes, 40 cells after three minutes, and so on. The
*   program should display the total cells that will exist after the time 
*   provided. For example:
*               Enter number of starting cells: 10
*               Enter number of minutes: 5
*               Total cells: 320
*   You do not need to do error checking for negative number inputs.
************************************************************************/

#include <iostream>
using namespace std;

int askCells()
{
   int startingCell;
   cout << "Enter number of starting cells: ";
   cin >> startingCell;
   return startingCell;
}

int askMinutes()
{
   int minutes;
   cout << "Enter number of minutes: ";
   cin >> minutes;
   return minutes;
}

int main()
{
   int startingCell = askCells();
   int minutes = askMinutes();
   for (int i = 0; i < minutes; i++)
   {
       startingCell *= 2;
   }
   cout << "Total cells: " << startingCell << endl;
   return 0;
}