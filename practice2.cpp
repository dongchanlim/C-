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


int readFile()
{
   // declare and open the output stream
   ifstream fin("number.txt");
   if (fin.fail())
      return -1; 
   // read the data
   int data;
   int sum = 0;
   while (fin >> data)
   {
      sum += data;
      if (fin.fail())
         return -1;
   }
   // close the stream
   fin.close();
   return sum;
}
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int number = readFile();
   cout << number << endl;
   return 0;
}
