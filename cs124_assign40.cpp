/***********************************************************************
* Program:
*    Assignment 40, Multi-Dimensional Arrays
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Write a function to read a Tic-Tac-Toe board into an array.
*    and display a Tic-Tac-Toe board on the screen. After that,
*    write a function to write the board to a file. 
*    Estimated:  0.5 hrs   
*    Actual:     0.5 hrs
*      There was nothing difficult or complex to solve.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Write a function to read a Tic-Tac-Toe board into an array.
 ***********************************************************************/
void readFile(char fileName[], char board[][3])
{
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error" << endl;
   }
   for (int row = 0; row < 3; row++)
   {
      for (int col = 0; col < 3; col++)
         fin >> board[row][col];
   }
   fin.close();
}

/**********************************************************************
 * Write a function to display a Tic-Tac-Toe board on the screen.
 ***********************************************************************/
void display(char board[][3])
{
   for (int row = 0; row < 3; row++)
   {
      for (int col = 0; col < 3; col++)
      {
         if (board[row][col] == '.')
            board[row][col] = ' ';
         if (col < 2)
            cout << " " << board[row][col] << " |";
         else
            cout << " " << board[row][col] << " " << endl;
      }
      if (row < 2)
         cout << "---+---+---" << endl;
   }
}

/**********************************************************************
 * Write a function to write the board to a file. 
 ***********************************************************************/
void writeFile(char fileName2[], char board[][3])
{
   ofstream fout(fileName2);
   
   if (fout.fail())
      cout << "Error" << endl;
      
   for (int row = 0; row < 3; row++)
   {
      for (int col = 0; col < 3; col++)
      {
         if (board[row][col] == ' ')
            board[row][col] = '.';
         if (col < 2)
            fout << board[row][col] << " ";
         else
            fout << board[row][col] << endl;
      }
   }
   cout << "File written" << endl;
}
   

/**********************************************************************
 * Read the file and display the board in accordance with format.
 * Then, write the file with the same format of readfile function.
 ***********************************************************************/
int main()
{
   char fileName[256];
   char fileName2[256];
   cout << "Enter source filename: " ;
   cin >> fileName;
   char board[3][3];
   readFile(fileName, board);
   display(board);
   cout << "Enter destination filename: ";
   cin >> fileName2;
   writeFile(fileName2, board);
   
   return 0;
}
