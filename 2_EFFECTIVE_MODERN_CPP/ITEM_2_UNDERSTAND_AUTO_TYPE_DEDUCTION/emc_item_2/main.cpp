#include <iostream>

void testAutoIdenticalToTemplateDeduction()
{
	int x{ 35 };
	const int* rx{ &x };
	const char* const str = "somethingBig";
	const char str2[] { "SomethingElse" };
	std::cout << "int x = " << x << "; const int* rx (points to x) = " << rx << ";" << std::endl << std::endl;

	auto autoval1{ x };
	const auto autoval2{ x };
	const auto& autoval3{ x };
	std::cout << "autoval 1 (auto autoval1{ x }) is T, and x is int. It means autoval1 is also int and can be changed: " << ++autoval1 << std::endl; 
	std::cout << "But as this is a pass-by-value, the original x is unchanged (we changed a copy on previous line): " << x << std::endl;
	std::cout << "autoval 2 (const auto autoval2{ x }) is const T, and x is int. It means autoval2 is const int: " << autoval2 << std::endl;
	std::cout << "it also means autoval2 can't be cahnged, and if you attempt to do that, compilation is going to fail." << std::endl;
	//autoval2++; //fails because auto deduced type is const int
	std::cout << "autoval 3 (const auto& autoval3{ x }) is const T& and x is int. It means that autoval3 is const int&: " << autoval3 << std::endl;
	std::cout << "it also means that autoval3 can't be changed and if you attempt to do that, compilation is going to fail." << std::endl << std::endl;
	//autoval3++; //fails because auto deduced type is const int&

	auto* autoval4{ rx };
	std::cout << "autoval4 (auto* autoval4{ rx }) is T*, and rx is const int*. It means that we get const int*: " << autoval4 << std::endl;
	std::cout << "It also means that you can change the pointer: " << ++autoval4 << ", but you can't change the value it points to. " << std::endl << std::endl; autoval4--;
	//(*autoval4)++; //this fails, because the value under autoval4 is const.

	auto autoval5{ str };
	std::cout << "autoval5 (auto autoval5{ str }) is T, str is const char* const. It means we get const char*: " << str << std::endl;
	std::cout << "it means that you can't change the value of what it points to, the compilation will fail." << std::endl;
	//(*autoval5)++; //doesn't work because the auto has been deduced to const char* and you can't change the value.
	std::cout << "However, we can change the pointer itself: " << ++autoval5 << std::endl << std::endl;

	auto autoval6{ str2 };
	std::cout << "autoval6 is auto autoval6{ str2 }, and str2 is const char[13]. This means that the resolved type is const char*: " << autoval6 << std::endl;
	std::cout << "It means the pointer itself can be changed: " << ++autoval6 << std::endl;
	std::cout << "However, the value it points to can't be changed." << std::endl;
	//(*autoval6)++; fails because the type is const char* and the value it points to can't be changed.


}

int main(int argc, int* argv)
{
	testAutoIdenticalToTemplateDeduction();

	std::cin.get();
	return 0;
}