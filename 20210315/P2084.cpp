#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>
#include <set>
#include <sstream>

using namespace std;

int main()
{
    // 48 0 65 A 97 a
    int x = 0;
    cin >> x;
    string input = "";
    cin >> input;
    int size = input.size();
    int z = size - 1;
    stringstream result;
    bool first = true;
    for (int i = 0; i < size; ++i)
    {
        char ch = input.at(i);
        int num = int(ch) - 48;
        if (num > 0)
        {
            if (!first)
            {
                result << "+";
            }
            else
            {
                first = false;
            }
            result << num << "*" << x << "^" << z;
        }
        --z;
    }
    cout << result.str();
    return 0;
}