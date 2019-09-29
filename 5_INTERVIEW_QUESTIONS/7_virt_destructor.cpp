#include <iostream>

class A
{
  public:
    A() { std::cout << "A::A()" << std::endl; }
    ~A() { std::cout << "A::~A()" << std::endl; }
};

class B: public A
{
  public:
    B() { std::cout << "B::B()" << std::endl; }
    ~B() { std::cout << "B::~B()" << std::endl; }
};

class C: public B
{
  public:
    C() { std::cout << "C::C()" << std::endl; }
    ~C() { std::cout << "C::~C()" << std::endl; }
};

int main()
{
    A* c = new C();
    delete c;
    //What will get printed to the console? Is there something wrong with this code?
    return 0;
}