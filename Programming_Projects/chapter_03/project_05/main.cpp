/*--------------------------------------------------------------------------------------*/
/*                                                                                      */
/* Chapter 3 | Project 5                                                                */
/* Write a program that asks for the user’s height, weight, and age, and then computes  */
/* clothing sizes according to the following formulas.                                  */
/* • Hat size = weight in pounds divided by height in inches and all that multiplied    */
/*   by 2.9.                                                                            */
/* • Jacket size (chest in inches) = height times weight divided by 288 and then        */
/*   adjusted by adding one-eighth of an inch for each 10 years over age 30. (Note      */
/*   that the adjustment only takes place after a full 10 years. So, there is no        */
/*   adjustment for ages 30 through 39, but one-eighth of an inch is added for age 40.) */
/* • Waist in inches = weight divided by 5.7 and then adjusted by adding one-tenth      */
/* of an inch for each 2 years over age 28. (Note that the adjustment only takes        */
/* place after a full 2 years. So, there is no adjustment for age 29, but one-tenth     */
/* of an inch is added for age 30.)                                                     */
/* Use functions for each calculation. Your program should allow the user to repeat     */
/* this calculation as often as he or she wishes.                                       */
/*                                                                                      */
/* Author: Eng. Rafael Del Pino                                                         */
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

double HatSize(double height, double weight)
{
    const double HAT_SIZE_CONST = 2.9;
    return HAT_SIZE_CONST * (weight/height);
}

double JacketSize(double height, double weight, unsigned int age)
{
    const double COAT_SIZE_CONST = 288;
    double size = 0.0;
    
    size = (height * weight) / COAT_SIZE_CONST;

    if (age > 30){
        size += 0.125 * ((age - 30) / 10); 
    }

    return size;
}

double BeltSize(double weight, unsigned int age)
{
    const double COAT_SIZE_CONST = 5.7;
    double size = 0.0;
  
    size = weight/COAT_SIZE_CONST;

    if (age > 28){
        size += 0.1 * (((age - 28) / 2)); 
    }

    return size;;
}

int main()
{      
    double height = 0.0;
    double weight = 0.0;
    unsigned int age = 0;
    char continueAnswer = 0;

    double hat = 0.0;
    double coat = 0.0;
    double belt = 0.0;
    
    do{
        std::cout << "Type your height (in): ";
        std::cin >> height;
        std::cout << "Type your weight (lbs): ";
        std::cin >> weight;
        std::cout << "Type your age: ";
        std::cin >> age;

        hat = HatSize(height, weight);
        coat = JacketSize(height, weight, age);
        belt = BeltSize(weight, age);

        printf("Hat Size: %2.2f | Coat size: %2.2fin | Belt size: %2.2fin\n",hat, coat, belt);
    }while(std::cout << "Calculate again? (y/n) ", 
           std::cin >> continueAnswer, 
           continueAnswer == 'y');
    
    return 0;
}