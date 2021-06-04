insertArc(adj, u, v)
{
    r = new arcnode;
    r->adjvex = v;
    r->next = adj[u - 1].firstArc;
    adj[u - 1].firstArc = r;
}