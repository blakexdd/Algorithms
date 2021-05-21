#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct CircularList
{
    int data;
    struct CircularList *next;
};

class CircularListHelper
{
private:
    static struct CircularList *addFirst(struct CircularList *last, int data)
    {
        if (last != NULL)
            return last;

        struct CircularList *temp =
            (struct CircularList *)malloc(sizeof(struct CircularList));

        temp->data = data;
        last = temp;
        last->next = last;

        return last;
    }

public:
    static struct CircularList *pushFront(struct CircularList *last, int data)
    {
        if (last == NULL)
            return CircularListHelper::addFirst(last, data);

        struct CircularList *temp =
            (struct CircularList *)malloc(sizeof(struct CircularList));

        temp->data = data;
        temp->next = last->next;
        last->next = temp;

        return last;
    }

    static struct CircularList *pushBack(struct CircularList *last, int data)
    {
        if (last == NULL)
            return CircularListHelper::addFirst(last, data);

        struct CircularList *temp =
            (struct CircularList *)malloc(sizeof(struct CircularList));

        temp->data = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;

        return last;
    }

    static struct CircularList *addAfter(struct CircularList *last, int data, int item)
    {
        if (last == NULL)
            return NULL;

        struct CircularList *temp, *p;
        p = last->next;
        do
        {
            if (p->data == item)
            {
                temp = (struct CircularList *)malloc(sizeof(struct CircularList));
                temp->data = data;
                temp->next = p->next;
                p->next = temp;

                if (p == last)
                    last = temp;
                return last;
            }
            p = p->next;
        } while (p != last->next);

        return last;
    }

    static void print(struct CircularList *last)
    {
        struct CircularList *p;

        if (last == NULL)
        {
            cout << "Empty" << endl;
            return;
        }

        p = last->next;

        do
        {
            cout << p->data << " ";
            p = p->next;

        } while (p != last->next);
    }
};

int main()
{
    struct CircularList *last = NULL;

    last = CircularListHelper::pushBack(last, 6);
    last = CircularListHelper::pushFront(last, 4);
    last = CircularListHelper::pushFront(last, 2);
    last = CircularListHelper::addAfter(last, 2, 3);
    last = CircularListHelper::pushBack(last, 5);
    last = CircularListHelper::pushFront(last, 2);

    CircularListHelper::print(last);

    return 0;
}