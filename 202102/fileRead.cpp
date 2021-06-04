#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::fstream fZookerper("E:\\Code\\cpp\\test.txt");
	std::string strLineConfig;
	while (std::getline(fZookerper, strLineConfig))
	{
		std::string strCounterPart = strLineConfig;

        cout << strCounterPart << endl;
		int x = 0;
	}
	fZookerper.close();

    return 0;
}