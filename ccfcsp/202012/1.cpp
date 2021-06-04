#include "bits/stdc++.h"

using namespace std;

int main()
{
    int typeAmount = 0;
    scanf("%d", &typeAmount);

    int sumResult = 0;

    for (int i = 0; i < typeAmount; ++i)
    {
        int importance = 0;
        int score = 0;
        scanf("%d %d", &importance, &score);

        sumResult += importance * score;
    }

    if (sumResult <= 0)
    {
        sumResult = 0;
    }
    printf("%d", sumResult);

    return 0;
}