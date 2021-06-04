#include <bits/stdc++.h>

using namespace std;

class B{
public:
    B();
    int id;
};

B::B()
{
    id = 10;
    cout << "B construct used!" << endl;
}

class A{
public:
    A();
    ~A();
    B* getB() const;
    B* ab;
};

A::A()
{
    ab = new B();
    cout << "A construct used!" << endl;
}

A::~A()
{
    delete (ab);
    ab = NULL;
    cout << "A destory used!" << endl;
}

B* A::getB() const
{
    return ab;
}

int main()
{
    A* a1 = new A();
    B* b1 = a1->getB();

    cout << b1->id << endl;

    delete (a1);
    a1 = NULL;

    cout << b1->id << endl;
    return 0;
}