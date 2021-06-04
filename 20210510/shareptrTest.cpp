#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>
#include <set>
#include <memory>

using namespace std;

class CJsonObject
{
public:
    CJsonObject()
    {
        cout << "construct!\n";
    };
    ~CJsonObject()
    {
        cout << "destruct!\n";
    };
};

std::shared_ptr<CJsonObject> BuildErrMsg(long _err, std::wstring _msg)
{
    auto errObj = std::make_shared<CJsonObject>();
    cout << _err << " ";
    wcout << _msg << endl;
    return errObj;
};

int main()
{
    auto sp = BuildErrMsg(0x83060101, L"test");
    return 0;
}
