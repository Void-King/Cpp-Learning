#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <functional>

int main()
{
    // std::map<std::string, std::function<double(double &a, double &b)> > m_mapLambdas;

    // m_mapLambdas.insert(std::make_pair("plus", [](double &a, double &b) { return a + b; }));

    double a = 5.0;
    std::cout << GetLambdas()["plus"](a, a) << std::endl;

    return 0;
}
