#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    char out[10] = {'\0'};
    for (int i = 0; i < s.length(); ++i)
    {
        char ch = s[i];
        out[9 - i] = ch;
    }
    for (auto ch : out)
    {
        if (ch != '\0')
        {
            cout << ch;
        }
    }
    // 48 0 65 A 97 a
    return 0;
}