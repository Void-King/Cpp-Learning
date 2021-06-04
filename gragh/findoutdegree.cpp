findOutDegree(ALGragh g, int outDegree[vexnum])
{
    for (i = 0; i < vexnum; ++i)
    {
        outDegree[i] = 0;
    }
    for (i = 0; i < vexnum; ++i)
    {
        for (auto p = g.vertices[i].firstArc; p != null; p = p->nextarc)
        {
            ++outDegree[i];
        }
    }
}