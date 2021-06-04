bitree_revo(treenode* root)
{
    if (root != nullptr)
    {
        treenode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        bitree_revo(root->left);
        bitree_revo(root->right);
    }
}

insertSort(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int temp = a[i];
        // 折半查找插入位置
        int low = 0;
        int high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] > temp) high = mid - 1;
            else low = mid + 1;
        }
        for (int j = i - 1; j > high; --j)
        {
            a[j + 1] = a[j];
        }
        a[high + 1] = temp;
    }
}

void finddegree(adj, int n)
{
    for (int i = 0; i < n; ++i)
    {
        outDegree[i] = 0;
        p = adj[i].firstarc;
        while (p != nullptr)
        {
            ++outDegree[i];
            p = p->next;
        }
    }
}