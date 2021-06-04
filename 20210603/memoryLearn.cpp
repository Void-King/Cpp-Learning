#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <memory>
#include <functional>

#include <map>
#include <list>
#include <set>
#include <queue>

using namespace std;

typedef void (*funcPtr)();

static void FuncPrint()
{
    cout << "static print function called\n";
};

static void FuncPrintMultiply10()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << "static print function called " << i << " \n";
    }
};

class constQuestions
{
public:
    void* GetDoubleOrInt(const double _input) const
    {
        if ((int)_input - _input < DBL_EPSILON &&
            _input - (int)_input < DBL_EPSILON)
        {
            int* result  = new int(_input);
            return result;
        }
        else{
            double* result = new double(_input);
            return result;
        }
    };

    const double* GetDouble(double _input)
    {
        return &m_dData;
    };


protected:
    double m_dData = 0;
};

int main()
{
    double a = 1.1;
    double b = 1.0;

    constQuestions tools;

    function<void()> funcPrint1 =
        [](){cout << "lambda print function called\n";};

    funcPrint1();

    // funcPtr func = &FuncPrint;
    // (*func)();
    // FuncPrint();

    std::map<string, funcPtr> mapFunc;

    mapFunc.insert(std::make_pair("print1", &FuncPrint));
    mapFunc.insert(std::make_pair("print10", &FuncPrintMultiply10));

    {
        // read file

        // read funcname

        // get chinese name

        // call actaul function

        // (*mapFunc["print10"])();
    }


    // (*mapFunc["打印1次"])();
    // (*mapFunc["打印10次"])();

    double* ra = (double*)tools.GetDoubleOrInt(a);
    std::shared_ptr<double> spRa(ra);

    int* rb = (int*)tools.GetDoubleOrInt(b);
    std::shared_ptr<int> spRb(rb);

    const double* ca = tools.GetDouble(a);

    std::cout << *ra << " " << *rb << " " << *ca << endl;

    return 0;
}