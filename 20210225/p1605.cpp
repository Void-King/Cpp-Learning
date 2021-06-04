#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int dfs(vector<vector<bool>> mapVec, vector<vector<bool>> visitVec,
        int bx, int by, int ex, int ey, int n, int m)
{
    if (bx < 0 || by < 0 || bx >= n || by >= m)
        return 0;
    if (!mapVec[bx][by])
        return 0;
    if (bx == ex && by == ey)
        return 1;
    if (visitVec[bx][by])
        return 0;
    visitVec[bx][by] = true;
    int sum = 0;
    sum += dfs(mapVec, visitVec, bx + 1, by, ex, ey, n, m);
    sum += dfs(mapVec, visitVec, bx, by + 1, ex, ey, n, m);
    sum += dfs(mapVec, visitVec, bx - 1, by, ex, ey, n, m);
    sum += dfs(mapVec, visitVec, bx, by - 1, ex, ey, n, m);
    visitVec[bx][by] = false;
    return sum;
}

int main()
{
    int n, m, t;
    scanf("%d %d %d", &n, &m, &t);
    vector<vector<bool>> mapVec;
    vector<vector<bool>> visitVec;
    for (int i = 0; i < n; ++i)
    {
        vector<bool> temp;
        vector<bool> tempSec;
        for (int j = 0; j < m; ++j)
        {
            temp.push_back(true);
            tempSec.push_back(false);
        }
        mapVec.push_back(temp);
        visitVec.push_back(tempSec);
    }
    int bx, by, ex, ey;
    scanf("%d %d %d %d", &bx, &by, &ex, &ey);
    for (int i = 0; i < t; ++i)
    {
        int fx, fy;
        scanf("%d %d", &fx, &fy);
        mapVec[fx - 1][fy - 1] = false;
    }
    int sum = dfs(mapVec, visitVec, bx - 1, by - 1, ex - 1, ey - 1, n, m);
    cout << sum;
    return 0;
}