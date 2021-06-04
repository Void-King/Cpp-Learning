#include <bits/stdc++.h>

using namespace std;

void InsertSort(int a[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int temp = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > temp; --j)
        {
            a[j + 1] = a[j];
        }
        a[j+1] = temp;
    }
}

int main()
{
    int n = 6;
    int a[] = {5,2,4,6,1,3};
    InsertSort(a, n);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}