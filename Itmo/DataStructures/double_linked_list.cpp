#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DoubleLinkedList
{
public:
    int data;
    DoubleLinkedList *next;
    DoubleLinkedList *prev;
};

class DoubleLinkedListHelper
{
public:
    static void pushFront(DoubleLinkedList **head, int new_value)
    {
        DoubleLinkedList *new_node = new DoubleLinkedList();

        new_node->data = new_value;
        new_node->next = (*head);
        new_node->prev = NULL;

        if ((*head) != NULL)
            (*head)->prev = new_node;

        (*head) = new_node;
    }

    static void pushBack(DoubleLinkedList **head, int new_value)
    {
        DoubleLinkedList *new_node = new DoubleLinkedList();
        DoubleLinkedList *last = *head;

        new_node->data = new_value;

        new_node->next = NULL;

        if (*head == NULL)
        {
            new_node->prev = NULL;
            *head = new_node;
            return;
        }

        while (last->next != NULL)
            last = last->next;

        last->next = new_node;
        new_node->prev = last;

        return;
    }

    static void insertAfter(DoubleLinkedList *node, int new_val)
    {
        if (node == NULL)
        {
            cout << "the given previous node cannot be NULL";
            return;
        }

        DoubleLinkedList *new_node = new DoubleLinkedList();

        new_node->data = new_val;
        new_node->next = node->next;
        node->next = new_node;
        new_node->prev = node;

        if (new_node->next != NULL)
            new_node->next->prev = new_node;
    }

    static void printDoubleLinkedList(DoubleLinkedList *node)
    {
        DoubleLinkedList *last;

        while (node != NULL)
        {
            cout << node->data << " ";
            last = node;
            node = node->next;
        }
    }
};

int main()
{
    DoubleLinkedList *head = NULL;

    DoubleLinkedListHelper::pushFront(&head, 2);
    DoubleLinkedListHelper::pushBack(&head, 3);
    DoubleLinkedListHelper::insertAfter(head->next, 5);
    DoubleLinkedListHelper::pushBack(&head, 7);
    DoubleLinkedListHelper::pushFront(&head, 10);

    cout << "Example double linked list:\n";
    DoubleLinkedListHelper::printDoubleLinkedList(head);
    cout << endl;

    return 0;
}