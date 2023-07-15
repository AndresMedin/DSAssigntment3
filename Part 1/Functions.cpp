#include "functions.h"
#include <stack>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

string infixToPostfix(const string& expression) {
    stack<char> stk;
    string postfix;
    int length = expression.length();

    for (int i = 0; i < length; i++) {
        char ch = expression[i];

        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stk.push(ch);
        } else if (ch == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            if (!stk.empty() && stk.top() != '(')
                return "Invalid expression";
            stk.pop();
        } else if (isOperator(ch)) {
            while (!stk.empty() && getPrecedence(ch) <= getPrecedence(stk.top())) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }

    while (!stk.empty()) {
        if (stk.top() == '(')
            return "Invalid expression";
        postfix += stk.top();
        stk.pop();
    }

    return postfix;
}

bool isBalancedParentheses(const string& expression) {
    stack<char> stk;
    int length = expression.length();

    for (int i = 0; i < length; i++) {
        char ch = expression[i];

        if (ch == '{' || ch == '(' || ch == '[') {
            stk.push(ch);
        } else if (ch == '}' || ch == ')' || ch == ']') {
            if (stk.empty())
                return false;
            char top = stk.top();
            stk.pop();

            if ((ch == '}' && top != '{') || (ch == ')' && top != '(') || (ch == ']' && top != '['))
                return false;
        }
    }

    return stk.empty();
}
