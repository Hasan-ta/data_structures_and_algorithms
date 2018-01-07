#include "recursion_problems.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::cout << "5! = " << factorial(5) << std::endl;
	std::cout << "4! = " << factorial(4) << std::endl;
	std::cout << "3! = " << factorial(3) << std::endl;
	std::cout << "2! = " << factorial(2) << std::endl;
	std::cout << "1! = " << factorial(1) << std::endl;
	std::cout << "0! = " << factorial(0) << std::endl;

	std::cout << "digitsSum(1234) = " << digitsSum(1234) << std::endl;
	std::cout << "digitsSum(1) = " << digitsSum(1) << std::endl;
	std::cout << "digitsSum(0) = " << digitsSum(0) << std::endl;
	std::cout << "digitsSum(123456789) = " << digitsSum(123456789) << std::endl;

	std::cout << "123456789 reverse: " << reversePhrase(std::string("123456789")) << std::endl;
}