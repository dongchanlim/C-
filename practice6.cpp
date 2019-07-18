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
/********************************/
void change(int* pNumber)
{
   (*pNumber)++;
   pNumber = NULL;
}
/********************************/
int main()
{
   int num = 10;
   int * pNum = &num;
   change(pNum);
   cout << num << endl;
   cout << *pNum << endl;
   return 0;
}

