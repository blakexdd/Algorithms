#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <climits>
#include <stack>

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    std::stack<int> stack;
private:
    int maxValue = INT32_MIN;
    std::stack<int> maxNumsStack;
public:
    bool Empty(){
        return stack.empty();
    }

    void Push(int value) {
        if (maxValue <= value){
            maxValue = value;
            maxNumsStack.push(maxValue);
        }

        stack.push(value);
    }

    void Pop() {
        assert(stack.size());
        if (maxValue == stack.top()){
            maxNumsStack.pop();
            maxValue = maxNumsStack.top();
        }

        stack.pop();
    }

    void Top() {
        assert(stack.size());

        stack.top();
    }

    int Max() const {
        assert(stack.size());
        return maxNumsStack.top();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}