/***********************************************************************
* Program:
*    Project 12, sudoku
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Write Sudoku Program project including displayOptions(), 
*    displayBoard(), and editSquare() functions
*    Estimated:  2.0 hrs   
*    Actual:     2.0 hrs
*      displayOption was difficult to generate the desired display.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * Get a file name to read the sudoku program.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin >> fileName;
}

/**********************************************************************
 * Display the options that can be performed.
 ***********************************************************************/
void displayOptions()
{
   cout << "Options:" << endl;
   cout << "   ?  " << "Show these instructions" << endl;
   cout << "   D  " << "Display the board" << endl;
   cout << "   E  " << "Edit one square" << endl;
   cout << "   S  " << "Show the possible values for a square" << endl;
   cout << "   Q  " << "Save and Quit" << endl;
   cout << endl;
}

/**********************************************************************
 * read a file and store a numbers into the 2 dimensional array.
 ***********************************************************************/  
bool readFile(char fileName[], int board[][9])
{
   getFileName(fileName);
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error" << endl;
      return false;
   }
   else
   {
      for (int col = 0; col < 9; col++)
      {
         for (int row = 0; row < 9; row++)
         {
            fin >> board[col][row];
         }
      }
      fin.close();
      return true;
   }
}

/**********************************************************************
 * display the file with board format so that user can perceive it as
 * actual sudoku game.
 ***********************************************************************/
void displayBoard(int board[][9])
{
   int col;
   int row;
   cout << "   A B C D E F G H I" << endl;
   for (col = 0; col < 9; col++)
   {
      cout << col + 1 << " ";
      for (row = 0; row < 9; row++)
      {
         if (row % 3 == 0 && row != 0)
         {
            if (board[col][row] != 0)
               cout << "|" << board[col][row];
            else
               cout << "| ";
         }
         else
         {
            if (board[col][row] != 0)
               cout << " " << board[col][row];
            else
               cout << "  ";
         }
      }
      if (col % 3 == 2 && col != 8)
         cout << endl << "   -----+-----+-----";
      cout << endl;
   }
   cout << endl; 
}

/**********************************************************************
 * get a row and column coordinate which indicates the point of 
 * target square
 ***********************************************************************/
void getCoordinates(char &r, int &c)
{
   cout << "What are the coordinates of the square: ";
   cin >> r >> c;
}

/**********************************************************************
 * Edit the empty square with number input so that it can be filled.
 ***********************************************************************/
void editSqaure(char r, int c, int board[][9])
{
   getCoordinates(r,c);
   if (board[c - 1][toupper(r) - 65] == 0)
   {
      int alt;
      cout << "What is the value at \'" << (char)toupper(r) 
         << c << "\': ";
      cin >> alt;
      board[c - 1][toupper(r) - 65] = alt;
   }
   else
   {
      cout << "ERROR: Square \'" << (char)toupper(r) 
         << c << "\' is filled" << endl;
   }
   cout << endl;
}

/**********************************************************************
 * Write a new program with new file name.
 ***********************************************************************/
void writeFile(char fileName2[], int board[][9])
{
   cout << "What file would you like to write your board to: ";
   cin >> fileName2;
   ofstream fout(fileName2);
   
   if (fout.fail())
      cout << "Error" << endl;
      
   for (int col = 0; col < 9; col++)
   {
      for (int row = 0; row < 9; row++)
      {
         if (row == 8)
            fout << board[col][row] << endl;
         else
            fout << board[col][row] << " ";
      }
   }
   cout << "Board written successfully" << endl;
}

/**********************************************************************
 * Interact with sudoku program by inputing command line.
 ***********************************************************************/
void interact(int board[][9])
{
   char selection;
   do
   {
      cout << "> ";
      cin >> selection;
      switch (toupper(selection))
      {
         case '?':
            displayOptions();
            cout << endl;
            break;
         case 'D':
            displayBoard(board);
            break;
         case 'E':
            char r;
            int c;
            editSqaure(r, c, board);
            break;
         case 'S':
            break;
         case 'Q':
            char fileName2[256];
            writeFile(fileName2, board);
            break;
         default:
            cout << "ERROR: Invalid command" << endl;
            break;
      }
   }
   while (toupper(selection) != 'Q');
}

/**********************************************************************
 * Get a file name and read the sudoku program from it.
 * Interact with program by display options, display boards,
 * edit the square independently, or write the new program.
 ***********************************************************************/
int main()
{
   char fileName[256];
   int board[9][9];
   if (readFile(fileName, board))
   {
      displayOptions();
      displayBoard(board);
      interact(board);
   }
   return 0;
}
