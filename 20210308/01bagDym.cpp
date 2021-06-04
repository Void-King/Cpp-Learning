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
    vector<vector<int>> matrix;
    vector<int> vi;
    vector<int> wi;
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < y + 1; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < x + 1; ++j)
        {
            temp.push_back(0);
        }
        matrix.push_back(temp);
    }

    for (int i = 0; i < y; ++i)
    {
        int m = 0;
        cin >> m;
        vi.push_back(m);
        wi.push_back(m);
    }

    for (int i = 1; i <= y; ++i)
    {
        for (int j = 1; j <= x; ++j)
        {
            if (wi[i - 1] > j)
            {
                matrix[i][j] = matrix[i - 1][j];
            }
            else
            {
                if (matrix[i - 1][j] > matrix[i - 1][j - wi[i - 1]] + vi[i - 1])
                {
                    matrix[i][j] = matrix[i - 1][j];
                }
                else
                {
                    matrix[i][j] = matrix[i - 1][j - wi[i - 1]] + vi[i - 1];
                }
            }
        }
    }
    // 48 0 65 A 97 a
    cout << matrix[y][x] << endl;;

    int v = x;
    for (int i = y; i > 0; --i)
    {
        if (matrix[i][v] == matrix[i - 1][v])
        {
            continue;
        }
        else
        {
            cout << i << " ";
            v = v - wi[i - 1];
        }
    }
    return 0;
}