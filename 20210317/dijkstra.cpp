#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef struct __distance__
{
    int to = -1;
    int maxCost = -1;
} Dist;

bool operator>(Dist a, Dist b)
{
    return a.maxCost > b.maxCost;
}

int n = 0;
vector<map<int, int> > mapVec;
bool visit[10000];
Dist disArray[10000];

priority_queue<Dist, vector<Dist>, greater<Dist> > distanceQue;

void dijkstra(int s)
{
    disArray[s].to = s;
    disArray[s].maxCost = 0;

    distanceQue.push(disArray[s]);

    while (!distanceQue.empty())
    {
        Dist cur = distanceQue.top();
        distanceQue.pop();
        if (visit[cur.to])
            continue;
        visit[cur.to] = true;

        for (auto itr = mapVec[cur.to].begin();
            itr != mapVec[cur.to].end(); ++itr)
        {
            if (visit[itr->first])
                continue;
            if ((disArray[itr->first].maxCost >= itr->second
                && disArray[itr->first].maxCost >= disArray[cur.to].maxCost)
                || disArray[itr->first].maxCost == -1)
            {
                disArray[itr->first].maxCost =
                    max (disArray[cur.to].maxCost, itr->second);
                distanceQue.push(disArray[itr->first]);
            }
        }
    }
}

int main()
{
    int m, s, t;
    cin >> n >> m >> s >> t;
    --s;
    --t;
    memset(visit, false, sizeof(bool) * n);
    for (int i = 0; i < n; ++i)
    {
        disArray[i].to = i;
        map<int, int> temp;
        mapVec.push_back(temp);
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        auto itr = mapVec[u].find(v);
        if (itr->second > w || itr == mapVec[u].end())
        {
            mapVec[v].erase(u);
            mapVec[u].erase(v);
            mapVec[u].insert(make_pair(v, w));
            mapVec[v].insert(make_pair(u, w));
        }
    }

    dijkstra(s);

    cout << disArray[t].maxCost;
    return 0;
}