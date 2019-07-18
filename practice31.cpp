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
#include <iomanip>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
float getAverage(int grades[], int gradeNums)
{
   float sum = 0;
   int i;
   for (i = 0; i < gradeNums; i++)
   {
      sum += grades[i];
   }
   float average = sum / i;
   return average;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void askGrades(int grades[], int &gradeNums)
{
   cout.setf(ios:: fixed);
   cout.precision(0);
   cout << "How many grades? " ;
   cin >> gradeNums;
   
   int i;
   
   for (i = 0; i < gradeNums; i++)
   {
      cout << "\tEnter grade " << i + 1 << ": ";
      cin >> grades[i];
   }
   for (i = 0; i < gradeNums; i++)
   {
      while (grades[i] < 0 || grades[i] > 100)
      {
         cout << "\tGrade " << i + 1 << " is not valid."
         << " Please re-enter grade " << i + 1 << ": ";
         cin >> grades[i];
      }
   }

}


/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int grades[100];
   int gradeNums;
   askGrades(grades, gradeNums);
   float average = getAverage(grades, gradeNums);
   cout << "The average grade is " << average << "%" << endl;
   return 0;
}
