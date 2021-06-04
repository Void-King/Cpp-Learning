#include <bits/stdc++.h>

using namespace std;

void ShellSort(int a[], int n)
{
    for (int dk = n / 2; dk > 0; dk /= 2)
    {
        if (dk % 2 == 0) --dk;
        for (int i = dk; i < n; ++i)
        {
            int temp = a[i];
            int j = i - dk;
            for (; j >= 0 && a[j] > temp; j -= dk)
            {
                a[j + dk] = a[j];
            }
            a[j + dk] = temp;
        }
    }
}

int main()
{
    int n = 6;
    int a[] = {5,2,4,6,1,3};
    ShellSort(a, n);
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    return 0;
}