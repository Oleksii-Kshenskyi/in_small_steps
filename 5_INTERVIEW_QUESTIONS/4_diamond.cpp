#include <iostream>

struct A
{
    int num;
    A() { num = 1; }
};

struct B : public A
{
    B() { num = 2; }
};

struct C : public A
{
    C() { num = 3; }
};

struct D : public B, C
{
};

int main()
{
    D d;
    std::cout << "B::Num: " << d.B::num << std::endl; // what's printed here?
    std::cout << "C::Num: " << d.C::num << std::endl; // what's printed here?

    return 0;
}