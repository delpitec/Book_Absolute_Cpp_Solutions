/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 1 | Project 2                                                                          */
/* A government research lab has concluded that an artificial sweetener commonly                  */
/* used in diet soda will cause death in laboratory mice. A friend of yours is desperate          */
/* to lose weight but cannot give up soda. Your friend wants to know how much diet                */
/* soda it is possible to drink without dying as a result. Write a program to supply              */
/* the answer. The input to the program is the amount of artificial sweetener needed              */
/* to kill a mouse, the weight of the mouse, and the weight of the dieter. To ensure              */
/* the safety of your friend, be sure the program requests the weight at which the                */
/* dieter will stop dieting, rather than the dieter’s current weight. Assume that diet            */
/* soda contains one-tenth of 1% artificial sweetener. Use a variable declaration with            */
/* the modifier const to give a name to this fraction. You may want to express the                */
/* percentage as the double value 0.001 .                                                         */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

int main()
{
    // 0.1%
    const float REFRIGERANT_SWEETENER_PERCENT = 0.001;
    
    float rat_weight = 0.0;
    float sweetener_fatal_amount_rat = 0.0;
    float person_target_weight = 0.0;
    float sweetener_fatal_amount_person = 0.0;
    float refrigerant_amount_permited = 0.0;
    
    // Set decimal number notation 
	cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Type rat weight (g): ";
    cin >> rat_weight;
    
    cout << "Type fatal sweetener amount to a " << rat_weight << " g rat (ml): ";
    cin >> sweetener_fatal_amount_rat;
    
    printf("Type person target weight (kg): ");
    cin >> person_target_weight;
    
    sweetener_fatal_amount_person = ((person_target_weight * 1000.0) * sweetener_fatal_amount_rat) / rat_weight;
    refrigerant_amount_permited = sweetener_fatal_amount_person / REFRIGERANT_SWEETENER_PERCENT;

    // Convert from ml to L
    refrigerant_amount_permited /= 1000.0;

    cout << "A " << person_target_weight << " kg person can drink a total soda amount of " <<  refrigerant_amount_permited << " L." << endl;

    return 0;
}