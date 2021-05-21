#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int front, rear, length;
    int *queue;
    Queue(int c)
    {
        front = rear = 0;
        length = c;
        queue = new int;
    }

    void pushBack(int data)
    {
        if (length == rear)
        {
            cout << "Out of mem";
            return;
        }
        else
        {
            queue[rear] = data;
            rear++;
        }
        return;
    }

    void popFront()
    {
        if (front == rear)
        {
            cout << "Empty";
            return;
        }
        else
        {
            for (int i = 0; i < rear - 1; i++)
            {
                queue[i] = queue[i + 1];
            }

            rear--;
        }
        return;
    }

    void print()
    {
        int i;
        if (front == rear)
        {
            cout << "Empty";
            return;
        }

        for (i = front; i < rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
        return;
    }
};

int main(void)
{
    Queue queue(5);

    queue.pushBack(2);
    queue.pushBack(3);
    queue.print();
    queue.popFront();
    queue.print();

    return 0;
}