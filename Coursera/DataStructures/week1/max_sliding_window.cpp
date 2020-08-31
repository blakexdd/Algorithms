#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <cassert>

class StackWithMax {
private:
    int maxValue = INT32_MIN;
    std::stack<int> maxNumsStack;
public:
    std::stack<int> stack;
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
            if (!maxNumsStack.empty())
                maxValue = maxNumsStack.top();
            else
                maxValue = INT32_MIN;
        }

        stack.pop();
    }

    int Top() {
        assert(stack.size());

        return stack.top();
    }

    int Max() const {
        assert(stack.size());
        return maxNumsStack.top();
    }
};

using std::cin;
using std::cout;
using std::vector;
using std::max;

void max_sliding_window_naive(vector<int> A, int w) {
    StackWithMax leftStack;
    StackWithMax rightStack;
    int counter = 0;

    for (int i = w - 1; i >= 0; i--)
        leftStack.Push(A[i]);

    for (int j = 0; j < A.size() - w + 1;){
        int leftMax = INT32_MIN;
        int rightMax = INT32_MIN;

        if (!leftStack.Empty())
            leftMax = leftStack.Max();

        if (!rightStack.Empty())
            rightMax = rightStack.Max();

        if (leftStack.Empty()){
            while(!rightStack.Empty()){
                int top = rightStack.Top();
                rightStack.Pop();
                leftStack.Push(top);
            }
        }else if (!leftStack.Empty()){
            leftStack.Pop();
            if (j + w < A.size())
                rightStack.Push(A[j + w]);

            std::cout << max(rightMax, leftMax) << " ";
            j++;
            counter++;
        }
    }

//    while(!rightStack.Empty()){
//        int top = rightStack.Top();
//        rightStack.Pop();
//        std::cout << "right: " << top << " ";
//    }
//
//    while(!leftStack.Empty()){
//        int top = leftStack.Top();
//        leftStack.Pop();
//        std::cout << "leftStack: " << top << " ";
//    }

    while (counter < A.size() - w + 1){
        int leftMax = INT32_MIN;
        int rightMax = INT32_MIN;

        if (!leftStack.Empty())
            leftMax = leftStack.Max();

        if (!rightStack.Empty())
            rightMax = rightStack.Max();

        if (rightMax != INT32_MIN || leftMax != INT32_MIN)
            std::cout << max(rightMax, leftMax) << " ";

        counter++;
    }

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
