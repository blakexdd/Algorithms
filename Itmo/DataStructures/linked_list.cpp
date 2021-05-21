#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList *next;
};

void printLinkedList(LinkedList *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void showLinkedListExample()
{
    LinkedList *head = new LinkedList();
    LinkedList *second = new LinkedList();
    LinkedList *third = new LinkedList();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    cout << "Printing example linked list:\n";
    printLinkedList(head);
    cout << endl;
}

int main(void)
{
    showLinkedListExample();

    return 0;
}