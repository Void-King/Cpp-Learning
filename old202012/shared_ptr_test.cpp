#include <bits/stdc++.h>

using namespace std;

int main()
{
    shared_ptr<int> a1 = make_shared<int>(10);
    shared_ptr<int> a2;
    a2 = a1;

    shared_ptr<int> a3 = make_shared<int>(12);
    a2 = a3;

    a2 = a1;
    a1 = a3;
   
    cout << "a1:" << *a1.get() << " " << a1.use_count() << endl;
    cout << "a2:" << *a2.get() << " " << a2.use_count() << endl;
    cout << "a3:" << *a3.get() << " " << a3.use_count() << endl;
    return 0;
}