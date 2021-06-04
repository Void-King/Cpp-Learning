#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool sortCus(std::pair<double, int>& a, std::pair<double, int>& b)
{
	if (a.first < b.first) return true;
	else if (a.first == b.first)
	{
		if (a.second < b.second) return true;
		else return false;
	}
	else return false;
}

int main()
{
	int i_n = 0;
	int i_x = 0;
	int i_y = 0;
	
	scanf ("%d %d %d", &i_n, &i_x, &i_y);
	
	std::vector<std::pair<double, int> > distanceSet;
	
	for (int i = 0; i < i_n; ++i)
	{
		int i_xi = 0;
		int i_yi = 0;
		scanf ("%d %d", &i_xi, &i_yi);
		
		double distance = std::sqrt(std::pow((i_xi - i_x), 2) + std::pow((i_yi - i_y), 2));
		distanceSet.push_back(std::make_pair(distance, i + 1));
	}
	
	std::sort(distanceSet.begin(), distanceSet.end(), sortCus);
	
	for (int i = 0; i < 3; ++i)
	{
		printf ("%d\n", distanceSet[i].second);
	}
	
	return 0;
}
