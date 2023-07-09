/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.*/

#include <climits>
#include <stack>

class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> mStack;
    int min;
    
public:
    MinStack() {
            min = INT_MAX;
    }
    
    void push(int val) {
        mainStack.push(val);
        if (val < min)
            min = val;
        mStack.push(min);
    }
    
    void pop() {
        int out = mainStack.top();
        mainStack.pop();
        mStack.pop();

        if (!mStack.empty()){
            min = mStack.top();
        }
        else{
            min = INT_MAX;
        }    
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return min;
    }
};