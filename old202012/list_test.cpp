#include <bits/stdc++.h>

using namespace std;

list<int> b;

void SetCache(list<int>& a)
{
    b = move(a);
}

void GetCache(list<int>& a)
{
    a = move(b);
}

int main()
{
    list<int> a;
    a.push_back(10);
    // SetCache(a);
    // GetCache(a);
    // if (a.empty())
    //     cout << "a empty" << endl;
    // else
    //     cout << *a.begin() << endl;
    // if (b.empty())
    //     cout << "b empty" << endl;
    // else
    //     cout << *b.begin() << endl;
    list<int> b = a;
    a.clear();
    cout << *a.begin() << endl;
    cout <<  *b.begin() << endl;
    return 0;
}