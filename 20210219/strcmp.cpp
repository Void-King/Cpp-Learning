#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    string a = "";
    string b = "";
    a.resize(10);
    b.resize(10);
    scanf ("%s", &a[0]);
    scanf ("%s", &b[0]);
    int x = strcmp(a.c_str(), b.c_str());
    // 48 0 65 A 97 a
    return 0;
}