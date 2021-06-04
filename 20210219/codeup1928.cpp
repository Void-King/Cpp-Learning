#include <cstdio>
#include <iostream>

using namespace std;

int yearset[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int yearcheck(int year)
{
    // / 400
    if (year % 400 == 0) return 1;
    // / 4 && ! / 100
    if (year % 4 == 0 && year % 100 != 0) return 1;
    return 0;
}

int main()
{
    int in1 = 0;
    int in2 = 0;
    while (scanf("%d%d", &in1, &in2) != EOF)
    {
        if (in1 > in2)
        {
            int t = in2;
            in2 = in1;
            in1 = t;
        }
        int re = 0;

        int y1 = in1 / 10000;
        int m1 = (in1 % 10000) / 100;
        int d1 = in1 % 100;

        int y2 = in2 / 10000;
        int m2 = (in2 % 10000) / 100;
        int d2 = in2 % 100;

        while (y1 < y2 || m1 < m2 || d1 < d2)
        {
            if (d1 == yearset[yearcheck(y1)][m1 - 1])
            {
                if (m1 == 12)
                {
                    ++y1;
                    m1 = 1;
                    d1 = 1;
                }
                else
                {
                    ++m1;
                    d1 = 1;
                }
            }
            else
            {
                ++d1;
            }
            ++re;
        }
        ++re;
        printf ("%d\n", re);
    }

    return 0;
}