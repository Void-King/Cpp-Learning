#include <bits/stdc++.h>
#include <regex>

using namespace std;

int main ()
{
    std::list<int> numIDList;
    std::regex classID("\" class_id=\"\\d+\"");
    std::regex numID("(\\d+)");
    std::smatch m1;
    std::smatch m2;
    string end = "begin";
    while (end.compare("end") != 0)
    {
        getline(cin, end);
        auto ret1 = std::regex_search(end, m1, classID);
        //cout << m1[0].str() << endl;
        string temp = m1[0].str();
        auto ret2 = std::regex_search(temp, m2, numID);
        //cout << m2[0] << endl;
        int tempID = atoi(m2[0].str().c_str());
        if (tempID != 0)
        {
            numIDList.push_back(tempID);
        }
    }
    numIDList.sort();
    for (auto itr = numIDList.begin(); itr != numIDList.end(); ++itr)
    {
        cout << (*itr) << endl;
    }
    return 0;
}