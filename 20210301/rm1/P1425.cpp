#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    // 48 0 65 A 97 a
    int bh, bm, eh, em;
    cin >> bh >> bm >> eh >> em;
    if (bm > em)
    {
        em += 60;
        ++bh;
    }
    cout << eh - bh << " " << em - bm;
    return 0;
}