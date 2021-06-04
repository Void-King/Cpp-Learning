#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>
#include <set>

using namespace std;

int main()
{
    int x = 0;
    vector<int> vec;
    cin >> x;
    while (x != 0)
    {
        vec.push_back(x);
        cin >> x;
    }
    int size = vec.size();
    for (int i = size - 1; i >= 0; --i)
    {
        cout << vec[i] << " ";
    }
    return 0;
}