#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int x;
    cin >> x;

    int localCost = x * 5;
    int luoguCost = x * 3 + 11;

    if (localCost < luoguCost)
    {
        cout << "Local";
    }
    else
    {
        cout << "Luogu";
    }

    return 0;
}