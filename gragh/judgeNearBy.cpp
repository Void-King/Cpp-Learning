judge(ALGragh* g, int i, int j)
{
    arcNode *p = g->vertices[i].firstarc;
    int found = 0;
    while (p != null)
    {
        if (p->adjvex == j)
        {
            found = 1;
            break;
        }
        p = p->nextarc;
    }
    if (found)
    {
        cout << "xiangling";
    }
    else
    {
        cout << "no"
    }
    return found;
}