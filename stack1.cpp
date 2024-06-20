//Use stacks to balance brackets in an expression entered by the user.

#include <iostream>
#include <stack>
#include <string>

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

std::string balanceBrackets(const std::string& expression) {
    std::stack<char> s;
    std::string balancedExpression = expression;
    std::stack<int> unmatchedIndices;

    // First pass: Identify unmatched closing brackets
    for (size_t i = 0; i < expression.size(); ++i)
        {
        char ch = expression[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
            unmatchedIndices.push(i);

        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (!s.empty() && isMatchingPair(s.top(), ch)) {
                s.pop();
                unmatchedIndices.pop();
                             // remove the unmatched index as a match of opening bracket is found
            } else {
                // Insert corresponding opening bracket at the start of the unmatched closing bracket
                if (ch == ')') balancedExpression.insert(balancedExpression.begin() + i, '(');
                else if (ch == '}') balancedExpression.insert(balancedExpression.begin() + i, '{');
                else if (ch == ']') balancedExpression.insert(balancedExpression.begin() + i, '[');
                i++;
            }
        }
    }

    // Second pass: Handle unmatched opening brackets by adding closing brackets at the end
    while (!s.empty()) {
        char unmatchedOpen = s.top();
        s.pop();
        if (unmatchedOpen == '(') balancedExpression += ')';
        else if (unmatchedOpen == '{') balancedExpression += '}';
        else if (unmatchedOpen == '[') balancedExpression += ']';
    }

    return balancedExpression;
}

int main() {
    std::string expression;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    std::string balancedExpression = balanceBrackets(expression);

    std::cout << "Balanced expression: " << balancedExpression << std::endl;

    return 0;
}
