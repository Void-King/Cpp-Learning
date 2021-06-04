#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    char str[10] = {'\0'};
    scanf("%[^\n]", str);
    char strSec[10] = {'\0'};
    copy(begin(str), end(str), begin(strSec));
    memset(strSec, 48, 2*sizeof(char));
    int x = atoi(strSec);
    cout << x;
    return 0;
}