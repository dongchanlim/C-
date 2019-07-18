/***********************************************************************
* Program:
*    Assignment 31, Array Design
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
 * if grade is equal to -1, grade is not factored into the average.
 ***********************************************************************/
int averageGrades(int Grades[],int GradeNum)
{
   int count = 0;
   int sum = 0;
   for (int i = 0; i < GradeNum; i++)
   {
      if (Grades[i] == -1)
      {
         Grades[i] = 0;
         count--;
      }
      sum += Grades[i];
      count++;
   }
   int average = (float)sum / count;
   return average;
}
     
/**********************************************************************
 * use arrays Grades and get each of grade and compute the average.
 * if average is less than 0, then retun '---' for aveerage.
 ***********************************************************************/
int main()
{
   int Grades[10];
   getGrades(Grades, 10);
   int average = averageGrades(Grades, 10);
   if (average < 0)
      cout << "Average Grade: " << "---" << "%" << endl;
   else
      cout << "Average Grade: " << average << "%" << endl;
   return 0;
}
