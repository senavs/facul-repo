from ..simple_queue import SimpleQueue
from ..simple_stack import SimpleStack


class MathExpressionCompiler(object):
    _OPERATORS = {'+': 1, '-': 1, '*': 2, '/': 2, '%': 2, '**': 3}
    _OPEN = {'('}
    _CLOSE = {')'}
    
    def to_postfix(self, infix, evaluate=False):
        infix = SimpleQueue(infix.strip().split())
        stack = SimpleStack()
        postfix = str()
        while len(infix) != 0:
            char = infix.dequeue()
            if char.isalpha() or char.isnumeric():  # If is an operand
                postfix += char
                postfix += ' '
            elif char in self._OPEN:  # If is a opened parentheses 
                stack.push(char)
            elif char in self._CLOSE:  # If is a closed parentheses 
                while stack.peek() not in self._OPEN:
                    postfix += stack.pop()
                    postfix += ' '
                stack.pop()
            else:  # If is an operator
                while len(stack) > 0 and stack.peek() not in self._OPEN and self._OPERATORS[stack.peek()] >= self._OPERATORS[char]:
                    postfix += stack.pop()
                    postfix += ' '
                stack.push(char)

            if len(infix) == 0 and len(stack) > 0:  # If infix queue is empty, so pop all operators in stack and add to postfix expression
                while len(stack) != 0:
                    postfix += stack.pop()
                    postfix += ' '
        if evaluate:
            return {'result': self.evaluate(postfix), 'postfix': postfix[:-1]}
        return postfix[:-1]
    
    def evaluate(self, postfix, variables={}):
        stack = SimpleStack()
        postfix = SimpleQueue(postfix.strip().split())
        while len(postfix) != 0:
            char = postfix.dequeue()
            if char.isalpha() or char.isnumeric():  # If is an operand
                stack.push(eval(char, variables))
            else:  # If is an operator
                operand_1 = stack.pop()
                operand_2 = stack.pop()
                answer = eval(f'operand_2 {char} operand_1', variables, locals())
                stack.push(answer)
        return stack.pop()

