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
    // 48 0 65 A 97 a
    int a = 1;
    int b = 15;

    wchar_t charSet[5];
    wstring time = L"8:00";

    swscanf(time.c_str(), L"%d:%d", &a, &b);
    
    wcout << time << L"\n";
    swprintf(charSet, L"%02d:%02d", a, b);
    swprintf(charSet, L"%02d:%02d", 1, 1);

    time = charSet;
    wcout << time << L"\n";
    wcout << time.length();


    return 0;
}