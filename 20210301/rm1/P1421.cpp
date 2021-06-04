#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int cost = 19;
    // 48 0 65 A 97 a
    int a, b;
    cin >> a >> b;
    int money = a * 10 + b;
    cout << money / cost;
    return 0;
}