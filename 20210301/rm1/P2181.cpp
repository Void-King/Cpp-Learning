#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    // 48 0 65 A 97 a
    unsigned long long x;
    cin >> x;
    unsigned long long lx = x * (x - 1) / 2 * (x - 2) / 3 * (x - 3) / 2 / 2;
    cout << lx;
    return 0;
}