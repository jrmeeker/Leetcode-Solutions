'''Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.'''

class MinStack:

    def __init__(self):
        self.stack = []
        self.min = float(inf)
        self.min_stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if val < self.min:
            self.min = val
        self.min_stack.append(self.min)
            
    def pop(self) -> None:
        out = self.top() 
        self.stack = self.stack[:-1]
        self.min_stack = self.min_stack[:-1]
        if self.min_stack:
            self.min = self.min_stack[-1]
        else:
            self.min = float(inf)
        return out

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min