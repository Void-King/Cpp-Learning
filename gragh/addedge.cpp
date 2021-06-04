addEdge(adj, u, v)
{
    p = adj[u - 1].firstarc;
    while (p->nextarc)
    {
        p = p->nextarc;
    }
    q = new arcnode;
    q->adjvex = v;
    q->nextarc = null;
    p->nextarc = q;

    p = adj[v - 1].firstarc
    while(p->nextarc)
    {
        p = p->nextarc;
    }
    q = new arcnode;
    q->adjvex = u;
    q->nextarc = null;
    p->nextarc = q;
}