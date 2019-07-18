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
#include <iomanip>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "What is the name of the file: ";
   cin >> fileName;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
float getThreshold()
{
   float threshold;
   cout << "What is the threshold: ";
   cin >> threshold;
   return threshold;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int readFile(char fileName[], float mileages[])
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error: unable to read " << fileName << endl;
      return 0;
   }
   float mileage;
   int count = 0;
   while (fin >> mileage)
   {
      mileages[count] = mileage;
      count++;
   }
   fin.close();
   return count;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void displayTheshold(float mileages[],int count, float threshold)
{
   cout << "The following items are below the threshold:" << endl;
   for (int i = 0; i < count; i++)
   {
      if (mileages[i] < threshold)
         cout << "\t" << mileages[i] << endl;
   }
}


/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   cout.setf(ios:: fixed);
   cout.precision(1);
   char fileName[256];
   getFileName(fileName);
   float threshold = getThreshold();
   float mileages[256];
   int num = readFile(fileName, mileages);
   if (num > 0)
      displayTheshold(mileages, num, threshold);
   return 0;
}
