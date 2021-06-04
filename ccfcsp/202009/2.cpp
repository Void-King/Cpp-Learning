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
	return 0;
}
