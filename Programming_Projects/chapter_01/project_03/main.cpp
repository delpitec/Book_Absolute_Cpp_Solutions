/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 1 | Project 3                                                                          */
/* Workers at a particular company have won a 7.6% pay increase retroactive for six               */
/* months. Write a program that takes an employee’s previous annual salary as input               */
/* and outputs the amount of retroactive pay due the employee, the new annual                     */
/* salary, and the new monthly salary. Use a variable declaration with the modifier               */
/* const to express the pay increase.                                                             */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

int main(int ac, char* av[])
{
    const double PERCENT_INCREASE = 7.6;
    double salary_input = 0.0;
    double total_pending_salary = 0.0;
    double new_year_salary = 0.0;
    double new_monthly_salary = 0.0;
    
    // Set decimal number notation 
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    std::cout << "Last year salary: ";
    std::cin >> salary_input;

    total_pending_salary = ((PERCENT_INCREASE * (salary_input / 12)) / 100 ) * 6;
    cout << "Total pending ammount: R$" << total_pending_salary << endl;
    
    new_year_salary = salary_input + ((PERCENT_INCREASE * salary_input) / 100 );
    cout << "New year salary: R$" << new_year_salary << endl;

    new_monthly_salary = new_year_salary / 12;
    cout << "New monthly salary: R$" << new_monthly_salary << endl;;

    return 0;
}