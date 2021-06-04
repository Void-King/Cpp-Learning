#include "bits/stdc++.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool sortVecByFirst(std::pair<int, int>& a, std::pair<int, int> &b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first == b.first)
    {
        if (a.second < b.second) return true;
        else return false;
    }
    else
    {
        return false;
    }
}

int main()
{
    int dataAmount = 0;
    scanf("%d", &dataAmount);

    std::vector<std::pair<int, int> > inputData;

    for (int i = 0; i < dataAmount; ++i)
    {
        int safety = 0;
        int pass = 0;
        scanf("%d %d", &safety, &pass);
        inputData.push_back(std::make_pair(safety, pass));
    }

    std::sort(inputData.begin(), inputData.end(), sortVecByFirst);

    int frontSum[dataAmount] = {0};
    frontSum[0] = inputData[0].second;
    
    // 得到数据的前缀和，即每个y的前部数据的挂科情况
    for (int i = 1; i < dataAmount; ++i)
    {
        frontSum[i] = frontSum[i - 1] + inputData[i].second;
    }

    std::map<int, int> resultData;
    for (int i = 0; i < dataAmount; ++i)
    {
        int beforeNotPass = 0;
        if (i != 0)
        {
            beforeNotPass = i - frontSum[i - 1];
        }
        int afterPass = frontSum[dataAmount - 1];
        if (i != 0)
        {
            afterPass = afterPass - frontSum[i - 1];
        }
        
        int totalSum = afterPass + beforeNotPass;
        if (resultData.find(inputData[i].first) == resultData.end())
        {
            resultData.insert(std::make_pair(inputData[i].first, totalSum));
        }
    }
    int max = 0;
    int maxResult = 0;
    for (std::map<int, int>::iterator itr = resultData.begin(); itr != resultData.end(); ++itr)
    {
        if (maxResult < itr->second)
        {
            max = itr->first;
            maxResult = itr->second;
        }
        else if (maxResult == itr->second)
        {
            if (max < itr->first)
            {
                max = itr->first;
            }
        }
        else
        {
            /* code */
        }
    }
    printf ("%d", max);
    return 0;
}