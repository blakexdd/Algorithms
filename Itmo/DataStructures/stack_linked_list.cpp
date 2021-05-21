#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *link;
};

class StackLinkedListHelper
{
public:
    static Node *pushBack(Node *top, int data)
    {
        struct Node *temp;
        temp = new Node();

        if (!temp)
        {
            cout << "Overflow";
            exit(1);
        }

        temp->data = data;
        temp->link = top;
        top = temp;

        return top;
    }

    static int empty(Node *top)
    {
        return top == NULL;
    }

    static Node *pop(Node *top)
    {
        struct Node *temp;

        if (top == NULL)
        {
            cout << "No items" << endl;
            exit(1);
        }
        else
        {
            temp = top;
            top = top->link;
            temp->link = NULL;
            free(temp);
            return top;
        }
    }

    static void print(Node *top)
    {
        struct Node *temp;

        if (top == NULL)
        {
            cout << "Empty";
            exit(1);
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->link;
            }
            cout << endl;
        }
    }
};

int main()
{
    struct Node *top;
    top = StackLinkedListHelper::
        pushBack(top, 1);
    top = StackLinkedListHelper::
        pushBack(top, 2);
    top = StackLinkedListHelper::
        pushBack(top, 3);
    top = StackLinkedListHelper::
        pushBack(top, 4);

    StackLinkedListHelper::print(top);

    top = StackLinkedListHelper::pop(top);

    StackLinkedListHelper::print(top);

    return 0;
}