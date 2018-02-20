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

//Testing type deduction of pointers - START
template <typename T>
void templatePointer(T* arg)
{
	std::cout << "If the type was with no modifiers, then it's a simple non-const pointer: " << arg << std::endl;
	std::cout << "The pointer itself can be changed: " << ++arg << std::endl; arg--;
	std::cout << "The pointer's pointed value (" << (*arg)++ << ") can also be changed: " << *arg << std::endl;
}

template <typename T>
void templatePointerConst(T* arg)
{
	std::cout << "However, if the expression type is already const type*, you get a const pointer: " << arg << std::endl;
	std::cout << "It means the pointer itself can change: " << ++arg << std::endl; arg--;
	std::cout << "But if you try to change the value pointed at, compilation will fail, because the value is const." << std::endl;
	//(*arg)++; this fails, because the value pointed at is const.
}

void testPointers()
{
	std::cout << "=== 3: TEST PTRS:====" << std::endl;

	int val = 30;
	std::cout << "val is " << val << " after init." << std::endl;
	const int* pval = &val;
	templatePointer(&val);
	templatePointerConst(pval);
}

//Testing type deduction of pointers - FINISH

//Testing type deduction of references - START
template<typename T>
void testNoModifiersType(T& arg)
{
	std::cout << "If your type has no modifiers, passing it into templated function as T& will get you a type&: " << arg++ << std::endl;
	std::cout << "Changed variable inside the changing function looks like: " << arg << std::endl;
}

template<typename T>
void testConstModifierType(T& arg)
{
	std::cout << "If you pass a const type into T& templated function, you get a const T&: " << arg << std::endl;
	std::cout << "You obviously can't change it, and the compilation fails if you try to." << std::endl;
	//arg++; //this fails because the variable is const int&
}

template<typename T>
void testConstRefModifierType(T& arg)
{
	std::cout << "If you pass a const type& into T& templated function, you get a const T& again: " << arg << std::endl;
	std::cout << "You obviously can't change it, and the compilation fails if you try to." << std::endl;
	//arg++; //this fails because the variable is const int&
}

template<typename T>
void testConstRefTemplate(const T& arg)
{
	std::cout << "If you pass anything (T, T&, const T&) into const T& templated function, you always get a const T&: " << arg << std::endl;
	std::cout << "You obviously can't change it, and the compilation fails if you try to." << std::endl;
	//arg++; //this fails because arg is always const int&
}

void testReferences()
{
	std::cout << "=== 4: TEST REFS:====" << std::endl;

	int val = 20;
	const int cval = 20;
	const int& rval = val;

	testNoModifiersType(val);
	std::cout << "However, a changed variable inside the caller function is still changed: " << val << std::endl;
	std::cout << "This proves that the variable is passed by reference." << std::endl;
	testConstModifierType(cval);
	testConstRefModifierType(rval);
	std::cout << "First pass with int: " << std::endl;
	testConstRefTemplate(val);
	std::cout << "Second pass with int&: " << std::endl;
	testConstRefTemplate(cval);
	std::cout << "Third pass with const int&: " << std::endl;
	testConstRefTemplate(rval);
}
//Testing type deduction of references - FINISH

//Testing type deduction of universal references - START
template <typename T>
void testNoModifiersUniLvalue(T&& arg)
{
	std::cout << "As long as universal reference is an lvalue, it will always be a reference: " << arg << std::endl;
	std::cout << "If it didn't have modifiers in the expression passed into function, then it's a simple non-const reference." << std::endl;
	std::cout << "Of course, it can be changed: " << ++arg << std::endl;
}

template<typename T>
void testModifiersUniLvalue(T&& arg)
{
	std::cout << "If universal reference had modifier (like const) before being passed, it's a const int& in a T&& templated function: " << arg << std::endl;
	std::cout << "Of course it can't be changed and attempting to do so will result compilation to fail." << std::endl;
	//arg++; //this fails because arg is const T&
}

template <typename T>
void testUniRvalue(T&& arg)
{
	std::cout << "If you pass an rvalue to T&& templated function, then argument is an rvalue reference: " << arg << std::endl;
	std::cout << "It can of course be changed (because it's a reference), but it'll get destroyed after function finishes, because it's temporary:" << ++arg << std::endl;
}

void testUniversalReferences()
{
	std::cout << "=== 5: TEST UNIVERSAL REFS:====" << std::endl;

	int val = 20;
	const int cval = 20;
	const int& rval = val;

	testNoModifiersUniLvalue(val);
	std::cout << "And of course, the value is changed in the caller function: " << val << std::endl;
	std::cout << "testModifiersUniLvalue() first pass for const int: " << std::endl;
	testModifiersUniLvalue(cval);
	std::cout << "testModifiersUniLvalue() second pass for const int&: " << std::endl;
	testModifiersUniLvalue(rval);
	testUniRvalue(36);
}

//Testing type deduction of universal references - FINISH

//Testing type deduction for pass-by-value cases - START
template<typename T> 
void templatePassByValue(T arg)
{
	std::cout << "No matter what you pass, if the template argument is pass-by-value, it will always be a simple modifiable copy: " << arg << std::endl;
	std::cout << "It means the value can be changed: " << ++arg << std::endl;
}

template <typename T>
void templatePassByValueConstStr(T arg)
{
	std::cout << "However, if you pass a const pointer to const string (const char* const), you get a const char*: " << arg << std::endl;
	std::cout << "It means that the pointer can be changed inside templated function: " << ++arg << std::endl;
	std::cout << "But it means that you can't change the value itself, because you'll get a compilation error." << std::endl;
	//(*arg)++ //this fails, because type is const char* and the value itself is constant and can't be changed.
	std::cout << "This happens because the variable that is passed by value is a pointer." << std::endl;
	std::cout << "By the rules of pass-by-value type deduction, all modifiers for that variable (pointer) are ignored." << std::endl;
	std::cout << "But the modifiers for the value the pointer points at remain unchanged, because that's a different entity." << std::endl;
}

void testPassByValue()
{
	std::cout << "=== 6: TEST PASS BY VALUE:====" << std::endl;

	int val = 20; 
	const int cval = 20;
	const int& rval = 20;

	std::cout << "First pass with int: " << std::endl;
	templatePassByValue(val);
	std::cout << "And it also means that in the caller function the value will be unchanged (because you changed a copy, not the original): " << val << std::endl;

	std::cout << "Second pass with const int: " << std::endl;
	templatePassByValue(cval);
	std::cout << "And it also means that in the caller function the value will be unchanged (because you changed a copy, not the original): " << cval << std::endl;

	std::cout << "Third pass with const int&: " << std::endl;
	templatePassByValue(rval);
	std::cout << "And it also means that in the caller function the value will be unchanged (because you changed a copy, not the original): " << rval << std::endl;

	const char* const str = "SomeString";
	templatePassByValueConstStr(str);
}
//Testing type deduction for pass-by-value cases - FINISH

int main(int argc, int* argv)
{
	testArrayRefs();

	std::cout << std::endl;

	testArrayPointers();

	std::cout << std::endl;

	testPointers();

	std::cout << std::endl;

	testReferences();

	std::cout << std::endl;

	testUniversalReferences();

	std::cout << std::endl;

	testPassByValue();

	std::cin.get();
}