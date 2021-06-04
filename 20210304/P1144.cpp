#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

void spfa(int root, vector<vector<int> >& mapVec, vector<int>& visitVec, vector<int>& disVec, vector<int>& ansVec)
{
    queue<int> que;
    que.push(root);
    disVec[root] = 0;
    ansVec[root] = 1;
    visitVec[root] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int i = 0; i < mapVec[u].size(); ++i)
        {
            int v = mapVec[u][i];
            if (disVec[v] > disVec[u] + 1)
            {
                disVec[v] = disVec[u] + 1;
                ansVec[v] = ansVec[u];
                if (visitVec[v] == 0)
                {
                    visitVec[v] = 1;
                    que.push(v);
                }
            }
            else if (disVec[v] == disVec[u] + 1)
            {
                ansVec[v] = (ansVec[v] + ansVec[u]) % 100003;
            }
        }
        visitVec[u] = 0;
    }
}

int main()
{
    vector<vector<int> > mapVec;
    vector<int> visitVec;
    vector<int> disVec;
    vector<int> ansVec;

    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x; ++i)
    {
        vector<int> temp;
        mapVec.push_back(temp);
        ansVec.push_back(0);
        visitVec.push_back(0);
        disVec.push_back(0x6fffffff);
    }
    for (int j = 0; j < y; ++j)
    {
        int b, e;
        cin >> b >> e;
        mapVec[b - 1].push_back(e - 1);
        mapVec[e - 1].push_back(b - 1);
    }

    spfa(0, mapVec, visitVec, disVec, ansVec);
    
    for (auto i : ansVec)
    {
        cout << i << endl;
    }
    return 0;
}