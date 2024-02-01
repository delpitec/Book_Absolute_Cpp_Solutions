/*-----------------------------------------------------------------------------------------*/
/*                                                                                         */
/* Chapter 2 | Project 2                                                                   */
/* You have just purchased a stereo system that cost $1,000 on the following credit        */
/* plan: no down payment, an interest rate of 18% per year (1.5% per month), and           */
/* monthly payments of $50. The monthly payment of $50 is used to pay the interest,        */
/* and whatever is left is used to pay part of the remaining debt. Hence, the first        */
/* month you pay 1.5% of $1,000 in interest. That is $15 in interest. The remaining        */
/* $35 is deducted from your debt, which leaves you with a debt of $965.00. The            */
/* next month you pay interest of 1.5% of $965.00, which is $14.48. Hence, you can         */
/* deduct $35.52 (which is $50 - $14.48) from the amount you owe.                          */ 
/* Write a program that will tell you how many months it will take you to pay off          */ 
/* the loan, as well as the total amount of interest paid over the life of the loan. Use a */ 
/* loop to calculate the amount of interest and the size of the debt after each month.     */ 
/* (Your final program need not output the monthly amount of interest paid and             */ 
/* remaining debt, but you may want to write a preliminary version of the program          */ 
/* that does output these values.) Use a variable to count the number of loop iterations   */ 
/* and hence the number of months until the debt is zero. You may want to use              */ 
/* other variables as well. The last payment may be less than $50 if the debt is small,    */ 
/* but do not forget the interest. If you owe $50, then your monthly payment of $50        */ 
/* will not pay off your debt, although it will come close. One month's interest on        */ 
/* $50 is only 75 cents.                                                                   */
/*                                                                                         */
/* Author: Eng. Rafael Del Pino                                                            */
/*                                                                                         */
/*-----------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

int main(int ac, char* av[]){
    
    double openAmount = 0.0;
    double monthInterestAmount = 0.0;
    double monthlyInterest = 1.5;
    double totalInterestPaid = 0.0;
    double installment = 50.0;
    int i = 0;

    // Set decimal number notation 
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    std::cout << "Type equipment value (R$): ";
    std::cin >> openAmount;

    std::cout << "Type monthly interest (%): ";
    std::cin >> monthlyInterest;

    std::cout << "Type installment (R$): ";
    std::cin >> installment;

    for(i = 0; openAmount > 0; i++){
        monthInterestAmount = (monthlyInterest*openAmount) / 100.0;
        totalInterestPaid += monthInterestAmount;
        openAmount -= installment - monthInterestAmount;
    }

    cout << "The total interest paid during " << i << " months is: R$" << totalInterestPaid << endl;

    return (0);
}