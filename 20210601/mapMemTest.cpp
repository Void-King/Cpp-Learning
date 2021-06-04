#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
    set<int>* ptr = nullptr;

    map<int, set<int> > testMap;

    set<int> testSet;
    testSet.insert(1);
    testSet.insert(2);

    // testMap.insert(make_pair(1, testSet));

    auto exist = testMap.find(1);
    if (exist != testMap.end())
    {
        ptr = &exist->second;
    }
    else
    {
        set<int> temp;
        testMap.insert(make_pair(1, temp));
        ptr = &testMap.find(1)->second;
    }

    ptr->insert(3);

    for (auto i : testMap.find(1)->second)
    {
        cout << i;
    }

    return 0;
}