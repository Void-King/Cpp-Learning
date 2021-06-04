#include <bits/stdc++.h>

using namespace std;

int Partition(int a[], int low, int high)
{
    int povit = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= povit)
        {
            --high;
        }
        a[low] = a[high];
        while (low < high && a[low] <= povit)
        {
            ++low;
        }
        a[high] = a[low];
    }
    a[low] = povit;
    return low;
}

void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int povit = Partition(a, low, high);
        QuickSort(a, low, povit - 1);
        QuickSort(a, povit + 1, high);
    }
}

int main()
{
    int n = 6;
    int a[] = {5,2,4,6,1,3};
    QuickSort(a, 0, 5);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}