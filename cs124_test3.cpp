/***********************************************************************
* Program:
*    Test 3, Reserve a File
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    This program is designed to reverse a file for some reason.
*    Write a program to display the conents of a file backwards
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
*      This is pretty easy for those who prepare for the test with
*      practice questions.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * get file name from the user.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
}

/**********************************************************************
 * read the file and return how many characters, symbols, digits, and 
 * spaces are inlcuded within the file, and store those into c-string
 * array.
 ***********************************************************************/
int readFile(char fileName[], char contents[])
{
   getFileName(fileName);
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error: unable to open " << fileName << endl;
      return 0;
   }
   char content;
   int count = 0;
   while (fin.get(content))
   {
      contents[count] = content;
      count++;
   }
   fin.close();
   return count;
}

/**********************************************************************
 * display the file backward.
 ***********************************************************************/
void displayBackward(char contents[], int count)
{
   int i;
   for (i = count - 1; contents[i]; i--)
   {
      cout << contents[i];
   }
   cout << endl;
}

/**********************************************************************
 * get filename from the user and display the content backward.
 ***********************************************************************/
int main()
{
   char fileName[256];
   char contents[4000];
   int count = readFile(fileName, contents);
   displayBackward(contents, count);
   return 0;
}
