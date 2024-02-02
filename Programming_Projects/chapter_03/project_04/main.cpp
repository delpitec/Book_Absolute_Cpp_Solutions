/*---------------------------------------------------------------------------------------*/
/*                                                                                       */
/* Chapter 3 | Project 4                                                                 */
/* The gravitational attractive force between two bodies with masses m1 and m2           */
/* separated by a distance d is given by the following formula,                          */
/*                                                                                       */
/*      F = (G * m1 * m2)/(d^2) [g*cm/sec^2]                                             */
/*                                                                                       */
/* where G is the universal gravitation constant:                                        */
/*      G = 6.673 * 10^(-8)     [cm^3/(g*sec^2)]                                         */
/*                                                                                       */
/* Write a function definition that takes arguments for the masses of two bodies         */
/* and the distance between them and returns the gravitational force between them.       */
/* Since you will use the previous formula, the gravitational force will be in dynes.    */
/* One dyne equals a (g*cm)/cm^2 .                                                       */
/* You should use a globally defined constant for the universal gravitational constant.  */
/* Embed your function definition in a complete program that computes the gravitational  */
/* force between two objects given suitable inputs. Your program should allow            */
/* the user to repeat this calculation as often as the user wishes.                      */
/*                                                                                       */
/* Author: Eng. Rafael Del Pino                                                          */
/*                                                                                       */
/*---------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

double GravitationalForce(double m1, double m2, double distance)
{
    const double UNIV_GRAVITATIONAL_CONS = 6.673 * pow(10,-8); 
    return (UNIV_GRAVITATIONAL_CONS*m1*m2) / pow(distance,2);
} 

int main()
{
    double mass1 = 0.0;
    double mass2 = 0.0;
    double distance = 0.0;
    double force = 0.0;
    char continueAnswer = 0;

    do{   
        std::cout << "Type mass 1 (g): ";
        std::cin >> mass1;
        std::cout << "Type mass 2 (g): ";
        std::cin >> mass2;
        std::cout << "Type distance between the points (cm): ";
        std::cin >> distance;
        
        force = GravitationalForce(mass1,mass2,distance);
        
        printf("Gravitacional force is: %4.3e g*cm/sec²\n", force);
            
    }while(std::cout << "Calculate again? (y/n) ", 
           std::cin >> continueAnswer, 
           continueAnswer == 'y');

    return 0;
}