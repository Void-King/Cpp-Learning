#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct edge
{
    int u, v;
    int cost;
};

bool cmp(edge a, edge b)
{
    return a.cost < b.cost;
}

// 并查集
vector<int> father;
int findFather(int x)
{
    if (x == father[x])
    {
        return x;
    }
    else
    {
        int f = findFather(father[x]);
        father[x] = f;
        return f;
    }
}

vector<edge> edgeVec;
int kruskal(int n, int m)
{
    int ans = 0;
    int numEdge = 0;

    sort (edgeVec.begin(), edgeVec.end(), cmp);

    for (int i = 0; i < n; ++i)
    {
        father.push_back(i);
    }
    for (int i = 0; i < m; ++i)
    {
        int fatU = findFather(edgeVec[i].u);
        int fatV = findFather(edgeVec[i].v);
        if (fatU != fatV)
        {
            father[fatV] = fatU;
            ans += edgeVec[i].cost;
            ++numEdge;
            if (numEdge == n - 1)
            {
                break;
            }
        }
    }
    if (numEdge != n - 1)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main()
{
    int x;
    cin >> x;
    vector<vector<int> > mapVec;

    for (int i = 0; i < x; ++i)
    {
        vector<int> tempVec;
        for (int j = 0; j < x; ++j)
        {
            int y;
            cin >> y;
            tempVec.push_back(y);
        }
        mapVec.push_back(tempVec);
    }

    int edgeAmount = 0;
    for (int i = 0; i < x; ++i)
    {
        for (int j = i + 1; j < x; ++j)
        {
            edge temp;
            temp.u = i;
            temp.v = j;
            temp.cost = mapVec[i][j];
            edgeVec.push_back(temp);
            ++edgeAmount;
        }
    }
    cout << kruskal(x, edgeAmount);
    return 0;
}