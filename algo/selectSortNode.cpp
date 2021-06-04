#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data = 0;
    node* next = nullptr;
};

void SelectSort(node* head)
{
    node* visit = head->next;
    node* visitBefore = head;
    while (visit != nullptr)
    {
        node* min = visit;
        node* visitSec = visit->next;
        while (visitSec != nullptr)
        {
            if (visitSec->data < min->data)
            {
                min = visitSec;
            }
            visitSec = visitSec->next;
        }
        node* minBefore = head;
        while (minBefore->next != min)
        {
            minBefore = minBefore->next;
        }
        node* temp = visit->next;
        minBefore->next = visit;
        visit->next = min->next;
        visitBefore->next = min;
        min->next = temp;

        visitBefore = min;
        visit = min->next;
    }
}

int main()
{
    int n = 6;
    int a[] = {5,2,4,6,1,3};

    node* a0 = new node;
    a0->data = -1;
    node* a1 = new node;
    a1->data = 5;
    a0->next = a1;
    node* a2 = new node;
    a2->data = 2;
    a1->next = a2;
    node* a3 = new node;
    a3->data = 4;
    a2->next = a3;
    node* a4 = new node;
    a4->data = 6;
    a3->next = a4;
    node* a5 = new node;
    a5->data = 1;
    a4->next = a5;
    node* a6 = new node;
    a6->data = 3;
    a5->next = a6;

    // SelectSort(a, n);
    // for (int i = 0; i < n; ++i)
    // {
    //     cout << a[i] << " ";
    // }
    SelectSort(a0);
    node* visit = a0;
    while (visit != nullptr)
    {
        cout << visit->data << " ";
        visit = visit->next;
    }
    return 0;
}