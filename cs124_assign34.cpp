/***********************************************************************
* Program:
*    Assignment 34, Pointer Arithmetic
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    use the function countLetters() then count how many letters exists
*    within the sentence.
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      There was nothing complex or difficult to solve.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 *  Modify countLetters() so that it walks through the string 
 *  using pointers instead of array indexes.
 ***********************************************************************/
int countLetters(char letter, char text[])
{
   int number = 0;
   for (char * pText = text; *pText; *pText++)
   {
      if (*pText == letter)
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
