delarc(adj, u, v)
{
    p = adj[u - 1].firstarc
    q = null;
    while(p->adjvex != v)
    {
        q = p;
        p = p->nextarc;
    }

    if (q == null)
        adj[u - 1].firstarc = p->nextarc;
    else
        q->nextarc = p->nextarc;
    delete p;
    
}