#include "recursion_problems.h"
#include "DynamicArray.hpp"
#include "Dequeue.hpp"
#include "Stack.hpp"
#include <string>
#include <iostream>
#include <algorithm>

int factorial(const int& number)
{
	if (number == 0)
		return 1;
	else
		return number*factorial(number-1);
}

int digitsSum(const int& number)
{
	int firstDigit = number%10;
	int divisionResult = number/10;

	if(divisionResult == 0)
		return firstDigit;
	else
		return firstDigit+digitsSum(divisionResult);
}

// DynamicArray<String> wordSplit(std::string toSplit, DynamicArray<std::string> listOfWords)
// {
// 	DynamicArray<std::string> output;
// 	std::string::iterator it = toSplit.begin();
// 	std::string temp("");
// 	while(it != toSplit.end())
// 	{
// 		bool found = false;
// 		temp += *it;
// 		for(int i == 0; i < listOfWords.size(); ++i)
// 		{
// 			if(temp.compare(listOfWords[i]) == 0)
// 			{
// 				output.append(temp);
// 				found = true;
// 				break;
// 			}
// 		}
// 		if(found)
// 			break;
// 	}

// 	if(temp.length>0)



// 	return output.append(wordSplit())

// }

std::string reversePhrase(const std::string& phrase)
{
	if (phrase.length() == 1)
		return phrase;
	else
		return std::string(phrase.substr(phrase.length()-1,1) + reversePhrase(phrase.substr(0, phrase.length()-1)));
}

std::vector <std::string> permute(const std::string& phrase)
{
	std::vector<std::string> permutations;
	if(phrase.length() == 1)
	{
		permutations.push_back(phrase);
		return permutations;
	}
	else
	{
		for(int i = 0; i < phrase.length(); ++i)
		{
			
			std::vector<std::string> tempPerm = permute(phrase.substr(0,i)+phrase.substr(i+1,phrase.length()));
			for (int j = 0; j < tempPerm.size(); ++j)
			{
				// std::cout << "current Letter: " << phrase[i] << std::endl;
				// std::cout << "current Perm: " << tempPerm[j] << std::endl;
				permutations.push_back(phrase[i]+tempPerm[j]);
			}

		}
	}

	return permutations;
}

int fib_rec(const int& n)
{
	if(n == 1 || n == 0)
		return n;
	else
		return fib_rec(n-1) + fib_rec(n-2);
}

int rec_coin(const int& target, const std::vector<int>& coins)
{
	// std::vector<int>::const_iterator it = std::find(coins.begin(), coins.end(), number);
	// int total = 0;
	// std::vector<int> diff;
	// int i =0;
	// while(number - coins[i] > 0)
	// {
	// 	diff.push_back(number - coins[i]);
	// 	++i;
	// }
	// if(it != coins.end()) return 1;
	// else if(coins.size() == 1) return number/coins[0];
	// else if(diff[i-1] < coins[coins.size()-1])
	// 	return total + 1 + rec_coin(number-coins[coins.size()-1], std::vector<int>(coins.begin(), coins.begin()+i-1));
	// else if(diff[i-1] < coins[0])
	// 	return total + rec_coin(number, std::vector<int>(coins.begin(), coins.begin()+i-1));
	// 	
		
	int minimumCoins = target;
	std::vector<int>::const_iterator it = std::find(coins.begin(), coins.end(), target);
	if(it != coins.end())
		return 1;
	else
	{
		for (int i = 0; i < coins.size(); ++i)
		{
			double numOfCoins;
			if(coins[i] <= target)
			{
				numOfCoins = 1 + rec_coin(target - coins[i], coins);
				if(numOfCoins < minimumCoins)
					minimumCoins = numOfCoins;
			}			
		}
		return minimumCoins;
	}
}