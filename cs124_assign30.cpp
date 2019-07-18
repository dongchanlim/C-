/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    prompt the user for ten grades and display the result 
*    by calling getGrades() and averageGrades()
*
*    Estimated:  0.1 hrs   
*    Actual:     0.1 hrs
*      Nothing is diffcult to solve. 
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * prompt the user for ten grades and return the result back to main().
 ***********************************************************************/
void getGrades(int Grades[], int GradeNum)
{
   for (int i = 0; i < GradeNum; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> Grades[i];
   }
   return;
}

/**********************************************************************
 * find the average of the grades and return the answer.
 ***********************************************************************/
int averageGrades(int Grades[],int GradeNum)
{
   int i;
   int sum = 0;
   for (i = 0; i < GradeNum; i++)
   {
      sum += Grades[i];
   }
   int average = (float)sum / i;
   return average;
}
     
/**********************************************************************
 * use arrays Grades and get each of grade and compute the average.
 ***********************************************************************/
int main()
{
   int Grades[10];
   getGrades(Grades, 10);
   int average = averageGrades(Grades, 10);
   cout << "Average Grade: " << average << "%" << endl;
   return 0;
}
