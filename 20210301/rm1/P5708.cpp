#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    // 48 0 65 A 97 a
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf ("%.1lf", s);
    return 0;
}