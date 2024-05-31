/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 4 | Project 1                                                                          */
/* Write a program that converts from 24-hour notation to 12-hour notation. For                   */
/* example, it should convert 14:25 to 2:25 P.M. The input is given as two integers.              */
/* There should be at least three functions: one for input, one to do the conversion,             */
/* and one for output. Record the A.M./P.M. information as a value of type char ,                 */
/* 'A' for A.M. and 'P' for P.M. Thus, the function for doing the conversions will                */
/* have a call-by-reference formal parameter of type char to record whether it is A.M.            */
/* or P.M. (The function will have other parameters as well.) Include a loop that lets            */
/* the user repeat this computation for new input values again and again until the user           */
/* says he or she wants to end the program..                                                      */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

void GetInput(unsigned int& in_h, unsigned int& in_min);
void Time24hTo12h(unsigned int& hour, unsigned int& min, char& period);
void Print12hFormat(unsigned int hour, unsigned int minute, char period);

int main(){
    
    unsigned int hour = 0;
    unsigned int minute = 0;
    char period = '0';
    char continueAnswer = 0;

    do
    {
        GetInput(hour, minute);
        Time24hTo12h(hour,minute,period);
        Print12hFormat(hour,minute,period);
    }while(std::cout << "Convert again? (y/n) ", 
           std::cin >> continueAnswer, 
           continueAnswer == 'y');
    
    return(0);
}

void GetInput(unsigned int& in_h, unsigned int& in_min)
{
    std::cout << "Type the 24h format hour (hh mm): ";
    std::cin >> in_h >> in_min;
}

void Time24hTo12h(unsigned int& hour, unsigned int& min, char& period)
{
    if (hour == 12)
    {
        hour = hour;  // dummy
        min = min;    // dummy
        period = 'P';
    }
    else if (hour > 12)
    {
        min = min;    // dummy
        period = 'P';
    }
    else
    {
        hour = hour;  // dummy
        min = min;    // dummy
        period = 'A';	
    }
}

void Print12hFormat(unsigned int hour, unsigned int minute, char period)
{
    printf("12h format: %02d:%02d %cM\n",hour, minute, period);
}