#include <bits/stdc++.h>

using namespace std;

std::pair<bool, int> halfSearch(int given, std::vector<std::pair<int, int>>& originSet)
{
    bool exist = false;
    int result = -1;

    int maxsize = originSet.size();
    int minsize = 0;
    int mid = 0;
    while (minsize <= maxsize)
    {
        mid = (minsize + maxsize) / 2;
        cout << minsize << "   " << mid << "   " << maxsize << "\n";
        if (originSet[mid].first <= given && originSet[mid].second >= given)
        {
            exist = true;
            result = mid;
            cout << "found! originSet[" << mid << "] = [" << originSet[mid].first
            << " - " << originSet[mid].second << "] within " << given << "\n";
            break;
        }
        else if (originSet[mid].first > given)
        {
            maxsize = mid - 1;
        }
        else if (originSet[mid].second < given)
        {
            minsize = mid + 1;
        }
        else
        {
        }
    }
    return std::make_pair(exist, result);
}

int main()
{
    std::vector<std::pair<int, int>> originSet;
    for (int i = 0; i < 10000; i += 10)
    {
        originSet.push_back(std::make_pair(i , i + 5));
    }

    auto result = halfSearch(981, originSet);

    if (result.first)
    {
        cout << "success: " << result.second << " \n";
    }
    else
    {
        cout << "failed! " << result.second << " \n";
    }
    
    return 0;
}