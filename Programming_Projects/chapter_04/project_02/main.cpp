/*------------------------------------------------------------------------------------------------*/
/*                                                                                                */
/* Chapter 4 | Project 2                                                                          */
/* The area of an arbitrary triangle can be computed using the formula                            */
/* area = sqrt((s-a)*(s-b)*(s-c))                                                                 */
/* where a, b, and c are the lengths of the sides, and s is the semiperimeter                     */
/* s = (a + b + c) / 2     Note: [a, b, c = integers]                                             */
/* Write a void function that uses five parameters: three value parameters that provide           */
/* the lengths of the edges, and two reference parameters that compute the area                   */
/* and perimeter ( not the semiperimeter ). Make your function robust. Note that not              */
/* all combinations of a, b, and c produce a triangle. Your function should produce               */
/* correct results for legal data and reasonable results for illegal combinations.                */
/*                                                                                                */
/* Author: Eng. Rafael Del Pino                                                                   */
/*                                                                                                */
/*------------------------------------------------------------------------------------------------*/
#include <iostream>

using namespace std;

void IncrementLower(unsigned int& n1,unsigned int& n2,unsigned int& n3)
{
    if (n1 < n2 && n1 < n3)
    {
        n1++;
    }
    else if (n2 < n1 && n2 < n3)
    {
        n2++;
    }
    else if (n3 < n1 && n3 < n2)
    {
        n3++;
    }
    else
    {
        n1++;
    }
}

double TriangleArea(unsigned int s1, unsigned int s2, unsigned int s3)
{
    double semiperimeter = 0.0;
    double area = 0.0;

    // Calculates area
    semiperimeter = (s1 + s2 + s3)/2.0;
    area = sqrt(semiperimeter * (semiperimeter-s1) * (semiperimeter-s2)*(semiperimeter-s3));

    return area;
}

unsigned int TrianglePerimeter(unsigned int s1, unsigned int s2, unsigned int s3)
{
    unsigned int perimeter = 0;
    
    // Calculates perimeter
    perimeter = s1 + s2 + s3;

    return perimeter;
}

void TriangleCalculator(double& area, unsigned int& perimeter, unsigned int s1, unsigned int s2, unsigned int s3)
{   
    area = TriangleArea(s1, s2, s3);
    
    // Check if area is a valid value
    if (!(area > 0))
    {
        while(!area)
        {
            IncrementLower(s1, s2, s3);
            area = TriangleArea(s1, s2, s3);
        }
        cout << "Original values could not be used. Suggest values bellow." << endl;
    }

    perimeter = TrianglePerimeter(s1, s2, s3);
}

int main()
{
    unsigned int side1 = 0;
    unsigned int side2 = 0;
    unsigned int side3 = 0;    
    double area = 0.0;
    unsigned int perimeter = 0;

    // Terminal input
    std::cout << "Type 1st side value: ";
    std::cin >> side1;
    std::cout << "Type 2nd side value: ";
    std::cin >> side2;
    std::cout << "Type 3rd side value: ";
    std::cin >> side3;

    // Calculator
    TriangleCalculator(area, perimeter, side1, side2, side3);
    
    // Terminal output
    cout << "A triangle with side a = " << side1 << " ; b = " << side2 << " ; c = " << side3 << " has:" << endl
         << "Perimeter: " << perimeter << " ; Area: " << area << endl;
    
    return 0;
}