/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.1 hrs   
*    Actual:     0.1 hrs
*      There was nothing complex or diffult to solve.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* not return anything but instead display the assigned message
***********************************************************************/
void questionPeter()
{
   cout << "Lord, how oft shall my brother sin against me,"
      << " and I forgive him?" << endl;
   cout << "Till seven times?" << endl;
   return;
}

/**********************************************************************
* return the Lord's response: 7 * 70
***********************************************************************/
int responseLord()
{
   int response = 7 * 70;
   return response;
}
 
/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}
