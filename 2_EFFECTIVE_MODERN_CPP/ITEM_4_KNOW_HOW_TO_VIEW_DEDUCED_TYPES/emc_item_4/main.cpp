#include <iostream>

//1. Testing viewing template deduced types via compilation errors
template<typename T>
class TD;

void testCompErrorView()
{
	std::cout << "1. ***COMPILATION ERRRORS***" << std::endl << "To view deduced type through compilation errors, you should declare template and template class with different names, the class incomplete." << std::endl;
	std::cout << "Then you try to instantiate that class: TD<decltype(x) xType; where TD is an incomplete class, and x is the variable you want to know the type of." << std::endl << std::endl;
	const int someNum = 35;

	auto x = someNum;
	auto y = &someNum;
	//TD<decltype(x)> xType; //uncomment this to learn x's type
	//TD<decltype(y)> yType; //uncomment this to learn y's type
}

template <typename T>
void funca(const T& funcaram)
{
	std::cout << "T = " << typeid(T).name() << std::endl;
	std::cout << "funcaram = " << typeid(funcaram).name() << std::endl;
}

void testTypeidName()
{
	std::cout << "2. ***TYPEID NAME***" << std::endl;
	std::cout << "You can also test deduced types via typeid(x).name(), where x is the variable you want to know the type of." << std::endl;

	int a = 35;
	int* p = &a;
	const int c = a;
	const int& r = a;

	std::cout << "int a: " << typeid(a).name() << std::endl;
	std::cout << "int* p: " << typeid(p).name() << std::endl;
	std::cout << "const int c: " << typeid(c).name() << std::endl;
	std::cout << "const int& r: " << typeid(r).name() << std::endl;

	auto val = a;
	auto& val2 = p;
	const auto val3 = r;

	std::cout << "auto val = a; = " << typeid(val).name() << std::endl;
	std::cout << "auto& val2 = p; = " << typeid(val2).name() << std::endl;
	std::cout << "const auto val3 = r; = " << typeid(val).name() << std::endl;

	funca(a);
}


int main(int argc, int* argv)
{
	testCompErrorView();
	testTypeidName();
	std::cin.get();
	return 0;
}