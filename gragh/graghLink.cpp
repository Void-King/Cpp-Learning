DFS:

bool judge()
{
    for (int i = 0; i < n; ++i)
    {
        if (!visit[i]) return false;
        else return true;
    }
}

void DFS(MGragh g, int i)
{
    int j = 0;
    visit[i] = 1;
    for (j = 0; j < g.arc[i].size(); ++j)
    {
        if (g.arc[i][j] == 1 && !visited[j])
        {
            DFS(g, j);
        }
    }
}

void BFS(gragh g, int u)
{
    queue<int> q;
    visit[u] = 1;
    q.push(u);
    while(!q.empty())
    {
        int i = q.front();
        q.pop();
        for (int j = 0; j < g.arc[i].size(); ++j)
        {
            if (g.arc[i][j] == 1 && !visit[j])
            {
                visit[j] = 1;
                q.push(j);
            }
        }
    }
}