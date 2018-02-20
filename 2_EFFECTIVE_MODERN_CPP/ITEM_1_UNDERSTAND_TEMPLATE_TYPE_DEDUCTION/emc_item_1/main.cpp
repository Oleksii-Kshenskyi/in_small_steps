#include <iostream>
#include <array>

//Testing array references - START
template<typename T, int Size>
constexpr std::size_t getArraySize(const T(&)[Size]) noexcept
{
	return Size;
}


void testArrayRefs()
{
	std::cout << "=== 1: TEST ARRAY REFS:====" << std::endl;

	int myArr[] = { 2, 3, 8, 12 };
	std::cout << "size of arbitrary int array (myArr) is: " << getArraySize(myArr) << std::endl;

	int newArr[getArraySize(myArr)];
	std::cout << "size of arr determined by getArraySize(myArr) is: " << getArraySize(newArr) << std::endl; 

	std::array<int, getArraySize(myArr)> stdArr;
	std::cout << "size of std::array is: " << stdArr.size() << std::endl;
}
//Testing array references - FINISH

//Testing array pointers - START
void passAsArray(const int[])
{
	std::cout << "passAsArray(const int[]) worked!" << std::endl;
}

/*void passAsArray(const int*) //this does not compile, because you can't pass an array into function
{}*/                           //it essentially works as a pointer, so this is effectively the same function as above

void passAsPointer(const int*) //same function as above, just with a different name to reflect that passing array as pointer works
{
	std::cout << "passAsPointer(const int*) worked!" << std::endl;
}

template <typename T>
void letsSeeArrays(T arg)
{
	std::cout << "Array on pass-by-value template arg is essentially a pointer. See? ==> " << arg << std::endl;
	//the type is const int*. Let's prove it.
	arg++; // this means pointer is NOT const and it can be changed (not const char* const)
	std::cout << "arg after increment is: " << arg << std::endl; //changed
	//"let's try to change the array element's value:
	//*arg = 12; // this does not compile, because array itself is const
	std::cout << "Trying to set value of one of array's ints does not compile, because type is CONST char*." << std::endl;
}

template <typename T>
void letsSeeArrayRefs(T& arg)
{
	std::cout << "Array by reference is passed as an actual array: " << arg << std::endl;
	std::cout << "However, attempting to increment it does not work, because it is a reference and an actual array type." << std::endl;
	//arg++; // does not compile, because type is a reference to const int[4] now.
}

void testArrayPointers()
{
	std::cout << "=== 2: TEST ARRAY PTRS:====" << std::endl;

	const int myArr[] = { 1, 3, 4, 5 }; //type is const int[4] 
	const int* ptrToArr = myArr; //even though type is const int*, it still compiles, because arrays decay to pointers
	                             //though in reality the types are NOT the same
	std::cout << "Array decay compiled successfully." << std::endl;

	passAsArray(myArr);
	passAsPointer(myArr);
	letsSeeArrays(myArr);
	letsSeeArrayRefs(myArr);
}
//Testing array pointers - FINISH

int main(int argc, int* argv)
{
	testArrayRefs();

	std::cout << std::endl;

	testArrayPointers();

	std::cout << std::endl;

	std::cin.get();
}