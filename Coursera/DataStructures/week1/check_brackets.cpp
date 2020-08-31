#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    bool matchLeft = false;
    bool redundantLeft = false;
    int lastClosingMismatch = 1;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            Bracket currElem(next, position);
            opening_brackets_stack.push(currElem);
        }

        if (next == ')' || next == ']' || next == '}') {
            lastClosingMismatch = position + 1;
            // Process closing bracket, write your code here
            if (!opening_brackets_stack.empty()){
                Bracket topStack = opening_brackets_stack.top();
                opening_brackets_stack.pop();
                matchLeft = topStack.Matchc(next);

                if (!matchLeft)
                    break;
            }else{
                redundantLeft = true;
                break;
            }
        }
    }

    // Printing answer, write your code here
    if (matchLeft && opening_brackets_stack.empty() && !redundantLeft)
        std::cout << "Success";
    else if (!matchLeft || redundantLeft)
        std::cout << lastClosingMismatch;
    else
        std::cout << opening_brackets_stack.top().position + 1;
    return 0;
}
