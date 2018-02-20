#include <iostream>
#include <array>

//Testing array references - START
template<typename T, int Size>
constexpr std::size_t getArraySize(const T(&)[Size]) noexcept
{
	return Size;
}


void getArrayType()
{
	std::cout << "=== 1: GET ARRAY TYPE [ARRAY REF]:====" << std::endl;
	int myArr[] = { 2, 3, 8, 12 };
	std::cout << "size of arbitrary int array (myArr) is: " << getArraySize(myArr) << std::endl;

	int newArr[getArraySize(myArr)];
	std::cout << "size of arr determined by getArraySize(myArr) is: " << getArraySize(newArr) << std::endl; 

	std::array<int, getArraySize(myArr)> stdArr;
	std::cout << "size of std::array is: " << stdArr.size() << std::endl;
}
//Testing array references - FINISH

int main(int argc, int* argv)
{
	getArrayType();

	std::cout << std::endl;

	std::cin.get();
}