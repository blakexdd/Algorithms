
#include <bits/stdc++.h>

class Node
{
public:
    std::string value;
    Node *left = NULL, *right = NULL;
    Node(std::string x)
    {
        value = x;
    }
};

int stringToNumber(std::string s)
{
    int num = 0;

    if (s[0] != '-')
    {
        for (int i = 0; i < s.length(); i++)
            num = num * 10 + (int(s[i]) - 48);
    }
    else
    {
        for (int i = 1; i < s.length(); i++)
        {
            num = num * 10 + (int(s[i]) - 48);
            num = num * -1;
        }
    }

    return num;
}

int solveTree(Node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return stringToNumber(root->value);

    int leftValue = solveTree(root->left);
    int rightValue = solveTree(root->right);

    if (root->value == "+")
        return leftValue + rightValue;

    if (root->value == "-")
        return leftValue - rightValue;

    if (root->value == "*")
        return leftValue * rightValue;

    return leftValue / rightValue;
}

int main()
{
    Node *root = new Node("/");
    root->left = new Node("*");
    root->right = new Node("3");
    root->left->left = new Node("+");
    root->left->left->left = new Node("2");
    root->left->left->right = new Node("3");
    root->left->right = new Node("-");
    root->left->right->left = new Node("7");
    root->left->right->right = new Node("4");

    std::cout << "Result: " << solveTree(root) << "\n";
    return 0;
}