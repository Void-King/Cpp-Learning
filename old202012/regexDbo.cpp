#include <bits/stdc++.h>
#include <regex>

using namespace std;

void sqlRegex()
{
    std::list<string> strList;
    std::regex classID("CREATE TABLE \\[(dbo|DBO)\\]\\.\\[.+\\]");
    std::regex numID("(T|TI)_[A-Za-z0-9]+");
    std::smatch m1;
    std::smatch m2;
    string end = "begin";
    while (end.compare("end") != 0)
    {
        getline(cin, end);
        auto ret1 = std::regex_search(end, m1, classID);
        //cout << m1[0].str() << endl;
        string temp = m1[0].str();
        if (temp.compare("") != 0)
        {
            auto ret2 = std::regex_search(temp, m2, numID);
            cout << m2[0] << endl;
            string tempStr = m2[0].str();
            if (tempStr.compare("") != 0)
            {
                transform(tempStr.begin(), tempStr.end(), tempStr.begin(), ::toupper);
                strList.push_back(tempStr);
            }
        }
    }
    strList.sort();
    for (auto itr = strList.begin(); itr != strList.end(); ++itr)
    {
        cout << (*itr) << endl;
    }
}

void oracleRegex()
{
    std::list<string> strList;
    std::regex classID("CREATE TABLE .+ \\(");
    std::regex numID("(T|TI)_[A-Za-z0-9]+");
    std::smatch m1;
    std::smatch m2;
    string end = "begin";
    while (end.compare("end") != 0)
    {
        getline(cin, end);
        auto ret1 = std::regex_search(end, m1, classID);
        //cout << m1[0].str() << endl;
        string temp = m1[0].str();
        if (temp.compare("") != 0)
        {
            auto ret2 = std::regex_search(temp, m2, numID);
            cout << m2[0] << endl;
            string tempStr = m2[0].str();
            if (tempStr.compare("") != 0)
            {
                transform(tempStr.begin(), tempStr.end(), tempStr.begin(), ::toupper);
                strList.push_back(tempStr);
            }
        }
    }
    strList.sort();
    for (auto itr = strList.begin(); itr != strList.end(); ++itr)
    {
        cout << (*itr) << endl;
    }
}

int main ()
{
    //sqlRegex();
    oracleRegex();
    return 0;
}