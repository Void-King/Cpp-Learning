#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 6;
    int *a = new int(n);
    a[0] = 1;
    std::shared_ptr<int> spNumSet(a);
    cout << a[0];
    return 0;
}