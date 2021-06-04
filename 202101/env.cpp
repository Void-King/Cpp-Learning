#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <sstream>
#include <fstream>

using namespace std;

std::pair<bool, std::wstring>
FileExist(std::wstring path, std::wstring fileName)
{
    std::wstring eachPath = path;
    int strSize = path.size();
    if (strSize > 0 && path.at(strSize - 1) != L'\\')
    {
        eachPath.append(L"\\");
    }
    eachPath.append(fileName);
    if (FILE *file = _wfopen(eachPath.c_str(), L"r"))
    {
        fclose(file);
        return std::make_pair(true, eachPath);
    }
    else
    {
        return std::make_pair(false, L"");
    }
}

std::pair<bool, std::wstring>
GetFileFromEnvPath(std::wstring fileName)
{
    // wregex wre(L";");
    // wcregex_iterator itr1(path, path + wcslen(path), wre);
    // wcregex_iterator itr2;
    // std::wstring least = L"";
    // for (wcregex_iterator itr = itr1; itr != itr2; ++itr)
    // {
    //     wcout << itr->prefix() << endl;
    //     least = itr->suffix();
    // }
    // wcout << least << endl;
    wchar_t* path = _wgetenv(L"path");
    int size = wcslen(path);
    std::wstringstream eachPathStream;
    for (int i = 0; i < size; ++i)
    {
        if (path[i] == L';')
        {
            auto re = FileExist(eachPathStream.str(),
                fileName);
            if (re.first)
            {
                return re;
            }
            eachPathStream.str(L"");
        }
        else
        {
            eachPathStream << path[i];
            if (i == size - 1)
            {
                auto re = FileExist(eachPathStream.str(),
                    fileName);
                if (re.first)
                {
                    return re;
                }
            }
        }
    }
    eachPathStream.str(L"");
    return std::make_pair(false, L"");
}

int main()
{
    auto re = GetFileFromEnvPath(L"EAPSecondaryDevelopmentAPI.dll");
    wcout << re.second;
    return 0;
}