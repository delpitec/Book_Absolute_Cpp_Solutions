/*---------------------------------------------------------------------------------------*/
/*                                                                                       */
/* Chapter 1 | Project 5                                                                 */
/* Write a program that determines whether a meeting room is in violation of fire law    */
/* regulations regarding the maximum room capacity. The program will read in the         */
/* maximum room capacity and the number of people to attend the meeting. If the          */
/* number of people is less than or equal to the maximum room capacity, the program      */
/* announces that it is legal to hold the meeting and tells how many additional people   */
/* may legally attend. If the number of people exceeds the maximum room capacity,        */
/* the program announces that the meeting cannot be held as planned due to fire          */
/* regulations and tells how many people must be excluded in order to meet the fire      */
/* regulations.                                                                          */
/*                                                                                       */
/* Author: Eng. Rafael Del Pino                                                          */
/*                                                                                       */
/*---------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    unsigned int maxCapacity = 0;
    unsigned int currOccupancy = 0;

    std::cout << "Room max capacity: ";
    std::cin >> maxCapacity;
    std::cout << "Room current occupancy: ";
    std::cin >> currOccupancy;

    if (currOccupancy > maxCapacity){
        std::cout << "More occupancy than alowwed capacity by legal fire regulations. ";
        std::cout << "Need to remove "<<  currOccupancy - maxCapacity << " people." << std::endl;
    }
    else{
        std::cout << "Occupancy within alowwed capacity by legal fire regulations. ";
        std::cout << "More "<< maxCapacity - currOccupancy << " people allowed." << std::endl;
    }
}
