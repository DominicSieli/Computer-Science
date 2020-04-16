#include <iostream>

#include "MathFunctions/Math.h"

int main()
{
	char continueCalc = 'y';
	unsigned int iStart = 0;
	unsigned int iStop = 0;
	unsigned int exponent = 0;

	while(continueCalc == 'y')
	{
		system("cls");

		std::cout << "Start: ";
		std::cin >> iStart;
		std::cout << "Stop: ";
		std::cin >> iStop;
		std::cout << "Exponent: ";
		std::cin >> exponent;

		system("cls");

		std::cout << Math::Summation(iStart, iStop, exponent) << std::endl;

		std::cout << "Continue? Y" << std::endl;
		std::cin >> continueCalc;
	}
}