#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char str[255] = {'\0'};
    //gets(str);
    int len = 0;
    // for (int i = 0; i < 255; ++i)
    // {
    //     if (str[i] == '\0')
    //     {
    //         break;
    //     }
    //     ++len;
    // }
    scanf ("%[^\n]", str);
    len = strlen(str);
    bool comp = true;
    for (int i = 0; i < len / 2; ++i)
    {
        if (str[i] != str[len - i - 1])
        {
            comp = false;
            break;
        }
    }
    if (comp)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}