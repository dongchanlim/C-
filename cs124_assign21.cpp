/***********************************************************************
* Program:
*    Assignment 21, Debugging
*    Sister Hansen, CS124
* Author:
*    Dongchan Lim
* Summary: 
*    determine how much money user is spending on his/her car
*    create stub functions for all the functions following
*    structure chart givien.
*    Estimated:  0.1 hrs   
*    Actual:     0.1 hrs
*      There was nothing complicated or difficult to solve.
************************************************************************/

#include <iostream>
using namespace std;

float getPeriodicCost();
float promptDevalue();
float promptInsurance();
float promptParking();
float getUsageCost();
float promptMileage();
float promptGas();
float promptRepairs();
float promptTires();
void display(float costPeriodic, float costUsage);
 
/**********************************************************************
 * use periodic cost and usage cost and display the result out of them.
 ***********************************************************************/
int main()
{
   float costPeriodic = getPeriodicCost();
   float costUsage = getUsageCost();
   display(costPeriodic, costUsage);
   return 0;
}

/**********************************************************************
 * stub function for getPeriodicCost function
 ***********************************************************************/
float getPeriodicCost()
{
   return 0.0;
}

/**********************************************************************
 * stub function for promptDevalue function
 ***********************************************************************/
float promptDevalue()
{
   return 0.0;
}

/**********************************************************************
 * stub function for promptInsurance function
 ***********************************************************************/
float promptInsurance()
{
   return 0.0;
}

/**********************************************************************
 * stub function for promptParking function
 ***********************************************************************/
float promptParking()
{
   return 0.0;
}

/**********************************************************************
 * stub function for getUsageCost function
 ***********************************************************************/
float getUsageCost()
{
   return 0.0;
}

/**********************************************************************
 * stub function for promptMileage function
 ***********************************************************************/
float promptMileage()
{
   return 0.0;
}

/**********************************************************************
 * stub function for promptGas function
 ***********************************************************************/
float promptGas()
{
   return 0.0;
}

/**********************************************************************
 * stub function for promptRepairs function
 ***********************************************************************/
float promptRepairs()
{
   return 0.0;
}

/**********************************************************************
 * stub function for promptTires function
 ***********************************************************************/
float promptTires()
{
   return 0.0;
}

/**********************************************************************
 * stub function for displaying the wanted output.
 ***********************************************************************/
void display(float costPeriodic, float costUsage)
{
   cout << "Success\n";
   return;
}
