#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


void testStandardCases()
{
	std::cout << "***STANDARD CASES***" << std::endl;
	
	//int a; - may not compile on some compilers and some warning level settings, contains junk
	//auto b; - does not compile, auto doesn't let you declare variables and leave them uninitialized
	auto c = 3;
	std::cout << "int a; - can be junk (uninitialized)" << std::endl
		<< "auto b; - can't be uninitialized, compiler error" << std::endl
	    << "auto c = 3; - initialized and free of type deduction problems: " << c << std::endl;

	std::cout << "Use auto to loop through container iterator types: std::vector<char> v(10): " << std::endl;
	std::vector<char> v(10);
	for (auto& it = v.begin(); it != v.end(); it++)
	{
		*it = 'k';
	}
	std::copy(v.begin(), v.end(), std::ostream_iterator<char>(std::cout, " "));

}

void testLambdasAndStuff()
{
	std::cout << "***TEST LAMBDAS AND STUFF***" << std::endl;

	auto ab = 35;
	std::cout << "You can store pointers to lambda functions with auto: " << std::endl
		      << "auto incrementFunc = [](const auto& ptr) { return ++(*ptr); };" << std::endl
	          << "auto ab = 35; = " << ab << std::endl;
	auto incrementFunc = [](const auto& ptr) { return ++(*ptr); };
	std::cout << "incrementFunc(&ab); = " << incrementFunc(&ab) << std::endl;
}

int main(int argc, int* argv)
{
	testStandardCases();
	testLambdasAndStuff();
	std::cin.get();
	return 0;
}