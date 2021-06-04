#include <bits/stdc++.h>

using namespace std;

void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] < a[j - 1])
            {
                int temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int n = 6;
    int a[] = {5,2,4,6,1,3};
    BubbleSort(a, n);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}