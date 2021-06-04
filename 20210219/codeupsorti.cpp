#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool sortcus(pair<string, int> a, pair<string, int> b)
{
    if (a.second > b.second) return true;
    else if (a.second == b.second)
    {
        int x = strcmp(a.first.c_str(), b.first.c_str());
        if (x < 0) return true;
        else return false;
    }
    else return false;
}

int main()
{
    int stus = 0;
    // 48 0 65 A 97 a
    while (scanf ("%d", &stus) != EOF)
    {
        if (stus == 0) break;
        vector<pair<string, int> > re;
        int renum = 0;
        int quess = 0;
        int line = 0;
        scanf ("%d%d", &quess, &line);
        vector<int> quesset;
        for (int i = 0; i < quess; ++i)
        {
            int point = 0;
            scanf ("%d", &point);
            quesset.push_back(point);
        }
        for (int i = 0; i < stus; ++i)
        {
            string code = "";
            code.resize(21);
            scanf ("%s", &code[0]);
            int allpat = 0;
            scanf ("%d", &allpat);
            int allpoint = 0;
            for (int j = 0; j < allpat; ++j)
            {
                int sub = 0;
                scanf ("%d", &sub);
                allpoint += quesset[sub - 1];
            }
            if (allpoint >= line)
            {
                re.push_back(make_pair(code, allpoint));
                ++renum;
            }
        }
        sort(re.begin(), re.end(), sortcus);

        printf ("%d\n", renum);
        for (int i = 0; i < renum; ++i)
        {
            for (int j = 0; j < 21; ++j)
            {
                if (re[i].first[j] != '\0')
                {
                    cout << re[i].first[j];
                }
            }
            cout << " " << re[i].second << endl;
        }
    }
    return 0;
}

