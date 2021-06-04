findInDegree(ALGraph g, int indegree[vexnum])
{
    for (i = 0; i < vexnum; ++i)
    {
        indegree[i] = 0;
    }
    for (i = 0; i < vexnum; ++i)
    {
        for (auto p = g.vertices[i].firstarc; p != null; p = p->nextarc)
        {
            k = p->adjvex;
            ++indegree[k];
        }
    }
}