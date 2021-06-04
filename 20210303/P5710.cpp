#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int result[4] = {0};
    // 48 0 65 A 97 a
    int x;
    cin >> x;
    if (x % 2 == 0 && x > 4 && x <= 12)
    {
        result[0] = 1;
        result[1] = 1;
    }
    else if (x % 2 == 0 || (x > 4 && x <= 12))
    {
        result[1] = 1;
        result[2] = 1;
    }
    else
    {
        result[3] = 1;
    }

    for (auto i : result)
    {
        cout << i << " ";
    }
    return 0;
}