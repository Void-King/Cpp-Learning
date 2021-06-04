#include <bits/stdc++.h>

using namespace std;

void InsertSortDivide(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        // 数据缓存
        int temp = a[i];

        // 二分查找
        int low = 0;
        int high = i - 1;
        // 在缓存数据前，找到数据应该在的位置
        while (low <= high)
        {
            int mid = (high + low) / 2;
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

int main()
{
    int n = 6;
    int a[] = {5,2,4,6,1,3};
    InsertSortDivide(a, n);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}