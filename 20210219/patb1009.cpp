#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    char str[81] = {'0'};
    scanf("%[^\n]", str);
    int len = strlen(str);
    
    vector<char* > re;
    int j = 0;
    int vlen = 0;
    char* temp = new char[81];
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i <= len; ++i)
    {
        if (str[i] == ' ' || i == len)
        {
            ++vlen;
            re.push_back(temp);
            temp = new char[81];
            memset(temp, 0, sizeof(temp));
            j = 0;
        }
        else
        {
            temp[j] = str[i];
            ++j;
        }
    }

    for (int i = vlen - 1; i >= 0; --i)
    {
        printf ("%s", re[i]);
        if (i != 0) cout << " ";
    }
    cout << "\n";
    return 0;
}