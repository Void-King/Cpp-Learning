#include <cstdio>
#include <map>
#include <memory>

std::map<int, double> mapA;
std::map<int, double> *mapB;

void changeA(
    int& _a,
    std::map<int, double>* &mapB)
{
    ++_a;
    mapB = &mapA;
    mapB->insert(std::make_pair<int, double>(5, 1.0));
    printf("3%d  %d\n", _a, mapA.size());
}

std::map<int, double>& getMap()
{
    return mapA;
}

void changeV(
    std::map<int, double>& mapC)
{
    mapC.insert(std::make_pair<int, double>(8, 4.0));
    printf("5%d\n",mapC.size());
}

int main(){
    int a = 10;
    auto test1 = std::make_shared<int>(15);
    mapA.insert(std::make_pair<int, double>(6, 2.0));
    printf("1%d  %d\n", a, mapA.size());
    changeA(a, mapB);
    printf("2%d  %d\n", a, mapA.size());
    changeV(mapA);
    printf("2%d  %d\n", a, mapA.size());
    getMap().insert(std::make_pair<int, double>(7, 3.0));
    printf("4%d  %d\n", a, mapA.size());
    printf("2%d  %d\n", a, mapB->size());

    int* c = test1.get();
    *c = 16;
    printf("%d", *test1.get());

    return 0;
}

