/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 1 | Project 1                                                                          */
/* A metric ton is 35,273.92 ounces. Write a program that will read the weight of a               */
/* package of breakfast cereal in ounces and output the weight in metric tons as well             */
/* as the number of boxes needed to yield one metric ton of cereal.                               */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

int main(int ac, char* av[])
{
	const double ONE_TONE_IN_OUNCE = 35273.92;
    double ounce_per_packet = 0.0;
    double package_in_ton = 0.0;
	double ton_in_package = 0.0;
	
	// Set decimal number notation 
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Write packet weight in ounces: ";
    cin >> ounce_per_packet;   
    
	package_in_ton = ounce_per_packet / ONE_TONE_IN_OUNCE;
	cout << "Each package has " << package_in_ton << " tons." << endl;
	    
	ton_in_package = ONE_TONE_IN_OUNCE / ounce_per_packet;
	cout << "One ton has " << ton_in_package << " packages." << endl;
	
    return 0;
}