#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"

bool compareTwoParantheses(char f, char l)
{
	if(f == '(' && l == ')')
		return true;
	else if (f == '[' && l == ']')
		return true;
	else if (f == '{' && l == '}')
		return true;
	else
		return false;
}	

bool balanceCheck(std::string testString)
{
	int strLength = testString.length();
	const char* strChars = testString.c_str();

	Stack<char> pStack;
	Queue<char> pQueue;
	bool balanced = true;
	for (int i = 0; i < strLength; ++i)
	{
		if(*(strChars+i) == '{' || *(strChars+i) == '[' || *(strChars+i) == '(')
			pStack.push(*(strChars+i));
		else
		{
			if(pStack.isEmpty())
			{
				balanced = false;
				break;
			}
			char f = pStack.pop();
			char l = *(strChars+i);
			if(!compareTwoParantheses(f,l))
			{
				balanced = false;
				break;
			}
		}
	}
	if(!pStack.isEmpty())
		balanced = false;
	return balanced;
}

int main (int argc, char** argv)
{
	std::string testString1("()(){]}");

	bool balanced = balanceCheck(testString1);
	if(balanced)
		std::cout << "String: " << testString1 << "is Balanced" << std::endl;
	else
		std::cout << "String: \"" << testString1 << "\" is Unbalanced" << std::endl;


	std::string testString2("[](){([[[]]])}");

	balanced = balanceCheck(testString2);
	if(balanced)
		std::cout << "String: \"" << testString2 << "\" is Balanced" << std::endl;
	else
		std::cout << "String: \"" << testString2 << "\" is Unbalanced" << std::endl;


	testString2 = "[](){([[[]]])}(";
	balanced = balanceCheck(testString2);
	if(balanced)
		std::cout << "String: \"" << testString2 << "\" is Balanced" << std::endl;
	else
		std::cout << "String: \"" << testString2 << "\" is Unbalanced" << std::endl;

	testString2 = "[{{{(())}}}]((()))";
	balanced = balanceCheck(testString2);
	if(balanced)
		std::cout << "String: \"" << testString2 << "\" is Balanced" << std::endl;
	else
		std::cout << "String: \"" << testString2 << "\" is Unbalanced" << std::endl;

	
	testString2 = "[[[]])]";
	balanced = balanceCheck(testString2);
	if(balanced)
		std::cout << "String: \"" << testString2 << "\" is Balanced" << std::endl;
	else
		std::cout << "String: \"" << testString2 << "\" is Unbalanced" << std::endl;


	// if(pStack.size() != pQueue.size())
	// 	std::cout << "Unbalanced" << std::endl;
	// else
	// {
	// 	bool balanced = true;
	// 	for (int i = 0; i < pStack.size(); ++i)
	// 	{
	// 		char f,l;
	// 		f = pStack.pop();
	// 		l = pQueue.dequeue();

	// 		if(!compareTwoParantheses(f,l))
	// 		{
	// 			balanced = false;
	// 			break;
	// 		}
	// }
	// 	if(balanced)
	// 		std::cout << "Balanced" << std::endl;
	// 	else
	// 		std::cout << "Unbalanced" << std::endl;
	// }

	return 0;
}