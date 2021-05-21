#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ExpressionEvaluator
{
public:
    static int order(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0;
    }

    static int calculateOperator(int a, int b, char op)
    {
        switch (op)
        {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        }

        return 0;
    }

    static int evaluate(string expresion)
    {
        int i;

        stack<int> values;
        stack<char> operations;

        for (i = 0; i < expresion.length(); i++)
        {

            if (expresion[i] == ' ')
                continue;

            else if (expresion[i] == '(')
            {
                operations.push(expresion[i]);
            }

            else if (isdigit(expresion[i]))
            {
                int val = 0;

                while (i < expresion.length() &&
                       isdigit(expresion[i]))
                {
                    val = (val * 10) + (expresion[i] - '0');
                    i++;
                }

                values.push(val);
                i--;
            }

            else if (expresion[i] == ')')
            {
                while (!operations.empty() && operations.top() != '(')
                {
                    int val2 = values.top();
                    values.pop();

                    int val1 = values.top();
                    values.pop();

                    char op = operations.top();
                    operations.pop();

                    values.push(calculateOperator(val1, val2, op));
                }

                if (!operations.empty())
                    operations.pop();
            }
            else
            {
                while (!operations.empty() && order(operations.top()) >= order(expresion[i]))
                {
                    int val2 = values.top();
                    values.pop();

                    int val1 = values.top();
                    values.pop();

                    char op = operations.top();
                    operations.pop();

                    values.push(calculateOperator(val1, val2, op));
                }

                operations.push(expresion[i]);
            }
        }

        while (!operations.empty())
        {
            int val2 = values.top();
            values.pop();

            int val1 = values.top();
            values.pop();

            char op = operations.top();
            operations.pop();

            values.push(calculateOperator(val1, val2, op));
        }

        return values.top();
    }
};

int main()
{
    cout << "Answer: " << ExpressionEvaluator::evaluate("2*(3+2)*((5*2-8)+(6-2*2))");
    return 0;
}