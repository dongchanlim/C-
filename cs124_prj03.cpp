/***********************************************************************
* Program:
*    Project 03, Monthly Budget
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    Displaying a personal monthly finance program to a user. 
*    Ask a user to input her/his monthly income, living expenses,
*    taxes withheld, tithe offerings, and other expenses. 
*    Then show the report of user's monthly actual expenses 
*    and budgeted living expenses. 
*    Estimated:  0.1 hrs   
*    Actual:     0.1 hrs
*      There was nothing complex or diffult to solve.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/***********************************************************************
* get user's monthly income
************************************************************************/
double getIncome()
{
   cout << "\tYour monthly income: ";
   double income;
   cin >> income;
   return income;
}

/***********************************************************************
* get user's budgeted living expenses
************************************************************************/
double getBudgetLiving()
{
   cout << "\tYour budgeted living expenses: ";
   double budgetedliving;
   cin >> budgetedliving;
   return budgetedliving;
}

/***********************************************************************
* get user's actual living expenses
************************************************************************/
double getActualLiving()
{
   cout << "\tYour actual living expenses: ";
   double actualliving;
   cin >> actualliving;
   return actualliving;
}

/***********************************************************************
* get user's acutal taxes withheld
************************************************************************/
double getActualTax()
{
   cout << "\tYour actual taxes withheld: ";
   double taxeswithheld;  
   cin >> taxeswithheld;
   return taxeswithheld;
}

/***********************************************************************
* get user's actual tithe offering
************************************************************************/
double getActualTithing()
{
   cout << "\tYour actual tithe offerings: ";
   double titheoffering;  
   cin >> titheoffering;
   return titheoffering;
}

/***********************************************************************
* get user's actual other expenses
************************************************************************/
double getActualOther()
{
   cout << "\tYour actual other expenses: ";
   double otherexpenses;
   cin >> otherexpenses;
   return otherexpenses;
}

/***********************************************************************
* set user's budgeted tax amount as 0
************************************************************************/
double computeTax(double income)
{
   return 0;
}

/***********************************************************************
* set users' budgeted tithe amount as 1/10 of income
************************************************************************/
double computeTithing(double income)
{
   return income * 0.1;
}

/***********************************************************************
* Takes the input gathered from the other modules 
* and puts it on the screen in an easy to read format.
************************************************************************/
void display(double income, double budgetLiving, double actualTax, 
   double actualTithing, double actualLiving, double actualOther)
{
   double budgetTax = computeTax(income);
   double budgetTithing = computeTithing(income);
   double budgetOther = income - budgetTax - budgetTithing - budgetLiving;
   double actualDifference = income - actualTax 
      - actualTithing - actualLiving - actualOther;
   double budgetDifference = 0;
   
   cout << "\nThe following is a report on your monthly expenses" << endl;
   cout << "\tItem                  Budget          Actual" << endl;
   cout << "\t=============== =============== ===============" << endl;
   cout << "\tIncome          " << "$" << setw(11) << income << "    $" 
      << setw(11) << income << endl;
   cout << "\tTaxes           " << "$" << setw(11) << budgetTax 
      << "    $" << setw(11) << actualTax << endl;
   cout << "\tTithing         " << "$" << setw(11) << budgetTithing 
      << "    $" << setw(11) << actualTithing << endl;  
   cout << "\tLiving          " << "$" << setw(11) << budgetLiving 
      << "    $" << setw(11) << actualLiving << endl;  
   cout << "\tOther           " << "$" << setw(11) << budgetOther 
      << "    $" << setw(11) << actualOther << endl;
   cout << "\t=============== =============== ===============" << endl;
   cout << "\tDifference      " << "$" << setw(11) << budgetDifference
      << "    $" << setw(11) << actualDifference << endl; 
}

/**********************************************************************
*  Prompts the user inputs (income, budget living, actual living expenses
*  and display the result with table format.
***********************************************************************/
int main()
{
   cout.setf(ios  ::fixed);
   cout.setf(ios  ::showpoint);
   cout.precision(2);  

   cout << "This program keeps track of your monthly budget" << endl;
   cout << "Please enter the following:" << endl;
  
   double income = getIncome();
   double budgetLiving = getBudgetLiving();
   double actualLiving = getActualLiving();
   double actualTax = getActualTax();
   double actualTithing = getActualTithing();
   double actualOther = getActualOther();
   

   display(income, budgetLiving, actualTax, actualTithing, 
      actualLiving, actualOther);
          
   return 0;
}
