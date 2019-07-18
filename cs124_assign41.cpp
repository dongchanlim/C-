/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Prompt the user for the number of characters in a string.
*    Allocate a string of sufficient length 
*    (one more than the number of characters!)
*    Prompt the user for the string using getline().
*    Display the string back to the user.
*    Release the memory and check for allocation failures.
*
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Prompt the user for the number of characters in a string.
 ***********************************************************************/
int askNumChar()
{
   int numChar;
   cout << "Number of characters: ";
   cin >> numChar;
   cin.ignore(); 
   return numChar;    
}

/**********************************************************************
 * Prompt the user for the string using getline()
 * Allocate a string of sufficient length 
 * (one more than the number of characters!)
 ***********************************************************************/
void askText(char text[], int numChar)
{
   cout << "Enter Text: ";
   cin.getline(text, numChar + 1);
}


/**********************************************************************
 * Display the string back to the user.
 * Release the memory and check for allocation failures.
 ***********************************************************************/
int main()
{
   int numChar = askNumChar();
   if (numChar < 1)
      cout << "Allocation failure!" << endl;
   else
   {
      char text[numChar + 1];
      askText(text, numChar);
      char * pText = new(nothrow) char[numChar + 1];
      for (int i = 0; i < numChar; i++)
         pText[i] = text[i];
      cout << "Text: " << pText << endl;
      delete [] pText;
   }
   return 0;
}
