#include <bits/stdc++.h>

using namespace std;
int* temp = NULL;

void cal(int& a)
{
    int* temp = NULL;
    temp = &a;
    *temp = 10;
    //delete (temp);
    temp = NULL;
}
void setNum(int& a)
{
    cal(a);
}

int main()
{
    int x = 1;
    setNum(x);
    cout << x;
    return 0;
}