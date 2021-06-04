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

class Entity
{
public:
    Entity();
    ~Entity();
};

Entity::Entity()
{
    cout << "Create Used!";
}

Entity::~Entity()
{
    cout << "Destory Used!";
}

int main()
{
    shared_ptr<Entity> sptr = nullptr;

    sptr = make_shared<Entity>();
    sptr.reset(new Entity());
    // 48 0 65 A 97 a
    return 0;
}