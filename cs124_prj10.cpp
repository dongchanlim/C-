/***********************************************************************
* Program:
*    Project 10, Madlib
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Write a program to implement Mad Lib program.  
*
*    Estimated:  3.0 hrs   
*    Actual:     3.0 hrs
*      Display function was the most difficult part to 
*      print correctly. spacing between words was the most complex one.
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
 * Prompt the user for all the substitute words according to the file
 * from readFile() function.
 ***********************************************************************/
void askQuestion(char story[])
{
   if (story[0] == ':' && isalpha(story[1]))
   {
      cout << "\t";
      cout << (char)toupper(story[1]);
      for (int i  = 2; story[i]; i++)
      {
         if (story[i] == '_')
            cout << ' ';
         else    
            cout << (char)tolower(story[i]);
      }
      cout << ": ";
      cin.getline(story, 32);
   }
}

/**********************************************************************
 * get a filename from user and count how many words exist in the file
 ***********************************************************************/
int readFile(char story[][256])
{
   char fileName[256];
   getFileName(fileName);
   cin.ignore();
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Unable to open file " << fileName << endl; 
      cout << "Thank you for playing." << endl;
      return 0;
   }
   int count = 0;
   while (fin >> story[count] && count < 256)
   {
      askQuestion(story[count]);
      count++;
   }
   fin.close();
   return count;
}

/**********************************************************************
 * Prompt the user for all the substitute words according to the file
 * from readFile() function.
 ***********************************************************************/
void getPunctuation(char punc[])
{
   if (punc[0] == ':')
   {
      switch (punc[1])
      {
         case '!':
            punc[0] = '\n';
            punc[1] = '\0';
            break;
         case ',':
            punc[0] = ',';
            punc[1] = '\0';
            break;
         case '.':
            punc[0] = '.';
            punc[1] = '\0';
            break;
         case '<':
            punc[0] = '\"';
            punc[1] = '\0';
            break;
         case '>':
            punc[0] = '\"';
            punc[1] = '\0';
            break;
      }
   }  
}

/**********************************************************************
 * determine whether add space or not according to the conditions
 ***********************************************************************/
bool noSpace(char story[], char story2[])
{
   if (story2[1] == '!' || story2[1] == ',' || 
      story2[1] == '.' || story2[1] == '>')
      return true;
   else if (story[1] == '!' || story[1] == '<') 
      return true;
   return false;
}


/**********************************************************************
 * display completed madlib program with the substitued words.
 ***********************************************************************/
void display(char story[][256], int count)
{
   int i;
   for (i = 1; i < count; i++)
   {
      if (noSpace(story[i - 1], story[i]))
      {
         getPunctuation(story[i - 1]);
         cout << story[i - 1];
      }
      else
      {
         getPunctuation(story[i - 1]);
         cout << story[i - 1] << " ";
      }
   } 
   getPunctuation(story[count - 1]);
   cout << story[count - 1];
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
   char story[256][256];
   int Num = readFile(story);
   cout << endl; 
   display(story, Num);  
   while (playAgain())
   {
      int Num = readFile(story);
      cout << endl;
      display(story, Num);
   } 
   
   cout << "Thank you for playing." << endl;
   return 0;
}
