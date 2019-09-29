#include <iostream>

int main()
{
    int array[] = {3, 5, 9, 15};
    const int* p1 = array;
    int* const p2 = &array[2];
    const int* const p3 = array;
    (*p1)++; // can we do this?
    p1++; // can we do this?
    (*p2)++; // can we do this?
    p2++; // can we do this?
    (*p3)++; // can we do this?
    p3++; // can we do this?

    std::cout << "p1: " << p1 << std::endl; // what's printed here if all the bad lines are commented out?
    std::cout << "p1 => " << *p1 << std::endl; // what's printed here if all the bad lines are commented out?
    std::cout << "p2 => " << *p2 << std::endl; // what's printed here if all the bad lines are commented out?
    std::cout << "p3 => " << *p3 << std::endl; // what's printed here if all the bad lines are commented out?
    
    return 0;
}
