/***********************************************************************
* Program:
*    Project 13, sudoku
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Write Sudoku Program project including displayOptions(), 
*    displayBoard(), and editSquare() functions
*    Estimated:  2.0 hrs   
*    Actual:     2.0 hrs
*      Constructing an entire functions in interactive way was the most
*      difficult part to do.
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
 * read a file and store numbers into the 2 dimensional array.
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
void getCoordinates(int &r, int &c)
{
   char charR;
   cout << "What are the coordinates of the square: ";
   cin >> charR >> c;
   r = toupper(charR) - 65;
   c--;
}

/**********************************************************************
 * Compute the availability of empty sqaure in the range from 1 to 9.
 ***********************************************************************/
void computeValues(bool possible[], int board[][9], int r, int c)
{
   int iRow;
   int iCol;
   for (int i = 0; i < 10; i++)
   {
      possible[i] = true;
   }
   for (iRow = 0; iRow < 9; iRow++)
   {
      if (board[c][iRow] > 0)
      {
         possible[board[c][iRow]] = false;
      }
   }
   for (iCol = 0; iCol < 9; iCol++)
   {
      if (board[iCol][r] > 0)
      {
         possible[board[iCol][r]] = false;
      }
   }
   for (iRow = 0; iRow < 3; iRow++)
   {
      for (iCol = 0; iCol < 3; iCol++)
      {
         if (board[c / 3 * 3 + iCol][r / 3 * 3 + iRow] > 0)
         {
            possible[board[c / 3 * 3 + iCol][r / 3 * 3 + iRow]] = false;
         }
      }
   }
}

/**********************************************************************
 * Edit the empty square with number input so that it can be filled.
 ***********************************************************************/
void editSqaure(int r, int c, int board[][9])
{
   if (board[c][r] == 0)
   {
      int alt;
      cout << "What is the value at \'" << (char)(r + 65) 
         << c + 1 << "\': ";
      cin >> alt;
      bool possible[10];
      computeValues(possible, board, r, c);
      if (!possible[alt])
         cout << "ERROR: Value \'" << alt << "\' in square \'"
            << (char)(r + 65) << c + 1 << "\' is invalid" << endl;
      else
         board[c][r] = alt;
   }
   else
   {
      cout << "ERROR: Square \'" << (char)(r + 65) 
         << c + 1 << "\' is filled" << endl;
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
   fout.close();
   cout << "Board written successfully" << endl;
}

/**********************************************************************
 * Show the possbile numbers for corresponding coordinates. (row & col)
 ***********************************************************************/
void showPossible(char r, int c, int board[][9])
{
   bool possible[10];
   computeValues(possible, board, r, c);
   cout << "The possible values for \'"
      << (char)(r + 65) << c + 1 << "\' are: ";
   bool first = true;
   for (int i = 1; i < 10; i++)
   {
      if (possible[i])
      {
         if (!first)
            cout << ", ";
         cout << i;
         first = false;
      }
   }
   cout << endl;
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
      int r;
      int c;
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
            getCoordinates(r,c);
            editSqaure(r,c,board);
            break;
         case 'S':
            getCoordinates(r,c);
            showPossible(r,c,board);
            cout << endl;
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
 * edit the square independently, showing the possible numbers to put in,
 * or write the new program.
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
