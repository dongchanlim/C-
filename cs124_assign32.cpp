/***********************************************************************
* Program:
*    Assignment 32, Strings
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    use the function countLetters() then a driver program to test it.
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      There was nothing complex or difficult to solve.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * count how many letter exists in the input text.
 ***********************************************************************/
int countLetters(char letter, char text[])
{
   int number = 0;
   for (int i = 0; text[i]; i++)
   {
      if (text[i] == letter)
      {
         number++;
      }
   }
   return number;
}
   

/**********************************************************************
 * input user's letter and text, counting how many letter are included
 * within the text.
 ***********************************************************************/
int main()
{
   char letter;
   char text[256];
   cout << "Enter a letter: ";
   cin >> letter;
   cin.ignore();
   cout << "Enter text: ";
   cin.getline(text, 256);
   int number = countLetters(letter, text);
   cout << "Number of " << "'" << letter << "'s: " << number << endl; 
   return 0;
}
