#include "recursion_problems.h"
#include <iostream>
#include <time.h>

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

	std::vector<std::string> perms = permute(std::string("abc"));
	std::vector<std::string>::const_iterator it = perms.begin();
	std::cout << "\n\"abc\" Permutations:  [";
	while(it != perms.end())
	{
		std::cout << *it++ << ", ";
	}
	std::cout << "\b\b \b].\n";

	perms = permute(std::string("1234"));
	it = perms.begin();
	std::cout << "\n\"1234\" Permutations:  [";
	while(it != perms.end())
	{
		std::cout << *it++ << ", ";
	}
	std::cout << "\b\b \b].\n";

	clock_t t = clock();
	std::cout << "fib(20) Recursively: " << fib_rec(20) << std::endl;
	t = clock() - t;
	std::cout << "Time Spent (Recursively): " << (float) t << std::endl;
	Memoization<int,int> mem(fib_rec);
	t = clock();
	std::cout << "fib(6) Memoization: " << mem(6) << std::endl;
	t = clock() - t;
	std::cout << "Time Spent (Memoization first iteration): " << (float) t << std::endl;
	t = clock();
	std::cout << "fib(20) Memoization: " << mem(20) << std::endl;
	t = clock() - t;
	std::cout << "Time Spent (Memoization second iteration): " << (float) t << std::endl;
		t = clock();
	std::cout << "fib(10) Memoization: " << mem(10) << std::endl;
	t = clock() - t;
	std::cout << "Time Spent (Memoization second iteration): " << (float) t << std::endl;

	std::vector<int> coins; coins.push_back(1); coins.push_back(5); coins.push_back(10); coins.push_back(25);
	t = clock();
	std::cout << "rec_coin(63, coins): " << rec_coin(63, coins) << std::endl;
	t = clock() -t;
	std::cout << "Time Spent (Recursively): " << (float) t << std::endl;

	DynamicCoinChange dc;
	t = clock();
	std::cout << "rec_coin(63, coins): " << dc(63, coins) << std::endl;
	t = clock() -t;
	std::cout << "Time Spent (Dynamically): " << (float) t << std::endl;


	return 0;
}