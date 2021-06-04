#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main()
{
    std::wregex timeRegex(L":");
	for (int i = 0; i < 1; ++i)
	{
		std::wstring beginTime = L"1:2";
		std::wstring endTime = L"12:00";
		std::wsmatch results1;
		auto ret1 = std::regex_search(beginTime, results1, timeRegex);
        if (ret1)
        {
	        std::wcout << results1.prefix() << L" " << results1.suffix()  << std::endl;
            std::cout << "----------------" << std::endl;
        }
        std::wsmatch results2;
        auto ret2 = std::regex_search(endTime, results2, timeRegex);
        if (ret2)
        {
            std::wcout << results2.prefix().str() << L" " << results2.suffix().str()  << std::endl;
            std::cout << "----------------" << std::endl;
        }
	}
    return 0;
}