/***********************************************************************
* Program:
*    Project 09, Madlib Program
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Write a program to implement Mad Lib program.  
*
*    Estimated:  3.0 hrs   
*    Actual:     3.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;


/**********************************************************************
 * Prompt the user for the filename that describes the Mad Lib
 ***********************************************************************/
void getFileName(char fileName[])
{  
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
}

/**********************************************************************
 * get a filename from user and count how many words exist in the file
 ***********************************************************************/
int readFile(char story[][32])
{
   char fileName[256];
   getFileName(fileName);
   cin.ignore();
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Unable to open file " << fileName << endl; 
      cout << "Thank you for playing." << endl;
      return -1;
   }
   int count = 0;
   while (fin >> story[count])
   {
      count++;
   }
   fin.close();
   return count;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
void display(char story[][32], int count, char prompt[][32], int promptNum)
{
   int i;
   for (i = 0; i < count; i++)
      if (story[i][0] == ':' && isalpha(story[i][1]))
         cout << prompt[0] << " ";
      else
         cout << story[i] << " ";
   cout << endl;
   return;
}

/**********************************************************************
 * Prompt the user for all the substitute words according to the file
 * from readFile() function.
 ***********************************************************************/
void askQuestion(char story[][32], int count, char prompt[][32])
{
   int promptNum = 0;
   for (int i = 0; i < count; i++)
   { 
      if (story[i][0] == ':' && isalpha(story[i][1]))
      {
         cout << "\t";
         cout << (char)toupper(story[i][1]);
         for (int j  = 2; story[i][j]; j++)
         {
            if (story[i][j] == '_')
               cout << ' ';
            else    
               cout << (char)tolower(story[i][j]);
         }
         cout << ": ";
         cin.getline(prompt[promptNum], 32);
         promptNum++;
      }
   }
   /*
   display(story, count, prompt, promptNum);
   */
   return;
}

/**********************************************************************
 * Ask the user if he/she wants to play another.
 ***********************************************************************/
bool playAgain()
{
   char again;
   cout << endl;
   cout << "Do you want to play again (y/n)? ";
   cin >> again;
   if (again == 'y')
      return true;
   else if (again == 'n')
      return false;
      
}

/**********************************************************************
 * get a file and implement madlib program according to the inputs of
 * users.
 ***********************************************************************/
int main()
{
   char story[256][32];
   char prompt[32][32];
   int Num = readFile(story); 
   askQuestion(story, Num, prompt);
   /*
   while (playAgain())
   {
      int Num = readFile(story); 
      askQuestion(story, Num, prompt);
   } 
   */
   cout << "Thank you for playing." << endl;
   return 0;
}
