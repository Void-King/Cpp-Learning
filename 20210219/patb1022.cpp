#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a, b, d;
    while (scanf("%d%d%d", &a, &b, &d) != EOF)
    {
        int re[50] = {0};
        int pot = 49;

        int c = a + b;
        while (c > 0)
        {
            int remain = c % d;
            c = c / d;
            re[pot] = remain;
            --pot;
        }
        bool start = false;
        for (int i = 0; i < 50; ++i)
        {
            if (re[i] == 0 && i != 49)
            {
                if (!start)
                {
                    continue;
                }
                cout << re[i];
            }
            else
            {
                start = true;
                cout << re[i];
            }
        }
        cout << endl;
    }

    return 0;
}