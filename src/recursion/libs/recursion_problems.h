#ifndef RECURSION_LIBS_RECURSION_PROBLEMS_H
#define RECURSION_LIBS_RECURSION_PROBLEMS_H
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <algorithm>



template <typename inputType, typename returnType> class Memoization{
private:
	std::unordered_map<inputType, returnType> dict_;
	std::function<returnType(inputType)> call_;
public:
	Memoization(std::function<returnType(inputType)> call) : call_(call){}
	returnType operator()(const inputType& n)
	{
		typename std::unordered_map<inputType, returnType>::const_iterator it = dict_.find(n);
		if(it != dict_.end())
			return it->second;
		else
		{
			int newEntry = call_(n);
			dict_.insert(std::pair<inputType, returnType>(n,newEntry));
			return newEntry;
		}
	}
};

/**
 * @brief      { function_description }
 *
 * @param[in]  number  The number
 *
 * @return     { description_of_the_return_value }
 */
int factorial(const int& number);

/**
 * @brief      { function_description }
 *
 * @param[in]  number  The number
 *
 * @return     { description_of_the_return_value }
 */
int digitsSum(const int& number);

std::string reversePhrase(const std::string& phrase);

std::vector <std::string> permute(const std::string& phrase);

int fib_rec(const int& n);

int rec_coin(const int& number, const std::vector<int>& coins);

class DynamicCoinChange
{
private:
	std::unordered_map<int, int> dict_;
public:

	int operator()(const int& target_, const std::vector<int>& coins_)
	{
		typename std::unordered_map<int, int>::const_iterator it1 = dict_.find(target_);
		if(it1 != dict_.end())
			return it1->second;

		else
		{
			int minimumCoins = target_;
			std::vector<int>::const_iterator it = std::find(coins_.begin(), coins_.end(), target_);
			if(it != coins_.end())
				return 1;
			else
			{
				for (int i = 0; i < coins_.size(); ++i)
				{
					double numOfCoins;
					if(coins_[i] <= target_)
					{
						numOfCoins = 1 + operator()(target_ - coins_[i], coins_);
						if(numOfCoins < minimumCoins)
						{
							minimumCoins = numOfCoins;
							dict_[target_] = minimumCoins;
						}
					}			
				}
				return minimumCoins;
			}
		}	
	}
};


#endif