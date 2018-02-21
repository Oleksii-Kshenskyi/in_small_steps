#include <iostream>
#include <vector>

void testAutoDecltypeDifference()
{
	std::cout << "*** 1. AUTO AND DECLTYPE DIFFERENCE ***" << std::endl;

	int x = 35;
	const int& rx = x; //declaring rx that is a constant reference to int

	auto autoval = rx; // this is auto type deduction, so it strips the variable of both constness and referenceness, autoval's type is just int
	std::cout << "auto autoval = rx where rx is const int&, so template type deduction strips variable of both constness and referenceness, " 
		      << "autoval's type is just int: " << autoval 
		      << std::endl;
	std::cout << "It means that autoval can be changed even though the ogirinal was const: " << ++autoval << std::endl;

	
	decltype(auto) declauto = rx; // this is a decltype variant, which returns exactly what the type implies: declauto is const int&
	std::cout << "However, decltype(auto) declauto = rx makes declauto a const int& instead [literal type deduction]" << std::endl;
	std::cout << "It means that if you try to change it, the compilation is going to fail." << std::endl << std::endl;
	//declauto++; //this does not compile, because decltype returns exactly what is passed into its expression, meaning that the object is const int&

}

auto decltypeTrailing(std::vector<int>& container, int index) -> decltype(container[index])
{
	std::cout << "Decltype auto functions enable you to return exactly the type returned from the function." << std::endl;
	std::cout << "It means that in case of an array, if you return its element (containter[index]), it will probably be index& type: " << container[index] << std::endl;
	return container[index];
}

auto autoTest(std::vector<int>& container, int index)
{
	std::cout << "However, if you try to return such a value from a function with just auto as return type, you get an ordinary int: " << container[index] << std::endl;
	std::cout << "It means that you can change it inside the function: " << ++container[index] << std::endl;
	return container[index];
}

decltype(auto) decltypeAuto(std::vector<int>& container, int index) 
{
	std::cout << "If instead of trailing return type you decide to use decltype(auto), it does the same thing, leaves object's type unchanged." << std::endl;
	std::cout << "It means that in case of an array, if you return its element (containter[index]), it will probably be index& type: " << container[index] << std::endl;
	return container[index];
}

decltype(auto) decltypeException()
{
	int x = 4;
	std::cout << "There is also one exception. If you declare decltype(auto) return value, but 'return x', you'll get a TYPE in the caller." << std::endl;
	std::cout << "However, if you do 'return (x)' and add parentheses, such a function returns TYPE&, because decltype returns T& for all entities that are lvalues and not names: " << x++ << std::endl;
	return (x);
}

void testDecltypeFunctions()
{
	std::cout << "*** 2. DECLTYPE FUNCTIONS: ***" << std::endl;
	std::vector<int> v{ 1,2 };
	decltype(auto) temp = decltypeTrailing(v, 1);
	std::cout << "this means that the returned value can be modified back in the caller function: " << ++temp << std::endl;

	decltype(auto) temp2 = autoTest(v, 1);
	temp2++;
	std::cout << "But in the caller function, if you try to change return value as a part of vector, it won't change, because you changed a copy: " << v[1] << std::endl;

	decltype(auto) temp3 = decltypeAuto(v, 1);
	std::cout << "which again means that the returned value can be modified back in the caller function: " << ++temp3 << std::endl;


	std::cout << "It means that your return value is a reference. Thus, if you declared a local variable and passed it hoping to get a copy, you can get junk instead: " << decltypeException() << std::endl;
}

int main(int argc, char* argv)
{
	testAutoDecltypeDifference();
	testDecltypeFunctions();
	std::cin.get();
	return 0;
}