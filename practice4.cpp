/***********************************************************************
* Program:
*    Assignment 
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void writeText(char text[])
{
   cout << text << endl;
}
/********************************/
void writeLetter(char letter)
{
   cout<< letter << endl;
}
/********************************/
int main()
{
   int grade[] = {1,2,3};
   char name[] = "Bob";
   char name2[] = {'B', 'O', 'b','\0'};
   writeText(name);
   writeText(name2);
   cout << grade << endl;
   cout << name << endl;
   cout << name2 << endl;
   writeLetter(name[0]);
   return 0;
}