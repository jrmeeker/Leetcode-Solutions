/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.*/

#include<string>
#include<stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numStack;
        std::unordered_set<string> operators {"+","-","*","/"};

        for(auto token:tokens){
            if(operators.count(token) < 1){
                numStack.push(stoi(token));
            }
            else{
                int b = numStack.top();
                numStack.pop();
                int a = numStack.top();
                numStack.pop();

                int res = 0;
                if (token == "+")
                    res = a + b;
                else if(token == "-")
                    res = a - b;
                else if(token == "*")
                    res = a * b; 
                else
                    res = (int)(a / b);

                numStack.push(res);
            }
        }

        return numStack.top();
    }
};