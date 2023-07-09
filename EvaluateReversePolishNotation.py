'''You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.'''


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        num_stack = [] 
        operators = set({'+','-','*','/'})

        for token in tokens:
            if token not in operators:
                num_stack.append(int(token))
            else:
                b = num_stack.pop() 
                a = num_stack.pop() 

                if token == '+':
                    res = a + b 
                elif token == '-':
                    res = a - b 
                elif token == '*': 
                    res = a * b 
                else:
                    res = int(a / b)

                num_stack.append(res)

        return num_stack.pop()