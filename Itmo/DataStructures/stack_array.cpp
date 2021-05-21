#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int a[1000];
    int top;

    Stack() { top = -1; }

    bool push(int x)
    {
        if (top >= (1000 - 1))
        {
            cout << "Overflow";
            return false;
        }
        else
        {
            a[++top] = x;
            return true;
        }
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Empty";
            return 0;
        }
        else
        {
            int x = a[top--];
            return x;
        }
    }

    bool empty()
    {
        return (top < 0);
    }
};

int main()
{
    class Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty())
    {
        cout << s.pop() << " ";
    }

    return 0;
}