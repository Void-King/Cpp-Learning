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
    int x;
    cin >> x;
    if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}