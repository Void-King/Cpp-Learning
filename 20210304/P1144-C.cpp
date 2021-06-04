#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+10;
const int mod=100003;
vector<int>mapp[MAXN];
int dis[MAXN],ans[MAXN];
bool vis[MAXN];
queue<int >qu;
int n,m;
void bfs(int root)
{
    memset(vis,false, sizeof(vis));
    for (int i = 1; i <=n ; ++i) {
        dis[i]=0x3f3f3f3f;
    }
    qu.push(root);vis[root]=true;
    dis[root]=0;ans[root]=1;
    while (!qu.empty())
    {
        int x=qu.front();qu.pop();
        for (int i = 0; i <mapp[x].size() ; ++i) {
            int v=mapp[x][i];
            if(dis[v]>dis[x]+1) {
                dis[v]=dis[x]+1;
                ans[v]=ans[x];
                if(!vis[v]) vis[v]=true,qu.push(v);
            }else if(dis[v] == dis[x]+1) {
                    ans[v]=(ans[v]+ans[x])%mod;
            }
            vis[x]= false;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int x,y;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&x,&y);
        if(x==y) continue;
        mapp[x].push_back(y);
        mapp[y].push_back(x);
    }
    bfs(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d\n",ans[i]);
    }
    return 0;
}