/*---------------------------------------------------------------------------------------*/
/*                                                                                       */
/* Chapter 1 | Project 4                                                                 */
/* Negotiating a consumer loan is not always straightforward. One form of loan is the    */
/* discount installment loan, which works as follows. Suppose a loan has a face value    */
/* of $1,000, the interest rate is 15%, and the duration is 18 months. The interest is   */
/* computed by multiplying the face value of $1,000 by 0.15, yielding $150. That         */
/* figure is then multiplied by the loan period of 1.5 years to yield $225 as the total  */
/* interest owed. That amount is immediately deducted from the face value, leaving       */
/* the consumer with only $775. Repayment is made in equal monthly installments          */
/* based on the face value. So the monthly loan payment will be $1,000 divided           */
/* by 18, which is $55.56. This method of calculation may not be too bad if the          */
/* consumer needs $775 dollars, but the calculation is a bit more complicated if the     */
/* consumer needs $1,000. Write a program that will take three inputs: the amount        */
/* the consumer needs to receive, the interest rate, and the duration of the loan in     */
/* months. The program should then calculate the face value required in order for        */
/* the consumer to receive the amount needed. It should also calculate the monthly       */
/* payment.                                                                              */
/*                                                                                       */
/* Author: Eng. Rafael Del Pino                                                          */
/*                                                                                       */
/*---------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

int main(int ac, char* av[])
{
    float loan = 0.0;
    float needed_loan = 0.0;
    float interest = 0.0;
    float interest_rate = 0.0;
    float loan_duration_years = 0.0;
    float refound = 0.0;
    float monthly_refound = 0.0;
    unsigned int loan_duration_months = 0;

    // Set decimal number notation 
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    std::cout << "Total amount need(R$): ";
    std::cin >> needed_loan;
    std::cout << "Loan interest rate(%): ";
    std::cin >> interest_rate;
    std::cout << "Loan duration (months): ";
    std::cin >> loan_duration_months;
    
    loan_duration_years = loan_duration_months / 12.0;
    interest = needed_loan * (interest_rate / 100.0) * loan_duration_years;
    refound = needed_loan - interest;
    
    loan = (needed_loan * needed_loan) / refound;
    monthly_refound = loan / loan_duration_months;
    
    cout << "If you need to receive R$" << needed_loan << " then you will need to order a R$" << loan << " nominal loan and refound in " << loan_duration_months << " installments of R$" << monthly_refound << endl;
}
