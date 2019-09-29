#include <iostream>

class TheClass
{
    public:
      static int i;
      TheClass(int newI)
      {
          i = newI;
      }
};

int TheClass::i = 0;

int main()
{
    TheClass one(1);
    TheClass two(2);
    std::cout << "one.i: " << one.i << std::endl; // what is printed here?
    std::cout << "two.i: " << two.i << std::endl; // what is printed here?
    return 0;
}