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

int dfs(vector<vector<int> > pathVec, vector<vector<int> > visitVec,
    int ix, int iy, int jx, int jy, int bordx, int bordy)
{
    if (ix < 0 || ix > bordx || iy < 0 || iy > bordy) return 0;
    if (pathVec[ix][iy] == 0) return 0;
    if (visitVec[ix][iy] == 1) return 0;
    if (ix == jx && iy == jy) return 1;

    int sum = 0;
    visitVec[ix][iy] = 1;
    sum += dfs(pathVec, visitVec, ix + 1, iy, jx, jy, bordx, bordy);
    sum += dfs(pathVec, visitVec, ix - 1, iy, jx, jy, bordx, bordy);
    sum += dfs(pathVec, visitVec, ix, iy + 1, jx, jy, bordx, bordy);
    sum += dfs(pathVec, visitVec, ix, iy - 1, jx, jy, bordx, bordy);
    visitVec[ix][iy] = 0;

    return sum;
}

int bfs(vector<vector<int> > pathVec, vector<vector<int> > visitVec,
    int ix, int iy, int jx, int jy, int bordx, int bordy)
{
    int sum = 0;
    queue<pair<int, int>> qu;
    qu.push(make_pair(ix, iy));
    while (!qu.empty())
    {
        auto p = qu.front();
        qu.pop();
        visitVec[p.first][p.second] = 1;
        if (p.first == jx && p.second == jy)
        {
            visitVec[p.first][p.second] = 0;
            sum += 1;
            continue;
        }
        else
        {
            list<pair<int, int>> ls;
            ls.push_back(make_pair(p.first + 1, p.second));
            ls.push_back(make_pair(p.first - 1, p.second));
            ls.push_back(make_pair(p.first, p.second + 1));
            ls.push_back(make_pair(p.first, p.second - 1));
            for (auto pt : ls)
            {
                if (pt.first < 0 || pt.first > bordx ||
                    pt.second < 0 || pt.second > bordy)
                {
                    continue;
                }
                if (pathVec[pt.first][pt.second] == 0)
                {
                    continue;
                }
                if (visitVec[pt.first][pt.second] == 0)
                {
                    qu.push(make_pair(pt.first, pt.second));
                }
            }
        }
    }
    return sum;
}

int main()
{
    vector<vector<int> > pathVec;
    vector<vector<int> > visitVec;
    int x, y, z;
    cin >> x >> y >> z;
    for (int i = 0; i < x; ++i)
    {
        vector<int> temp;
        vector<int> tempV;
        for (int j = 0; j < y; ++j)
        {
            temp.push_back(1);
            tempV.push_back(0);
        }
        pathVec.push_back(temp);
        visitVec.push_back(tempV);
    }

    int ix, iy, jx, jy;
    cin >> ix >> iy >> jx >> jy;

    for (int i = 0; i < z; ++i)
    {
        int m, n;
        cin >> m >> n;
        pathVec[m - 1][n - 1] = 0;
    }

    // cout << dfs(pathVec, visitVec, ix - 1, iy - 1,
    //     jx - 1, jy - 1, x - 1, y - 1) << endl;
    cout << bfs(pathVec, visitVec, ix - 1, iy - 1,
        jx - 1, jy - 1, x - 1, y - 1);
    return 0;
}