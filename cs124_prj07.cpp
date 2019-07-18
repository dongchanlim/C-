/***********************************************************************
* Program:
*    Project 07, Calendar 
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Create the calendar.
*
*    Estimated:  2.0 hrs   
*    Actual:     3.0 hrs
*      Connecting between functions using parameters.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int getMonth();
int getYear();
int computeOffset(int Year, int Month);
int numDaysInYear(int Year);
int numDaysInMonth(int Month, int Year);
bool isLeapYear(int Year);
void display(int& Month, int& Year, int& Offset, int& NumberDaysInMonth);
void displayTable(int& Offset, int& NumberDaysInMonth);
void displayHeader(int& Month, int& Year);

/**********************************************************************
 * display the calendar by getting corresponding 
 * month and year from user
 ***********************************************************************/
int main()
{
   int Month = getMonth();
   int Year = getYear();
   cout << endl;
   int NumDaysInYear = numDaysInYear(Year);
   int NumDaysInMonth = numDaysInMonth(Month, Year);
   int Offset = computeOffset(Year, Month);
   display(Month, Year, Offset, NumDaysInMonth);
   return 0;
}

/**********************************************************************
 * Get which month it is from user
 ***********************************************************************/
int getMonth()
{
   int Month;
   cout << "Enter a month number: ";
   cin >> Month;
   while (Month < 1 || Month > 12)
   {
      cout << "Month must be between 1 and 12." << endl;
      cout << "Enter a month number: ";
      cin >> Month;
   }
   ;
   return Month;
}

/**********************************************************************
 * Get which year it is from user
 ***********************************************************************/
int getYear()
{
   int Year;
   cout << "Enter year: ";
   cin >> Year;
   while (Year < 1753)
   {
      cout << "Year must be 1753 or later." << endl;
      cout << "Enter year: ";
      cin >> Year;
   }
   return Year;
}

/**********************************************************************
 * Check if year is leap year or not.
 ***********************************************************************/
bool isLeapYear(int Year)
{
   if (Year % 4 != 0)
      return false;
   if (Year % 100 !=  0)
      return true;
   if (Year % 400 == 0)
      return true;
   return false;
}

/**********************************************************************
 * Compute the number of days per year depending on 
 * whether it is leap year or not.
 ***********************************************************************/
int numDaysInYear(int Year)
{
   bool LeapYear = isLeapYear(Year);
   if (LeapYear)
      return 366;
   else 
      return 365;
}

/**********************************************************************
 * compute the offset(Starting point of week) to display the calendar
 * of each month.
 ***********************************************************************/
int computeOffset(int Year, int Month)
{
   int NumDays = 0;
   for (int YearCount = 1753; YearCount < Year; YearCount++)
      NumDays += numDaysInYear(YearCount); 
   for (int MonthCount = 1; MonthCount < Month; MonthCount++)
      NumDays += numDaysInMonth(MonthCount, Year);
   int Offset = NumDays % 7;
   return Offset;
}

/**********************************************************************
 * Calculate the number of days of each month depending on 
 * whether it is leap year or not.
 ***********************************************************************/
int numDaysInMonth(int Month, int Year)
{
   if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || 
      Month == 8 || Month == 10 || Month == 12)
      return 31;
   else if (Month == 2)
   {
      if (isLeapYear(Year))
         return 29;
      else
         return 28;
   }
   else
      return 30;
}

/**********************************************************************
 * combine displayHeader and displayTable functions.
 ***********************************************************************/
void display(int& Month, int& Year, int& Offset, int& NumberDaysInMonth)
{
   displayHeader(Month, Year);
   displayTable(Offset, NumberDaysInMonth);
   return;
}

/**********************************************************************
 * Display the actual calendar.
 ***********************************************************************/
void displayTable(int& Offset, int& NumberDaysInMonth)
{
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
   cout << setw(4 + (Offset + 1) % 7 * 4);
   for (int i = 1; i <= NumberDaysInMonth; i++)
   {
      cout << i << setw(4); 
      if (((i % 7) + Offset) == 6)
         cout << endl << setw(4);    
   }
   if ((Offset + NumberDaysInMonth - 1) % 7 != 5)
      cout << endl;
   return;
}


/**********************************************************************
 * Display the header of calendar with Month and Year.
 ***********************************************************************/
void displayHeader(int& Month, int& Year)
{
   if (Month == 1)
      cout << "January, " << Year << endl;
   if (Month == 2)
      cout << "February, " << Year << endl;
   if (Month == 3)
      cout << "March, " << Year << endl;
   if (Month == 4)
      cout << "April, " << Year << endl;
   if (Month == 5)
      cout << "May, " << Year << endl;
   if (Month == 6)
      cout << "June, " << Year << endl;
   if (Month == 7)
      cout << "July, " << Year << endl;
   if (Month == 8)
      cout << "August, " << Year << endl;
   if (Month == 9)
      cout << "September, " << Year << endl;
   if (Month == 10)
      cout << "October, " << Year << endl;
   if (Month == 11)
      cout << "November, " << Year << endl;
   if (Month == 12)
      cout << "December, " << Year << endl;                                       
   return;
}