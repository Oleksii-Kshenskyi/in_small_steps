#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

//What is the lowest C++ standard necessary for this to compile?
int main()
{
    std::vector vec {6, 10, 6, 7, 6, 8, 6};
    //do something to remove all 6s from vec
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " ")); // what does this line do?
    return 0;
}
