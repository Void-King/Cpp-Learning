#include <bits/stdc++.h>
#define N 10005
#define M 20005
using namespace std;
int n,m,s,t,tot=0,head[N],ver[2*M],edge[2*M],Next[2*M],d[N];//d[i]表示从s到i路径上的最大路径的最小值 
bool v[N];
priority_queue< pair<int,int> >q;
void add(int x,int y,int z)
{
    ver[++tot]=y,edge[tot]=z,Next[tot]=head[x],head[x]=tot;
}
void dijkstra()
{
    d[s]=0;
    q.push(make_pair(-d[s],s));
    while(q.size())
    {
        int x=q.top().second;q.pop();
        if(v[x])continue;
        v[x]=1;
        int i;
        for(i=head[x];i;i=Next[i])
        {
            int y=ver[i],z=edge[i];
            if(d[y]>min(d[x],z))//小于等于的话就没必要更新了 
            {
                if(z>d[x])
                {
                    if(d[y]>z)//d[x] z d[y]
                    {
                        d[y]=z;
                        q.push(make_pair(-d[y],y));
                    }
                }
                else//z<=d[x]
                {
                    if(d[y]>d[x])//z d[x] d[y]
                    {
                        d[y]=d[x];
                        q.push(make_pair(-d[y],y));
                    }
                }
            }
        }
    }
}
int main()
{
    memset(d,0x3f3f3f3f,sizeof(d));
    memset(v,0,sizeof(v));
    int i;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dijkstra();
    cout<<d[t];
    return 0;
}