#include <iostream>

class MyClass
{
  public: 
    void print()
    {
        std::cout << "Does this work?\n";
    }
};

int main(int argc, char** argv)
{
    MyClass* p = nullptr;
    p->print(); // what happens here?
    return 0;
}