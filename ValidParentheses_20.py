'''Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
  determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.'''

class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0:
            return False 

        p_stack = []
        for ch in s:
            if ch == '(':
                p_stack.append(')')
            elif ch == '[':
                p_stack.append(']')
            elif ch == '{':
                p_stack.append('}')

            else:
                if len(p_stack) < 1 or p_stack.pop() != ch:
                    return False 

        return len(p_stack) == 0