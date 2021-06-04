#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>
#include <set>

using namespace std;

class parentCls
{
public:
    virtual void Test();
protected:
    int m_tsetInt = 0;
};

void parentCls::Test()
{
    m_tsetInt = 10;
    cout << m_tsetInt;
}

class childCls : public parentCls
{
public:
    virtual void Test();
};

void childCls::Test()
{
    m_tsetInt = 20;
    cout << m_tsetInt;
}

int main()
{
    // parentCls test;
    // test.Test();
    int value = 0x80005153;
    printf ("%d", value);
    // 48 0 65 A 97 a
    return 0;
}