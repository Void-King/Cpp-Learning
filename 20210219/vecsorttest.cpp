#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool sortcus1(int* a, int* b)
{
    if (a[0] < b[0]) return true;
    else return false;
}

bool sortcus2(int* a, int* b)
{
    if (a[1] < b[1]) return true;
    else return false;
}

int main()
{
    vector<int* > intpointvec;
    int* a = new int[2];
    a[0] = 15;
    a[1] = 16;
    intpointvec.push_back(a);

    int* b = new int[2];
    b[0] = 12;
    b[1] = 18;
    intpointvec.push_back(b);

    sort(intpointvec.begin(), intpointvec.end(), sortcus1);
    sort(intpointvec.begin(), intpointvec.end(), sortcus2);
    return 0;
}