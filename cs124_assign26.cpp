/***********************************************************************
* Program:
*    Assignment 26, Files
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Write a program to read 10 grades from a file 
*    and display the average by including functions 
*    getFileName(), displayAverage() and readFile().
*
*    Estimated:  0.5 hrs   
*    Actual:     1.0 hrs
*      The most difficult part was to connect the all fuctions 
*      interchangably and bring out error message in specific cases.
************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std; 

void getFileName(char fileName[]);
float readFile(char fileName[]);
void display(float& average);

/**********************************************************************
 * read 10 grades from a file and display the average
 ***********************************************************************/
int main()
{
   cout.setf(ios  ::fixed);
   cout.precision(0);
   char fileName[10];
   getFileName(fileName);
   float average = readFile(fileName);
   if (average != -1)
      display(average);
   return 0;
}

/**********************************************************************
 * prompt the user for the name of the file and return it
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
   return;
}

/**********************************************************************
 * read the file and return the average score of the ten values.
 * If there are more or less 10 numbers in the file, 
 * then the function must report an error
 ***********************************************************************/
float readFile(char fileName[])
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return -1;
   }
   float sum = 0;
   int count = 0;
   int grade;
   while (fin >> grade)
   {
      sum += grade;
      count += 1;
   }
   if (count != 10)
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return -1;
   }   
   float average = sum / count;
   fin.close();
   return average;
}

/**********************************************************************
 * display the average score to zero decimals of accuracy (rounded).
 ***********************************************************************/
void display(float& average)
{
   cout << "Average Grade: " << average << "%" << endl;
   return;
}
   