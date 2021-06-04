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

struct edge
{
    int u;
    int v;
    int cost;
};

bool edgeCompare(edge &a, edge &b)
{
    return a.cost < b.cost;
}

vector<int> father;
int findFather(int x)
{
    if (father[x] == x)
        return x;
    else
    {
        int a = findFather(father[x]);
        father[x] = a;
        return a;
    }
}

int dji(int x, int y, int n,
        vector<vector<int>> &mapVec, vector<int> &disVec)
{
    disVec[x] = 0;
    int curX = x;
    int num = 1;

    while (num < n)
    {
        int near = curX;
        int min = 0x6fffffff;
        for (int i = 0; i < n; ++i)
        {
            if (mapVec[x][i] > 0 && mapVec[x][i] < min)
            {
                near = i;
                min = mapVec[x][i];
            }
        }
        if (near == curX)
        {
            continue;
        }
        int curDis = disVec[curX] + min;
        if (curDis < disVec[near])
        {
            disVec[near] = curDis;
        }
        curX = near;
        ++num;
    }
}

int main()
{
    // 48 0 65 A 97 a
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> mapVec;
    vector<int> disVec;
    vector<int> perMax;

    for (int i = 0; i < n; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
            {
                temp.push_back(0);
            }
            else
            {
                temp.push_back(-1);
            }
        }
        disVec.push_back(0x6fffffff);
        perMax.push_back(0);
        mapVec.push_back(temp);
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (mapVec[x - 1][y - 1] > 0 && mapVec[x - 1][y - 1] < z)
        {
            mapVec[x - 1][y - 1] = z;
            mapVec[y - 1][x - 1] = z;
            if (s == x)
            {
                disVec[y] = z;
                perMax[y] = z;
            }
            if (s == y)
            {
                disVec[x] = z;
                perMax[x] = z;
            }
        }
    }

    return 0;
}