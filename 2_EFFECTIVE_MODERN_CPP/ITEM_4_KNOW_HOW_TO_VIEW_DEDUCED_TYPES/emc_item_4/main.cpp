#include <iostream>
#include <boost\type_index.hpp>

using boost::typeindex::type_id_with_cvr;

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

	funca(a); std::cout << std::endl;
}

template <typename T>
void funca2(const T& funcaram)
{
	std::cout << "T = " << type_id_with_cvr<T>().pretty_name() << std::endl;
	std::cout << "funcaram = " << type_id_with_cvr<decltype(funcaram)>().pretty_name() << std::endl;
}

void testBoostTypeIndex()
{
	std::cout << "3. ***BOOST TYPE INDEX***" << std::endl;
	std::cout << "You can also identify types with boost::type_index. This is the most precise tool." << std::endl;

	int a = 35;
	int* p = &a;
	const int c = a;
	const int& r = a;
	const int* pp = &a;

	std::cout << "int a: " << type_id_with_cvr<decltype(a)>().pretty_name() << std::endl;
	std::cout << "int* p: " << type_id_with_cvr<decltype(p)>().pretty_name() << std::endl;
	std::cout << "const int c: " << type_id_with_cvr<decltype(c)>().pretty_name() << std::endl;
	std::cout << "const int& r: " << type_id_with_cvr<decltype(r)>().pretty_name() << std::endl;
	std::cout << "const int* pp = &a; = " << type_id_with_cvr<decltype(pp)>().pretty_name() << std::endl;

	auto val = a;
	auto& val2 = p;
	const auto val3 = r;
	auto autopp = pp;

	std::cout << "auto val = a; = " << type_id_with_cvr<decltype(val)>().pretty_name() << std::endl;
	std::cout << "auto& val2 = p; = " << type_id_with_cvr<decltype(val2)>().pretty_name() << std::endl;
	std::cout << "auto val3 = r; = " << type_id_with_cvr<decltype(val3)>().pretty_name() << std::endl;
	std::cout << "auto autopp = pp; = " << type_id_with_cvr<decltype(autopp)>().pretty_name() << std::endl;

	funca2(r);

	const int someNum = 35;

	auto x = someNum;
	auto y = &someNum;

	std::cout << "const int someNum = " << type_id_with_cvr<decltype(someNum)>().pretty_name() << std::endl;
	std::cout << "auto x = someNum; = " << type_id_with_cvr<decltype(x)>().pretty_name() << std::endl;
	std::cout << "auto y = &someNum; = " << type_id_with_cvr<decltype(y)>().pretty_name() << std::endl;
}


int main(int argc, int* argv)
{
	testCompErrorView();
	testTypeidName();
	testBoostTypeIndex();
	std::cin.get();
	return 0;
}