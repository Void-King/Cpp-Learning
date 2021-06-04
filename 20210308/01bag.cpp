#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>
#include <set>

using namespace std;

vector<int> vVec;
vector<int> wVec;
set<int> items;

int ks(int i, int j)
{
    int result = 0;
    if (i == 0 || j == 0)
    {
        result = 0;
    }
    else if (wVec[i - 1] > j)
    {
        result = ks(i - 1, j);
    }
    else
    {
        int temp1 = ks(i - 1, j);
        int temp2 = ks(i - 1, j - wVec[i - 1]) + vVec[i - 1];
        result = max(temp1, temp2);
    }
    return result;
}

int main()
{
    int v = 0;
    cin >> v;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        cin >> x;
        vVec.push_back(x);
        wVec.push_back(x);
    }
    int maxV = ks(n, v);
    // 48 0 65 A 97 a
    cout << v - maxV << endl;

    return 0;
}