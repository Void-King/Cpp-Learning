#include <bits/stdc++.h>

using namespace std;

struct treeNode
{
    treeNode *leftChild = nullptr;
    treeNode *rightChild = nullptr;
    char data = ' ';
};

void NormalLeftCenterRight(treeNode *node)
{
    if (node != nullptr)
    {
        NormalLeftCenterRight(node->leftChild);
        cout << node->data << ' ';
        NormalLeftCenterRight(node->rightChild);
    }
}

void NotCycleLeftCenterRight(treeNode *node)
{
    if (node == nullptr)
        return;
    std::stack<treeNode *> trackTemp;
    treeNode *cur = node;
    while (!trackTemp.empty() || cur != nullptr)
    {
        if (cur != nullptr)
        {
            trackTemp.push(cur);
            cur = cur->leftChild;
        }
        else
        {
            cur = trackTemp.top();
            cout << cur->data << ' ';
            trackTemp.pop();
            cur = cur->rightChild;
        }
    }
}

void NormalCenterLeftRight(treeNode *node)
{
    if (node != nullptr)
    {
        cout << node->data << ' ';
        NormalCenterLeftRight(node->leftChild);
        NormalCenterLeftRight(node->rightChild);
    }
}

void NotCycleCenterLeftRight(treeNode *node)
{
    if (node == nullptr)
        return;
    std::stack<treeNode *> stackTemp;
    stackTemp.push(node);
    while (!stackTemp.empty())
    {
        treeNode *top = stackTemp.top();
        cout << top->data << ' ';
        stackTemp.pop();
        if (top->rightChild != nullptr)
        {
            stackTemp.push(top->rightChild);
        }
        if (top->leftChild != nullptr)
        {
            stackTemp.push(top->leftChild);
        }
    }
    // if (node == nullptr) return;
    // std::stack<treeNode*> trackTemp;
    // trackTemp.push(node);
    // while (!trackTemp.empty())
    // {
    //     treeNode* temp = trackTemp.top();
    //     cout << temp->data << ' ';
    //     trackTemp.pop();
    //     if (temp->rightChild != nullptr)
    //     {
    //         trackTemp.push(temp->rightChild);
    //     }
    //     if (temp->leftChild != nullptr)
    //     {
    //         trackTemp.push(temp->leftChild);
    //     }
    //     //if (trackTemp.empty()) return;
    // }
    node* temp = node->leftChild;
    if (node->rightChild != nullptr)
    {
        node->leftChild = node->rightChild;
    }
    node->rightChild = temp;
}

void NormalLeftRightCenter(treeNode *node)
{
    if (node != NULL)
    {
        NormalLeftRightCenter(node->leftChild);
        NormalLeftRightCenter(node->rightChild);
        cout << node->data << ' ';
    }
}

void NotCycleLeftRightCenter(treeNode *node)
{
    if (node == nullptr)
        return;
    std::stack<treeNode *> trackTemp;
    trackTemp.push(node);

    treeNode *temp = trackTemp.top();
    treeNode *last = nullptr;

    while (temp->leftChild != nullptr)
    {
        temp = temp->leftChild;
        trackTemp.push(temp);
    }

    while (!trackTemp.empty())
    {
        temp = trackTemp.top();

        if (temp->rightChild == nullptr || last == temp->rightChild)
        {
            cout << temp->data << ' ';
            last = temp;
            trackTemp.pop();
        }
        else
        {
            temp = temp->rightChild;
            trackTemp.push(temp);
            while (temp->leftChild != nullptr)
            {
                temp = temp->leftChild;
                trackTemp.push(temp);
            }
        }
    }
}

void NotCycleLeftRightCenterSec(treeNode *node)
{
    if (node == nullptr)
        return;
    std::stack<treeNode *> stackTemp;

    treeNode *temp = node;
    treeNode *last = nullptr;

    stackTemp.push(temp);
    while (temp->leftChild != nullptr)
    {
        temp = temp->leftChild;
        stackTemp.push(temp);
    }
    while (!stackTemp.empty())
    {
        temp = stackTemp.top();
        if (temp->rightChild == nullptr || temp->rightChild == last)
        {
            stackTemp.pop();
            cout << temp->data << ' ';
            last = temp;
        }
        else
        {
            temp = temp->rightChild;
            stackTemp.push(temp);
            while (temp->leftChild != nullptr)
            {
                temp = temp->leftChild;
                stackTemp.push(temp);
            }
        }
    }
}

int main()
{
    treeNode *a = new treeNode;
    a->data = 'A';

    treeNode *b = new treeNode;
    b->data = 'B';
    treeNode *c = new treeNode;
    c->data = 'C';
    treeNode *d = new treeNode;
    d->data = 'D';
    treeNode *e = new treeNode;
    e->data = 'E';
    treeNode *f = new treeNode;
    f->data = 'F';
    treeNode *g = new treeNode;
    g->data = 'G';
    treeNode *h = new treeNode;
    h->data = 'H';

    a->leftChild = b;
    a->rightChild = c;
    b->leftChild = d;
    b->rightChild = e;
    //c->leftChild = f;
    c->rightChild = g;
    d->leftChild = h;

    // a->leftChild = b;
    // a->rightChild = c;
    // b->leftChild = d;
    // b->rightChild = e;
    // c->leftChild = f;
    // c->rightChild = g;
    // d->leftChild = h;

    NormalLeftCenterRight(a);
    cout << endl;
    NotCycleLeftCenterRight(a);
    cout << endl;
    NormalCenterLeftRight(a);
    cout << endl;
    NotCycleCenterLeftRight(a);
    cout << endl;
    NormalLeftRightCenter(a);
    cout << endl;
    NotCycleLeftRightCenter(a);
    cout << endl;
    NotCycleLeftRightCenterSec(a);
    cout << endl;
    return 0;
}