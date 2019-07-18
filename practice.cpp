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
#include <fstream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
bool writeFile()
{
   ofstream fout;
   fout.open("greeting.txt");
   // ofstream fout("greeting.txt");
   
   if (fout.fail())
      return false;
   
   fout << "Hello, World\n";
   if (fout.fail())
   {
      fout.close();
      return false;
   }
   
   fout.close(); 
 
   return true;
}
 
int main()
{
   writeFile();
   return 0;
}
