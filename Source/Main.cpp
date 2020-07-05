#include <iostream>

#include "Math.h"

int main()
{
	char continueCalc = 'y';
	unsigned int iStart = 0;
	unsigned int iStop = 0;
	unsigned int exponent = 0;

	while (continueCalc == 'y')
	{
		system("clear");

		std::cout << "Start: ";
		std::cin >> iStart;
		std::cout << "Stop: ";
		std::cin >> iStop;
		std::cout << "Exponent: ";
		std::cin >> exponent;

		system("clear");

		std::cout << Math::Summation(iStart, iStop, exponent) << '\n';

		std::cout << "Continue? Y" << '\n';
		std::cin >> continueCalc;
	}
}