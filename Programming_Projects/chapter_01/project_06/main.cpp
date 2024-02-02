/*---------------------------------------------------------------------------------------*/
/*                                                                                       */
/* Chapter 1 | Project 6                                                                 */
/* An employee is paid at a rate of $16.78 per hour for regular hours worked in a        */
/* week. Any hours over that are paid at the overtime rate of one and one-half times     */
/* that. From the worker’s gross pay, 6% is withheld for Social Security tax, 14% is     */
/* withheld for federal income tax, 5% is withheld for state income tax, and $10 per     */
/* week is withheld for union dues. If the worker has three or more dependents, then     */
/* an additional $35 is withheld to cover the extra cost of health insurance beyond      */
/* what the employer pays. Write a program that will read in the number of hours         */
/* worked in a week and the number of dependents as input and that will then output      */
/* the worker’s gross pay, each withholding amount, and the net take-home pay for        */
/* the week.                                                                             */
/*                                                                                       */
/* Author: Eng. Rafael Del Pino                                                          */
/*                                                                                       */
/*---------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    const double hourSalary = 16.78;
    const double overHourFactor = 1.5;
    const unsigned int regularWeeklyHours = 44;
    const unsigned int percentSocialSecurityTax = 6;
    const unsigned int percentFederalTax = 14;
    const unsigned int percentStateTax = 5;
    const unsigned int unionTax = 10;
    const unsigned int dependentsDiscount = 35;
    const unsigned int dependentsExtraTax = 3;
    
    double workedHours = 0.0;
    double socialSecurityDiscount = 0.0;
    double valueToBePaid = 0.0;
    unsigned int dependents = 0;

    // Set decimal number notation 
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    std::cout << "Worked hours in the week: ";
    std::cin >> workedHours;
    std::cout << "Dependents quantity: ";
    std::cin >> dependents;
    
    // Payment
    valueToBePaid = regularWeeklyHours * hourSalary;
    if (workedHours > regularWeeklyHours){
        valueToBePaid += (workedHours - regularWeeklyHours) * (hourSalary * overHourFactor);
    }

    // Discount
    valueToBePaid -= (percentSocialSecurityTax * valueToBePaid) / 100.0;
    valueToBePaid -= (percentFederalTax * valueToBePaid) / 100.0;
    valueToBePaid -= (percentStateTax * valueToBePaid) / 100.0;
    valueToBePaid -= unionTax;
    
    if (dependents >= dependentsExtraTax){
        valueToBePaid -= dependentsDiscount;
    }
    
    std::cout << "Value to be paid: R$" << valueToBePaid << endl;
}