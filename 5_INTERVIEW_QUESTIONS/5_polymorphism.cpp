#include <iostream>

struct A
{
    void foo() {std::cout << "A::foo()" << std::endl; }
};

struct B: public A
{
    void foo() {std::cout << "B::foo()" << std::endl; }
};

struct C: public B
{
    void foo() {std::cout << "C::foo()" << std::endl; }
};

int main()
{
    A* a = new A();
    A* b = new B();
    B* c = new C();

    a->foo(); // what's printed here?
    b->foo(); // what's printed here?
    c->foo(); // what's printed here?
}