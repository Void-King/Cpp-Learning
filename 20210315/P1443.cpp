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

void dfs(int x, int y, int curPace, int borderX, int borderY,
         vector<vector<int>> &visit)
{
    if (x >= borderX || x < 0 || y < 0 || y >= borderY)
    {
        return;
    }
    visit[x][y] = curPace;

    int children[8][2] = {
        {x - 2, y - 1},
        {x - 2, y + 1},
        {x + 2, y - 1},
        {x + 2, y + 1},
        {x + 1, y - 2},
        {x + 1, y + 2},
        {x - 1, y - 2},
        {x - 1, y + 2}};

    int nextPace = curPace + 1;

    for (int i = 0; i < 8; ++i)
    {
        int xi = children[i][0];
        int yi = children[i][1];
        if (xi >= borderX || xi < 0 || yi < 0 || yi >= borderY)
        {
            continue;
        }
        if (visit[xi][yi] > nextPace || visit[xi][yi] == -1)
        {
            dfs(xi, yi, nextPace, borderX, borderY, visit);
        }
    }
}

void bfs(int x, int y, int curPace, int borderX, int borderY,
         vector<vector<int>> &visit)
{
    queue<std::pair<std::pair<int, int>, int>> que;
    que.push(std::make_pair(std::make_pair(x, y), curPace));

    int pace = 0;

    while (!que.empty())
    {
        auto pair = que.front();
        que.pop();
        int xi = pair.first.first;
        int yi = pair.first.second;

        if (visit[xi][yi] != -1)
        {
            continue;
        }

        visit[xi][yi] = pair.second;

        int children[8][2] = {
            {xi - 2, yi - 1},
            {xi - 2, yi + 1},
            {xi + 2, yi - 1},
            {xi + 2, yi + 1},
            {xi + 1, yi - 2},
            {xi + 1, yi + 2},
            {xi - 1, yi - 2},
            {xi - 1, yi + 2}
        };

        for (int i = 0; i < 8; ++i)
        {
            int xt = children[i][0];
            int yt = children[i][1];
            if (xt >= borderX || xt < 0 || yt < 0 || yt >= borderY)
            {
                continue;
            }
            else
            {
                que.push(std::make_pair(std::make_pair(xt, yt),
                    pair.second + 1));
            }
        }
    }
}

int main()
{
    vector<vector<int>> visit;
    // 48 0 65 A 97 a
    int x, y;
    cin >> x >> y;
    int xi, yi;
    cin >> xi >> yi;
    for (int i = 0; i < x; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < y; ++j)
        {
            temp.push_back(-1);
        }
        visit.push_back(temp);
    }
    bfs(xi - 1, yi - 1, 0, x, y, visit);
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            printf("%-5d", visit[i][j]);
        }
        if (i != x - 1)
        {
            cout << endl;
        }
    }
    return 0;
}